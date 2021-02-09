#include "OpenCLWnd.h"

namespace gp
{
	namespace app
	{
		
		IMPLEMENT_DYNCREATE(OpenCLWnd, CMDIChildWnd)

		OpenCLWnd::OpenCLWnd() noexcept
		{

		}

		OpenCLWnd::~OpenCLWnd()
		{
		}

		BOOL OpenCLWnd::PreCreateWindow(CREATESTRUCT& cs)
		{
			cs.lpszName = L"MDIChildWindow";

			cs.x = 10;
			cs.y = 10;

			cs.style &= ~FWS_ADDTOTITLE;

			if (!CMDIChildWnd::PreCreateWindow(cs)) {
				return FALSE;
			}

			return TRUE;
		}
	}
}