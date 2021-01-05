#pragma once

#include <Windows.h>
#include <d2d1.h>

#include "Proportions.h"

namespace gp {
	namespace app {

		class ApplicationWindow
		{
		public:

			ApplicationWindow() = default;
			ApplicationWindow(HINSTANCE hInst, LPCSTR windowName, LPCSTR className);
			~ApplicationWindow();

			LRESULT WindowFunction(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

			bool Init();
			bool InitDirectX();
			INT Create();
			void Run();

		private:
			static LRESULT WindowFunctionSetup(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
			static LRESULT WindowFunctionThunk(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

		private:
			void OnSize();
			void OnPaint();

		private:
			HWND m_hWnd;
			HINSTANCE m_Instance;

			ID2D1Factory* m_d2d1Factory{};
			ID2D1HwndRenderTarget* m_d2d1RenderTarget{};

			LPCSTR m_WindowName;
			LPCSTR m_ClassName;

			PAINTSTRUCT m_PaintStruct;

			prop::WindowProportion m_WindowProportions;
		};
	}
}
