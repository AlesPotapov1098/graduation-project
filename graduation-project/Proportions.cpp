#include "Proportions.h"

namespace gp
{
	namespace app
	{
		WindowProportion::WindowProportion()
		{
			m_Parent = GetDesktopWindow();
			HDC ScreenMonitor = GetWindowDC(m_Parent);
			m_ParentWndWidth = GetDeviceCaps(ScreenMonitor, HORZRES);
			m_ParentWndHeight = GetDeviceCaps(ScreenMonitor, VERTRES);
			m_ParentWndPosX = 0;
			m_ParentWndPosY = 0;

			m_Width = m_Height = m_PosY = m_PosX = 0;
		}

		WindowProportion::WindowProportion(HWND parent)
		{
			SetParent(parent);
		}

		WindowProportion::~WindowProportion()
		{
			m_Parent = 0;

			m_ParentWndHeight = m_ParentWndWidth = 0;
			m_ParentWndPosX = m_ParentWndPosY = 0;

			m_Width = m_Height = 0;
			m_PosX = m_PosY = 0;
		}

		void WindowProportion::SetParent(HWND parent)
		{
			m_Parent = parent;

			RECT rect;
			GetClientRect(m_Parent, &rect);
			m_ParentWindowRect = rect;

			m_ParentWndWidth = m_ParentWindowRect.Width();
			m_ParentWndHeight = m_ParentWindowRect.Height();
			m_ParentWndPosX = m_ParentWindowRect.top;
			m_ParentWndPosY = m_ParentWindowRect.left;

			m_Width = m_Height = m_PosY = m_PosX = 0;
		}

		int WindowProportion::GetWidth() const
		{
			return m_Width;
		}

		int WindowProportion::GetHeight() const
		{
			return m_Height;
		}

		int WindowProportion::GetX() const
		{
			return m_PosX;
		}

		int WindowProportion::GetY() const
		{
			return m_PosY;
		}

		CRect WindowProportion::GetWindowRect() const
		{
			return m_WindowRect;
		}

		void MainWindowAppPropportion::CalculateWindowProportion()
		{
			m_Width = m_ParentWndWidth * 8 / 10;
			m_Height = m_ParentWndHeight * 9 / 10;

			m_PosX = (m_ParentWndWidth - m_Width) / 2;
			m_PosY = (m_ParentWndHeight - m_Height) / 2;

			m_WindowRect.SetRect(m_PosX, m_PosY, m_Width, m_Height);
		}

		void MDIClientRectWindowProportion::CalculateWindowProportion()
		{
			m_Width = m_ParentWndWidth * 7 / 10;
			m_Height = m_ParentWndHeight - 10;

			int dy = m_ParentWndHeight - m_Height;;

			m_PosX = (m_ParentWndWidth - m_Width) - dy / 2;
			m_PosY = dy / 2;
		}

	}
}