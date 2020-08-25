#ifndef CL_PLATFORM_H
#define CL_PLATFORM_H

#include <CL/cl.h>
#include <vector>
#include <map>
#include <fstream>

#include "PlatformUnitInitialize.h"

namespace gp
{


	class Platform
	{
	public:
		Platform();
		Platform(cl_platform_id plID);
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
		Device(const Device& dev)
		{

		};
		~Device();
			
		cl_device_id GetID();

		const char * GetName();
		const char * GetVendor();
		const char * GetProfile();
		const char * GetVersion();

		const Device& operator=(const Device& dev)
		{
			*this = Device(dev);
			return *this;
		}

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
	
	typedef cl_uint PlatformDataID;
	
	struct PlatformData
	{
		PlatformData();
		PlatformData(const PlatformData& plData);
		PlatformData(std::nullptr_t);
		~PlatformData();
		
		PlatformDataID id;
		Platform m_Platform;
		std::vector<Device> m_Devices;

	};

	class PlatformUnit
	{
	public:
		PlatformUnit();
		~PlatformUnit();
		
		void OnInitPlatformData();
		void OnRemovePlatformData(__int32 index);
		void OnRemoveAll();
		
		void AddPlatformData(const PlatformData& plData);
		void AddPlatformData(const Platform& platform, const Device& device);
		void AddPlatformData(const Platform& platform, std::vector<Device>& devices);

		//void AddPlatformData(PlatformDataID id, const PlatformData& plData);
		//void AddPlatformData(PlatformDataID id, const Platform& platform, const Device& device);
		//void AddPlatformData(PlatformDataID id, const Platform& platfrom, const std::vector<Device>& devices);
		
		const PlatformData& GetPlatformData(__int32 index);
		const Platform& GetPlatform(__int32 index);

		__int32 CountPlatformData();
		__int32 CountPlatforms();
		__int32 CountDevices();
		
	private:
		std::vector<PlatformData> m_PlatformDataStorage;
		__int32 m_CountPlatformData;
	};
}

#endif // !CL_PROGRAM_H
