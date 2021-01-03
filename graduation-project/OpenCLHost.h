#pragma once

#include <CL/opencl.hpp>

namespace gp {
	namespace gpgpu
	{
		/// <summary>
		/// ���������� ������������� ��� �����
		/// </summary>
		using ID = int;

		/// <summary>
		/// ���������� ������ ��� �������� ���������� � ��������� ���������� ����� �����
		/// </summary>
		struct OpenCLHostHardware
		{
			cl::Platform m_Platform;
			cl::Device   m_Device;
		};

		/// <summary>
		/// ��������� ������ ��� ���������� ������
		/// </summary>
		class OpenCLHost
		{
		public:
			OpenCLHost() = default;
			OpenCLHost(ID, OpenCLHostHardware&&);
			~OpenCLHost();

			ID GetID() const;
			const OpenCLHostHardware& GetHardware() const;

		private:
			OpenCLHostHardware m_Hardware;
			ID m_ID;
		};
	}
}

