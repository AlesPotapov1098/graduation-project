#include "OpenCLWnd.h"

namespace gp
{
	namespace app
	{
		
		IMPLEMENT_DYNCREATE(OpenCLWnd, CMDIChildWnd)

		BEGIN_MESSAGE_MAP(OpenCLWnd, CMDIChildWnd)
			ON_WM_CREATE()
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

		int OpenCLWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
		{
			dlg::CDialogCreateOpenCLWnd dialog;
			auto nRes = dialog.DoModal();

			switch (nRes)
			{
				case FAIL:
				case IDCANCEL:
					return FAIL;

				case IDOK:
					m_Host = dialog.GetOpenCLHost();
					break;

				default:
					break;
			}

			gpgpu::exec::OpenCLExec exec(m_Host);

			exec.Init();

			if (!exec.LoadSourceCode(L"first.cl"))
				return FAIL;

			exec.Build();

			return CMDIChildWnd::OnCreate(lpCreateStruct);
		}
	}
}