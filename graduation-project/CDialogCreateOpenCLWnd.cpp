#include "CDialogCreateOpenCLWnd.h"

#include <algorithm>
#include <iostream>

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
				return m_Host;
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
				int nPlatform = \
					static_cast<CComboBox*>(this->GetDlgItem(IDC_COMBO_PLATFROMS))->GetCurSel();
				int nDevice = \
					static_cast<CComboBox*>(this->GetDlgItem(IDC_COMBO_DEVICE))->GetCurSel();
				auto hard = m_Connect.GetHardware(nPlatform);
				m_Host.SetPlatform(hard.GetPlatform());
				m_Host.SetDevice(hard.GetDevice(nDevice));

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
				auto comboBox = static_cast<CComboBox*>(this->GetDlgItem(IDC_COMBO_PLATFROMS));
				ASSERT(comboBox != nullptr);

				if (comboBox->GetCount() != 0)
					comboBox->ResetContent();
				
				int countHard = m_Connect.GetSize();
				gpgpu::OpenCLHardware hard;
				
				for (int i = 0; i < countHard; i++)
				{
					hard = m_Connect.GetHardware(i);
					int countDevs = hard.GetCountDevices();
					
					for (int j = 0; j < countDevs; j++)
					{
						gpgpu::info::OpenCLHostInfo info(hard.GetPlatform(), hard.GetDevice(j));
						
						comboBox->AddString(info.GetPlatformName().c_str());
					}
				}

				comboBox->SetCurSel(0);
			}

			void CDialogCreateOpenCLWnd::FillInPlatformPanel()
			{
				auto comboBox = static_cast<CComboBox*>(this->GetDlgItem(IDC_COMBO_PLATFROMS));

				int CurSell = comboBox->GetCurSel();
				gpgpu::OpenCLHardware hard = m_Connect.GetHardware(CurSell);
				gpgpu::info::OpenCLHostInfo info(
					hard.GetPlatform(),
					hard.GetDevice(0));

				auto editPlatformVendor = \
					static_cast<CEdit*>(this->GetDlgItem(IDC_EDIT_PLATFORM_VENDOR));
				editPlatformVendor->SetWindowTextW(info.GetPlatformVendor().c_str());

				auto editPlatformVersion = \
					static_cast<CEdit*>(this->GetDlgItem(IDC_EDIT_PLATFORM_VERSION));
				editPlatformVersion->SetWindowTextW(info.GetPlatformVersion().c_str());

				auto listPlatformExtension = \
					static_cast<CListBox*>(this->GetDlgItem(IDC_LIST_PLATFORM_EXTENSIONS));

				std::wstring extension = info.GetPlatformExtensions();

				FillListBox(listPlatformExtension, extension);
			}

			void CDialogCreateOpenCLWnd::FillInComboDevice()
			{
				auto comboBox = \
					static_cast<CComboBox*>(this->GetDlgItem(IDC_COMBO_PLATFROMS));

				int curSell = comboBox->GetCurSel();
				gpgpu::OpenCLHardware hard = m_Connect.GetHardware(curSell);
				gpgpu::info::OpenCLHostInfo info;

				auto comboDevices = \
					static_cast<CComboBox*>(this->GetDlgItem(IDC_COMBO_DEVICE));
				int countDevs = hard.GetCountDevices();

				for (int i = 0; i < countDevs; i++)
				{
					info.SetDevice(hard.GetDevice(i));
					comboDevices->AddString(info.GetDeviceName().c_str());
				}

				comboDevices->SetCurSel(0);
			}

			void CDialogCreateOpenCLWnd::FillInDevicePanel()
			{
				auto comboBox = \
					static_cast<CComboBox*>(this->GetDlgItem(IDC_COMBO_PLATFROMS));

				int curSell = comboBox->GetCurSel();
				gpgpu::OpenCLHardware hard = m_Connect.GetHardware(curSell);
				gpgpu::info::OpenCLHostInfo info;

				auto comboDevice = \
					static_cast<CComboBox*>(this->GetDlgItem(IDC_COMBO_DEVICE));

				int curSellComboDevices = comboDevice->GetCurSel();
				info.SetDevice(hard.GetDevice(curSellComboDevices));

				auto editDeviceVendor = \
					static_cast<CEdit*>(this->GetDlgItem(IDC_EDIT_DEVICE_VENDOR));
				editDeviceVendor->SetWindowTextW(info.GetDeviceVendor().c_str());

				auto editDeviceVersion = \
					static_cast<CEdit*>(this->GetDlgItem(IDC_EDIT_DEVICE_VERSION));
				editDeviceVersion->SetWindowTextW(info.GetDeviceVersion().c_str());

				auto listDeviceExtension = \
					static_cast<CListBox*>(this->GetDlgItem(IDC_LIST_DEVICE_EXTENSIONS));
				
				std::wstring extension = info.GetDeviceExtensions();
				
				FillListBox(listDeviceExtension, extension);
			}

			void CDialogCreateOpenCLWnd::FillListBox(CListBox * listBox, const std::wstring& str)
			{
				ASSERT(listBox != nullptr);
				if (str.empty())
					return;

				if (listBox->GetCount() != 0)
					listBox->ResetContent();

				int length = str.length();
				size_t pos = str.find(L' ');
				size_t initPos = 0;

				while (pos != std::wstring::npos)
				{
					listBox->AddString(str.substr(initPos, pos - initPos).c_str());
					initPos = pos + 1;

					pos = str.find(L' ', initPos);
				}

				// TODO: починить добавление последней строки
				listBox->AddString(
					str.substr(initPos, pos < str.size() ? pos : str.size() - initPos + 1).c_str());
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