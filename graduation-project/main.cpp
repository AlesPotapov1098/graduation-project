#include <iostream>
#include <Windows.h>

#include "cl_platform.h"

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

struct PainUIObject
{
	HDC			hDevContext;
	HBITMAP		hBitMap;
	BITMAPINFO	hBitmapInfo;
	LPVOID		pPixels;
};

LRESULT MainWindowProc(HWND window, UINT mess, WPARAM wparam, LPARAM lparam);

BOOL OnInit(HINSTANCE instance, LPCSTR classname);
HWND OnCreate(HINSTANCE inst,LPCSTR wndname, LPCSTR classname);

void OnInitPlatformUnit()
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

int main(int argc, char ** argv) 
{
	cl_uint count = 0;
	cl_uint ErrorCode = clGetPlatformIDs(0, nullptr, &count);
	if (ErrorCode) {
		return ErrorCode;
	}

	if (count == 0) {
		return -2;
	}

	cl_platform_id * platforms = new cl_platform_id[count];
	ErrorCode = clGetPlatformIDs(count, platforms, nullptr);
	if (ErrorCode){
		return ErrorCode;
	}

	

	delete[] platforms;
	
	return 0;
}

BOOL OnInit(HINSTANCE instance,LPCSTR classname)
{
	WNDCLASSEXA WindowClass;
	std::memset(&WindowClass,0,sizeof(WNDCLASSEXA));
	WindowClass.cbSize = sizeof(WNDCLASSEXA);
	WindowClass.style = CS_HREDRAW | CS_VREDRAW;
	WindowClass.hInstance = instance;
	WindowClass.lpfnWndProc = &MainWindowProc;
	WindowClass.lpszClassName = classname;
	WindowClass.hbrBackground = CreateSolidBrush(COLOR_WINDOW);

	return RegisterClassExA(&WindowClass);
}

HWND OnCreate(HINSTANCE inst, LPCSTR wndname, LPCSTR classname)
{
	return  CreateWindowExA(
			0,
			classname, 
			wndname,
			WS_OVERLAPPEDWINDOW,
			500, 300, 500, 380,
			NULL, NULL, inst, NULL);
}

LRESULT MainWindowProc(HWND window, UINT mess, WPARAM wparam, LPARAM lparam)
{
	switch (mess)
	{
		case WM_CREATE:
		{
			OnInitPlatformUnit();
		} break;	

		case WM_SIZE:
		{

		} break;

		case WM_PAINT:
		{

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



