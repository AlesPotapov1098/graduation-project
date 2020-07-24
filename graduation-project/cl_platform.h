#ifndef CL_PLATFORM_H
#define CL_PLATFORM_H

#pragma once

#include <CL/cl.h>
#include <vector>

namespace gp
{
	struct platform 
	{
		cl_platform_id id; 
		
	};

	class platforom_loader
	{
		public:
			platforom_loader();
			~platforom_loader();

			const std::vector<platform>& get_platforms() const;
			const platform& get_cpu_platforms() const;
			const platform& get_gpu_platforms() const;

		private:
			std::vector<platform> _platforms;
			std::size_t			  _count_platform;
	};
}

#endif // !CL_PROGRAM_H
