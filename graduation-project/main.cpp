#include <CL/cl.h>
#include <iostream>
#include <Windows.h>
#include <windowsx.h>

#include "cl_platform.h"

typedef HWND (*__stdcall create_window)(HINSTANCE instance,LPCSTR window_name,LPCSTR class_windw_name);

HWND __stdcall CreateEWindow(HINSTANCE inst,LPCSTR wndname, LPCSTR classname);

int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR cmdLine,
	int count) 
{
	create_window start = &CreateEWindow;
	if (!start(hInstance, "First Window", "GraduationProjectMainWindow")) {
		MessageBoxExA(nullptr,"Что-то пошло не так","Error",0,RUSSIAN_CHARSET);
		return -1;
	}
	
	return 0;
}

HWND __stdcall CreateEWindow(HINSTANCE inst, LPCSTR wndname, LPCSTR classname)
{
	WNDCLASSEXA windowClass;
	std::memset(&windowClass,0,sizeof(WNDCLASSEXA));

	windowClass.cbSize = sizeof(WNDCLASSEXA);
	windowClass.hInstance = inst;
	windowClass.lpfnWndProc = DefWindowProcA;
	windowClass.lpszClassName = classname;

	if (!RegisterClassExA(&windowClass)) {
		return nullptr;
	}

	HWND hwnd = CreateWindowExA(
			0,
			classname, 
			wndname,
			WS_OVERLAPPEDWINDOW | WS_VISIBLE,
			500, 300, 500, 380,
			NULL, NULL, inst, NULL);

	return hwnd;
}
