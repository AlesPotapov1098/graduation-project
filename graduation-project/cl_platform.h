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
	/// �������������� ��������� � ������� �� ����������
	/// </summary>
	/// <param name="size">[OUT] ���������� �������� �� �����</param>
	/// <returns>��������� �� PlatfromData, �������� ID ��������� � ����������</returns>
	PlatformData* InitPlatformUnit(int& size);

	/// <summary>
	/// ��������� ���������� �� ���������
	/// </summary>
	/// <param name="platfromData">���������, ��� ������� ���������� ���������� ����������</param>
	/// <returns>true ���� ������� ��������� ��� ���� PlatformInfo, false � ��������� ������</returns>
	bool FillPlatformInfo(PlatformData*);

	/// <summary>
	/// ������ ��� ���������
	/// </summary>
	/// <param name="id">����������� ������ �� ID ���������</param>
	/// <returns>nullptr ������ ������� ��� ����������� ��������� �� ������ ���� char</returns>
	const char* GetPlatformName(const cl_platform_id& id);

	/// <summary>
	/// ������ ������������� ���������
	/// </summary>
	/// <param name="id">����������� ������ �� ID ���������</param>
	/// <returns>nullptr ������ ������� ��� ����������� ��������� �� ������ ���� char</returns>
	const char* GetPlatformVendor(const cl_platform_id& id);

	/// <summary>
	/// ������ ������ ���������
	/// </summary>
	/// <param name="id">����������� ������ �� ID ���������</param>
	/// <returns>nullptr ������ ������� ��� ����������� ��������� �� ������ ���� char</returns>
	const char* GetPlatformVersion(const cl_platform_id& id);

	/// <summary>
	/// ������ ������� ���������
	/// </summary>
	/// <param name="id">����������� ������ �� ID ���������</param>
	/// <returns>nullptr ������ ������� ��� ����������� ��������� �� ������ ���� char</returns>
	const char* GetPlatformProfile(const cl_platform_id& id);

	/// <summary>
	///  ��������� ��������� Info ��� ����������
	/// </summary>
	/// <param name="deviceData">��������� �� ��������� DeviceData</param>
	/// <returns>true ���� ������� ��������� ��� ���� ��������� DeviceInfo, false - � ��������� ������</returns>
	bool FillDeviceInfo(DeviceData* deviceData);

	/// <summary>
	/// ������ �������� ����������
	/// </summary>
	/// <param name="id">����������� ������ �� ID ����������</param>
	/// <returns>��������� �� char, �� �������� ����� ��������� � �������� ����������, nullptr - � ��������� ������</returns>
	const char* GetDeviceName(const cl_device_id& id);

	/// <summary>
	/// ������ ������������� ����������
	/// </summary>
	/// <param name="id">����������� ������ �� ID ����������</param>
	/// <returns>��������� �� char, �� �������� ����� ��������� � ����� ������������� ����������, nullptr - � ��������� ������</returns>
	const char* GetDeviceVendor(const cl_device_id& id);

	/// <summary>
	/// ������ ������ ����������
	/// </summary>
	/// <param name="id">����������� ������ �� ID ����������</param>
	/// <returns>��������� �� char, �� �������� ����� ��������� � ������ ����������, nullptr - � ��������� ������</returns>
	const char* GetDeviceVersion(const cl_device_id& id);

	/// <summary>
	/// ������ ������� ���������� (��������� ������� ���������) 
	/// </summary>
	/// <param name="id">����������� ������ �� ID ����������</param>
	/// <returns>��������� �� char, �� �������� ����� ��������� � ������� ����������, nullptr - � ��������� ������</returns>
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
