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

			const cl::vector <devices> & GetDevices() const;
			const cl::vector <cl::Platform> & GetPlatforms() const;

		private:
			
			cl_int m_CountPlatfroms;
			cl_int m_CountDevices;

			cl::vector<cl::Platform> m_Platfroms;
			cl::vector<devices> m_Devices;
		};

	}
}
