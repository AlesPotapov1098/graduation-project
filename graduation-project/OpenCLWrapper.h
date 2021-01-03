#pragma once

#define CL_HPP_ENABLE_EXCEPTIONS

#include <string>
#include <CL/opencl.hpp>

#include "OpenCLDtoWrappers.h"

namespace gpgpu {

	const char* NONE = "NONE";
	const char* GPU = "GPU";
	const char* CPU = "CPU";

	class OpenCLPlatformLoadInfo {
	public:
		OpenCLPlatformLoadInfo() = default;
		OpenCLPlatformLoadInfo(const cl::Platform& platform);
		~OpenCLPlatformLoadInfo() = default;

		const PlatfromInfoDTOWrapper& GetPlatformInfo();

	private:
		PlatfromInfoDTOWrapper m_PlatformInfo;
	};

	class OpenCLDeviceLoadInfo {
	public:
		OpenCLDeviceLoadInfo() = default;
		OpenCLDeviceLoadInfo(const cl::Device& device);
		~OpenCLDeviceLoadInfo() = default;

		const DeviceInfoDTOWrapper& GetDeviceInfo();
	private:
		DeviceInfoDTOWrapper m_DeviceInfo;
	};

	class OpenCLPlatformUnitWrapper
	{
	public:
		OpenCLPlatformUnitWrapper();
		~OpenCLPlatformUnitWrapper();

		void Init();
		const PlatfromUnitDTO& getDTO(unsigned int index);

	private:
		std::vector<PlatfromUnitDTO> m_Units;
	};

}
