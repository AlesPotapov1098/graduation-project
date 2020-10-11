#pragma once
#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

#include <iostream>
#include <Windows.h>

enum Color : COLORREF
{
	BLUE		= 0x00ff0000,
	RED			= 0x000000ff,
	GREEN		= 0x0000ff00,
};

LRESULT WindowProcedure(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{

	switch (message)
	{
	case WM_DESTROY:
	{
		PostQuitMessage(EXIT_SUCCESS);
	}
	return 0;

	case WM_CREATE:
	{
		HWND button = CreateWindow(L"BUTTON", L"OK", WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE, 0, 0, 100, 100, hwnd, nullptr, nullptr, nullptr);
	}
	return 0;

	default:
		break;
	}

	return DefWindowProcA(hwnd,message,wParam,lParam);
}

class IObject
{
public:
	IObject()
	{
		m_ClassObjectName = "ClassObject";
		m_ObjectName = "ObjectName";
		m_hWnd = nullptr;
	}

	IObject(LPCSTR className, LPCSTR objectName) 
	{
		m_ClassObjectName = className;
		m_ObjectName = objectName;
		m_hWnd = nullptr;
	}

	void onCreate(HWND parent = nullptr)
	{

	}

	void onRegister(HINSTANCE hInst) 
	{
		ZeroMemory(&m_WndClass, sizeof(WNDCLASSEXA));
		m_WndClass.cbSize = sizeof(WNDCLASSEXA);
		m_WndClass.lpfnWndProc = WindowProcedure;
		m_WndClass.hInstance = hInst;
		m_WndClass.lpszClassName = m_ClassObjectName;
		m_WndClass.lpszMenuName = nullptr;
		m_WndClass.style = CS_VREDRAW | CS_HREDRAW;
		m_WndClass.hbrBackground = CreateSolidBrush(Color::RED);

		if (!RegisterClassExA(&m_WndClass))
		{
			abort();
		}

		m_hWnd = CreateWindowExA(0, m_ClassObjectName, m_ObjectName, WS_OVERLAPPEDWINDOW, 0, 0, 600, 600, nullptr, nullptr, hInst, nullptr);
		if (!m_hWnd)
		{
			abort();
		}

		ShowWindow(m_hWnd, SW_NORMAL);
		UpdateWindow(m_hWnd);
	}

	void onStart()
	{
		MSG msg{};
		while (GetMessageA(&msg, nullptr, 0, 0))
		{
			TranslateMessage(&msg);
			DispatchMessageA(&msg);
		}
	}
	
	~IObject()
	{
		CloseWindow(m_hWnd);
		ZeroMemory(&m_WndClass, sizeof(WNDCLASSEXA));
	}

private:
	HWND m_hWnd;
	WNDCLASSEXA m_WndClass;
	LPCSTR m_ClassObjectName;
	LPCSTR m_ObjectName;
};

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR cmd, int count)
{
	IObject test{ "First","FirstWindow" };
	test.onRegister(hInstance);
	test.onStart();
	return 0;
}









