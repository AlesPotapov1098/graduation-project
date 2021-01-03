#include "ApplicationWindow.h"

namespace gp {

    namespace app {

        ApplicationWindow::ApplicationWindow(HINSTANCE hInst, LPCSTR windowName, LPCSTR className)
            : m_Instance(hInst), m_WindowName(windowName), m_ClassName(className)
        {
            m_hWnd = nullptr;
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
            }

            return DefWindowProcA(hWnd, msg, wParam, lParam);
        }

        LRESULT ApplicationWindow::WindowFunctionSetup(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
        {
            ApplicationWindow* appWnd = reinterpret_cast<ApplicationWindow*>(GetWindowLongPtrA(hWnd, GWLP_USERDATA));

            if (!appWnd)
                return appWnd->WindowFunction(hWnd, msg, wParam, lParam);

            switch (msg)
            {
            case WM_DESTROY:
                PostQuitMessage(EXIT_SUCCESS);
                break;
            }

            return DefWindowProcA(hWnd, msg, wParam, lParam);
        }

        bool ApplicationWindow::Init()
        {
            WNDCLASSA wndClass = { sizeof wndClass };
            ZeroMemory(&wndClass, sizeof wndClass);

            wndClass.hInstance = m_Instance;
            wndClass.lpszClassName = m_ClassName;
            wndClass.lpfnWndProc = WindowFunctionSetup;
            wndClass.hbrBackground = CreateSolidBrush(BLACKNESS);

            return RegisterClassA(&wndClass);
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
                this);

            if (!m_hWnd)
                return GetLastError();

            return 0;
        }

        void ApplicationWindow::Run()
        {
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
        }

    }

}
