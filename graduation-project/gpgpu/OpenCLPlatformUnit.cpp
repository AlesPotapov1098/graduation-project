#include "OpenCLPlatformUnit.h"

namespace gpgpu {

	namespace objects {

		template<typename T>
		inline OpenCLPlatformUnit<T>::OpenCLPlatformUnit()
		{

		}

		template<typename T>
		inline OpenCLPlatformUnit<T>::~OpenCLPlatformUnit()
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
				int error = clGetPlatformInfo(m_ID, CL_PLATFORM_NAME, 0, nullptr, &nameSize);
				if (error || !nameSize)
					return "FAIL";

				char* buff = new char[nameSize];

				error = clGetPlatformInfo(m_ID, CL_PLATFORM_NAME, nameSize, (void*)buff, nullptr);
				if (error)
					return "FAIL";

				m_Name = buff;
				delete[] buff;
			}

			return m_Name;
		}

		const std::string& OpenCLPlatform::getVendor()
		{
			if (!m_ID)
				return "NONE";

			if (m_Vendor.empty())
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
				delete[] buff;
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
				delete[] buff;
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
				delete[] buff;
			}

			return m_Version;
		}

		const std::string& OpenCLPlatform::getExtensions()
		{
			if (!m_ID)
				return "NONE";

			if (m_Extensions.empty())
			{
				std::size_t extensionsSize = 0;
				int error = clGetPlatformInfo(m_ID, CL_PLATFORM_EXTENSIONS, 0, nullptr, &extensionsSize);
				if (error || !extensionsSize)
					return "FAIL";

				char* buff = new char[extensionsSize];

				error = clGetPlatformInfo(m_ID, CL_PLATFORM_EXTENSIONS, extensionsSize, buff, nullptr);
				if (error)
					return "FAIL";

				m_Extensions = buff;
				delete[] buff;
			}

			return m_Extensions;
		}

		OpenCLDevice::OpenCLDevice(cl_device_id id)
		{
			m_ID = id;
		}

		OpenCLDevice::~OpenCLDevice()
		{
		}

		const std::string& OpenCLDevice::getName()
		{
			if (!m_ID)
				return "NONE";

			if (m_Name.empty())
			{
				std::size_t nameSize = 0;
				int error = clGetDeviceInfo(m_ID, CL_DEVICE_NAME, 0, nullptr, &nameSize);
				if (error || !nameSize)
					return "FAIL";

				char* buff = new char[nameSize];

				error = clGetDeviceInfo(m_ID, CL_DEVICE_NAME, nameSize, buff, nullptr);

				if (error)
					return "FAIL";

				m_Name = buff;
				delete [] buff;
			}

			return m_Name;
		}

		const std::string& OpenCLDevice::getVendor()
		{
			if (!m_ID)
				return "NONE";

			if (m_Vendor.empty())
			{
				std::size_t vendorSize = 0;
				int error = clGetDeviceInfo(m_ID, CL_DEVICE_VENDOR, 0, nullptr, &vendorSize);
				if (error || !vendorSize)
					return "FAIL";

				char* buff = new char[vendorSize];

				error = clGetDeviceInfo(m_ID, CL_DEVICE_VENDOR, vendorSize, buff, nullptr);
				if (error)
					return "FAIL";

				m_Vendor = buff;
				delete [] buff;
			}

			return m_Vendor;
		}

		const std::string& OpenCLDevice::getProfile()
		{
			if (!m_ID)
				return "NONE";

			if (m_Profile.empty())
			{
				std::size_t profileSize = 0;
				int error = clGetDeviceInfo(m_ID, CL_DEVICE_PROFILE, 0, nullptr, &profileSize);
				if (error || !profileSize)
					return "FAIL";

				char* buff = new char[profileSize];

				error = clGetDeviceInfo(m_ID, CL_DEVICE_PROFILE, profileSize, buff, nullptr);
				if (error)
					return "FAIL";

				m_Profile = buff;
				delete [] buff;
			}

			return m_Profile;
		}

		const std::string& OpenCLDevice::getVersion()
		{
			if (!m_ID)
				return "NONE";

			if (m_Version.empty())
			{
				std::size_t versionSize = 0;
				int error = clGetDeviceInfo(m_ID, CL_DEVICE_VERSION, 0, nullptr, &versionSize);
				if (error || !versionSize)
					return "FAIL";

				char* buff = new char[versionSize];

				error = clGetDeviceInfo(m_ID, CL_DEVICE_VERSION, versionSize, buff, nullptr);
				if (error)
					return "FAIL";

				m_Profile = buff;
				delete [] buff;
			}

			return m_Version;
		}

		const std::string& OpenCLDevice::getExtensions()
		{
			if (!m_ID)
				return "NONE";

			if (m_Extensions.empty())
			{
				std::size_t extensionsSize = 0;
				int error = clGetDeviceInfo(m_ID, CL_DEVICE_EXTENSIONS, 0, nullptr, &extensionsSize);
				if (error || !extensionsSize)
					return "FAIL";

				char* buff = new char[extensionsSize];

				error = clGetDeviceInfo(m_ID, CL_DEVICE_EXTENSIONS, extensionsSize, buff, nullptr);
				if (error)
					return "FAIL";

				m_Extensions = buff;
				delete [] buff;
			}

			return m_Extensions;
		}

	}

}