#pragma once

#include <afxwin.h>

#define CL_HPP_ENABLE_EXCEPTIONS
#define CL_HPP_TARGET_OPENCL_VERSION 220

#include <CL/opencl.hpp>

#include "GraduationProjectMainWindow.h"

class App : public CWinApp
{
private:
    gp::app::GraduationProjectMainWindow* m_pMainMDIWnd;

public:

    App(); // конструктор
    virtual BOOL InitInstance();

    afx_msg void OnFileNew();
    DECLARE_MESSAGE_MAP()
    afx_msg void OnMenuCreateNewOpenclWindow();
};

App theApp;