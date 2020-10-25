#include "OpenCLWrapper.h"

namespace gpgpu {

    OpenCLPlatformLoadInfo::OpenCLPlatformLoadInfo(const cl::Platform& platform)
    {
        
            m_PlatformInfo.m_PlatformName = platform.getInfo<CL_PLATFORM_NAME>();
            m_PlatformInfo.m_PlatformExtensions = platform.getInfo<CL_PLATFORM_EXTENSIONS>();
            m_PlatformInfo.m_PlatformProfile = platform.getInfo<CL_PLATFORM_PROFILE>();
            m_PlatformInfo.m_PlatformVendor = platform.getInfo<CL_PLATFORM_VENDOR>();
            m_PlatformInfo.m_PlatformVersion = platform.getInfo<CL_PLATFORM_VERSION>();
        
    }

    const PlatfromInfoDTOWrapper& gpgpu::OpenCLPlatformLoadInfo::GetPlatformInfo()
    {
        return m_PlatformInfo;
    }

    OpenCLDeviceLoadInfo::OpenCLDeviceLoadInfo(const cl::Device& device)
    {
        m_DeviceInfo.m_DeviceName = device.getInfo<CL_DEVICE_NAME>();
        m_DeviceInfo.m_DeviceExtensions = device.getInfo<CL_DEVICE_EXTENSIONS>();
        m_DeviceInfo.m_DeviceProfile = device.getInfo<CL_DEVICE_PROFILE>();
        m_DeviceInfo.m_DeviceVendor = device.getInfo<CL_DEVICE_VENDOR>();
        m_DeviceInfo.m_DeviceVersion = device.getInfo<CL_DEVICE_VERSION>();

		auto deviceTypeCode = device.getInfo<CL_DEVICE_TYPE>();
		switch (deviceTypeCode)
		{
		case CL_DEVICE_TYPE_GPU:
			m_DeviceInfo.m_DeviceType = GPU;
			break;

		case CL_DEVICE_TYPE_CPU:
			m_DeviceInfo.m_DeviceType = CPU;
			break;

		default:
			m_DeviceInfo.m_DeviceType = NONE;
			break;
		}
    }

    const DeviceInfoDTOWrapper& OpenCLDeviceLoadInfo::GetDeviceInfo()
    {
        return m_DeviceInfo;
    }

    OpenCLPlatformUnitWrapper::OpenCLPlatformUnitWrapper()
    {
    }

    OpenCLPlatformUnitWrapper::~OpenCLPlatformUnitWrapper()
    {
    }

    void OpenCLPlatformUnitWrapper::Init()
    {
        try
        {
            cl::vector<cl::Platform> platfroms;
            cl::Platform::get(&platfroms);
            for (auto pl : platfroms) {
                PlatfromUnitDTO dto;
                dto.m_Platfrom = std::move(pl);
                dto.m_Platfrom.getDevices(CL_DEVICE_TYPE_ALL, &dto.m_Devices);
                m_Units.push_back(std::move(dto));
            }
        }
        catch (const cl::Error& error) {

        }
    }
    const PlatfromUnitDTO& OpenCLPlatformUnitWrapper::getDTO(unsigned int index)
    {
        if (index >= m_Units.size())
        {
            throw std::exception("Invalid index!");
        }

        return m_Units[index];
    }
}
