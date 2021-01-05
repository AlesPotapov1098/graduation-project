#include "ApplicationWindow.h"

namespace gp {

    namespace app {

        ApplicationWindow::ApplicationWindow(HINSTANCE hInst, LPCSTR windowName, LPCSTR className)
            : m_Instance(hInst), m_WindowName(windowName), m_ClassName(className)
        {
            m_hWnd = nullptr;
            m_PaintStruct = { 0 };
        }

        ApplicationWindow::~ApplicationWindow()
        {
            DeleteObject(m_hWnd);
        }

        LRESULT ApplicationWindow::WindowFunction(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
        {
            switch (msg)
            {
            case WM_DESTROY:
                PostQuitMessage(EXIT_SUCCESS);
                break;

            case WM_DISPLAYCHANGE:
            case WM_PAINT:
                OnPaint();
                break;
            }

            return DefWindowProcA(hWnd, msg, wParam, lParam);
        }

        LRESULT ApplicationWindow::WindowFunctionSetup(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
        {
            if (msg == WM_NCCREATE)
            {
                static CREATESTRUCTA* createStruct = reinterpret_cast<CREATESTRUCTA*>(lParam);
                ApplicationWindow* const appWnd = static_cast<ApplicationWindow*>(createStruct->lpCreateParams);
                
                SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(appWnd));
               
                SetWindowLongPtr(hWnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(&ApplicationWindow::WindowFunctionThunk));

                return appWnd->WindowFunction(hWnd, msg, wParam, lParam);
            }

            return DefWindowProcA(hWnd, msg, wParam, lParam);
        }

        LRESULT ApplicationWindow::WindowFunctionThunk(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
        {
            ApplicationWindow* const appWnd = reinterpret_cast<ApplicationWindow*>(GetWindowLongPtr(hWnd, GWLP_USERDATA));

            if (appWnd)
                return appWnd->WindowFunction(hWnd, msg, wParam, lParam);

            return DefWindowProcA(hWnd, msg, wParam, lParam);
        }

        bool ApplicationWindow::Init()
        {
            WNDCLASSA wndClass = { sizeof wndClass };
            ZeroMemory(&wndClass, sizeof wndClass);

            wndClass.hInstance = m_Instance;
            wndClass.lpszClassName = m_ClassName;
            wndClass.lpfnWndProc = WindowFunctionSetup;

            return RegisterClassA(&wndClass);
        }

        bool ApplicationWindow::InitDirectX()
        {
            HRESULT result = D2D1CreateFactory(D2D1_FACTORY_TYPE::D2D1_FACTORY_TYPE_SINGLE_THREADED, &m_d2d1Factory);

            if (!SUCCEEDED(result) || !m_d2d1Factory)
                return false;

            result = m_d2d1Factory->CreateHwndRenderTarget(
                D2D1::RenderTargetProperties(), 
                D2D1::HwndRenderTargetProperties(m_hWnd, 
                    D2D1::SizeU(
                        m_WindowProportions.GetWidth(), 
                        m_WindowProportions.GetHeight())), 
                &m_d2d1RenderTarget);

            if (!SUCCEEDED(result) || !m_d2d1RenderTarget)
                return false;

            return true;
        }

        INT ApplicationWindow::Create()
        {
            m_hWnd = CreateWindowExA(
                0,
                m_ClassName,
                m_WindowName,
                WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                m_WindowProportions.GetX(),
                m_WindowProportions.GetY(),
                m_WindowProportions.GetWidth(),
                m_WindowProportions.GetHeight(),
                nullptr,
                nullptr,
                m_Instance,
                (LPVOID)this);

            if (!m_hWnd)
                return GetLastError();

            return 0;
        }

        void ApplicationWindow::Run()
        {
            if (!InitDirectX())
                return;

            MSG msg;
            
            while (GetMessage(&msg, nullptr, 0, 0))
            {
                TranslateMessage(&msg);
                DispatchMessageA(&msg);
            }
        }

        void ApplicationWindow::OnSize()
        {
        }

        void ApplicationWindow::OnPaint()
        {
            BeginPaint(m_hWnd, &m_PaintStruct);
            m_d2d1RenderTarget->BeginDraw();
            m_d2d1RenderTarget->Clear(D2D1::ColorF(D2D1::ColorF::Bisque));
            m_d2d1RenderTarget->EndDraw();
            EndPaint(m_hWnd, &m_PaintStruct);
        }

    }

}
