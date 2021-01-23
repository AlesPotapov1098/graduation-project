#pragma once

#include <afxwin.h>

#include "Proportions.h"

namespace gp
{
	namespace app
	{
		class GraduationProjectMainWindow : public CMDIFrameWnd
		{
		public:

			/// <summary>
			/// Конструктор = вызов Create
			/// </summary>
			GraduationProjectMainWindow();

			/// <summary>
			/// Деструктор = закрытие всех открытых MDI-child окон
			/// </summary>
			~GraduationProjectMainWindow();

			/// <summary>
			/// Переопределение функции, вызываемой перед функцией CreateClient
			/// </summary>
			afx_msg BOOL OnCreateClient(
				LPCREATESTRUCT lpcs,
				CCreateContext* pContext);

			/// <summary>
			/// Преопределение функции создания дочернего окна класса MDICLIENT
			/// </summary>
			afx_msg BOOL CreateClient(
				LPCREATESTRUCT lpCreateStruct,
				CMenu* pWindowMenu);

			DECLARE_MESSAGE_MAP()

		private:

			/// <summary>
			/// Имя главного окна
			/// </summary>
			LPCTSTR m_WindowName = L"Graduation Project";

		private:

			/// <summary>
			/// Объект для управления позицией, шириной и высотой главного окна приложения
			/// </summary>
			MainWindowAppPropportion m_MainWindowPropportions;

			/// <summary>
			/// Объект для управления позицией, шириной и высотой окна MDICLIENT
			/// </summary>
			MDIClientRectWindowProportion m_MDIClientProportion;
		};
	}
}
