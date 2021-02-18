#pragma once

#include <afxwin.h>
#include <afxext.h>
#include <afxcontrolbars.h>

#include "resource.h"

#include "Proportions.h"
#include "OpenCLWnd.h"
#include "OpenCLConnection.h"

#define ID_CREATE_NEW_CHILD_WINDOW_BUTTON	100
#define FAIL	-1

namespace gp
{
	namespace app
	{
		class HologramMainWnd : public CMDIFrameWnd
		{
			DECLARE_DYNCREATE(HologramMainWnd)
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

			/// <summary>
			/// ������ MFC ��� ������ ���������
			/// </summary>
			CStatusBar m_wndStatusBar;

			/// <summary>
			/// ������ ������ OpenCLConnection ��� ������������� OpenCL
			/// </summary>
			gpgpu::OpenCLConnection m_OpenCLConncetion;

		private:

			bool InitStatusBar();
			bool InitToolBar();

		public:

			/// <summary>
			/// ����������� = ����� Create
			/// </summary>
			HologramMainWnd() noexcept;

			/// <summary>
			/// ���������� = �������� ���� �������� MDI-child ����
			/// </summary>
			~HologramMainWnd();

			/// <summary>
			/// �������� ������ ��������� MDI ����
			/// </summary>
			void CreateMDIChild();
		
			gpgpu::OpenCLConnection GetConnection() const;

		public:

			virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
			afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);

			DECLARE_MESSAGE_MAP()
		};
	}
}
