#pragma once

#include <vector>

#include "IOpenCLObject.h"
#include "OpenCLPlatformUnit.h"

namespace gpgpu {

	namespace objects {

		template<typename T>
		class OpenCLExecutionUnit : public IOpenCLObject<T> {
		public:
			OpenCLExecutionUnit();
			virtual ~OpenCLExecutionUnit();

			virtual cl_uint getDeviceCount() = 0;
			virtual cl_uint getCountReferences() = 0;
			virtual const std::vector<OpenCLDevice>& getDevices() = 0;
		protected:
			cl_uint m_CountRefences;
			cl_uint m_CountDevices;
			std::vector<OpenCLDevice> m_Devices;
		};

		class OpenCLContext : public OpenCLExecutionUnit<cl_context> {
		public:
			OpenCLContext();
			~OpenCLContext();

			cl_uint getDeviceCount() override;
			cl_uint getCountReferences() override;
			const std::vector<OpenCLDevice>& getDevices() override;
			cl_context_properties getContextProperties();
		private:
			cl_context_properties m_ContextProperties;
		};

		class OpenCLCommandQueue : public OpenCLExecutionUnit<cl_command_queue> {
		public:
			OpenCLCommandQueue();
			~OpenCLCommandQueue();

			cl_uint getDeviceCount() override;
			cl_uint getCountReferences() override;
			const std::vector<OpenCLDevice>& getDevice() override;
			cl_command_queue_properties getCommandQueueProperties();
		private:
			cl_command_queue_properties m_CommandQueueProperties;
		};

	}

}