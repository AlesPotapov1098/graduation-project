#include "cl_platform.h"

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

	const platform& platforom_loader::get_gpu_platforms() const
	{
		return platform();
	}

	const platform& platforom_loader::get_cpu_platforms() const
	{
		return platform();
	}
}
