#pragma once

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // ��������� ����� ������������ ���������� �� ���������� Windows
#endif

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // ��������� ������������ CString ����� ������

// ��������� ������� ������� ��������� ����� � ����� ������������ �������������� MFC
#define _AFX_ALL_WARNINGS

#include <afxwin.h>         // �������� � ����������� ���������� MFC
#include <afxext.h>         // ���������� MFC


#include <afxdisp.h>        // ������ ������������� MFC



#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // ��������� MFC ��� ������� ��������� ���������� Internet Explorer 4
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>             // ��������� MFC ��� ������� ��������� ���������� Windows
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <afxcontrolbars.h>     // ��������� MFC ��� ���� � ������� ����������

#include "Proportions.h"

namespace gp {
	namespace app {
		class OpenCLWnd : public CMDIChildWnd
		{
			DECLARE_DYNCREATE(OpenCLWnd)
		private:
			MDIChildWindowProportion m_WindowProportion;

			LPCWSTR m_MDIWindowName = L"MDIChildWnd";

		public:
			OpenCLWnd() noexcept;
			~OpenCLWnd();

			afx_msg BOOL PreCreateWindow(CREATESTRUCT& cs);

			DECLARE_MESSAGE_MAP()
		};
	}
}
