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
			// TODO: �������� ����� �������� return
		}

		const std::string& OpenCLPlatform::getVendor()
		{
			// TODO: �������� ����� �������� return
		}

		const std::string& OpenCLPlatform::getProfile()
		{
			// TODO: �������� ����� �������� return
		}

		const std::string& OpenCLPlatform::getVersion()
		{
			// TODO: �������� ����� �������� return
		}
	}
}