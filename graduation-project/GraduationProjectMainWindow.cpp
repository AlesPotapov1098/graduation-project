#include "GraduationProjectMainWindow.h"

namespace gp {

	namespace app {

		BEGIN_MESSAGE_MAP(GraduationProjectMainWindow, CMDIFrameWnd)
			ON_WM_CREATE()
			ON_WM_PAINT()
			ON_BN_CLICKED(ID_CREATE_NEW_CHILD_WINDOW_BUTTON,click)
			ON_COMMAND(ID_MENU_CREATE_NEW_OPENCL_WINDOW, &GraduationProjectMainWindow::CreateMDIChild)
		END_MESSAGE_MAP()


		GraduationProjectMainWindow::GraduationProjectMainWindow()
		{
			m_MainWindowPropportions.CalculateWindowProportion();
		}

		GraduationProjectMainWindow::GraduationProjectMainWindow(HINSTANCE instance)
		{
		}

		GraduationProjectMainWindow::~GraduationProjectMainWindow()
		{

		}

		BOOL GraduationProjectMainWindow::PreCreateWindow(CREATESTRUCT& cs)
		{
			// Изменение парметров главного окна (фрейма)
			cs.lpszName = m_WindowName;
			cs.x = m_MainWindowPropportions.GetX();
			cs.y = m_MainWindowPropportions.GetY();
			cs.cx = m_MainWindowPropportions.GetWidth();
			cs.cy = m_MainWindowPropportions.GetHeight();
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

		void GraduationProjectMainWindow::CreateMDIChild()
		{
			HINSTANCE instd = AfxGetResourceHandle();

			HMENU menu = ::LoadMenu(instd, MAKEINTRESOURCE(IDR_MAINFRAME));

			CreateNewChild(RUNTIME_CLASS(OpenCLWnd), IDR_MAINFRAME, menu);

		}
	}
}
