#pragma once

#include <iostream>

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

    App(); 
    virtual ~App();

    virtual BOOL InitInstance();

    afx_msg void OnMenuCreateNewOpenclWindow();
    
    
    DECLARE_MESSAGE_MAP()
};

App theApp;