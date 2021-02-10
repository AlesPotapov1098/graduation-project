#pragma once

#include <afxwin.h>

#define CL_HPP_ENABLE_EXCEPTIONS
#define CL_HPP_TARGET_OPENCL_VERSION 220

#include <CL/opencl.hpp>

#include "GraduationProjectMainWindow.h"

#include "resource.h"

class App : public CWinApp
{
private:
    gp::app::GraduationProjectMainWindow* m_pMainMDIWnd;
public:

    App() noexcept;
    ~App();

    virtual BOOL InitInstance();

    afx_msg void OnMenuCreateNewOpenclWindow();
    afx_msg void OnCreateFromImage();
    
    DECLARE_MESSAGE_MAP()
};

extern App theApp;