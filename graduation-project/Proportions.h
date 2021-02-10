#pragma once

#include <afxwin.h>
#include <afxext.h>

namespace gp
{
	namespace app
	{
		/// <summary>
		/// ����������� ������� ����� ��� ���������� ����������������� � ����������� ����
		/// </summary>
		class WindowProportion
		{
		public:

			/// <summary>
			/// ����������� �� ���������.
			/// � �������� ������������� ���� ����� �������
			/// </summary>
			WindowProportion();

			/// <summary>
			/// ����������� � �����������.
			/// ��������� �������, ������ � ������ ����
			/// </summary>
			/// <param name="parent">����� ������������� ����</param>
			WindowProportion(HWND parent);
			~WindowProportion();

			void SetParent(HWND parent);

			/// <summary>
			/// ���������� ������ ����
			/// </summary>
			/// <returns>������ ����</returns>
			int GetWidth() const;

			/// <summary>
			/// ���������� ������ ����
			/// </summary>
			/// <returns>������ ����</returns>
			int GetHeight() const;

			/// <summary>
			/// ���������� ������� �� ��� �������
			/// </summary>
			/// <returns>X</returns>
			int GetX() const;

			/// <summary>
			/// ���������� ������� �� ��� �������
			/// </summary>
			/// <returns>Y</returns>
			int GetY() const;

			/// <summary>
			/// ���������� ��������� CRect ����
			/// </summary>
			/// <returns>RECT</returns>
			CRect GetWindowRect();

			/// <summary>
			/// ������� ��� ��������� ��������� � ��������� ����
			/// </summary>
			virtual void CalculateWindowProportion() = 0;

		protected:
			int m_Width;
			int m_Height;
			int m_PosX;
			int m_PosY;

			int m_ParentWndWidth;
			int m_ParentWndHeight;
			int m_ParentWndPosX;
			int m_ParentWndPosY;

			CRect m_WindowRect;
			CRect m_ParentWindowRect;

			HWND m_Parent;
		};

		class MainWindowAppPropportion : public WindowProportion
		{
		public:

			MainWindowAppPropportion() : WindowProportion() {};
			MainWindowAppPropportion(HWND hwnd) : WindowProportion(hwnd) {};
			~MainWindowAppPropportion() {};

			void CalculateWindowProportion() override;
		};

		class MDIClientRectWindowProportion : public WindowProportion
		{
		public:

			MDIClientRectWindowProportion() : WindowProportion() {};
			MDIClientRectWindowProportion(HWND hwnd) : WindowProportion(hwnd) {};
			~MDIClientRectWindowProportion() {};

			void CalculateWindowProportion() override;
		};

		class MDIChildWindowProportion : public WindowProportion
		{
		public:
			void CalculateWindowProportion() override;
		};
	}
}
