

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // ��������� ����� ������������ ���������� �� ���������� Windows
#endif

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // ��������� ������������ CString ����� ������

// ��������� ������� ������� ��������� ����� � ����� ������������ �������������� MFC
#define _AFX_ALL_WARNINGS

#include <afxwin.h>
#include <afxext.h>

#include <afxdtctl.h>
#include <afxcmn.h>

#include <afxcontrolbars.h>

#include "Proportions.h"
#include "CDialogCreateOpenCLWnd.h"
#include "OpenCLExec.h"

#define FAIL	-1

namespace gp {
	namespace app {
		class OpenCLWnd : public CMDIChildWnd
		{
			DECLARE_DYNCREATE(OpenCLWnd)
		private:
			MDIChildWindowProportion m_WindowProportion;

			LPCWSTR m_MDIWindowName = L"MDIChildWnd";

			gpgpu::host::OpenCLHost m_Host;

		public:
			OpenCLWnd() noexcept;
			~OpenCLWnd();

			afx_msg BOOL PreCreateWindow(CREATESTRUCT& cs);
			afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);

			DECLARE_MESSAGE_MAP()
		};
	}
}
