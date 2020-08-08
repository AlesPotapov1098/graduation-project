#include <CL/cl.h>
#include <iostream>
#include <Windows.h>
#include <windowsx.h>

struct host
{
	cl_platform_id   platform;
	cl_device_id     device;
	cl_context	     contex;
	cl_program	     program;
	cl_kernel        kernel;
	cl_command_queue command_queue;
};

host pC;

LRESULT MainWindowProc(HWND window, UINT mess, WPARAM wparam, LPARAM lparam);

BOOL InitWindow(HINSTANCE instance, LPCSTR classname);
HWND CreateEWindow(HINSTANCE inst,LPCSTR wndname, LPCSTR classname);

void InitHost()
{
	cl_uint count_platfroms = 0;
	if (clGetPlatformIDs(0, nullptr, &count_platfroms) != CL_SUCCESS)
	{
		MessageBoxA(nullptr,"Not platfroms id!!!","Error",MB_OK);
		return;
	}

	if (count_platfroms == 0)
	{
		MessageBoxA(nullptr, "Not platfroms id!!!", "Error", MB_OK);
		return;
	}

	cl_platform_id * platfroms = new cl_platform_id[count_platfroms];
	
	if (clGetPlatformIDs(count_platfroms, platfroms, nullptr) != CL_SUCCESS)
	{
		MessageBoxA(nullptr, "Not platfroms id!!!", "Error", MB_OK);
		return;
	}

	pC.platform = platfroms[1];

	if (clGetDeviceIDs(pC.platform, CL_DEVICE_TYPE_GPU, 1, &pC.device, nullptr) != CL_SUCCESS)
	{
		MessageBoxA(nullptr, "Not device GPU!!!", "Error", MB_OK);
		return;
	}
}

int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR cmdLine,
	int count) 
{
	LPCSTR MainWindowClassName = "Graduation project";
	LPCSTR MainWindowName = "Simple Windows App";
	
	if (!InitWindow(hInstance,MainWindowClassName))
	{
		return -1;
	}

	HWND hMainWindow = CreateEWindow(hInstance,MainWindowName,MainWindowClassName);
	
	if (!hMainWindow)
	{
		return -2;
	}

	MSG msg = {0};
	while (GetMessageA(&msg, nullptr, 0, 0))
	{
		if (msg.message == WM_QUIT)
		{
			break;
		}

		TranslateMessage(&msg);
		DispatchMessageA(&msg);
	}
	
	return 0;
}

BOOL InitWindow(HINSTANCE instance,LPCSTR classname)
{
	WNDCLASSEXA WindowClass;
	std::memset(&WindowClass,0,sizeof(WNDCLASSEXA));
	WindowClass.cbSize = sizeof(WNDCLASSEXA);
	WindowClass.style = CS_HREDRAW | CS_VREDRAW;
	WindowClass.hInstance = instance;
	WindowClass.lpfnWndProc = &MainWindowProc;
	WindowClass.lpszClassName = classname;

	return RegisterClassExA(&WindowClass);
}

HWND CreateEWindow(HINSTANCE inst, LPCSTR wndname, LPCSTR classname)
{
	return  CreateWindowExA(
			0,
			classname, 
			wndname,
			WS_OVERLAPPEDWINDOW | WS_VISIBLE | WS_SIZEBOX,
			500, 300, 500, 380,
			NULL, NULL, inst, NULL);
}

LRESULT MainWindowProc(HWND window, UINT mess, WPARAM wparam, LPARAM lparam)
{
	switch (mess)
	{
		case WM_CREATE:
		{
			InitHost();
		} break;		
		case WM_CLOSE:
		{
			PostQuitMessage(WM_QUIT);
		} break;
		case WM_DESTROY:
			break;

		default:
			break;
	}

	return DefWindowProcA(window,mess,wparam,lparam);
}



