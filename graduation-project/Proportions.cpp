#include "Proportions.h"

namespace gp
{
	namespace prop
	{
		WindowProportion::WindowProportion()
		{
			m_Window = nullptr;

			m_X = CW_USEDEFAULT;
			m_Y = CW_USEDEFAULT;

			m_Width = 1600;
			m_Height = 800;

			m_Rect = { 0,0,0,0 };
		}

		WindowProportion::~WindowProportion()
		{
		}

		void WindowProportion::SetHWND(HWND hWnd)
		{
			m_Window = hWnd;
		}

		void WindowProportion::CalculateProportion()
		{
			GetWindowRect(m_Window, &m_Rect);
			m_Width = m_Rect.right - m_Rect.left;
			m_Height = m_Rect.bottom - m_Rect.top;
		}

		int WindowProportion::GetX() const
		{
			return m_X;
		}

		int WindowProportion::GetY() const
		{
			return m_Y;
		}

		int WindowProportion::GetWidth() const
		{
			return m_Width;
		}

		int WindowProportion::GetHeight() const
		{
			return m_Height;
		}

		int WindowProportion::GetCX() const
		{
			return m_Width;
		}

		int WindowProportion::GetCY() const
		{
			return m_Height;
		}
		ClientAreaProportion::ClientAreaProportion(HWND parent)
			: m_ParentWindow(parent)
		{

		}

		void ClientAreaProportion::CalculateProportion()
		{
			WindowProportion::CalculateProportion();
			
			m_X = m_Width * 3 / 10;
			m_Y = 10;
			
			m_Width *= (7 / 10) - 10;
			m_Height -= 20;
		}
	}
}