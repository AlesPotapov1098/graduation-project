#pragma once

#include <Windows.h>
#include <map>

namespace gp
{
	namespace app {

		class WindowMessageProcedure
		{
		public:
			WindowMessageProcedure();
			~WindowMessageProcedure();

			virtual LRESULT operator()(HWND, UINT, WPARAM, LPARAM);
		};

		class MessageWindowStorage
		{
		public:
			MessageWindowStorage() = default;
			~MessageWindowStorage();
		private:
			
		};
	}

}

