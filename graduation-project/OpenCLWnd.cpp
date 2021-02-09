#include "OpenCLWnd.h"

namespace gp
{
	namespace app
	{
		
		IMPLEMENT_DYNCREATE(OpenCLWnd, CMDIChildWnd)

		BEGIN_MESSAGE_MAP(OpenCLWnd, CMDIChildWnd)

		END_MESSAGE_MAP()

		OpenCLWnd::OpenCLWnd() noexcept
		{
		}

		OpenCLWnd::~OpenCLWnd()
		{
		}

		BOOL OpenCLWnd::PreCreateWindow(CREATESTRUCT& cs)
		{
			cs.lpszName = m_MDIWindowName;

			m_WindowProportion.SetParent(cs.hwndParent);
			m_WindowProportion.CalculateWindowProportion();

			cs.cx = m_WindowProportion.GetWidth();
			cs.cy = m_WindowProportion.GetHeight();

			cs.style &= ~FWS_ADDTOTITLE;

			if (!CMDIChildWnd::PreCreateWindow(cs)) {
				return FALSE;
			}

			return TRUE;
		}
	}
}