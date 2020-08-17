#include <iostream>
#include <Windows.h>
#include <vector>
#include <CL\cl.h>
#include <string>



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
		for (std::vector<DeviceData>::iterator it = platforms[i].DevicesStorage.begin();
			it < platforms[i].DevicesStorage.end(); 
			it++)
		{
			if (FillDeviceInfo(&*it))
			{
				std::cout << it->Info.Name << std::endl;
				std::cout << it->Info.Vendor << std::endl;
				std::cout << it->Info.Version << std::endl;
				std::cout << it->Info.Profile << std::endl;
			}
		}
	}

	return 0;
}











