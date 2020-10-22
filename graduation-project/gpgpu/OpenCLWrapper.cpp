#include "OpenCLWrapper.h"

namespace gpgpu {
    OpenCLPlatformLoadInfo::OpenCLPlatformLoadInfo(const cl::Platform& platform)
    {
        try {
            m_PlatformInfo.m_PlatformName = platform.getInfo<CL_PLATFORM_NAME>();
            m_PlatformInfo.m_PlatformExtensions = platform.getInfo<CL_PLATFORM_EXTENSIONS>();
            m_PlatformInfo.m_PlatformProfile = platform.getInfo<CL_PLATFORM_PROFILE>();
            m_PlatformInfo.m_PlatformVendor = platform.getInfo<CL_PLATFORM_VENDOR>();
            m_PlatformInfo.m_PlatformVersion = platform.getInfo<CL_PLATFORM_VERSION>();
        }
        catch (cl::Error error) {

        }
    }

    const PlatfromInfoDTOWrapper& gpgpu::OpenCLPlatformLoadInfo::GetPlatformInfo()
    {
        return m_PlatformInfo;
    }
}
