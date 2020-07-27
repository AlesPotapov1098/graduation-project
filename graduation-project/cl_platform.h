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

	enum type_info 
	{
		/*Common type info*/
		ID_NAME = 0,
		ID_VENDOR,
		ID_VERSION,
		ID_PROFILE,

		/*Platfrom specific type info*/
		ID_PLATFROM_EXTENSIONS,

		/*Device specific type info*/
		ID_DEVICE_DRIVER_VERSION
	};

	class information
	{
		public:
			__stdcall information();
			virtual const std::string& __stdcall get_name();
			virtual const std::string& __stdcall get_vendor();
			virtual const std::string& __stdcall get_version();
			virtual const std::string& __stdcall get_profile();
		protected:
			template<typename T> T __stdcall load_info(type_info type) {return T(); };
		protected:
			std::string name;
			std::string vendor;
			std::string version;
			std::string profile;
	};
		
	class device : public information
	{
		public:
			__stdcall device();
			__stdcall ~device();
	
		private:
			cl_device_id id;
			
		public:
			const std::string& __stdcall get_driver_version();
			
		protected:
			template<typename T> T __stdcall load_info(type_info type);

		private:
			std::string driver_version;
	};

	class platform : public information
	{
		public:
			__stdcall platform();
			__stdcall ~platform();
			
			void __stdcall load_device();

			const std::string& __stdcall get_extensions();
	
		private:
			cl_platform_id		id; 
			cl_int				count_devices;
			std::vector<device>	device;	

		protected:
			template<typename T> T __stdcall load_info(type_info type);
		private:
			std::string extensions;
	};

	class platforom_loader
	{
		public:
			platforom_loader();
			~platforom_loader();

			const std::vector<platform>& get_platforms() const;
			const platform& get_cpu_platforms() const;
			const platform& get_gpu_platforms() const;

		private:
			std::vector<platform> _platforms;
			std::size_t			  _count_platform;
	};
	









	template<typename T>
	inline T platform::load_info(type_info type)
	{
		cl_uint cl_type_info = 0;

		switch (type)
		{
		case ID_NAME:
			cl_type_info = CL_PLATFORM_NAME;
			break;
		case ID_PROFILE:
			cl_type_info = CL_PLATFORM_PROFILE;
			break;
		case ID_VENDOR:
			cl_type_info = CL_PLATFORM_VENDOR;
			break;
		case ID_VERSION:
			cl_type_info = CL_PLATFORM_VERSION;
			break;
		case ID_PLATFROM_EXTENSIONS:
			cl_type_info = CL_PLATFORM_EXTENSIONS;
			break;
		default:
			cl_type_info = 0;
			break;
		}

		if (cl_type_info == 0) {
			throw std::exception("Bag!!!");
		}

		std::size_t info_size = 0;

		if (clGetPlatformInfo(id, cl_type_info, 0, nullptr, &info_size)) {
			throw std::exception("Bag!!!");
		}

		if (info_size == 0) {
			throw std::exception("Bag!!!");
		}

		T* info = new T[info_size];

		if (clGetPlatformInfo(id, cl_type_info, info_size, info, nullptr)) {
			throw std::exception("Bag!!!");
		}

		return *info;
	}
	
	template<typename T>
	inline T __stdcall device::load_info(type_info type)
	{
		cl_uint cl_type_info = 0;

		switch (type)
		{
		case ID_NAME:
			cl_type_info = CL_DEVICE_NAME;
			break;
		case ID_PROFILE:
			cl_type_info = CL_DEVICE_PROFILE;
			break;
		case ID_VENDOR:
			cl_type_info = CL_DEVICE_VENDOR;
			break;
		case ID_VERSION:
			cl_type_info = CL_DEVICE_VERSION;
			break;
		case ID_DEVICE_DRIVER_VERSION:
			cl_type_info = CL_DEVICE_VENDOR;
			break;
		default:
			cl_type_info = 0;
			break;
		}

		if (cl_type_info == 0) {
			return nullptr;
		}

		std::size_t info_size = 0;

		if (clGetDeviceInfo(id, cl_type_info, 0, nullptr, &info_size)) {
			throw std::exception("Bag!!!");
		}

		if (info_size == 0) {
			throw std::exception("Bag!!!");
		}

		T* info = new T[info_size];

		if (clGetDeviceInfo(id, cl_type_info, info_size, info, nullptr)) {
			throw std::exception("Bag!!!");
		}

		return *info;
	}
}

#endif // !CL_PROGRAM_H
