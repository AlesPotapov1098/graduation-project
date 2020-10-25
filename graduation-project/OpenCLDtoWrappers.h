#pragma once

#include <string>

namespace gpgpu {

	struct PlatfromInfoDTOWrapper {
		std::string m_PlatformName;
		std::string m_PlatformVendor;
		std::string m_PlatformVersion;
		std::string m_PlatformProfile;
		std::string m_PlatformExtensions;
	};

	struct DeviceInfoDTOWrapper {
		std::string m_DeviceName;
		std::string m_DeviceVersion;
		std::string m_DeviceProfile;
		std::string m_DeviceVendor;
		std::string m_DeviceExtensions;
		std::string m_DeviceType;
	};
}