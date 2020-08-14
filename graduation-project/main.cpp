#include <iostream>
#include <Windows.h>
#include <vector>
#include <CL\cl.h>

struct DeviceData
{
	cl_device_id DeviceID;

	DeviceData() : DeviceID(nullptr) {};

	DeviceData(cl_device_id id):DeviceID(id){};
};

struct PlatformData
{
	cl_platform_id PlatformID;

	PlatformData() : PlatformID(nullptr) {};

	PlatformData(cl_platform_id id) : PlatformID(id) {};

	std::vector<DeviceData> DevicesStorage;
};

/// <summary>
/// »нициализируем платформы и смежные им устройства
/// </summary>
/// <param name="size">[OUT] количество платформ на хосте</param>
/// <returns>”казатель на PlatfromData, содержа€ ID платформы и устройства</returns>
PlatformData* OnInitPlatformUnit(int& size);

int main(int argc, char ** argv) {
	
	int CountOfPlatforms = 0;
	PlatformData * platforms = OnInitPlatformUnit(CountOfPlatforms);

	return 0;
}

PlatformData * OnInitPlatformUnit(int& size) {
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

		platforms->DevicesStorage.resize(CountDevicesOfPlatform);
		
		cl_device_id * devices = new cl_device_id[CountDevicesOfPlatform];
		ErrorCode = clGetDeviceIDs(platforms[i].PlatformID,CL_DEVICE_TYPE_ALL,CountDevicesOfPlatform,devices,nullptr);
		if (ErrorCode){
			delete[] devices;
			delete[] platforms;
			delete[] platfroms;
			return nullptr;
		}

		for (int j = 0; j < CountDevicesOfPlatform; j++) {
			platforms[i].DevicesStorage[j] = DeviceData(devices[j]);
		}

		delete[] devices;
		
	}

	delete[] platfroms;

	size = CountPlatforms;

	return platforms;
}

