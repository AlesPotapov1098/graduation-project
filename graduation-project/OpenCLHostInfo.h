#pragma once

#include <string>
#include <codecvt>

#include "OpenCLHost.h"

namespace gpgpu {
	namespace info {

		class OpenCLHostInfo
		{
		private:
			cl::Platform m_Platform;
			cl::Device   m_Device;

		public:
			OpenCLHostInfo() = default;
			OpenCLHostInfo(const cl::Platform&, const cl::Device&);
			~OpenCLHostInfo() = default;

			void SetPlatform(const cl::Platform&);
			void SetDevice(const cl::Device&);

			std::wstring GetPlatformName() const;
			std::wstring GetPlatformVendor() const;
			std::wstring GetPlatformVersion() const;
			std::wstring GetPlatformExtensions() const;

			std::wstring GetDeviceName() const;
			std::wstring GetDeviceVendor() const;
			std::wstring GetDeviceVersion() const;
			std::wstring GetDeviceExtensions() const;
		};

	}
}
