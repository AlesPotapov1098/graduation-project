#pragma once
#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

#include <iostream>
#include "OpemCLObject.h"

int main()
{
	cl_uint size = 0;
	cl_platform_id * id;
	cl_int error = clGetPlatformIDs(0, nullptr, &size);

	if(error || !size)
	{
		return -1;
	}
	
	id = new cl_platform_id[size];
	error = clGetPlatformIDs(size, id, 0);

	gpgpu::objects::OpenCLPlatform test(id[0]);

	std::cout << test.getName() << std::endl;
	std::cout << test.getVendor() << std::endl;
	std::cout << test.getProfile() << std::endl;
	std::cout << test.getVersion() << std::endl;
	std::cout << test.getExtensions() << std::endl;

	return 0;
}









