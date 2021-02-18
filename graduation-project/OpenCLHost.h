#pragma once

#include <CL/opencl.hpp>

namespace gpgpu
{
	namespace host
	{
		/// <summary>
		/// —труктура данных дл€ управлени€ хостом
		/// </summary>
		class OpenCLHost
		{
		public:
			OpenCLHost() = default;
			~OpenCLHost();
			
			const cl::Platform& GetPlatform() const;
			const cl::Device& GetDevice() const;

		private:
			cl::Platform m_Platform;
			cl::Device   m_Device;
		};
	}
}


