#pragma once

#include <CL/cl2.h>

namespace gp {

	namespace gpgpu {

		using devices = cl::vector<cl::Device>;

		class OpenCLConnection
		{
		public:
			OpenCLConnection();
			~OpenCLConnection();

			bool Init();
		private:

			cl_int m_CountPlatfroms;
			cl_int m_CountDevices;

			cl::vector<cl::Platform> m_Platfroms;
			cl::vector<devices> m_Devices;
		};

	}
}
