#pragma once

#include <string>
#include <CL/cl.h>

namespace gpgpu {

	namespace objects {
	
		template<typename T>
		class IOpenCLObject
		{
		public:
			IOpenCLObject() = default;
			virtual ~IOpenCLObject() = default;

			T getID() { return m_ID; }
		protected:
			
			T m_ID;
		};

	}

}

