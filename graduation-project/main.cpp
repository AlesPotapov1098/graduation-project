#include <iostream>
#include <string>
#include <fstream>

#include "PlatformUnitInitialize.h"
#include "PlatformUnit.h"

int main(int argc, char ** argv) {
	
	int CountPlatforms = 0;
	cl_platform_id * Platforms = pl::InitPlatforms(&CountPlatforms);

	if (CountPlatforms == 0 || !Platforms)
	{	
		return -1;
	}

	for (int i = 0; i < CountPlatforms; i++)
	{
		std::cout << pl::GetPlatformName(Platforms[i]) << std::endl;
		std::cout << pl::GetPlatformVendor(Platforms[i]) << std::endl;
	}
		
	int CurPlatform = 0;

	int CountDevicesOfCurPlatform = 0;
	cl_device_id * DevicesCurPlatform = pl::InitDevices(Platforms[CurPlatform], &CountDevicesOfCurPlatform);

	if (CountDevicesOfCurPlatform == 0 || !DevicesCurPlatform)
	{
		return -2;
	}

	std::cout << "----------------------------------------------------" << std::endl;
	std::cout << "Cur Device" << std::endl;
	std::cout << "----------------------------------------------------" << std::endl;

	for (int i = 0; i < CountDevicesOfCurPlatform; i++)
	{
		std::cout << pl::GetDeviceName(DevicesCurPlatform[i]) << std::endl;
		std::cout << pl::GetDeviceVendor(DevicesCurPlatform[i]) << std::endl;
	}

	cl_int res = 0;
	cl_context Context = clCreateContext(nullptr, CountDevicesOfCurPlatform, &DevicesCurPlatform[0],nullptr,nullptr,&res);
	
	if (Context == nullptr)
	{
		return -3;
	}

	if (res != CL_SUCCESS)
	{
		return -4;
	}

	std::ifstream kernel_file = std::ifstream("D:\\graduation-project\\graduation-project\\image_rotate.cl");
	if (!kernel_file.is_open()) {
		printf("Error (mess) - can not open file\n");
		return -5;
	}
	std::string source_code = 
			std::string(std::istreambuf_iterator<char>(kernel_file), 
						(std::istreambuf_iterator<char>()));
	kernel_file.close();

	std::cout << source_code << std::endl;

	return 0;
}











