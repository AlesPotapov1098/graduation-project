#include "main.h"

BEGIN_MESSAGE_MAP(App, CWinApp)
    ON_COMMAND(ID_MENU_CREATE_NEW_OPENCL_WINDOW, &App::OnMenuCreateNewOpenclWindow)
END_MESSAGE_MAP()

App::App()
{
    m_pMainMDIWnd = nullptr;
}

App::~App()
{
}

BOOL App::InitInstance()
{
    CWinApp::InitInstance();

   m_pMainMDIWnd = new gp::app::GraduationProjectMainWindow();

    if (!m_pMainMDIWnd->LoadFrame(IDR_MAINFRAME))
        return FALSE;

    m_pMainWnd = m_pMainMDIWnd;
    
    m_pMainWnd->ShowWindow(SW_RESTORE);
    m_pMainWnd->UpdateWindow();

    return TRUE;
}

void App::OnMenuCreateNewOpenclWindow()
{
    m_pMainMDIWnd->CreateMDIChild();
}
