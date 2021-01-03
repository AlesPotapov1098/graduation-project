#pragma once

#include <Windows.h>

namespace gp
{
	namespace prop
	{
        class Proportion
        {
        public:
            Proportion() = default;
            Proportion(UINT32 x = 0, UINT32 y = 0, UINT32 cx = 100, UINT32 cy = 100)
                : m_X(x), m_Y(y), m_Cx(cx), m_Cy(cy) {};
            ~Proportion() = default;

            virtual void ConvertFromRectToPos(RECT&) = 0;

            UINT32 GetX() const { return m_X; }
            UINT32 GetY() const { return m_Y; }
            UINT32 GetCX() const { return m_Cx; }
            UINT32 GetCY() const { return m_Cy; }

        protected:
            UINT32 m_X;
            UINT32 m_Y;
            UINT32 m_Cx;
            UINT32 m_Cy;
        };

        class ClientAreaPos : public Proportion
        {
        public:
            ClientAreaPos(UINT32 x = 0, UINT32 y = 0, UINT32 cx = 100, UINT32 cy = 100)
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
	}

}
