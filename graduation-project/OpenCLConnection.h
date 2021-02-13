#pragma once

#include <CL/cl2.h>

namespace gp {

	namespace gpgpu {

		using devices = cl::vector<cl::Device>;

		struct OpenCLInfo
		{
			cl::string m_PlatformName;
			cl::string m_PlatformVendor;
			cl::string m_PlatfromVersion;
			cl::string m_PlatfromExtensions;
		};

		class OpenCLConnection
		{
		public:
			OpenCLConnection();
			~OpenCLConnection();

			bool Init();

			const cl::vector <devices> & GetDevices() const;
			const cl::vector <cl::Platform> & GetPlatforms() const;

			OpenCLInfo GetPlatfromInfo() const;

		private:
			
			cl_int m_CountPlatfroms;
			cl_int m_CountDevices;

			cl::vector<cl::Platform> m_Platfroms;
			cl::vector<devices> m_Devices;
		};

	}
}
