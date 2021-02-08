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
};

BOOL App::InitInstance()
{
    CWinApp::InitInstance();

    auto m_pMainMDIWindow = new gp::app::GraduationProjectMainWindow;

    if (!m_pMainMDIWindow->LoadFrame(IDR_MAINFRAME))
        return FALSE;

    m_pMainWnd = m_pMainMDIWindow;
    
    m_pMainWnd->ShowWindow(SW_RESTORE);
    m_pMainWnd->UpdateWindow();

    return TRUE;
}

App theApp;