#pragma once

#define CL_HPP_ENABLE_EXCEPTIONS

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

	class OpenCLWrapper
	{
	public:
		OpenCLWrapper();
		~OpenCLWrapper();

		void Init();

	private:

	};

}
