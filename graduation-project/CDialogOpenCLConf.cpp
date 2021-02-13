// CDialogOpenCLConf.cpp: файл реализации
//

#include "stdafx.h"
#include "CDialogOpenCLConf.h"
#include "afxdialogex.h"
#include "resource.h"


// Диалоговое окно CDialogOpenCLConf

IMPLEMENT_DYNAMIC(CDialogOpenCLConf, CDialogEx)

CDialogOpenCLConf::CDialogOpenCLConf(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_OPENCL_CONFIGURE, pParent)
{

}

CDialogOpenCLConf::~CDialogOpenCLConf()
{
}

void CDialogOpenCLConf::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDialogOpenCLConf, CDialogEx)
END_MESSAGE_MAP()


// Обработчики сообщений CDialogOpenCLConf
