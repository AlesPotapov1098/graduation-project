#pragma once
#include <Windows.h>

#include "IGUIObject.h"
#include "ColorScheme.h"

namespace gui {
	namespace ctrl {
		class Control : public IGUIObject
		{
		public:

			Control() = default;
			Control(HWND parent, LPCSTR text, __int32 id, __int32 width, __int32 heigth, __int32 x, __int32 y, LPCSTR ClassName, LPCSTR ControlName);
			virtual ~Control();

			virtual void OnPaint() = 0;

			LPCSTR GetText() const;
			COLORREF GetBackColor() const;
			COLORREF GetForeColor() const;
			HWND GetParentHWND() const;
			__int32 GetControlID() const;

		protected:
			HWND m_ParentHandle;
			HFONT m_ControlTextFont;
			COLORREF m_BackColor;
			COLORREF m_ForeColor;
			LPCSTR m_ControlText;
			__int32 m_ControlID;
		};
	}
}