#pragma once

#include <CL/cl2.h>
#include <vector>

#include "OpenCLHost.h"

namespace gpgpu {

	class OpenCLHardware
	{
	private:
		cl::Platform m_Platform;
		cl::vector<cl::Device> m_Devices;
	public:
		OpenCLHardware() = default;
		OpenCLHardware(const cl::Platform&);
		~OpenCLHardware() = default;

		std::size_t GetCountDevices() const;
		const cl::Device& GetDevice(unsigned int index) const;
		const cl::Platform& GetPlatform() const;
	};

	class OpenCLConnection
	{
	private:
		cl::vector<OpenCLHardware> m_Hardware;
	
	public:
		OpenCLConnection();
		~OpenCLConnection();

		bool Init();
		std::size_t GetSize() const;
		const OpenCLHardware& GetHardware(unsigned int index) const;
	};

}

