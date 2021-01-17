#include "OpenCLConnection.h"

gp::gpgpu::OpenCLConnection::OpenCLConnection()
{
    m_CountPlatfroms = 0;
    m_CountDevices = 0;
}

gp::gpgpu::OpenCLConnection::~OpenCLConnection()
{
}

bool gp::gpgpu::OpenCLConnection::Init()
{
    cl::Platform::get(&m_Platfroms);
    m_CountPlatfroms = m_Platfroms.size();

    for (auto& pl : m_Platfroms)
    {
        devices devs;
        pl.getDevices(CL_DEVICE_TYPE_ALL, &devs);

        if (devs.empty())
            break;

        m_Devices.push_back(devs);
        m_CountDevices += devs.size();
    }

    return m_CountPlatfroms == 0 && m_CountDevices == 0;
}
