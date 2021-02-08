#include "GraduationProjectMainWindow.h"

namespace gp {

	namespace app {

		BEGIN_MESSAGE_MAP(GraduationProjectMainWindow, CMDIFrameWnd)
			ON_WM_CREATE()
			ON_WM_PAINT()
			ON_BN_CLICKED(ID_CREATE_NEW_CHILD_WINDOW_BUTTON,click)
		END_MESSAGE_MAP()


		GraduationProjectMainWindow::GraduationProjectMainWindow()
		{
			m_MainWindowPropportions.CalculateWindowProportion();
		}

		GraduationProjectMainWindow::~GraduationProjectMainWindow()
		{

		}

		BOOL GraduationProjectMainWindow::PreCreateWindow(CREATESTRUCT& cs)
		{
			cs.lpszName = m_WindowName;
			if (!CMDIFrameWnd::PreCreateWindow(cs))
				return FALSE;

			return TRUE;
		}

		void GraduationProjectMainWindow::click()
		{
			CreateNewChild(RUNTIME_CLASS(CMDIChildWnd), 0);
		}

		int GraduationProjectMainWindow::OnCreate(LPCREATESTRUCT lpCreateStruct)
		{
			if (CMDIFrameWnd::OnCreate(lpCreateStruct) == FAIL)
				return FAIL;

			//if (!m_wndToolBar.Create(this, WS_CHILD | WS_VISIBLE | CBRS_SIZE_FIXED | CBRS_TOP | CBRS_TOOLTIPS)
			//	|| !m_wndToolBar.LoadToolBar(IDR_TOOLBAR1))
			//{
			//	return FAIL;
			//}

			return 0;
		}

	}
}
