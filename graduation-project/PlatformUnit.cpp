#include "PlatformUnit.h"

namespace gp
{
	std::string LoadSrc(const char* filename)
	{
		if (filename == nullptr)
		{
			return nullptr;
		}

		std::ifstream file(filename, std::ios_base::in);
		
		if (!file.is_open())
		{
			return nullptr;
		}

		file.seekg(0,std::ios_base::end);
		std::size_t size = file.tellg();
		std::string src(size, '\0');
		file.read(&src[0],size);
		file.close();

		return src;
	}

	cl_context CreateCompatibleContext(cl_device_id deviceID)
	{
		if (deviceID == nullptr)
		{
			return nullptr;
		}

		cl_int ErrorCode = 0;
		cl_context Context = clCreateContext(
								nullptr,
								1,
								&deviceID,
								nullptr,
								nullptr,
								&ErrorCode);

		if (!Context)
		{
			return nullptr;
		}
	
		if (ErrorCode)
		{
			return nullptr;
		}

		return Context;
	}

	Platform::Platform()
	{
		m_PlatformID = nullptr;
		m_PlatformName = nullptr;
		m_PlatformProfile = nullptr;
		m_PlatformVendor = nullptr;
		m_PlatformVersion = nullptr;
	}

	Platform::Platform(const cl_platform_id& plID)
	{
		m_PlatformID = plID;
	}

	Platform::~Platform()
	{
		m_PlatformID = nullptr;
		
		if (m_PlatformName)
		{	
			delete m_PlatformName;
		}

		if (m_PlatformProfile)
		{
			delete m_PlatformProfile;
		}

		if (m_PlatformVendor)
		{
			delete m_PlatformVendor;
		}

		if (m_PlatformVersion)
		{	
			delete m_PlatformVersion;
		}
	}

	cl_platform_id Platform::GetID()
	{
		return m_PlatformID;
	}

	const char* Platform::GetName()
	{
		if (!m_PlatformName)
		{
			InitName();
		}
	
		return m_PlatformName;
	}

	const char* Platform::GetVendor()
	{
		if (!m_PlatformVendor)
		{
			InitVendor();
		}

		return m_PlatformVendor;
	}

	const char* Platform::GetProfile()
	{
		if (!m_PlatformProfile)
		{
			InitProfile();
		}

		return m_PlatformProfile;
	}

	const char* Platform::GetVersion()
	{
		if (!m_PlatformVersion)
		{
			InitVersion();
		}
	
		return m_PlatformVersion;
	}

	void Platform::InitName()
	{
		m_PlatformName = pl::GetPlatformName(m_PlatformID);
	}

	void Platform::InitVendor()
	{
		m_PlatformVendor = pl::GetPlatformName(m_PlatformID);
	}

	void Platform::InitProfile()
	{
		m_PlatformProfile = pl::GetPlatformProfile(m_PlatformID);
	}

	void Platform::InitVersion()
	{
		m_PlatformVersion = pl::GetPlatformVersion(m_PlatformID);
	}

	Device::Device()
	{
		m_DeviceID = nullptr;	
		m_DeviceName = nullptr;
		m_DeviceProfile = nullptr;
		m_DeviceVersion = nullptr;
		m_DeviceVendor = nullptr;
	}
	
	Device::Device(cl_device_id devID)
	{
		m_DeviceID = devID;
	}
	
	Device::~Device()
	{
		m_DeviceID = nullptr;

		if (m_DeviceName)
		{
			delete m_DeviceName;
		}

		if (m_DeviceProfile)
		{
			delete m_DeviceProfile;
		}

		if (m_DeviceVendor)
		{
			delete m_DeviceVendor;
		}

		if (m_DeviceVersion)
		{
			delete m_DeviceVersion;
		}
	}

	cl_device_id Device::GetID()
	{
		return m_DeviceID;
	}

	const char* Device::GetName()
	{
		if (!m_DeviceName)
		{
			InitName();
		}

		return m_DeviceName;
	}

	const char* Device::GetVendor()
	{
		if (!m_DeviceVendor)
		{
			InitVendor();
		}

		return m_DeviceVendor;
	}

	const char* Device::GetProfile()
	{
		if (!m_DeviceProfile)
		{
			InitProfile();
		}

		return m_DeviceProfile;
	}

	const char* Device::GetVersion()
	{
		if (!m_DeviceVersion)
		{
			InitVersion();
		}
	
		return m_DeviceVersion;
	}

	void Device::InitName()
	{
		m_Name = std::make_unique<const char*>(pl::GetDeviceName(m_DeviceID));
		m_DeviceName = pl::GetDeviceName(m_DeviceID);
	}

	void Device::InitVendor()
	{
		m_DeviceProfile = pl::GetDeviceProfile(m_DeviceID);
	}

	void Device::InitProfile()
	{
		m_DeviceVendor = pl::GetDeviceVendor(m_DeviceID);
	}

	void Device::InitVersion()
	{
		m_DeviceVersion = pl::GetDeviceVersion(m_DeviceID);
	}
}


