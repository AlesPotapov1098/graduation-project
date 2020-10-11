#include "IGUIObject.h"

namespace gui {

	IGUIObject::IGUIObject(__int32 width, __int32 heigth, __int32 x, __int32 y, LPCSTR ClassName, LPCSTR ObjectName)
		: m_Width(width), m_Heigth(heigth), m_XPos(x), m_YPos(y), m_ClassObjectName(ClassName), m_ObjectName(ObjectName)
	{
		m_hwnd = nullptr;
	}

	IGUIObject::~IGUIObject()
	{
	}

	HWND IGUIObject::GetHWND() const
	{
		return m_hwnd;
	}

	__int32 IGUIObject::GetPosX() const
	{
		return m_XPos;
	}

	__int32 IGUIObject::GetPosY() const
	{
		return m_YPos;
	}

	__int32 IGUIObject::GetWidth() const
	{
		return m_Width;
	}

	__int32 IGUIObject::GetHeigth() const
	{
		return m_Heigth;
	}

	LPCSTR IGUIObject::GetClassObjectName() const
	{
		return m_ClassObjectName;
	}

	LPCSTR IGUIObject::GetName() const
	{
		return m_ObjectName;
	}

}
