#ifndef CL_PLATFORM_H
#define CL_PLATFORM_H

#pragma once

#include <CL/cl.h>
#include <vector>
#include <string>

namespace gp
{
	class information;
	class device;
	class platform;

	enum type_info : __int32
	{
		/*Common type info*/
		ID_NAME = 0,
		ID_VENDOR = 1,
		ID_VERSION = 2,
		ID_PROFILE = 3,

		/*Platfrom specific type info*/
		ID_PLATFROM_EXTENSIONS = 4,

		/*Device specific type info*/
		ID_DEVICE_DRIVER_VERSION = 5
	};

	class information
	{
		public:
			__stdcall information();
			virtual const std::string& __stdcall get_name();
			virtual const std::string& __stdcall get_vendor();
			virtual const std::string& __stdcall get_version();
			virtual const std::string& __stdcall get_profile();
			virtual void*  __stdcall load_info(type_info type) = 0;
		protected:
			std::string name;
			std::string vendor;
			std::string version;
			std::string profile;
	};
		
	class device : public information
	{
		public:
			device();
			device(cl_device_id devID);
			~device();
			const std::string& __stdcall get_driver_version();
			void * __stdcall load_info(type_info type) override;
	
		private:
			cl_device_id id;
			std::string driver_version;
	};

	class platform : public information
	{
		public:
			platform();
			~platform();
			
			void __stdcall load_device();
			const std::vector<device>& get_devices() const;
// 			const device & get_cpu_device_id() const;
// 			const device & get_gpu_device_id() const;

			const std::string& __stdcall get_extensions();
			void* __stdcall load_info(type_info type) override;
	
		private:
			cl_platform_id		id; 
			cl_uint				count_devices;
			std::vector<device>	devices;	
			std::string extensions;
	};

	class platforom_unit
	{
		public:
			platforom_unit();
			~platforom_unit();

			const std::vector<platform>& get_platforms() const;
			const platform& get_cpu_platforms() const;
			const platform& get_gpu_platforms() const;

		private:
			std::vector<platform> _platforms;
			std::size_t			  _count_platform;
	};
}

#endif // !CL_PROGRAM_H
