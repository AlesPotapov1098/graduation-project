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

			int GetWidth() const;
			int GetHeight() const;
			int GetX() const;
			int GetY() const;

			virtual void CalculateWindowProportion() = 0;

		protected:
			int m_Width;
			int m_Height;
			int m_PoxX;
			int m_PosY;

			CRect m_WindowRect;

			HWND m_Parent;
		};

		class MainWindowAppPropportion : public WindowProportion
		{
		public:
			void CalculateWindowProportion() override;
		};

		class MDIClientRectWindowProportion : public WindowProportion
		{
		public:
			void CalculateWindowProportion() override;
		};
	}
}
