#pragma once
#include <Windows.h>

namespace gui {
	class IGUIObject
	{
	public:
		IGUIObject() = default;
#ifdef E_UNICODE
		IGUIObject(__int32 width, __int32 heigth, __int32 x, __int32 y, LPWSTR ClassName = L"ObjectClassName", LPWSTR ObjectName = L"ObjectName");
#else
		IGUIObject(__int32 width, __int32 heigth, __int32 x, __int32 y, LPCSTR ClassName = "ObjectClassName", LPCSTR ObjectName = "ObjectName") {}
#endif // ! E_UNICODE
		~IGUIObject()
		{
			CloseWindow(m_hwnd);
		}

	private:
		HWND m_hwnd;
		__int32 m_Width;
		__int32 m_Heigth;
		__int32 m_XPos;
		__int32 m_YPos;
#ifdef E_UNICODE
		LPWSTR m_ClassObjectName;
		LPWSTR m_ObjectName;
#else
		LPCSTR m_ClassObjectName;
		LPCSTR m_ObjectName;
#endif // ! E_UNICODE

	};
}
