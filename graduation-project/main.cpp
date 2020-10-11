#pragma once
#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

#include <iostream>
#include <Windows.h>
#include "MainWindow.h"

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR cmd, int count)
{
	gui::MainWindow test(600, 600, 100, 100, "MainWindowClass", "MainWindow", hInstance);
	if (!test.Build())
	{
		return -1;
	}

	test.Run();
	return 0;
}









