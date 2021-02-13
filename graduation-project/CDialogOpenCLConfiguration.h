#pragma once

#include <afxwin.h>

class CDialogOpenCLConfiguration : public CDialog
{
	DECLARE_DYNAMIC(CDialogOpenCLConfiguration)

public:
	CDialogOpenCLConfiguration() noexcept;
	virtual ~CDialogOpenCLConfiguration();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);

	DECLARE_MESSAGE_MAP()
};
