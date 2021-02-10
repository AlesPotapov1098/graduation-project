#pragma once

#include <afxwin.h>
#include <afxext.h>
#include <afxcontrolbars.h>

#include "resource.h"

#include "Proportions.h"
#include "OpenCLWnd.h"

#define ID_CREATE_NEW_CHILD_WINDOW_BUTTON	100
#define FAIL	-1

namespace gp
{
	namespace app
	{
		class GraduationProjectMainWindow : public CMDIFrameWnd
		{
			DECLARE_DYNCREATE(GraduationProjectMainWindow)
		protected:

			CToolBar m_wndToolBar;
			HMENU m_WndMenu;
			HACCEL m_WndAccel;

		/// <summary>
		/// ���� ����� ��� MFC
		/// </summary>
		private:

			/// <summary>
			/// ��� �������� ����
			/// </summary>
			LPCTSTR m_WindowName = L"Graduation Project";

			LPCTSTR m_MDIClientClass = L"MDICLIENT";

			/// <summary>
			/// ������ ��� ���������� ��������, ������� � ������� �������� ���� ����������
			/// </summary>
			MainWindowAppPropportion m_MainWindowPropportions;

			/// <summary>
			/// ������ ��� ���������� ��������, ������� � ������� ���� MDICLIENT
			/// </summary>
			MDIClientRectWindowProportion m_MDIClientProportion;

			CStatusBar m_wndStatusBar;

		private:

			bool InitStatusBar();
			bool InitToolBar();

		public:

			/// <summary>
			/// ����������� = ����� Create
			/// </summary>
			GraduationProjectMainWindow() noexcept;

			/// <summary>
			/// ���������� = �������� ���� �������� MDI-child ����
			/// </summary>
			~GraduationProjectMainWindow();

			/// <summary>
			/// �������� ������ ��������� MDI ����
			/// </summary>
			void CreateMDIChild();
		
		public:

			virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
			afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);

			DECLARE_MESSAGE_MAP()
		};
	}
}
