#include <windows.h>

int WINAPI WinMain(
		HINSTANCE hInstance,
		HINSTANCE hPrevInstance,
		LPSTR     lpCmdLine,
		int       nShowCmd) 
{
	MessageBoxA(nullptr,"Message Box","Message",0);
	return 0;
}