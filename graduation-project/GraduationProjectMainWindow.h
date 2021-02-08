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

		protected:

			HMENU m_WndMenu;
			HACCEL m_WndAccel;

		/// <summary>
		/// Поля класс для MFC
		/// </summary>
		private:

			/// <summary>
			/// Имя главного окна
			/// </summary>
			LPCTSTR m_WindowName = L"Graduation Project";

			LPCTSTR m_MDIClientClass = L"MDICLIENT";

			/// <summary>
			/// Объект для управления позицией, шириной и высотой главного окна приложения
			/// </summary>
			MainWindowAppPropportion m_MainWindowPropportions;

			/// <summary>
			/// Объект для управления позицией, шириной и высотой окна MDICLIENT
			/// </summary>
			MDIClientRectWindowProportion m_MDIClientProportion;

			CButton button1;

			
		public:
			//DECLARE_DYNAMIC(CMainFrame)
			/// <summary>
			/// Конструктор = вызов Create
			/// </summary>
			GraduationProjectMainWindow();

			GraduationProjectMainWindow(HINSTANCE instance);

			/// <summary>
			/// Деструктор = закрытие всех открытых MDI-child окон
			/// </summary>
			~GraduationProjectMainWindow();

			virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

			afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);

			void CreateMDIChild();

			DECLARE_MESSAGE_MAP()
		};
	}
}
