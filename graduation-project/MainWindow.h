#pragma once

#include "IGUIObject.h"
#include "ColorScheme.h"

namespace gui {
	class MainWindow : public IGUIObject
	{
	public:
		MainWindow() = default;
		MainWindow(__int32 width, __int32 heigth, __int32 x, __int32 y, LPCSTR ClassName, LPCSTR WindowName, HINSTANCE hInst);
		~MainWindow();

		bool Build() override;
		void Run();

	private:
		WNDCLASSEXA m_WindowClass;
		MSG m_MessageStruct;
		HBRUSH m_ForeBrush;
		HINSTANCE m_hInstance;
	};
}

