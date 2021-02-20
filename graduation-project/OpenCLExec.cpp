#include "OpenCLExec.h"

namespace gpgpu {
	namespace exec {
		OpenCLExec::OpenCLExec(const host::OpenCLHost& host)
		{
			m_Host = host;
		}

		OpenCLExec::~OpenCLExec()
		{
		}

		void OpenCLExec::Init()
		{
			m_Context = std::vector<cl::Device>(1, m_Host.GetDevice());
			m_CommandQueue = cl::CommandQueue(m_Context, m_Host.GetDevice());
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
			if (m_Program.build(m_Host.GetDevice()) != CL_SUCCESS)
			{
				return false;
			}

			return true;
		}
	}
}