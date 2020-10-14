#include "OpemCLObject.h"

namespace gpgpu {

	namespace objects {

		template<typename T>
		inline OpenCLObject<T>::~OpenCLObject()
		{
		}

		OpenCLPlatform::OpenCLPlatform(cl_platform_id id)
		{
			m_ID = id;
		}

		OpenCLPlatform::~OpenCLPlatform()
		{
		}

		const std::string& OpenCLPlatform::getName()
		{
			if (!m_ID)
				return "NONE";

			if (m_Name.empty())
			{
				std::size_t nameSize = 0;
				int error = clGetPlatformInfo(m_ID,	CL_PLATFORM_NAME, 0, nullptr, &nameSize);
				if (error || !nameSize) 
					return "FAIL";

				char * buff = new char[nameSize];

				error = clGetPlatformInfo(m_ID, CL_PLATFORM_NAME, nameSize, (void*)buff, nullptr);
				if (error)
					return "FAIL";

				m_Name = buff;
				delete [] buff;
			}
			
			return m_Name;
		}

		const std::string& OpenCLPlatform::getVendor()
		{
			if (!m_ID)
				return "NONE";

			if (m_Name.empty())
			{
				std::size_t vendorSize = 0;
				int error = clGetPlatformInfo(m_ID, CL_PLATFORM_VENDOR, 0, nullptr, &vendorSize);
				if (error || !vendorSize)
					return "FAIL";

				char* buff = new char[vendorSize];

				error = clGetPlatformInfo(m_ID, CL_PLATFORM_VENDOR, vendorSize, (void*)buff, nullptr);
				if (error)
					return "FAIL";

				m_Vendor = buff;
				delete [] buff;
			}

			return m_Vendor;
		}

		const std::string& OpenCLPlatform::getProfile()
		{
			if (!m_ID)
				return "NONE";

			if (m_Profile.empty())
			{
				std::size_t profileSize = 0;
				int error = clGetPlatformInfo(m_ID, CL_PLATFORM_PROFILE, 0, nullptr, &profileSize);
				if (error || !profileSize)
					return "FAIL";

				char* buff = new char[profileSize];

				error = clGetPlatformInfo(m_ID, CL_PLATFORM_PROFILE, profileSize, (void*)buff, nullptr);
				if (error)
					return "FAIL";

				m_Profile = buff;
				delete [] buff;
			}

			return m_Profile;
		}

		const std::string& OpenCLPlatform::getVersion()
		{
			if (!m_ID)
				return "NONE";

			if (m_Version.empty())
			{
				std::size_t versionSize = 0;
				int error = clGetPlatformInfo(m_ID, CL_PLATFORM_VERSION, 0, nullptr, &versionSize);
				if (error || !versionSize)
					return "FAIL";

				char* buff = new char[versionSize];

				error = clGetPlatformInfo(m_ID, CL_PLATFORM_VERSION, versionSize, (void*)buff, nullptr);
				if (error)
					return "FAIL";

				m_Version = buff;
				delete [] buff;
			}

			return m_Version;
		}
	}
}