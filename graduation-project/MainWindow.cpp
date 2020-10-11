#include "MainWindow.h"

namespace gui {

	LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT mess, WPARAM wParam, LPARAM lParam)
	{

		switch (mess)
		{
		case WM_DESTROY:
		{
			PostQuitMessage(EXIT_SUCCESS);
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
