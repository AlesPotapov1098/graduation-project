#pragma once

#include <string>
#include <CL/cl.h>

namespace gpgpu {

	namespace objects {
	
		template<typename T>
		class OpenCLObject
		{
		public:
			OpenCLObject() = default;
			virtual ~OpenCLObject();

			virtual const std::string& getName() = 0;
			virtual const std::string& getVendor() = 0;
			virtual const std::string& getProfile() = 0;
			virtual const std::string& getVersion() = 0;
			T getID();
		protected:
			std::string m_Name;
			std::string m_Vendor;
			std::string m_Profile;
			std::string m_Version;
			T m_ID;
		};

		class OpenCLPlatform : public OpenCLObject<cl_platform_id>
		{
		public:
			OpenCLPlatform(cl_platform_id id);
			~OpenCLPlatform();

			const std::string& getName() override;
			const std::string& getVendor() override;
			const std::string& getProfile() override;
			const std::string& getVersion() override;
		};

		

	}

}

