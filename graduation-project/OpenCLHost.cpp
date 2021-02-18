#include "OpenCLHost.h"

namespace gpgpu {

	namespace host
	{
		OpenCLHost::~OpenCLHost()
		{
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

