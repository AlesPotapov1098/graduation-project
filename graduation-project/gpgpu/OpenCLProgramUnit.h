#pragma once

#include "IOpenCLObject.h"

namespace gpgpu {

	namespace objects {

		template<typename T>
		class OpenCLProgramUnit : public IOpenCLObject<T> {
		public:
			OpenCLProgramUnit() = default;
			virtual ~OpenCLProgramUnit() = default;


		};

		class OpenCLProgram : public OpenCLProgramUnit<cl_program> {

		};

		class OpenCLKernel : public OpenCLProgramUnit<cl_kernel> {

		};

		class OpenCLSampler : public OpenCLProgramUnit<cl_sampler> {

		};


	}

}