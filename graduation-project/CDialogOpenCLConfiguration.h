#pragma once

#include <afxwin.h>

#include "OpenCLConnection.h"

class CDialogOpenCLConfiguration : public CDialog
{
	DECLARE_DYNAMIC(CDialogOpenCLConfiguration)

private:
	const gp::gpgpu::OpenCLInfo * m_OpenCLInfoStruct;
		
public:
	CDialogOpenCLConfiguration(gp::gpgpu::OpenCLInfo*) noexcept;
	virtual ~CDialogOpenCLConfiguration();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);
	
	afx_msg BOOL OnInitDialog();
	
	DECLARE_MESSAGE_MAP()
};
