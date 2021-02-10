#pragma once

#include <afxwin.h>
#include <afxext.h>

namespace gp
{
	namespace app
	{
		/// <summary>
		/// Абстрактный базовый класс для управления позиционированием и пропорциями окон
		/// </summary>
		class WindowProportion
		{
		public:

			/// <summary>
			/// Конструктор по умолчанию.
			/// В качестве родительского окна берет монитор
			/// </summary>
			WindowProportion();

			/// <summary>
			/// Конструктор с параметрами.
			/// Определит позицию, высоту и ширину окна
			/// </summary>
			/// <param name="parent">Хендл родительского окна</param>
			WindowProportion(HWND parent);
			~WindowProportion();

			void SetParent(HWND parent);

			/// <summary>
			/// Возвращает ширину окна
			/// </summary>
			/// <returns>Ширина окна</returns>
			int GetWidth() const;

			/// <summary>
			/// Возвращает высоту окна
			/// </summary>
			/// <returns>Высота окна</returns>
			int GetHeight() const;

			/// <summary>
			/// Возвращает позицию по оси абсцисс
			/// </summary>
			/// <returns>X</returns>
			int GetX() const;

			/// <summary>
			/// Возвращает позицию по оси ординат
			/// </summary>
			/// <returns>Y</returns>
			int GetY() const;

			/// <summary>
			/// Возвращает структуру CRect окна
			/// </summary>
			/// <returns>RECT</returns>
			CRect GetWindowRect();

			/// <summary>
			/// Функция для вчисления пропорция и положения окна
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
