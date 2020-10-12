#include "Button.h"

namespace gui {
    namespace ctrl {
        Button::Button(HWND parent, LPCSTR text, __int32 width, __int32 heigth, __int32 x, __int32 y, LPCSTR ClassName, LPCSTR ControlName)
            : Control(parent,text,width,heigth,x,y,ClassName,ControlName)
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
                nullptr,
                nullptr,
                nullptr);

            return m_hwnd;
        }
    }
}