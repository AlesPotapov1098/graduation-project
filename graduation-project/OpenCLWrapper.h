#pragma once

//#define CL_HPP_ENABLE_EXCEPTIONS

#pragma warning(disable : 4996)

#include <string>
#include <CL/opencl.hpp>

#include "OpenCLDtoWrappers.h"

namespace gpgpu {

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

	class OpenCLWrapper
	{
	public:
		OpenCLWrapper();
		~OpenCLWrapper();

		void Init();

	private:

	};

}
