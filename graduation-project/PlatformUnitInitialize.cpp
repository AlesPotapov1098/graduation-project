#include "PlatformUnitInitialize.h"

namespace pl
{
	cl_platform_id * InitPlatforms(int* count) {
		cl_uint CountPlatforms = 0;
		cl_int ErrorCode = clGetPlatformIDs(0, nullptr, &CountPlatforms);
		if (ErrorCode)
		{
			return nullptr;
		}

		*count = CountPlatforms;

		if (CountPlatforms == 0)
		{
			return nullptr;
		}

		cl_platform_id* platforms = new cl_platform_id[CountPlatforms];

		if (clGetPlatformIDs(CountPlatforms, platforms, nullptr))
		{
			delete[] platforms;
			return nullptr;
		}

		return platforms;
	}

	cl_device_id* __stdcall InitDevices(cl_platform_id platformID, int * count)
	{
		if (platformID == nullptr)
		{
			return nullptr;
		}

		cl_uint CountDevices = 0;
		if(clGetDeviceIDs(platformID, CL_DEVICE_TYPE_ALL,0,nullptr, &CountDevices))
		{
			return nullptr;
		}

		*count = CountDevices;

		if (CountDevices == 0)
		{
			return nullptr;
		}

		cl_device_id * devices = new cl_device_id[CountDevices];

		if (clGetDeviceIDs(platformID,CL_DEVICE_TYPE_ALL,CountDevices,devices,nullptr))
		{
			delete[] devices;
			return nullptr;
		}

		return devices;
	}

	const char* __stdcall GetPlatformName(cl_platform_id id) {
		if (id == nullptr) {
			return nullptr;
		}

		cl_uint ErrorCode = 0;
		std::size_t SizeName = 0;

		ErrorCode = clGetPlatformInfo(
			id,
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
		ErrorCode = clGetPlatformInfo(
			id,
			CL_PLATFORM_NAME,
			SizeName,
			(void*)PlatformName,
			nullptr);

		if (ErrorCode) {
			delete[] PlatformName;
			return nullptr;
		}

		return PlatformName;
	}

	const char* __stdcall GetPlatformVendor(cl_platform_id id) {
		if (id == nullptr) {
			return nullptr;
		}

		cl_uint ErrorCode = 0;
		std::size_t SizeVendor = 0;

		ErrorCode = clGetPlatformInfo(
			id,
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
		ErrorCode = clGetPlatformInfo(
			id,
			CL_PLATFORM_VENDOR,
			SizeVendor,
			(void*)PlatformVendor,
			nullptr);

		if (ErrorCode) {
			delete[] PlatformVendor;
			return nullptr;
		}

		return PlatformVendor;
	}

	const char* __stdcall GetPlatformVersion(cl_platform_id id) {
		if (id == nullptr) {
			return nullptr;
		}

		cl_uint ErrorCode = 0;
		std::size_t SizeVersion = 0;

		ErrorCode = clGetPlatformInfo(
			id,
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
		ErrorCode = clGetPlatformInfo(
			id,
			CL_PLATFORM_VERSION,
			SizeVersion,
			(void*)PlatformVersion,
			nullptr);
	
		if (ErrorCode) {
			delete[] PlatformVersion;
			return nullptr;
		}

		return PlatformVersion;
	}

	const char* __stdcall GetPlatformProfile(cl_platform_id id) {
		if (id == nullptr) {
			return nullptr;
		}

		cl_uint ErrorCode = 0;
		std::size_t SizeProfile = 0;

		ErrorCode = clGetPlatformInfo(
			id,
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
		ErrorCode = clGetPlatformInfo(
			id,
			CL_PLATFORM_PROFILE,
			SizeProfile,
			(void*)PlatformProfile,
			nullptr);
	
		if (ErrorCode) {
			delete[] PlatformProfile;
			return nullptr;
		}

		return PlatformProfile;
	}

	const char* __stdcall GetDeviceName(cl_device_id id) {
		if (id == nullptr) {
			return nullptr;
		}

		cl_uint ErrorCode = 0;
		std::size_t SizeName = 0;

		ErrorCode = clGetDeviceInfo(
			id,
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
		ErrorCode = clGetDeviceInfo(
			id,
			CL_DEVICE_NAME,
			SizeName,
			(void*)DeviceName,
			nullptr);
		if (ErrorCode) {
			return nullptr;
		}

		return DeviceName;
	}
				
	const char* __stdcall GetDeviceVendor(cl_device_id id) {
		if (id == nullptr) {
			return nullptr;
		}

		cl_uint ErrorCode = 0;
		std::size_t SizeName = 0;

		ErrorCode = clGetDeviceInfo(
			id,
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
		ErrorCode = clGetDeviceInfo(
			id,
			CL_DEVICE_VENDOR,
			SizeName,
			(void*)DeviceVendor,
			nullptr);
		if (ErrorCode) {
			return nullptr;
		}

		return DeviceVendor;
	}
				
	const char* __stdcall GetDeviceVersion(cl_device_id id) {
		if (id == nullptr) {
			return nullptr;
		}

		cl_uint ErrorCode = 0;
		std::size_t SizeName = 0;

		ErrorCode = clGetDeviceInfo(
			id,
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
		ErrorCode = clGetDeviceInfo(
			id,
			CL_DEVICE_VERSION,
			SizeName,
			(void*)DeviceVersion,
			nullptr);
		if (ErrorCode) {
			return nullptr;
		}

		return DeviceVersion;
	}
				
	const char* __stdcall GetDeviceProfile(cl_device_id id) {
		if (id == nullptr) {
			return nullptr;
		}

		cl_uint ErrorCode = 0;
		std::size_t SizeName = 0;

		ErrorCode = clGetDeviceInfo(
			id,
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
		ErrorCode = clGetDeviceInfo(
			id,
			CL_DEVICE_PROFILE,
			SizeName,
			(void*)DeviceProfile,
			nullptr);
		if (ErrorCode) {
			return nullptr;
		}

		return DeviceProfile;
	}
}

