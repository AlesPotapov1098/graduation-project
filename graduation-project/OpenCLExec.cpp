#include "OpenCLExec.h"

namespace gpgpu {
	namespace exec {
		OpenCLExec::OpenCLExec(const host::OpenCLHost& host)
		{
		}

		OpenCLExec::~OpenCLExec()
		{
		}

		bool OpenCLExec::LoadSourceCode(const std::wstring & path)
		{
			std::ifstream file(path);
			if(!file.is_open() || !file)
				return false;

			m_Src = std::string(std::istreambuf_iterator<char>(file), (std::istreambuf_iterator<char>()));

			file.close();

			return true;
		}

		bool OpenCLExec::Build()
		{
			cl::Program::Sources sources;
			sources.push_back(m_Src);

			m_Program = cl::Program(m_Context, sources);

			return false;
		}
	}
}