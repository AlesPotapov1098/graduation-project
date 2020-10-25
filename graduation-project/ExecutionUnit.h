#pragma once

#include <CL/cl.h>

namespace gp
{

	class EContext
	{
	public:
		EContext();
		EContext(cl_device_id devID);
		~EContext();

		const cl_context& GetContext() const;

	private:	
		cl_context m_Context;
	};

	class EProgram
	{

	};

	class EKernel
	{
	public:
		EKernel();
		~EKernel();

		

	private:
		cl_kernel m_Kernel;
	};

}


