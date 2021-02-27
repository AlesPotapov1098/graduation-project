#pragma once

#include <afxwin.h>
#include <string>
#include <codecvt>
#include <sstream>
#include <vector>

#include "resource.h"

#include "OpenCLConnection.h"
#include "OpenCLHostInfo.h"

namespace gp {
	namespace app {
		namespace dlg {
			class CDialogCreateOpenCLWnd : public CDialog
			{
				DECLARE_DYNAMIC(CDialogCreateOpenCLWnd)
			private:
				gpgpu::OpenCLConnection m_Connect;
				gpgpu::host::OpenCLHost m_Host;

				bool m_IsConteinsDirectXSharging;

			public:
				CDialogCreateOpenCLWnd(CWnd* pParent = nullptr);
				virtual ~CDialogCreateOpenCLWnd();

				gpgpu::host::OpenCLHost GetOpenCLHost() const;

				bool IsD2D1Khr() const {
					return true;
				}

			protected:
				virtual void DoDataExchange(CDataExchange* pDX);
				afx_msg BOOL OnInitDialog();

				afx_msg void OnOK();
				afx_msg void OnCancel();

				afx_msg void OnCbnSelchangeComboPlatforms();
				afx_msg void OnCbnSelchangeComboDevice();

				void FillInComboPlatforms();
				void FillInPlatformPanel();

				void FillInComboDevice();
				void FillInDevicePanel();

				DECLARE_MESSAGE_MAP()
			};
		}
	}
}

