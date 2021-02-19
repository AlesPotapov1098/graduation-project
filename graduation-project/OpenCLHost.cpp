#include "OpenCLHost.h"

namespace gpgpu {

	namespace host
	{
		OpenCLHost::OpenCLHost(const cl::Platform& pl, const cl::Device& dev)
		{
			m_Device = dev;
			m_Platform = pl;
		}
		
		OpenCLHost::~OpenCLHost()
		{
		}

		void OpenCLHost::SetPlatform(const cl::Platform& platform)
		{
			m_Platform = platform;
		}

		void OpenCLHost::SetDevice(const cl::Device& dev)
		{
			m_Device = dev;
		}

		const cl::Device& OpenCLHost::GetDevice() const
		{
			return m_Device;
		}

		const cl::Platform& OpenCLHost::GetPlatform() const
		{
			return m_Platform;
		}

	}
}

