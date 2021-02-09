#include "GraduationProjectMainWindow.h"

namespace gp {

	namespace app {

		BEGIN_MESSAGE_MAP(GraduationProjectMainWindow, CMDIFrameWnd)
			ON_WM_CREATE()
			ON_WM_PAINT()
		END_MESSAGE_MAP()

		static UINT indicators[] =
		{
			ID_SEPARATOR,           // индикатор строки состояния
			ID_INDICATOR_CAPS,
			ID_INDICATOR_NUM,
			ID_INDICATOR_SCRL,
		};

		GraduationProjectMainWindow::GraduationProjectMainWindow() 
		{
			m_MainWindowPropportions.CalculateWindowProportion();
			m_WndMenu = nullptr;
			m_WndAccel = nullptr;
		}

		GraduationProjectMainWindow::~GraduationProjectMainWindow()
		{
			if (m_WndMenu != nullptr)
				FreeResource(m_WndMenu);
			if (m_WndAccel != nullptr)
				FreeResource(m_WndAccel);
		}

		BOOL GraduationProjectMainWindow::PreCreateWindow(CREATESTRUCT& cs)
		{
			// Изменение парметров главного окна (фрейма)
			cs.lpszName = m_WindowName;
			cs.x = m_MainWindowPropportions.GetX();
			cs.y = m_MainWindowPropportions.GetY();
			cs.cx = m_MainWindowPropportions.GetWidth();
			cs.cy = m_MainWindowPropportions.GetHeight();
			cs.style &= ~FWS_ADDTOTITLE;
			if (!CMDIFrameWnd::PreCreateWindow(cs))
				return FALSE;

			HINSTANCE hInst = AfxGetResourceHandle();

			m_hMenu = ::LoadMenu(hInst, MAKEINTRESOURCE(IDR_MAINFRAME));

			return TRUE;
		}

		int GraduationProjectMainWindow::OnCreate(LPCREATESTRUCT lpCreateStruct)
		{
			if (CMDIFrameWnd::OnCreate(lpCreateStruct) == FAIL)
				return FAIL;

			if (!m_wndStatusBar.Create(this))
			{
				return FAIL;
			}

			m_wndStatusBar.SetIndicators(indicators, sizeof(indicators) / sizeof(UINT));
			//if (!m_wndToolBar.Create(this, WS_CHILD | WS_VISIBLE | CBRS_SIZE_FIXED | CBRS_TOP | CBRS_TOOLTIPS)
			//	|| !m_wndToolBar.LoadToolBar(IDR_TOOLBAR1))
			//{
			//	return FAIL;
			//}

			return 0;
		}

		void GraduationProjectMainWindow::CreateMDIChild()
		{
			CreateNewChild(RUNTIME_CLASS(OpenCLWnd), IDR_MAINFRAME);
		}
	}
}
