#pragma once

#include <CL/cl.h>
#include <iostream>

namespace pl
{
	/// <summary>
	/// �������������� ��������� � ������� �� ����������
	/// </summary>
	/// <param name="size">[OUT] ���������� �������� �� �����</param>
	/// <returns>��������� �� cl_platform_id,nullptr ������ �������</returns>
	cl_platform_id * __stdcall InitPlatforms(int& size);

	/// <summary>
	/// �������������� ���������� ��� ���������� ���������
	/// </summary>
	/// <param name="platformID">����������� ������ �� ��������� ���������, 
	///	��� ������� ���������� ���������� ����������</param>
	/// <returns>��������� �� cl_device_id, nullptr � ������ �������</returns>
	cl_device_id * __stdcall InitDevices(cl_platform_id platformID);

	/// <summary>
	/// ������ ��� ���������
	/// </summary>
	/// <param name="id">����������� ������ �� ID ���������</param>
	/// <returns>nullptr ������ ������� ��� ����������� ��������� �� ������ ���� char</returns>
	const char* __stdcall GetPlatformName(cl_platform_id id);

	/// <summary>
	/// ������ ������������� ���������
	/// </summary>
	/// <param name="id">����������� ������ �� ID ���������</param>
	/// <returns>nullptr ������ ������� ��� ����������� ��������� �� ������ ���� char</returns>
	const char* __stdcall GetPlatformVendor(cl_platform_id id);

	/// <summary>
	/// ������ ������ ���������
	/// </summary>
	/// <param name="id">����������� ������ �� ID ���������</param>
	/// <returns>nullptr ������ ������� ��� ����������� ��������� �� ������ ���� char</returns>
	const char* __stdcall GetPlatformVersion(cl_platform_id id);

	/// <summary>
	/// ������ ������� ���������
	/// </summary>
	/// <param name="id">����������� ������ �� ID ���������</param>
	/// <returns>nullptr ������ ������� ��� ����������� ��������� �� ������ ���� char</returns>
	const char* __stdcall GetPlatformProfile(cl_platform_id id);

	/// <summary>
	/// ������ �������� ����������
	/// </summary>
	/// <param name="id">����������� ������ �� ID ����������</param>
	/// <returns>��������� �� char, �� �������� ����� ��������� � �������� ����������, nullptr - � ��������� ������</returns>
	const char* __stdcall GetDeviceName(cl_device_id id);

	/// <summary>
	/// ������ ������������� ����������
	/// </summary>
	/// <param name="id">����������� ������ �� ID ����������</param>
	/// <returns>��������� �� char, �� �������� ����� ��������� � ����� ������������� ����������, nullptr - � ��������� ������</returns>
	const char* __stdcall GetDeviceVendor(cl_device_id id);

	/// <summary>
	/// ������ ������ ����������
	/// </summary>
	/// <param name="id">����������� ������ �� ID ����������</param>
	/// <returns>��������� �� char, �� �������� ����� ��������� � ������ ����������, nullptr - � ��������� ������</returns>
	const char* __stdcall GetDeviceVersion(cl_device_id id);

	/// <summary>
	/// ������ ������� ���������� (��������� ������� ���������) 
	/// </summary>
	/// <param name="id">����������� ������ �� ID ����������</param>
	/// <returns>��������� �� char, �� �������� ����� ��������� � ������� ����������, nullptr - � ��������� ������</returns>
	const char* __stdcall GetDeviceProfile(cl_device_id id);
}