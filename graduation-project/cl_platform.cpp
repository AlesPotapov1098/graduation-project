#include "cl_platform.h"

namespace gp
{
	PlatformData* InitPlatformUnit(int& size) {
		cl_uint CountPlatforms = 0;
		cl_int ErrorCode = clGetPlatformIDs(0, nullptr, &CountPlatforms);
		if (ErrorCode)
		{
			return nullptr;
		}

		if (CountPlatforms == 0)
		{
			return nullptr;
		}

		cl_platform_id* platfroms = new cl_platform_id[CountPlatforms];

		if (clGetPlatformIDs(CountPlatforms, platfroms, nullptr))
		{
			delete[] platfroms;
			return nullptr;
		}

		PlatformData* platforms = new PlatformData[CountPlatforms];
		for (int i = 0; i < CountPlatforms; i++) {
			platforms[i].PlatformID = platfroms[i];
		}

		for (int i = 0; i < CountPlatforms; i++) {
			cl_uint CountDevicesOfPlatform = 0;
			ErrorCode = clGetDeviceIDs(platforms[i].PlatformID, CL_DEVICE_TYPE_ALL, 0, nullptr, &CountDevicesOfPlatform);
			if (ErrorCode) {
				delete[] platforms;
				delete[] platfroms;
				return nullptr;
			}

			if (CountDevicesOfPlatform == 0) {
				delete[] platforms;
				delete[] platfroms;
				return nullptr;
			}

			cl_device_id* devices = new cl_device_id[CountDevicesOfPlatform];
			ErrorCode = clGetDeviceIDs(platforms[i].PlatformID, CL_DEVICE_TYPE_ALL, CountDevicesOfPlatform, devices, nullptr);
			if (ErrorCode) {
				delete[] devices;
				delete[] platforms;
				delete[] platfroms;
				return nullptr;
			}

			for (int j = 0; j < CountDevicesOfPlatform; j++) {
				platforms[i].DevicesStorage.push_back(DeviceData(devices[j]));
			}

			delete[] devices;

		}

		delete[] platfroms;

		size = CountPlatforms;

		return platforms;
	}

	bool FillPlatformInfo(PlatformData* platformData) {

		if (platformData == nullptr) {
			return false;
		}

		if (platformData->PlatformID == nullptr) {
			return false;
		}

		platformData->Info.Name = GetPlatformName(platformData->PlatformID);
		platformData->Info.Profile = GetPlatformProfile(platformData->PlatformID);
		platformData->Info.Vendor = GetPlatformVendor(platformData->PlatformID);
		platformData->Info.Version = GetPlatformVersion(platformData->PlatformID);

		return (platformData->Info.Name &&
			platformData->Info.Profile &&
			platformData->Info.Vendor &&
			platformData->Info.Version);
	}

	const char* GetPlatformName(const cl_platform_id& id) {
		if (id == nullptr) {
			return nullptr;
		}

		cl_uint ErrorCode = 0;
		std::size_t SizeName = 0;

		ErrorCode = clGetPlatformInfo(id,
			CL_PLATFORM_NAME,
			0, nullptr,
			&SizeName);
		if (ErrorCode) {
			return nullptr;
		}

		if (SizeName == 0) {
			return nullptr;
		}

		char* PlatformName = new char[SizeName];
		ErrorCode = clGetPlatformInfo(id,
			CL_PLATFORM_NAME,
			SizeName,
			(void*)PlatformName,
			nullptr);
		if (ErrorCode) {
			return nullptr;
		}

		return PlatformName;
	}

	const char* GetPlatformVendor(const cl_platform_id& id) {
		if (id == nullptr) {
			return nullptr;
		}

		cl_uint ErrorCode = 0;
		std::size_t SizeVendor = 0;

		ErrorCode = clGetPlatformInfo(id,
			CL_PLATFORM_VENDOR,
			0, nullptr,
			&SizeVendor);
		if (ErrorCode) {
			return nullptr;
		}

		if (SizeVendor == 0) {
			return nullptr;
		}

		char* PlatformVendor = new char[SizeVendor];
		ErrorCode = clGetPlatformInfo(id,
			CL_PLATFORM_VENDOR,
			SizeVendor,
			(void*)PlatformVendor,
			nullptr);
		if (ErrorCode) {
			return nullptr;
		}

		return PlatformVendor;
	}

	const char* GetPlatformVersion(const cl_platform_id& id) {
		if (id == nullptr) {
			return nullptr;
		}

		cl_uint ErrorCode = 0;
		std::size_t SizeVersion = 0;

		ErrorCode = clGetPlatformInfo(id,
			CL_PLATFORM_VERSION,
			0, nullptr,
			&SizeVersion);
		if (ErrorCode) {
			return nullptr;
		}

		if (SizeVersion == 0) {
			return nullptr;
		}

		char* PlatformVersion = new char[SizeVersion];
		ErrorCode = clGetPlatformInfo(id,
			CL_PLATFORM_VERSION,
			SizeVersion,
			(void*)PlatformVersion,
			nullptr);
		if (ErrorCode) {
			return nullptr;
		}

		return PlatformVersion;
	}

	const char* GetPlatformProfile(const cl_platform_id& id) {
		if (id == nullptr) {
			return nullptr;
		}

		cl_uint ErrorCode = 0;
		std::size_t SizeProfile = 0;

		ErrorCode = clGetPlatformInfo(id,
			CL_PLATFORM_PROFILE,
			0, nullptr,
			&SizeProfile);
		if (ErrorCode) {
			return nullptr;
		}

		if (SizeProfile == 0) {
			return nullptr;
		}

		char* PlatformProfile = new char[SizeProfile];
		ErrorCode = clGetPlatformInfo(id,
			CL_PLATFORM_PROFILE,
			SizeProfile,
			(void*)PlatformProfile,
			nullptr);
		if (ErrorCode) {
			return nullptr;
		}

		return PlatformProfile;
	}

	bool FillDeviceInfo(DeviceData* deviceData)
	{
		if (deviceData == nullptr) {
			return false;
		}

		if (deviceData->DeviceID == nullptr) {
			return false;
		}

		deviceData->Info.Name = GetDeviceName(deviceData->DeviceID);
		deviceData->Info.Profile = GetDeviceProfile(deviceData->DeviceID);
		deviceData->Info.Vendor = GetDeviceVendor(deviceData->DeviceID);
		deviceData->Info.Version = GetDeviceVersion(deviceData->DeviceID);

		return (deviceData->Info.Name &&
			deviceData->Info.Profile &&
			deviceData->Info.Vendor &&
			deviceData->Info.Version);
	}

	const char* GetDeviceName(const cl_device_id& id) {
		if (id == nullptr) {
			return nullptr;
		}

		cl_uint ErrorCode = 0;
		std::size_t SizeName = 0;

		ErrorCode = clGetDeviceInfo(id,
			CL_DEVICE_NAME,
			0, nullptr,
			&SizeName);
		if (ErrorCode) {
			return nullptr;
		}

		if (SizeName == 0) {
			return nullptr;
		}

		char* DeviceName = new char[SizeName];
		ErrorCode = clGetDeviceInfo(id,
			CL_DEVICE_NAME,
			SizeName,
			(void*)DeviceName,
			nullptr);
		if (ErrorCode) {
			return nullptr;
		}

		return DeviceName;
	}

	const char* GetDeviceVendor(const cl_device_id& id) {
		if (id == nullptr) {
			return nullptr;
		}

		cl_uint ErrorCode = 0;
		std::size_t SizeName = 0;

		ErrorCode = clGetDeviceInfo(id,
			CL_DEVICE_VENDOR,
			0, nullptr,
			&SizeName);
		if (ErrorCode) {
			return nullptr;
		}

		if (SizeName == 0) {
			return nullptr;
		}

		char* DeviceVendor = new char[SizeName];
		ErrorCode = clGetDeviceInfo(id,
			CL_DEVICE_VENDOR,
			SizeName,
			(void*)DeviceVendor,
			nullptr);
		if (ErrorCode) {
			return nullptr;
		}

		return DeviceVendor;
	}

	const char* GetDeviceVersion(const cl_device_id& id) {
		if (id == nullptr) {
			return nullptr;
		}

		cl_uint ErrorCode = 0;
		std::size_t SizeName = 0;

		ErrorCode = clGetDeviceInfo(id,
			CL_DEVICE_VERSION,
			0, nullptr,
			&SizeName);
		if (ErrorCode) {
			return nullptr;
		}

		if (SizeName == 0) {
			return nullptr;
		}

		char* DeviceVersion = new char[SizeName];
		ErrorCode = clGetDeviceInfo(id,
			CL_DEVICE_VERSION,
			SizeName,
			(void*)DeviceVersion,
			nullptr);
		if (ErrorCode) {
			return nullptr;
		}

		return DeviceVersion;
	}

	const char* GetDeviceProfile(const cl_device_id& id) {
		if (id == nullptr) {
			return nullptr;
		}

		cl_uint ErrorCode = 0;
		std::size_t SizeName = 0;

		ErrorCode = clGetDeviceInfo(id,
			CL_DEVICE_PROFILE,
			0, nullptr,
			&SizeName);
		if (ErrorCode) {
			return nullptr;
		}

		if (SizeName == 0) {
			return nullptr;
		}

		char* DeviceProfile = new char[SizeName];
		ErrorCode = clGetDeviceInfo(id,
			CL_DEVICE_PROFILE,
			SizeName,
			(void*)DeviceProfile,
			nullptr);
		if (ErrorCode) {
			return nullptr;
		}

		return DeviceProfile;
	}

	const char* LoadSrc(const char* filename)
	{
		if (filename == nullptr)
		{
			return nullptr;
		}

		std::ifstream file(filename, std::ios_base::in);
		
		if (!file.is_open())
		{
			return nullptr;
		}

		file.seekg(0,std::ios_base::end);
		std::size_t size = file.tellg();
		std::string src(size, '\0');
		file.read(&src[0],size);
		file.close();

		return src.c_str();
	}
}


