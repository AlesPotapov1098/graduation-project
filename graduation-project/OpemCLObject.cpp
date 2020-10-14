#include "OpemCLObject.h"

namespace gpgpu {

	namespace objects {

		template<typename T>
		inline OpenCLObject<T>::~OpenCLObject()
		{
		}

		OpenCLPlatform::OpenCLPlatform()
		{
			
		}

		OpenCLPlatform::~OpenCLPlatform()
		{
		}

		const std::string& OpenCLPlatform::getName()
		{
			// TODO: вставьте здесь оператор return
		}

		const std::string& OpenCLPlatform::getVendor()
		{
			// TODO: вставьте здесь оператор return
		}

		const std::string& OpenCLPlatform::getProfile()
		{
			// TODO: вставьте здесь оператор return
		}

		const std::string& OpenCLPlatform::getVersion()
		{
			// TODO: вставьте здесь оператор return
		}
	}
}