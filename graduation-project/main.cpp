#include <iostream>
#include <Windows.h>
#include <vector>
#include <CL\cl.h>
#include <string>

struct PlatformInfo
{
	std::string Name;
	std::string Vendor;
	std::string Profile;
	std::string Version;
};

struct DeviceInfo
{
	std::string Name;
	std::string Vendor;
	std::string Profile;
	std::string Version;
};

struct DeviceData
{
	cl_device_id DeviceID;
	DeviceInfo Info;

	DeviceData() : DeviceID(nullptr) {};

	DeviceData(cl_device_id id):DeviceID(id){};
};

struct PlatformData
{
	cl_platform_id PlatformID;
	PlatformInfo Info;

	PlatformData() : PlatformID(nullptr) {};

	PlatformData(cl_platform_id id) : PlatformID(id) {};

	std::vector<DeviceData> DevicesStorage;
};

/// <summary>
/// Инициализируем платформы и смежные им устройства
/// </summary>
/// <param name="size">[OUT] количество платформ на хосте</param>
/// <returns>Указатель на PlatfromData, содержая ID платформы и устройства</returns>
PlatformData* InitPlatformUnit(int& size);

/// <summary>
/// Заполняем информацию об платфорем
/// </summary>
/// <param name="platfromData">Платформа, для которой необходимо определить информацию</param>
/// <returns>true если удалось заполнить все поля PlatformInfo, false в противном случае</returns>
bool FillPlatformInfo(PlatformData*);

std::string GetPlatformName(const cl_platform_id& id);
std::string GetPlatformVendor(const cl_platform_id& id);
std::string GetPlatformVersion(const cl_platform_id& id);
std::string GetPlatformProfile(const cl_platform_id& id);

int main(int argc, char ** argv) {
	
	int CountOfPlatforms = 0;
	PlatformData * platforms = InitPlatformUnit(CountOfPlatforms);
	for (int i = 0; i < CountOfPlatforms; i++) {
		if (FillPlatformInfo(&platforms[i])) {
			std::cout << platforms[i].Info.Name << std::endl;
			std::cout << platforms[i].Info.Vendor << std::endl;
			std::cout << platforms[i].Info.Version << std::endl;
			std::cout << platforms[i].Info.Profile << std::endl;
		}
	}

	return 0;
}

PlatformData * InitPlatformUnit(int& size) {
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

	cl_platform_id * platfroms = new cl_platform_id[CountPlatforms];
	
	if (clGetPlatformIDs(CountPlatforms, platfroms, nullptr))
	{
		delete[] platfroms;
		return nullptr;
	}

	PlatformData * platforms = new PlatformData[CountPlatforms];
	for (int i = 0; i < CountPlatforms; i++) {
		platforms[i].PlatformID = platfroms[i];
	}

	for (int i = 0; i < CountPlatforms; i++) {
		cl_uint CountDevicesOfPlatform = 0;
		ErrorCode = clGetDeviceIDs(platforms[i].PlatformID,CL_DEVICE_TYPE_ALL,0,nullptr,&CountDevicesOfPlatform);
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
		
		cl_device_id * devices = new cl_device_id[CountDevicesOfPlatform];
		ErrorCode = clGetDeviceIDs(platforms[i].PlatformID,CL_DEVICE_TYPE_ALL,CountDevicesOfPlatform,devices,nullptr);
		if (ErrorCode){
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

bool FillPlatformInfo(PlatformData* platformData){
	
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

	return (!platformData->Info.Name.empty() &&
			!platformData->Info.Profile.empty() &&
			!platformData->Info.Vendor.empty() && 
			!platformData->Info.Version.empty());
}

std::string GetPlatformName(const cl_platform_id& id) {
	if (id == nullptr) {
		return nullptr;
	}

	cl_uint ErrorCode = 0;
	std::size_t SizeName = 0;
	
	ErrorCode = clGetPlatformInfo(id,
		CL_PLATFORM_NAME,
		0,nullptr,
	    &SizeName);
	if (ErrorCode) {
		return nullptr;
	}

	if (SizeName == 0) {
		return nullptr;
	}

	char * PlatformName = new char[SizeName];
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

std::string GetPlatformVendor(const cl_platform_id& id) {
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

std::string GetPlatformVersion(const cl_platform_id& id) {
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

std::string GetPlatformProfile(const cl_platform_id& id) {
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









