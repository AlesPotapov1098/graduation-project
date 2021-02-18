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

			/// <summary>
			/// Объект MFC для строки состояния
			/// </summary>
			CStatusBar m_wndStatusBar;

			/// <summary>
			/// Объект класса OpenCLConnection для инициализации OpenCL
			/// </summary>
			gpgpu::OpenCLConnection m_OpenCLConncetion;

		private:

			bool InitStatusBar();
			bool InitToolBar();

		public:

			/// <summary>
			/// Конструктор = вызов Create
			/// </summary>
			HologramMainWnd() noexcept;

			/// <summary>
			/// Деструктор = закрытие всех открытых MDI-child окон
			/// </summary>
			~HologramMainWnd();

			/// <summary>
			/// Создание нового дочернего MDI окна
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
