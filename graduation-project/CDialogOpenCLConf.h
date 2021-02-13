#pragma once


// Диалоговое окно CDialogOpenCLConf

class CDialogOpenCLConf : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogOpenCLConf)

public:
	CDialogOpenCLConf(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~CDialogOpenCLConf();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_OPENCL_CONFIGURE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
};
