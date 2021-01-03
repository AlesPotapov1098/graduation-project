#pragma once

#include <CL/opencl.hpp>

namespace gp {
	namespace gpgpu
	{
		/// <summary>
		/// Уникальный идентификатор для хоста
		/// </summary>
		using ID = int;

		/// <summary>
		/// Струтктура данных для хранения информации и состояния аппартаной части хоста
		/// </summary>
		struct OpenCLHostHardware
		{
			cl::Platform m_Platform;
			cl::Device   m_Device;
		};

		/// <summary>
		/// Структура данных для управления хостом
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

