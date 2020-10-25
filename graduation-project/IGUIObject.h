#pragma once
#include <Windows.h>

namespace gui {

	class IGUIObject
	{
	public:
		IGUIObject() = default;
	
		IGUIObject(__int32 width, __int32 heigth, __int32 x, __int32 y, LPCSTR ClassName = "ObjectClassName", LPCSTR ObjectName = "ObjectName");
		
		virtual ~IGUIObject();

		HWND GetHWND() const;

		__int32 GetPosX() const;
		__int32 GetPosY() const;

		__int32 GetWidth() const;
		__int32 GetHeigth() const;

		LPCSTR GetClassObjectName() const;
		LPCSTR GetName() const;

		virtual bool Build() = 0;

	protected:
		HWND m_hwnd;
		__int32 m_Width;
		__int32 m_Heigth;
		__int32 m_XPos;
		__int32 m_YPos;
		LPCSTR m_ClassObjectName;
		LPCSTR m_ObjectName;

	};
}
