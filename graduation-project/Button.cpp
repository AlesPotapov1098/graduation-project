#include "Button.h"

namespace gui {
    namespace ctrl {
        Button::Button(HWND parent, LPCSTR text, __int32 id,__int32 width, __int32 heigth, __int32 x, __int32 y, LPCSTR ClassName, LPCSTR ControlName)
            : Control(parent,text,id,width,heigth,x,y,ClassName,ControlName)
        {
        }

        Button::~Button()
        {
        }

        bool Button::Build()
        {
            m_hwnd = CreateWindowA(
                m_ClassObjectName,
                m_ObjectName,
                WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                m_XPos,m_YPos,
                m_Width,m_Heigth,
                m_ParentHandle,
                reinterpret_cast<HMENU>(m_ControlID),
                nullptr,
                nullptr);

            if (!m_hwnd)
                return false;

            m_ControlTextFont = CreateFontA(
                18, 0, 0, 0, FW_REGULAR, 0, 0, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, DEFAULT_PITCH, "Roboto");
            
            if (!m_ControlTextFont)
                return false;

            SendMessageA(m_hwnd, WM_SETFONT, reinterpret_cast<WPARAM>(m_ControlTextFont), 0);
            SendMessageA(m_hwnd, WM_SETTEXT, reinterpret_cast<WPARAM>("Button"), 0);

            return m_hwnd;
        }

        void Button::OnClick()
        {
            MessageBoxA(nullptr, "TestButton Click!!!", "Event", MB_ICONINFORMATION | MB_OK);
        }
    }
}