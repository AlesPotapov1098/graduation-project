#include "main.h"

BEGIN_MESSAGE_MAP(App, CWinAppEx)
    ON_COMMAND(ID_MENU_CREATE_NEW_OPENCL_WINDOW, &App::OnMenuCreateNewOpenclWindow)
    ON_COMMAND(ID_CREATE_FROM_IMAGE, &App::OnCreateFromImage)
    ON_COMMAND(ID_OPENCL_CONFIGURATION, &App::OnOpenclConfiguration)
END_MESSAGE_MAP()

App theApp;

App::App() noexcept
{
    //m_pMainMDIWnd = nullptr;
}

App::~App()
{
}

BOOL App::InitInstance()
{
    CWinApp::InitInstance();

    m_pMainMDIWnd = new gp::app::HologramMainWnd();

    if (!m_pMainMDIWnd || !m_pMainMDIWnd->LoadFrame(IDR_MAINFRAME))
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


void App::OnCreateFromImage()
{
}


void App::OnOpenclConfiguration()
{
    CDialogOpenCLConfiguration OpenCLConfig;
    OpenCLConfig.DoModal();
}
