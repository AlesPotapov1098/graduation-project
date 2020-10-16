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
			virtual ~IOpenCLObject();

			T getID();
		protected:
			
			T m_ID;
		};

		template<typename T>
		class OpenCLPlatformUnit : public IOpenCLObject<T>
		{
		public:

			OpenCLPlatformUnit();
			virtual ~OpenCLPlatformUnit();

			virtual const std::string& getName() = 0;
			virtual const std::string& getVendor() = 0;
			virtual const std::string& getProfile() = 0;
			virtual const std::string& getVersion() = 0;
			virtual const std::string& getExtensions() = 0;
		protected:
			std::string m_Name;
			std::string m_Vendor;
			std::string m_Profile;
			std::string m_Version;
			std::string m_Extensions;

		};

		class OpenCLPlatform : public OpenCLPlatformUnit<cl_platform_id>
		{
		public:
			OpenCLPlatform(cl_platform_id id);
			~OpenCLPlatform();

			const std::string& getName() override;
			const std::string& getVendor() override;
			const std::string& getProfile() override;
			const std::string& getVersion() override;
			const std::string& getExtensions() override;
		};

		class OpenCLDevice : public OpenCLPlatformUnit<cl_platform_id>
		{
		public:
			OpenCLDevice(cl_platform_id id);
			~OpenCLDevice();

			const std::string& getName() override;
			const std::string& getVendor() override;
			const std::string& getProfile() override;
			const std::string& getVersion() override;
			const std::string& getExtensions() override;
		};


	
	}

}

