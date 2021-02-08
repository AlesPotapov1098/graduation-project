#pragma once

#include <afxwin.h>

#define CL_HPP_ENABLE_EXCEPTIONS
#define CL_HPP_TARGET_OPENCL_VERSION 220

#include <CL/opencl.hpp>

#include "GraduationProjectMainWindow.h"

class App : public CWinApp
{
public:
    App() {}; // конструктор
    virtual BOOL InitInstance();

public:
    afx_msg void OnFileNew();
    DECLARE_MESSAGE_MAP()
};

App theApp;