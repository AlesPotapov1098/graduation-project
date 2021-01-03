#pragma once

#include <Windows.h>

#include "Proportions.h"

namespace gp {
	namespace app {

		class ApplicationWindow
		{
		public:

			ApplicationWindow() = default;
			ApplicationWindow(HINSTANCE hInst, LPCSTR windowName, LPCSTR className);
			~ApplicationWindow();

			LRESULT CALLBACK WindowFunction(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

			static LRESULT CALLBACK WindowFunctionSetup(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

			bool Init();
			INT Create();
			void Run();

		private:
			void OnSize();
			void OnPaint();

		private:
			HWND m_hWnd;
			HINSTANCE m_Instance;

			LPCSTR m_WindowName;
			LPCSTR m_ClassName;

			prop::WindowProportion m_WindowProportions;
		};
	}
}
