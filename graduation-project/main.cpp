#pragma once
#include <Windows.h>
#include <d2d1.h>

#define WINDOW_CLASSIS 0x001a0000

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
const __int32 wndWidth = 500;
const __int32 wndHeight = 600;
PAINTSTRUCT ps;
HINSTANCE hInst;

//Переменные DirectX
ID2D1Factory* d2d1Factory{};
ID2D1HwndRenderTarget* rt{};

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

//Переменные клиентского окна

HWND hWndClientWindow;
LPCSTR ClientWindowClass = "MDICLIETN";

//Функции клиентского окна

bool InitClientWindowClass(HINSTANCE);

LRESULT CALLBACK ClientWindowProc(HWND, UINT, WPARAM, LPARAM);

//Переменные MDI-окная



//Функции MDI-окна

LRESULT CALLBACK SimpleMDIWindowProc(HWND, UINT, WPARAM, LPARAM);

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
    wndClass.hbrBackground = CreateSolidBrush(WINDOW_CLASSIS);

    if (!RegisterClassA(&wndClass) || !InitClientWindowClass(hInstance))
        return -1;
    
    auto hwnd = CreateWindowA(WindowClass, WindowName, WS_OVERLAPPEDWINDOW | WS_VISIBLE, 200, 200, wndWidth, wndHeight, nullptr, nullptr, hInstance, nullptr);
    if (!hwnd)
        return -1;

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

    switch (msg)
    {

    case WM_CREATE:
    {
        CLIENTCREATESTRUCT cs;
        ZeroMemory(&cs, sizeof cs);

        hWndClientWindow = CreateWindowA(
            ClientWindowClass,
            (LPCSTR)NULL,
            WS_CHILD | WS_CLIPCHILDREN ,
            0, 0, 300, 400,
            hwnd,
            nullptr,
            hInst,
            (LPSTR)&cs);

        if (!hWndClientWindow)
            return 0;

        ShowWindow(hWndClientWindow, SW_SHOW);

        InitRenderTarget(hWndClientWindow);
    } 
    break;

    case WM_DESTROY:
        PostQuitMessage(EXIT_SUCCESS);
        break;

    case WM_DISPLAYCHANGE:
    case WM_PAINT:
        
        break;

    default:
        break;
    }

    return DefWindowProcA(hwnd, msg, wParam, lParam);
}

bool InitClientWindowClass(HINSTANCE hInstance)
{
    WNDCLASSA ClientWndClass = { sizeof ClientWndClass };
    ClientWndClass.hInstance = hInstance;
    ClientWndClass.hCursor = LoadCursor(nullptr, IDC_ARROW);
    ClientWndClass.hbrBackground = CreateSolidBrush(WHITE_BRUSH);
    ClientWndClass.lpszClassName = ClientWindowClass;
    ClientWndClass.lpfnWndProc = ClientWindowProc;

    return RegisterClassA(&ClientWndClass);
}

LRESULT CALLBACK ClientWindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{

    switch (msg)
    {
    case WM_NCPAINT:
    {
        BeginPaint(hwnd, &ps);
        rt->BeginDraw();
        rt->Clear(D2D1::ColorF(D2D1::ColorF::Brown));
        rt->EndDraw();
        EndPaint(hwnd, &ps);
    }
    break;

    case WM_NCCREATE:
        break;

    default:
        break;
    }

    return DefMDIChildProcA(hwnd, msg, wParam, lParam);
}







