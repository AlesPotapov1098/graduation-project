#pragma once

#include <afxwin.h>

namespace gp
{
	namespace app
	{
		class WindowProportion
		{
		public:

			WindowProportion();
			WindowProportion(HWND parent);
			~WindowProportion();

			void SetParent(HWND parent);

			int GetWidth() const;
			int GetHeight() const;
			int GetX() const;
			int GetY() const;

			CRect GetWindowRect() const;

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
	}
}
