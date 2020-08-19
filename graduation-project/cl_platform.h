#ifndef CL_PLATFORM_H
#define CL_PLATFORM_H

#include <CL/cl.h>
#include <vector>
#include <fstream>

namespace gp
{
	struct ExecutionUnit
	{
		cl_kernel KernelID;
		cl_program Program;
		cl_context ContextID;
	};

	struct PlatformInfo
	{
		const char* Name;
		const char* Vendor;
		const char* Profile;
		const char* Version;
	};

	struct DeviceInfo
	{
		const char* Name;
		const char* Vendor;
		const char* Profile;
		const char* Version;
	};

	struct DeviceData
	{
		cl_device_id DeviceID;
		DeviceInfo Info;
		std::vector<ExecutionUnit> ExcUnit;

		DeviceData() : DeviceID(nullptr) {};

		DeviceData(cl_device_id id) :DeviceID(id) {};
	};

	struct PlatformData
	{
		cl_platform_id PlatformID;
		PlatformInfo Info;

		PlatformData() : PlatformID(nullptr) {};

		PlatformData(cl_platform_id id) : PlatformID(id) {};

		std::vector<DeviceData> DevicesStorage;
	};

	/// <summary>
	/// Инициализируем платформы и смежные им устройства
	/// </summary>
	/// <param name="size">[OUT] количество платформ на хосте</param>
	/// <returns>Указатель на PlatfromData, содержая ID платформы и устройства</returns>
	PlatformData* InitPlatformUnit(int& size);

	/// <summary>
	/// Заполняем информацию об платфорем
	/// </summary>
	/// <param name="platfromData">Платформа, для которой необходимо определить информацию</param>
	/// <returns>true если удалось заполнить все поля PlatformInfo, false в противном случае</returns>
	bool FillPlatformInfo(PlatformData*);

	/// <summary>
	/// Выдает имя платформы
	/// </summary>
	/// <param name="id">Константная ссылка на ID платформы</param>
	/// <returns>nullptr случае неудачи или константный указатель на строку типа char</returns>
	const char* GetPlatformName(const cl_platform_id& id);

	/// <summary>
	/// Выдает производителя платформы
	/// </summary>
	/// <param name="id">Константная ссылка на ID платформы</param>
	/// <returns>nullptr случае неудачи или константный указатель на строку типа char</returns>
	const char* GetPlatformVendor(const cl_platform_id& id);

	/// <summary>
	/// Выдает версию платформы
	/// </summary>
	/// <param name="id">Константная ссылка на ID платформы</param>
	/// <returns>nullptr случае неудачи или константный указатель на строку типа char</returns>
	const char* GetPlatformVersion(const cl_platform_id& id);

	/// <summary>
	/// Выдает профиль платформы
	/// </summary>
	/// <param name="id">Константная ссылка на ID платформы</param>
	/// <returns>nullptr случае неудачи или константный указатель на строку типа char</returns>
	const char* GetPlatformProfile(const cl_platform_id& id);

	/// <summary>
	///  Заполняет структуру Info для устройства
	/// </summary>
	/// <param name="deviceData">Указатель на структуру DeviceData</param>
	/// <returns>true если удалось заполнить все поля структуру DeviceInfo, false - в противном случае</returns>
	bool FillDeviceInfo(DeviceData* deviceData);

	/// <summary>
	/// Выдает название устройства
	/// </summary>
	/// <param name="id">Константная ссылка на ID устройства</param>
	/// <returns>Указатель на char, по которому можно обраиться к названию устройства, nullptr - в противном случае</returns>
	const char* GetDeviceName(const cl_device_id& id);

	/// <summary>
	/// Выдает производителя устройства
	/// </summary>
	/// <param name="id">Константная ссылка на ID устройства</param>
	/// <returns>Указатель на char, по которому можно обраиться к имени производителя устройства, nullptr - в противном случае</returns>
	const char* GetDeviceVendor(const cl_device_id& id);

	/// <summary>
	/// Выдает версию устройства
	/// </summary>
	/// <param name="id">Константная ссылка на ID устройства</param>
	/// <returns>Указатель на char, по которому можно обраиться к версии устройства, nullptr - в противном случае</returns>
	const char* GetDeviceVersion(const cl_device_id& id);

	/// <summary>
	/// Выдает профиль устройства (идентичен профилю платформы) 
	/// </summary>
	/// <param name="id">Константная ссылка на ID устройства</param>
	/// <returns>Указатель на char, по которому можно обраиться к профилю устройства, nullptr - в противном случае</returns>
	const char* GetDeviceProfile(const cl_device_id& id);

	bool InititalizeExecutionUnit(DeviceData * deviceData);

	std::string LoadSrc(const char * filename);

	bool CompileOpenCLProgram(const char * src, std::size_t length, ExecutionUnit * excUnit);

	const char * GetCompileError(cl_build_status buildStatus, ExecutionUnit * excUnit);

	cl_context CreateCompatibleContext(cl_device_id deviceID);

	cl_program CreateCompatibleProgram();

	cl_kernel CreateCompatibleKernel();
}

#endif // !CL_PROGRAM_H
