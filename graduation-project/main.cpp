#include "main.h"

BEGIN_MESSAGE_MAP(App, CWinApp)
    
END_MESSAGE_MAP()

using namespace gp::app;

BOOL App::InitInstance()
{
    CWinApp::InitInstance();

    auto m_pMainMDIWindow = new gp::app::GraduationProjectMainWindow(m_hInstance);

    if (!m_pMainMDIWindow->LoadFrame(IDR_MAINFRAME))
        return FALSE;

    m_pMainWnd = m_pMainMDIWindow;
    
    m_pMainWnd->ShowWindow(SW_RESTORE);
    m_pMainWnd->UpdateWindow();

    return TRUE;
}

void App::OnFileNew()
{
}

