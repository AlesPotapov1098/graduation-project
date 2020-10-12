#pragma once

#include "Control.h"

namespace gui {
	namespace ctrl {
		class Button : public Control
		{
		public:
			Button() = default;
			Button(HWND parent, LPCSTR text, __int32 id, __int32 width, __int32 heigth, __int32 x, __int32 y, LPCSTR ClassName, LPCSTR ControlName);
			~Button();

			bool Build() override;
			void OnPaint() override { return; }
			virtual void OnClick();
		};
	}
}

