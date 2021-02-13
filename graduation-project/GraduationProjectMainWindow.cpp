#include "GraduationProjectMainWindow.h"



namespace gp {

	namespace app {

		IMPLEMENT_DYNCREATE(GraduationProjectMainWindow, CMDIFrameWnd)

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

		GraduationProjectMainWindow::GraduationProjectMainWindow() noexcept
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

		bool GraduationProjectMainWindow::InitStatusBar()
		{
			if (!m_wndStatusBar.Create(this))
			{
				return false;
			}

			m_wndStatusBar.SetIndicators(indicators, sizeof(indicators) / sizeof(UINT));

			return true;
		}

		bool GraduationProjectMainWindow::InitToolBar()
		{
			if (!m_wndToolBar.Create(this) || !m_wndToolBar.LoadToolBar(IDR_TOOLBAR256))
				return false;

			EnableDocking(CBRS_ALIGN_ANY);
			m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);

			return true;
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

			if (!InitStatusBar())
				return FAIL;
			
			if (!InitToolBar())
				return FAIL;

			if (!m_OpenCLConncetion.Init())
				return FAIL;
			
			return 0;
		}

		void GraduationProjectMainWindow::CreateMDIChild()
		{
			CreateNewChild(RUNTIME_CLASS(OpenCLWnd), IDR_MAINFRAME);
		}
	}
}
