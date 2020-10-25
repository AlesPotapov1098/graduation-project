#pragma once

#include <string>

#include "IOpenCLObject.h"

namespace gpgpu {

	namespace objects {

		template<typename T, typename L>
		class OpenCLProgramUnit : public IOpenCLObject<T> {
		public:
			OpenCLProgramUnit() = default;
			virtual ~OpenCLProgramUnit() = default;

			virtual bool Load(const L&) = 0;
			virtual bool Build() = 0;
			virtual const std::string& ErrorMessage() = 0;
		protected:
			L m_Obj;
		};

		class OpenCLProgram : public OpenCLProgramUnit<cl_program, std::string> {
		public:
			OpenCLProgram();
			~OpenCLProgram();

			bool Load(const std::string& src) override;
			bool Build() override;
			const std::string ErrorMessage() override;

		private:
			std::string m_SRC;
		};

		class OpenCLKernel : public OpenCLProgramUnit<cl_kernel, OpenCLProgram> {
		public:
			OpenCLKernel();
			~OpenCLKernel();

			bool Load(const OpenCLProgram& program) override;
			bool Build() override;
			const std::string ErrorMessage() override;
		};

	}

}