#pragma once

#pragma comment(lib,"OpenCL.lib")

#define CL_HPP_ENABLE_EXCEPTIONS
#define CL_HPP_MINIMUM_OPENCL_VERSION 200
#define CL_HPP_TARGET_OPENCL_VERSION  220

#include <iostream>
#include <CL/opencl.hpp>
#include <string>
#include <vector>

int main()
{
	try {
		std::vector<cl::Platform> platforms;
		cl::Platform::get(&platforms);

		for (auto& platfrom : platforms)
		{
			auto platform_name = platfrom.getInfo<CL_PLATFORM_NAME>();
			std::cout << platform_name << std::endl;
			std::string platform_ext = platfrom.getInfo<CL_PLATFORM_EXTENSIONS>();
			std::cout << platform_ext << std::endl;
			std::vector<cl::Device> devices;
			platfrom.getDevices(CL_DEVICE_TYPE_ALL, &devices);
			for (auto& device : devices)
			{
				auto device_name = device.getInfo<CL_DEVICE_NAME>();
				std::cout << device_name << std::endl;
				cl::string device_vendor = device.getInfo<CL_DEVICE_VENDOR>();
				std::cout << device_vendor << std::endl;
				cl::string device_ext = device.getInfo<CL_DEVICE_EXTENSIONS>();
				std::cout << device_ext << std::endl;
				auto type = device.getInfo<CL_DEVICE_TYPE>();
			}
		}
	}
	catch (std::exception error) {
		std::cout << error.what() << std::endl;
	}

	return 0;
}









