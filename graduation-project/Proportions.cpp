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

			m_Width = m_Height = m_PosY = m_PoxX = 0;
		}

		WindowProportion::WindowProportion(HWND parent)
		{
			m_Parent = parent;
			HDC ParentDC = GetWindowDC(m_Parent);

			m_ParentWndWidth = GetDeviceCaps(ParentDC, HORZRES);
			m_ParentWndHeight = GetDeviceCaps(ParentDC, VERTRES);
			m_ParentWndPosX = 0;
			m_ParentWndPosY = 0;

			m_Width = m_Height = m_PosY = m_PoxX = 0;
		}

		WindowProportion::~WindowProportion()
		{
		}

		int WindowProportion::GetWidth() const
		{
			return 0;
		}

		int WindowProportion::GetHeight() const
		{
			return 0;
		}

		int WindowProportion::GetX() const
		{
			return 0;
		}

		int WindowProportion::GetY() const
		{
			return 0;
		}

		void MainWindowAppPropportion::CalculateWindowProportion()
		{
		}

		void MDIClientRectWindowProportion::CalculateWindowProportion()
		{
		}

	}
}