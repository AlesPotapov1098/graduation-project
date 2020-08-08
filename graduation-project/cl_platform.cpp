#include "cl_platform.h"

namespace gp
{
	information::information()
	{
		/*name	= nullptr;
		profile	= nullptr;
		vendor  = nullptr;
		version = nullptr;*/
	}

	const std::string& information::get_name()
	{
		if(name.empty()) 
			name = static_cast<const char*>(load_info(ID_NAME)); 
		return name;
	}

	const std::string& information::get_vendor()
	{
		if(vendor.empty())
			vendor = static_cast<const char*>(load_info(ID_VENDOR));
		return vendor;
	}
	
	const std::string& information::get_version()
	{
		if(version.empty())
			version = static_cast<const char*>(load_info(ID_VERSION));
		return version;
	}
	const std::string& information::get_profile()
	{
		if(profile.empty())
			profile = static_cast<const char*>(load_info(ID_PROFILE));
		return profile;
	}
}

namespace gp
{
	device::device()
	{
		id = nullptr;
		driver_version = nullptr;
	}

	device::device(cl_device_id devID)
	{
		id = devID;
	}

	device::~device()
	{
	}

	const std::string& device::get_driver_version()
	{
		if(driver_version.empty())
			driver_version = static_cast<const char*>(load_info(ID_DEVICE_DRIVER_VERSION));
		return driver_version;
	}

	void* __stdcall device::load_info(type_info type)
	{
		cl_device_info device_type_info = 0;

		switch (type)
		{
			case ID_NAME: 
				device_type_info = CL_DEVICE_NAME; 
				break;
			case ID_PROFILE : 
				device_type_info = CL_DEVICE_PROFILE; 
				break;
			case ID_VERSION : 
				device_type_info = CL_DEVICE_VERSION; 
				break;
			case ID_VENDOR: 
				device_type_info = CL_DEVICE_VENDOR; 
				break;
			case ID_DEVICE_DRIVER_VERSION: 
				device_type_info = CL_DRIVER_VERSION; 
				break;
	
			default: 
				device_type_info = -1; 
				break;
		}

		if (device_type_info == -1)
		{
			return nullptr;
		}

		std::size_t info_size = 0;
		if (clGetDeviceInfo(id, device_type_info, 0, nullptr, &info_size) != CL_SUCCESS)
		{
			return nullptr;
		}

		void * info = std::malloc(info_size);

		if (clGetDeviceInfo(id, device_type_info, info_size, info, nullptr) == CL_SUCCESS)
		{
			return info;
		}

		return nullptr;
	}
}

namespace gp
{
	platform::platform()
	{
		id = nullptr;
		count_devices = 0;
		/*extensions = nullptr;*/
	}

	platform::~platform()
	{
	}

	void platform::load_device()
	{
		count_devices = 0;
		
		if (clGetDeviceIDs(id, CL_DEVICE_TYPE_ALL, 0, nullptr, &count_devices) != CL_SUCCESS)
		{
			return;
		}
		
		if (count_devices == 0)
		{
			return;
		}
		
		cl_device_id * device_ids = new cl_device_id[count_devices];
		
		if (clGetDeviceIDs(id, CL_DEVICE_TYPE_ALL, count_devices, device_ids, nullptr) != CL_SUCCESS)
		{
			return;
		}

		for (int i = 0; i < count_devices; i++)
		{
			devices.push_back(device(device_ids[i]));
		}
	}

	const std::string& platform::get_extensions()
	{
		extensions = static_cast<const char*>(load_info(ID_PLATFROM_EXTENSIONS));
		return extensions;
	}

	void* __stdcall platform::load_info(type_info type)
	{
		cl_platform_info platform_type_info = 0;
		
		switch (type)
		{
		case ID_NAME:
			platform_type_info = CL_PLATFORM_NAME;
			break;
		case ID_PROFILE:
			platform_type_info = CL_PLATFORM_PROFILE;
			break;
		case ID_VERSION:
			platform_type_info = CL_PLATFORM_VERSION;
			break;
		case ID_VENDOR:
			platform_type_info = CL_PLATFORM_VENDOR;
			break;
		case ID_PLATFROM_EXTENSIONS:
			platform_type_info = CL_PLATFORM_EXTENSIONS;
			break;

		default:
			platform_type_info = -1;
			break;
		}

		if (platform_type_info == -1)
		{
			return nullptr;
		}

		
	}

	
}

namespace gp
{
	platforom_unit::platforom_unit()
	{
	}

	platforom_unit::~platforom_unit()
	{
	}

	const std::vector<platform>& platforom_unit::get_platforms() const
	{
		return _platforms;
	}

	const platform& platforom_unit::get_cpu_platforms() const
	{
		return platform();
	}

	const platform& platforom_unit::get_gpu_platforms() const
	{
		return platform();
	}
}