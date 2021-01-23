#pragma once

#include <afxwin.h>

#define _WIN32_WINNT

#define CL_HPP_ENABLE_EXCEPTIONS
#define CL_HPP_TARGET_OPENCL_VERSION 220

#include <CL/opencl.hpp>

#define _WIN32_WINNT

#include "GraduationProjectMainWindow.h"

class CMyApp : public CWinApp
{
public:
    CMyApp() {}; // конструктор
    virtual BOOL InitInstance() {

        auto m_pMainMDIWindow = new gp::app::GraduationProjectMainWindow;

        if (!m_pMainMDIWindow)
            return FALSE;
        m_pMainWnd = m_pMainMDIWindow;
        m_pMainWnd->ShowWindow(SW_RESTORE);
        m_pMainWnd->UpdateWindow();
        return TRUE;
    }
};

CMyApp theApp;