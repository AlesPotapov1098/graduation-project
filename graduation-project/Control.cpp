#include "Control.h"

namespace gui {
	namespace ctrl {
		Control::Control(HWND parent, LPCSTR text, __int32 id, __int32 width, __int32 heigth, __int32 x, __int32 y, LPCSTR ClassName, LPCSTR ControlName)
			: IGUIObject(width, heigth, x, y, ClassName, ControlName)
		{
			m_ParentHandle = parent;
			m_ControlText = text;
			m_ControlID = id;

			m_BackColor = color::WHITE;
			m_ForeColor = color::BLACK;
			m_ControlTextFont = nullptr;
		}

		Control::~Control()
		{
		}

		LPCSTR Control::GetText() const
		{
			return m_ControlText;
		}

		COLORREF Control::GetBackColor() const
		{
			return m_BackColor;
		}

		COLORREF Control::GetForeColor() const
		{
			return m_ForeColor;
		}

		HWND Control::GetParentHWND() const
		{
			return m_ParentHandle;
		}

		__int32 Control::GetControlID() const
		{
			return m_ControlID;
		}
	}
}