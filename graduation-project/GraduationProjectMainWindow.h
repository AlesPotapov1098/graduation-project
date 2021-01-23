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
			/// ����������� = ����� Create
			/// </summary>
			GraduationProjectMainWindow();

			/// <summary>
			/// ���������� = �������� ���� �������� MDI-child ����
			/// </summary>
			~GraduationProjectMainWindow();

			/// <summary>
			/// ��������������� �������, ���������� ����� �������� CreateClient
			/// </summary>
			afx_msg BOOL OnCreateClient(
				LPCREATESTRUCT lpcs,
				CCreateContext* pContext);

			/// <summary>
			/// �������������� ������� �������� ��������� ���� ������ MDICLIENT
			/// </summary>
			afx_msg BOOL CreateClient(
				LPCREATESTRUCT lpCreateStruct,
				CMenu* pWindowMenu);

			DECLARE_MESSAGE_MAP()

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
		};
	}
}
