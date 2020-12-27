#pragma once
#include <Windows.h>
#include <d2d1.h>

//Переменные окна
LPCSTR WindowName = "GraduationProject";
LPCSTR WindowClass = "DirectXWindow";
const __int32 wndWidth = 500;
const __int32 wndHeight = 600;
PAINTSTRUCT ps;

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

    if (!RegisterClassA(&wndClass))
        return -1;
    
    auto hwnd = CreateWindowA(WindowClass, WindowName, WS_OVERLAPPEDWINDOW | WS_VISIBLE, 200, 200, wndWidth, wndHeight, nullptr, nullptr, hInstance, nullptr);
    if (!hwnd)
        return -1;

    if (!InitRenderTarget(hwnd))
        return EXIT_FAILURE;

    MSG msg;
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }

	return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{

    switch (msg)
    {
    case WM_DESTROY:
        PostQuitMessage(EXIT_SUCCESS);
        break;

    case WM_DISPLAYCHANGE:
    case WM_PAINT:
        BeginPaint(hwnd, &ps);
        rt->BeginDraw();
        rt->Clear(D2D1::ColorF(D2D1::ColorF::Brown));
        rt->EndDraw();
        EndPaint(hwnd, &ps);
        break;

    default:
        break;
    }

    return DefWindowProcA(hwnd, msg, wParam, lParam);
}









