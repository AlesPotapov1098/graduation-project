#include "OpenCLConnection.h"

namespace gpgpu {
	
	OpenCLHardware::OpenCLHardware(const cl::Platform& platform)
	{
		m_Platform = platform;
		platform.getDevices(CL_DEVICE_TYPE_ALL,&m_Devices);
	}

	std::size_t OpenCLHardware::GetCountDevices() const
	{
		return m_Devices.size();
	}
	
	const cl::Device& OpenCLHardware::GetDevice(unsigned int index) const
	{
		return m_Devices[index];
	}
	
	const cl::Platform& OpenCLHardware::GetPlatform() const
	{
		return m_Platform;
	}
	
	OpenCLConnection::OpenCLConnection()
	{
	}

	OpenCLConnection::~OpenCLConnection()
	{
	}

	bool OpenCLConnection::Init()
	{
		cl::vector<cl::Platform> platfroms;
		cl::Platform::get(&platfroms);

		for (auto pl : platfroms)
		{
			OpenCLHardware hard(pl);
			m_Hardware.push_back(hard);
		}

		return true;
	}
	
	std::size_t OpenCLConnection::GetSize() const
	{
		return m_Hardware.size();
	}
	
	const OpenCLHardware& OpenCLConnection::GetHardware(unsigned int index) const
	{
		return m_Hardware[index];
	}
}
