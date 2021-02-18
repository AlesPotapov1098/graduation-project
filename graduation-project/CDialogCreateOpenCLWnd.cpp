#include "CDialogCreateOpenCLWnd.h"

namespace gp {
	namespace app {
		namespace dlg {
			IMPLEMENT_DYNAMIC(CDialogCreateOpenCLWnd, CDialog)

				CDialogCreateOpenCLWnd::CDialogCreateOpenCLWnd(CWnd* pParent /*=nullptr*/)
				: CDialog(IDD_DIALOG_CREATE_WINDOW, pParent)
			{

			}

			CDialogCreateOpenCLWnd::~CDialogCreateOpenCLWnd()
			{
			}

			gpgpu::host::OpenCLHost CDialogCreateOpenCLWnd::GetOpenCLHost() const
			{
				return gpgpu::host::OpenCLHost();
			}

			void CDialogCreateOpenCLWnd::DoDataExchange(CDataExchange* pDX)
			{
				CDialog::DoDataExchange(pDX);
			}

			BOOL CDialogCreateOpenCLWnd::OnInitDialog()
			{
				if (!CDialog::OnInitDialog())
					return FALSE;

				if (!m_Connect.Init())
					return FALSE;

				FillInComboPlatforms();
				FillInPlatformPanel();

				FillInComboDevice();
				FillInDevicePanel();

				return TRUE;
			}

			void CDialogCreateOpenCLWnd::OnOK()
			{
				CDialog::OnOK();
			}

			void CDialogCreateOpenCLWnd::OnCancel()
			{
				CDialog::OnCancel();
			}

			void CDialogCreateOpenCLWnd::OnCbnSelchangeComboPlatforms()
			{
				FillInPlatformPanel();
				FillInDevicePanel();
			}

			void CDialogCreateOpenCLWnd::OnCbnSelchangeComboDevice()
			{
				FillInDevicePanel();
			}

			void CDialogCreateOpenCLWnd::FillInComboPlatforms()
			{
				auto comboBox = static_cast<CComboBox*>(
						this->GetDlgItem(IDC_COMBO_PLATFROMS));
				
				int countHard = m_Connect.GetSize();
				gpgpu::OpenCLHardware hard;
				
				for (int i = 0; i < countHard; i++)
				{
					hard = m_Connect.GetHardware(i);
					int countDevs = hard.GetCountDevices();
					
					for (int j = 0; j < countDevs; j++)
					{
						gpgpu::info::OpenCLHostInfo info(
							hard.GetPlatform(), 
							hard.GetDevice(j));
						
						comboBox->AddString(
							info.GetPlatformName().c_str());
					}
				}

				comboBox->SetCurSel(0);
			}

			void CDialogCreateOpenCLWnd::FillInPlatformPanel()
			{
				auto comboBox = static_cast<CComboBox*>(
					this->GetDlgItem(IDC_COMBO_PLATFROMS));

				int CurSell = comboBox->GetCurSel();
				gpgpu::OpenCLHardware hard = m_Connect.GetHardware(CurSell);
				gpgpu::info::OpenCLHostInfo info(
					hard.GetPlatform(),
					hard.GetDevice(0));

				auto editPlatformVendor = static_cast<CEdit*>(
					this->GetDlgItem(IDC_EDIT_PLATFORM_VENDOR));

				editPlatformVendor->SetWindowTextW(
					info.GetPlatformVendor().c_str());

				auto editPlatformVersion = static_cast<CEdit*>(
					this->GetDlgItem(IDC_EDIT_PLATFORM_VERSION));

				editPlatformVersion->SetWindowTextW(
					info.GetPlatformVersion().c_str());

				auto listPlatformExtension = static_cast<CListBox*>(
					this->GetDlgItem(IDC_LIST_PLATFORM_EXTENSIONS));

				std::wstring extension = info.GetPlatformExtensions();
				int length = extension.length();
				for (int i = 0; i < length; i++)
					if (extension[i] == ' ')
						extension[i] = '\n';

				listPlatformExtension->AddString(
					extension.c_str());
			}

			void CDialogCreateOpenCLWnd::FillInComboDevice()
			{
				auto comboBox = static_cast<CComboBox*>(
					this->GetDlgItem(IDC_COMBO_PLATFROMS));

				int curSell = comboBox->GetCurSel();
				gpgpu::OpenCLHardware hard = m_Connect.GetHardware(curSell);
				gpgpu::info::OpenCLHostInfo info;

				auto comboDevices = static_cast<CComboBox*>(
					this->GetDlgItem(IDC_COMBO_DEVICE));
				int countDevs = hard.GetCountDevices();

				for (int i = 0; i < countDevs; i++)
				{
					info.SetDevice(hard.GetDevice(i));
					comboDevices->AddString(
						info.GetDeviceName().c_str());
				}

				comboDevices->SetCurSel(0);
			}

			void CDialogCreateOpenCLWnd::FillInDevicePanel()
			{
				auto comboBox = static_cast<CComboBox*>(
					this->GetDlgItem(IDC_COMBO_PLATFROMS));

				int curSell = comboBox->GetCurSel();
				gpgpu::OpenCLHardware hard = m_Connect.GetHardware(curSell);
				gpgpu::info::OpenCLHostInfo info;

				auto comboDevice = static_cast<CComboBox*>(
					this->GetDlgItem(IDC_COMBO_DEVICE));

				int curSellComboDevices = comboDevice->GetCurSel();
				info.SetDevice(
					hard.GetDevice(curSellComboDevices));

				auto editDeviceVendor = static_cast<CEdit*>(
					this->GetDlgItem(IDC_EDIT_DEVICE_VENDOR));

				editDeviceVendor->SetWindowTextW(
					info.GetDeviceVendor().c_str());

				auto editDeviceVersion = static_cast<CEdit*>(
					this->GetDlgItem(IDC_EDIT_DEVICE_VERSION));

				editDeviceVersion->SetWindowTextW(
					info.GetDeviceVersion().c_str());

				auto listDeviceExtension = static_cast<CListBox*>(
					this->GetDlgItem(IDC_LIST_DEVICE_EXTENSIONS));

				std::wstring extension = info.GetDeviceExtensions();
				int length = extension.length();
				for (int i = 0; i < length; i++)
					if (extension[i] == ' ')
						extension[i] = '\n';

				listDeviceExtension->AddString(
					extension.c_str());
			}

			BEGIN_MESSAGE_MAP(CDialogCreateOpenCLWnd, CDialog)
				ON_CBN_SELCHANGE(IDC_COMBO_PLATFROMS, 
					&CDialogCreateOpenCLWnd::OnCbnSelchangeComboPlatforms)
				
				ON_CBN_SELCHANGE(IDC_COMBO_DEVICE, 
					&CDialogCreateOpenCLWnd::OnCbnSelchangeComboDevice)
			END_MESSAGE_MAP()
		}
	}
}