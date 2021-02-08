#pragma once

#include <afxwin.h>
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

		protected:

			CMFCToolBar m_wndToolBar;

		private:
			void click();

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

			CButton button1;
			
		public:

			/// <summary>
			/// ����������� = ����� Create
			/// </summary>
			GraduationProjectMainWindow();

			/// <summary>
			/// ���������� = �������� ���� �������� MDI-child ����
			/// </summary>
			~GraduationProjectMainWindow();

			virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

			afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);

			DECLARE_MESSAGE_MAP()
		};
	}
}
