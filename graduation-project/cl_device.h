#ifndef CL_DEVICE_H
#define CL_DEVICE_H
#pragma once

#include <CL/cl.h>

namespace gp
{

	struct device
	{
		cl_device_id id;
	};

	class device_loader
	{
		public:
			device_loader();
			~device_loader();

			const device& get_device() const;
		private:
			device _device;
	};
}

#endif // !CL_DEVICE_H
