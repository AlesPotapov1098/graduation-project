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
		name = this->load_info<char>(ID_NAME);
		return name;
	}

	const std::string& information::get_vendor()
	{
		vendor = load_info<char>(ID_VENDOR);
		return vendor;
	}
	
	const std::string& information::get_version()
	{
		version = load_info<char>(ID_VERSION);
		return version;
	}
	const std::string& information::get_profile()
	{
		profile = load_info<char>(ID_PROFILE);
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

	device::~device()
	{
	}

	const std::string& device::get_driver_version()
	{
		driver_version = load_info<char*>(ID_DEVICE_DRIVER_VERSION);
		return driver_version;
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
	}

	const std::string& platform::get_extensions()
	{
		extensions = load_info<char>(ID_PLATFROM_EXTENSIONS);
		return extensions;
	}

	
}

namespace gp
{
	platforom_loader::platforom_loader()
	{
	}

	platforom_loader::~platforom_loader()
	{
	}

	const std::vector<platform>& platforom_loader::get_platforms() const
	{
		return _platforms;
	}

	const platform& platforom_loader::get_cpu_platforms() const
	{
		return platform();
	}

	const platform& platforom_loader::get_gpu_platforms() const
	{
		return platform();
	}
}