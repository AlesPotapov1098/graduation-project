#include "GraduationProjectMainWindow.h"

namespace gp {

	namespace app {

		BEGIN_MESSAGE_MAP(GraduationProjectMainWindow, CMDIFrameWnd)
		
		END_MESSAGE_MAP()


		GraduationProjectMainWindow::GraduationProjectMainWindow()
		{
			Create(NULL, m_WindowName, WS_OVERLAPPEDWINDOW, { 500,500,1000,1000 });
		}

		GraduationProjectMainWindow::~GraduationProjectMainWindow()
		{

		}

		BOOL GraduationProjectMainWindow::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
		{
			return CreateClient(lpcs, nullptr);
		}

		BOOL GraduationProjectMainWindow::CreateClient(LPCREATESTRUCT lpCreateStruct, CMenu* pWindowMenu)
		{
			ASSERT(m_hWnd != nullptr);
			ASSERT(m_hWndMDIClient == nullptr);

			DWORD dwStyle = WS_BORDER | WS_CHILD | WS_VISIBLE | WS_CLIPCHILDREN;

			CLIENTCREATESTRUCT ccs;

			ccs.hWindowMenu = nullptr;
			ccs.idFirstChild = 0;

			m_hWndMDIClient = CreateWindowEx(
				0,
				L"MDICLIENT",
				nullptr,
				dwStyle,
				100,
				100,
				200,
				200,
				m_hWnd,
				nullptr,
				AfxGetInstanceHandle(),
				(LPVOID)&ccs);

			if (m_hWndMDIClient == NULL)
			{
				TRACE(traceAppMsg, 0, _T("Warning: CMDIFrameWnd::OnCreateClient: failed to create MDICLIENT.")
					_T(" GetLastError returns 0x%8.8X\n"), ::GetLastError());
				return FALSE;
			}

			::BringWindowToTop(m_hWndMDIClient);

			return TRUE;
		}


	}
}
