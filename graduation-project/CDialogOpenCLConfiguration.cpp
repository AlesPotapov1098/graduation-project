#include "CDialogOpenCLConfiguration.h"
#include "stdafx.h"
#include "resource.h"

IMPLEMENT_DYNAMIC(CDialogOpenCLConfiguration, CDialog)

CDialogOpenCLConfiguration::CDialogOpenCLConfiguration(gp::gpgpu::OpenCLInfo* info) noexcept 
	: CDialog(IDD_OPENCL_CONFIG)
{
	m_OpenCLInfoStruct = info;
}

CDialogOpenCLConfiguration::~CDialogOpenCLConfiguration()
{
}

void CDialogOpenCLConfiguration::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BOOL CDialogOpenCLConfiguration::OnInitDialog()
{
	return CDialog::OnInitDialog();
}

BEGIN_MESSAGE_MAP(CDialogOpenCLConfiguration, CDialog)
END_MESSAGE_MAP()
