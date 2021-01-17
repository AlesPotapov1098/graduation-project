#pragma once

#include <afxwin.h>

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

			LPCTSTR m_WindowName = L"Graduation Project";
		};
	}
}
