#pragma once

#include <afxwin.h>

#include "OpenCLConnection.h"

class CDialogOpenCLConfiguration : public CDialog
{
	DECLARE_DYNAMIC(CDialogOpenCLConfiguration)

private:
		
public:
	CDialogOpenCLConfiguration() noexcept;
	virtual ~CDialogOpenCLConfiguration();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);
	
	afx_msg BOOL OnInitDialog();
	
	DECLARE_MESSAGE_MAP()
public:
	
};
