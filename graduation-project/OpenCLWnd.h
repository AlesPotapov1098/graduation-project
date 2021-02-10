

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // Исключите редко используемые компоненты из заголовков Windows
#endif

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // некоторые конструкторы CString будут явными

// отключает функцию скрытия некоторых общих и часто пропускаемых предупреждений MFC
#define _AFX_ALL_WARNINGS

#include <afxwin.h>
#include <afxext.h>

#include <afxdtctl.h>
#include <afxcmn.h>

#include <afxcontrolbars.h>

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
