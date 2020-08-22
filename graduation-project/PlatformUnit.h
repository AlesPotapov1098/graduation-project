#ifndef CL_PLATFORM_H
#define CL_PLATFORM_H

#include <CL/cl.h>
#include <vector>
#include <fstream>

#include "PlatformUnitInitialize.h"

namespace gp
{

	class Platform
	{
	public:
		Platform();
		Platform(const cl_platform_id& plID);
		~Platform();

		cl_platform_id GetID();

		const char * GetName();
		const char * GetVendor();
		const char * GetProfile();
		const char * GetVersion();

	protected:
	
		void InitName();
		void InitVendor();
		void InitProfile();
		void InitVersion();

	private:
		
		cl_platform_id m_PlatformID;

		const char* m_PlatformName;
		const char* m_PlatformVendor;
		const char* m_PlatformProfile;
		const char* m_PlatformVersion;
	};

	class Device
	{
	public:
		Device();
		Device(cl_device_id devID);
		~Device();
			
		cl_device_id GetID();

		const char * GetName();
		const char * GetVendor();
		const char * GetProfile();
		const char * GetVersion();

	private:

		void InitName();
		void InitVendor();
		void InitProfile();
		void InitVersion();

	private:
		cl_device_id m_DeviceID;
		
		std::unique_ptr<const char*> m_Name;
		const char * m_DeviceName;
		const char * m_DeviceVendor;
		const char * m_DeviceProfile; // In depends of platform profile
		const char * m_DeviceVersion;
	};

	std::string LoadSrc(const char * filename);

	cl_context CreateCompatibleContext(cl_device_id deviceID);

	cl_program CreateCompatibleProgram();

	cl_kernel CreateCompatibleKernel();
}

#endif // !CL_PROGRAM_H
