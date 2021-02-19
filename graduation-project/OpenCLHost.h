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
			OpenCLHost(const cl::Platform&, const cl::Device&);
			~OpenCLHost();
			
			void SetPlatform(const cl::Platform&);
			void SetDevice(const cl::Device&);

			const cl::Platform& GetPlatform() const;
			const cl::Device& GetDevice() const;

		private:
			cl::Platform m_Platform;
			cl::Device   m_Device;
		};
	}
}


