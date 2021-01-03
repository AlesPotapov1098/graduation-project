#include "OpenCLHost.h"

namespace gp {

	namespace gpgpu {

		OpenCLHost::OpenCLHost(ID id, OpenCLHostHardware&& hardware)
		{
			m_ID = id;
			m_Hardware = hardware;
		}

		OpenCLHost::~OpenCLHost()
		{
		}

		ID OpenCLHost::GetID() const
		{
			return m_ID;
		}

		const OpenCLHostHardware& OpenCLHost::GetHardware() const
		{
			return m_Hardware;
		}
	}
}
