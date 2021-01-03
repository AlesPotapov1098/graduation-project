#pragma once
#include <Windows.h>
#include <d2d1.h>

#include "Proportions.h"

class MessageProcedure
{
public:
    MessageProcedure() = default;
    ~MessageProcedure() = default;

    virtual LRESULT operator()(HWND, WPARAM, LPARAM) const = 0;
};

//Переменные окна
LPCSTR WindowName = "GraduationProject";
LPCSTR WindowClass = "DirectXWindow";
const __int32 wndWidth = 1600;
const __int32 wndHeight = 800;
PAINTSTRUCT ps;
HINSTANCE hInst;

//Переменные DirectX
ID2D1Factory* d2d1Factory{};
ID2D1HwndRenderTarget* rt{};
ID2D1HwndRenderTarget* rt1{};

//Window функции
LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

//Функции рендера
bool InitDirectX()
{
    HRESULT res = D2D1CreateFactory(D2D1_FACTORY_TYPE::D2D1_FACTORY_TYPE_SINGLE_THREADED, &d2d1Factory);
    return SUCCEEDED(res);
}

bool InitRenderTarget(HWND hwnd)
{
    HRESULT res = d2d1Factory->CreateHwndRenderTarget(D2D1::RenderTargetProperties(), D2D1::HwndRenderTargetProperties(hwnd, D2D1::SizeU(wndWidth, wndHeight)), &rt);
    return SUCCEEDED(res) && rt;
}

bool InitRenderTarget1(HWND hwnd)
{
    HRESULT res = d2d1Factory->CreateHwndRenderTarget(D2D1::RenderTargetProperties(), D2D1::HwndRenderTargetProperties(hwnd, D2D1::SizeU(wndWidth, wndHeight)), &rt1);
    return SUCCEEDED(res) && rt1;
}

//Переменные клиентского окна

HWND hWndClientWindow;
LPCSTR ClientWindowClass = "MDICLIENT";

//Функции клиентского окна

bool InitClientWindowClass(HINSTANCE);

LRESULT CALLBACK ClientWindowProc(HWND, UINT, WPARAM, LPARAM);

//Переменные MDI-окная

HWND hWndMDIWindow;
LPCSTR MDIWindowClass = "MDIWindow";

//Функции MDI-окна

LRESULT CALLBACK SimpleMDIWindowProc(HWND, UINT, WPARAM, LPARAM);

gp::prop::ClientAreaPos clientAreaPos;

//Начало
int WinMain(HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    PSTR szCmdLine,
    int iCmdShow)
{
    if (!InitDirectX())
        return EXIT_FAILURE;

    WNDCLASSA wndClass{ sizeof wndClass};
    wndClass.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wndClass.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
    wndClass.hInstance = hInstance;
    wndClass.style = CS_VREDRAW | CS_HREDRAW;
    wndClass.lpfnWndProc = WindowProc;
    wndClass.lpszClassName = WindowClass;

    if (!RegisterClassA(&wndClass) || !InitClientWindowClass(hInstance))
        return -1;
    
    auto hwnd = CreateWindowA(WindowClass, WindowName, WS_OVERLAPPEDWINDOW | WS_VISIBLE | WS_SIZEBOX, 200, 200, wndWidth, wndHeight, nullptr, nullptr, hInstance, nullptr);
    if (!hwnd)
        return -1;

    if (!InitRenderTarget1(hwnd))
        return EXIT_FAILURE;

    hInst = hInstance;

    MSG msg;
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateMDISysAccel(hWndClientWindow, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessageW(&msg);
        }
    }

	return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    static PAINTSTRUCT ps1;
    switch (msg)
    {

    case WM_CREATE:
    {
        RECT rect;
        GetClientRect(hwnd, &rect);

        clientAreaPos.ConvertFromRectToPos(rect);

        CLIENTCREATESTRUCT ccs;
        memset(&ccs, 0, sizeof(CLIENTCREATESTRUCT));

        hWndClientWindow = CreateWindowA(
            ClientWindowClass,
            (LPCSTR)NULL,
            WS_CHILD | WS_CLIPCHILDREN ,
            clientAreaPos.GetX(), 
            clientAreaPos.GetY(),
            clientAreaPos.GetCX(), 
            clientAreaPos.GetCY(),
            hwnd,
            nullptr,
            hInst,
            (LPSTR)&ccs);

        if (!hWndClientWindow)
            return 0;

        ShowWindow(hWndClientWindow, SW_SHOW);
    } 
    break;

    case WM_DESTROY:
        PostQuitMessage(EXIT_SUCCESS);
        break;

    case WM_DISPLAYCHANGE:
    case WM_PAINT:
    {
        BeginPaint(hwnd, &ps1);
        rt1->BeginDraw();
        rt1->Clear(D2D1::ColorF(D2D1::ColorF::Bisque));
        rt1->EndDraw();
        EndPaint(hwnd, &ps1);
    }
    break;

    case WM_SIZE:
    {
        RECT rect;
        GetClientRect(hwnd, &rect);

        clientAreaPos.ConvertFromRectToPos(rect);

        SetWindowPos(
            hWndClientWindow, 
            nullptr, 
            clientAreaPos.GetX(), 
            clientAreaPos.GetY(),
            clientAreaPos.GetCX(),
            clientAreaPos.GetCY(), 
            0);
    }
    break;;

    case WM_LBUTTONDOWN:
    {
        if (hWndMDIWindow)
            return 0;

        hWndMDIWindow = CreateMDIWindowA(MDIWindowClass, (LPCSTR)"MDI Window",
            MDIS_ALLCHILDSTYLES, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, hWndClientWindow, hInst, NULL);

        if (!hWndMDIWindow)
            return 0;

        ShowWindow(hWndMDIWindow, SW_SHOW);
    }    break;

    default:
        return DefWindowProcA(hwnd, msg, wParam, lParam);
    }

    return 0;
}

bool InitClientWindowClass(HINSTANCE hInstance)
{
    WNDCLASSA ClientWndClass = { sizeof ClientWndClass };
    ClientWndClass.hInstance = hInstance;
    ClientWndClass.hCursor = LoadCursor(nullptr, IDC_ARROW);
    ClientWndClass.hbrBackground = CreateSolidBrush(WHITE_BRUSH);
    ClientWndClass.lpszClassName = MDIWindowClass;
    ClientWndClass.lpfnWndProc = ClientWindowProc;

    return RegisterClassA(&ClientWndClass);
}

LRESULT CALLBACK ClientWindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    static PAINTSTRUCT ps;
    switch (msg)
    {

    case WM_CREATE:
    {
        InitRenderTarget(hwnd);
    }
    break;

    case WM_PAINT:
    {
        BeginPaint(hwnd, &ps);
        rt->BeginDraw();
        rt->Clear(D2D1::ColorF(D2D1::ColorF::Firebrick));
        rt->EndDraw();
        EndPaint(hwnd, &ps);
    }
    break;

    case WM_LBUTTONDOWN:
    {
        
    }
    break;

   

    default:
        break;
    }

    return DefMDIChildProcA(hwnd, msg, wParam, lParam);
}






