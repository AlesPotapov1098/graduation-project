#include "MainWindow.h"

namespace gui {


	LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT mess, WPARAM wParam, LPARAM lParam)
	{
		static ctrl::Button test(hwnd,"Test Button",1001,100,50,50,50,"BUTTON","TestButton");

		switch (mess)
		{
		case WM_DESTROY:
		{
			PostQuitMessage(EXIT_SUCCESS);
		}
		return 0;

		case WM_CREATE:
		{
			if (!test.Build())
			{
				abort();
			}
		}
		return 0;

		case WM_COMMAND:
		{
			if (test.GetControlID() == static_cast<__int32>(wParam))
			{
				test.OnClick();
			}
		}
		return 0;

		case WM_DRAWITEM:
		{
			OutputDebugStringA("WM_DRAWITEM");
		}
		return 0;
		
		default:
			break;
		}

		return DefWindowProcA(hwnd, mess, wParam, lParam);
	}

	MainWindow::MainWindow(__int32 width, __int32 heigth, __int32 x, __int32 y, LPCSTR ClassName, LPCSTR WindowName, HINSTANCE hInst)
	: IGUIObject(width,heigth,x,y,ClassName,WindowName)
	{
		m_hInstance = hInst;
		ZeroMemory(&m_WindowClass, sizeof(WNDCLASSEXA));
		m_ForeBrush = CreateSolidBrush(color::ANTHRACITE);
		m_Cursor = LoadCursor(0, IDC_ARROW);
	}

	MainWindow::~MainWindow()
	{
		CloseWindow(m_hwnd);
		ZeroMemory(&m_WindowClass, sizeof(WNDCLASSEXA));
	}

	bool MainWindow::Build()
	{
		m_WindowClass.cbSize = sizeof(WNDCLASSEXA);
		m_WindowClass.lpfnWndProc = WindowProcedure;
		m_WindowClass.hInstance = m_hInstance;
		m_WindowClass.style = CS_VREDRAW | CS_HREDRAW;
		m_WindowClass.hbrBackground = m_ForeBrush;
		m_WindowClass.lpszClassName = m_ClassObjectName;
		m_WindowClass.hCursor = m_Cursor;

		if (!RegisterClassExA(&m_WindowClass))
			return false;

		m_hwnd = CreateWindowExA(
			0, 
			m_WindowClass.lpszClassName, 
			m_ObjectName, 
			WS_OVERLAPPEDWINDOW, 
			m_XPos, m_YPos, 
			m_Width, m_Heigth, 
			nullptr, 
			nullptr, 
			m_hInstance, 
			nullptr);

		return m_hwnd;
	}

	void MainWindow::Run()
	{
		ShowWindow(m_hwnd, SW_SHOWNORMAL);
		UpdateWindow(m_hwnd);
		while(GetMessageA(&m_MessageStruct, nullptr, 0, 0))
		{
			TranslateMessage(&m_MessageStruct);
			DispatchMessageA(&m_MessageStruct);
		}
	}
}
