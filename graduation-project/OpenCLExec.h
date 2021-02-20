#pragma once

#include <CL\cl2.h>
#include <string>
#include <fstream>

#include "OpenCLHost.h"

namespace gpgpu {
	namespace exec {
		class OpenCLExec
		{
		private:
			cl::Context m_Context;
			cl::Program m_Program;
			std::string m_Src;
			cl::Kernel m_Kernel;
			cl::CommandQueue m_CommandQueue;

			host::OpenCLHost m_Host;

		public:
			OpenCLExec(const host::OpenCLHost&);
			~OpenCLExec();

			bool LoadSourceCode(const std::wstring&);
			bool Build();
			std::wstring GetBuilError();
		};
	}
}

