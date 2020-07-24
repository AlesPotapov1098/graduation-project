#include "cl_device.h"


namespace gp 
{
	device_loader::device_loader()
	{
	}

	device_loader::~device_loader()
	{
	}

	const device& device_loader::get_device() const
	{
		return _device;
	}
}
