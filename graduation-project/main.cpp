//#pragma comment(lib,"user32.lib")
#include <CL/cl.h>
#include <iostream>
#include <Windows.h>
#include <windowsx.h>

#include "cl_platform.h"

int WINAPI WinMain(
					HINSTANCE hInstance,
					HINSTANCE hPrevInstance,
					LPSTR cmdLine,
					int count) {

	MessageBoxA(nullptr,"Message","Hello World!!!",0);

	return 0;
}