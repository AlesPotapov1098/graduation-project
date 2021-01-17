#pragma once

#include <afxwin.h>

namespace gp
{
	namespace prop
	{
        class Proportion
        {
        public:
            Proportion() = default;
            Proportion(UINT x = 0, UINT y = 0, UINT cx = 100, UINT cy = 100)
                : m_X(x), m_Y(y), m_Cx(cx), m_Cy(cy) {};
            ~Proportion() = default;

            virtual void ConvertFromRectToPos(RECT&) = 0;

            UINT GetX() const { return m_X; }
            UINT GetY() const { return m_Y; }
            UINT GetCX() const { return m_Cx; }
            UINT GetCY() const { return m_Cy; }

        protected:
            UINT m_X;
            UINT m_Y;
            UINT m_Cx;
            UINT m_Cy;
        };

        class ClientAreaPos : public Proportion
        {
        public:
            ClientAreaPos(UINT x = 0, UINT y = 0, UINT cx = 100, UINT cy = 100)
                : Proportion(x, y, cx, cy) {};
            ~ClientAreaPos() = default;

            void ConvertFromRectToPos(RECT& rect) override
            {
                m_Cx = (rect.right - rect.left) * 80 / 100 - 10;
                m_Cy = (rect.bottom - rect.top) - 20;

                m_X = (rect.right - rect.left) * 20 / 100;
                m_Y = 10;
            }
        };

        class WindowProportion
        {
        public:
            WindowProportion();
            ~WindowProportion();

            void SetHWND(HWND hWnd);

            virtual void CalculateProportion();

            int GetX() const;
            int GetY() const;
            int GetWidth() const;
            int GetHeight() const;
            int GetCX() const;
            int GetCY() const;

        protected:
            int m_X;
            int m_Y;
            int m_Width;
            int m_Height;

            HWND m_Window;
            RECT m_Rect;
        };

        class ClientAreaProportion : public WindowProportion
        {
        public:
            ClientAreaProportion(HWND parent);
            void CalculateProportion() override;

        private:
            HWND m_ParentWindow;
        };
	}

}
