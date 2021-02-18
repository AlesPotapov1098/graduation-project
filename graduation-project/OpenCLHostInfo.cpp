#include "OpenCLHostInfo.h"

namespace gpgpu {
	namespace info {
		OpenCLHostInfo::OpenCLHostInfo(const cl::Platform& platform, const cl::Device& device)
		{
			m_Platform = platform;
			m_Device = device;
		}

		void OpenCLHostInfo::SetPlatform(const cl::Platform& platform)
		{
			m_Platform = platform;
		}

		void OpenCLHostInfo::SetDevice(const cl::Device& device)
		{
			m_Device = device;
		}

		std::wstring OpenCLHostInfo::GetPlatformName() const
		{
			std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> conv;
			return conv.from_bytes(m_Platform.getInfo<CL_PLATFORM_NAME>());
		}

		std::wstring OpenCLHostInfo::GetPlatformVendor() const
		{
			std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> conv;
			return conv.from_bytes(m_Platform.getInfo<CL_PLATFORM_VENDOR>());
		}

		std::wstring OpenCLHostInfo::GetPlatformVersion() const
		{
			std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> conv;
			return conv.from_bytes(m_Platform.getInfo<CL_PLATFORM_VERSION>());
		}

		std::wstring OpenCLHostInfo::GetPlatformExtensions() const
		{
			std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> conv;
			return conv.from_bytes(m_Platform.getInfo<CL_PLATFORM_EXTENSIONS>());
		}

		std::wstring OpenCLHostInfo::GetDeviceName() const
		{
			std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> conv;
			return conv.from_bytes(m_Device.getInfo<CL_DEVICE_NAME>());
		}

		std::wstring OpenCLHostInfo::GetDeviceVendor() const
		{
			std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> conv;
			return conv.from_bytes(m_Device.getInfo<CL_DEVICE_VENDOR>());
		}

		std::wstring OpenCLHostInfo::GetDeviceVersion() const
		{
			std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> conv;
			return conv.from_bytes(m_Device.getInfo<CL_DEVICE_VERSION>());
		}

		std::wstring OpenCLHostInfo::GetDeviceExtensions() const
		{
			std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> conv;
			return conv.from_bytes(m_Device.getInfo<CL_DEVICE_EXTENSIONS>());
		}

	}
}
