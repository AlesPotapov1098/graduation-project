#include "OpenCLConnection.h"

namespace gp {

	namespace gpgpu {

		OpenCLConnection::OpenCLConnection()
		{
			m_CountPlatfroms = 0;
			m_CountDevices = 0;
		}

		OpenCLConnection::~OpenCLConnection()
		{
		}

		bool OpenCLConnection::Init()
		{
			cl::Platform::get(&m_Platfroms);
			m_CountPlatfroms = m_Platfroms.size();

			for (auto& pl : m_Platfroms)
			{
				devices devs;
				pl.getDevices(CL_DEVICE_TYPE_ALL, &devs);

				if (devs.empty())
					break;

				m_Devices.push_back(devs);
				m_CountDevices += devs.size();
			}

			return !(m_CountPlatfroms == 0 && m_CountDevices == 0);
		}

		const cl::vector<cl::Platform>& OpenCLConnection::GetPlatforms() const
		{
			return m_Platfroms;
		}

		OpenCLInfo OpenCLConnection::GetPlatfromInfo() const
		{
			OpenCLInfo info;

			info.m_PlatformName = m_Platfroms[0].getInfo<CL_PLATFORM_NAME>();
			info.m_PlatformVendor = m_Platfroms[0].getInfo<CL_PLATFORM_VENDOR>();
			info.m_PlatfromVersion = m_Platfroms[0].getInfo<CL_PLATFORM_VERSION>();
			info.m_PlatfromExtensions = m_Platfroms[0].getInfo<CL_PLATFORM_EXTENSIONS>();

			return info;
		}

		const cl::vector<devices>& OpenCLConnection::GetDevices() const
		{
			return m_Devices;
		}
	}
}