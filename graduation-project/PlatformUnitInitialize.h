#pragma once

#include <CL/cl.h>
#include <iostream>

namespace pl
{
	/// <summary>
	/// Инициализируем платформы и смежные им устройства
	/// </summary>
	/// <param name="size">[OUT] количество платформ на хосте</param>
	/// <returns>Указатель на cl_platform_id,nullptr случае неудачи</returns>
	cl_platform_id * __stdcall InitPlatforms(int& size);

	/// <summary>
	/// Инициализируем устройства для конкретной платформы
	/// </summary>
	/// <param name="platformID">Константная ссылка на конкретну платформу, 
	///	для которой необходимо определить устройства</param>
	/// <returns>Указатель на cl_device_id, nullptr в случае неудачи</returns>
	cl_device_id * __stdcall InitDevices(cl_platform_id platformID);

	/// <summary>
	/// Выдает имя платформы
	/// </summary>
	/// <param name="id">Константная ссылка на ID платформы</param>
	/// <returns>nullptr случае неудачи или константный указатель на строку типа char</returns>
	const char* __stdcall GetPlatformName(cl_platform_id id);

	/// <summary>
	/// Выдает производителя платформы
	/// </summary>
	/// <param name="id">Константная ссылка на ID платформы</param>
	/// <returns>nullptr случае неудачи или константный указатель на строку типа char</returns>
	const char* __stdcall GetPlatformVendor(cl_platform_id id);

	/// <summary>
	/// Выдает версию платформы
	/// </summary>
	/// <param name="id">Константная ссылка на ID платформы</param>
	/// <returns>nullptr случае неудачи или константный указатель на строку типа char</returns>
	const char* __stdcall GetPlatformVersion(cl_platform_id id);

	/// <summary>
	/// Выдает профиль платформы
	/// </summary>
	/// <param name="id">Константная ссылка на ID платформы</param>
	/// <returns>nullptr случае неудачи или константный указатель на строку типа char</returns>
	const char* __stdcall GetPlatformProfile(cl_platform_id id);

	/// <summary>
	/// Выдает название устройства
	/// </summary>
	/// <param name="id">Константная ссылка на ID устройства</param>
	/// <returns>Указатель на char, по которому можно обраиться к названию устройства, nullptr - в противном случае</returns>
	const char* __stdcall GetDeviceName(cl_device_id id);

	/// <summary>
	/// Выдает производителя устройства
	/// </summary>
	/// <param name="id">Константная ссылка на ID устройства</param>
	/// <returns>Указатель на char, по которому можно обраиться к имени производителя устройства, nullptr - в противном случае</returns>
	const char* __stdcall GetDeviceVendor(cl_device_id id);

	/// <summary>
	/// Выдает версию устройства
	/// </summary>
	/// <param name="id">Константная ссылка на ID устройства</param>
	/// <returns>Указатель на char, по которому можно обраиться к версии устройства, nullptr - в противном случае</returns>
	const char* __stdcall GetDeviceVersion(cl_device_id id);

	/// <summary>
	/// Выдает профиль устройства (идентичен профилю платформы) 
	/// </summary>
	/// <param name="id">Константная ссылка на ID устройства</param>
	/// <returns>Указатель на char, по которому можно обраиться к профилю устройства, nullptr - в противном случае</returns>
	const char* __stdcall GetDeviceProfile(cl_device_id id);
}