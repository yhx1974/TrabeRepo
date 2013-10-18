// MainDlg.h : interface of the CMainDlg class
//
/////////////////////////////////////////////////////////////////////////////

#pragma once

//------------------------------------------------------------------------------
#include "ui\MainDlgUI.h"
//------------------------------------------------------------------------------

class CMainDlg : public CDialogImpl<CMainDlg>, 
				 public CMainDlgUI<CMainDlg>
{
public:
	enum { IDD = IDD_MAINDLG };

	//-------------------------------------------------------
	CStatic m_textPath, m_textBasicInfo, m_textInfo, m_textThick, m_textArea;
	CStatic m_loLimit, m_upLimit, m_loVal, m_upVal;
	CTrackBarCtrl  m_sliderLo, m_sliderUp;
	CListViewCtrl m_listCase, m_listImage;
	CImageList m_ilCase, m_ilImage;
//	CTrabeImageCtrl m_trabeImageCtrl;
	UINT loDiff, upDiff;
	

//	CTrabeData m_imageData;
	int m_nOldImageIndex, m_nOldCaseIndex;	//old index of list view
	ATL::CString m_strCurPath; // current case path

	//-------------------------------------------------------

	BEGIN_MSG_MAP(CMainDlg)
		MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
		COMMAND_ID_HANDLER(ID_APP_ABOUT, OnAppAbout)
		COMMAND_ID_HANDLER(IDOK, OnOK)
		COMMAND_ID_HANDLER(IDCANCEL, OnCancel)
		//-------------------------------------------------------
		COMMAND_HANDLER(IDC_BTN_PATH, BN_CLICKED, OnBtnPathClicked)

		//-------------------------------------------------------
	END_MSG_MAP()

// Handler prototypes (uncomment arguments if needed):
//	LRESULT MessageHandler(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
//	LRESULT CommandHandler(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
//	LRESULT NotifyHandler(int /*idCtrl*/, LPNMHDR /*pnmh*/, BOOL& /*bHandled*/)

	LRESULT OnInitDialog(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
	{
		// center the dialog on the screen
		CenterWindow();

		// set icons
		HICON hIcon = AtlLoadIconImage(IDR_MAINFRAME, LR_DEFAULTCOLOR, ::GetSystemMetrics(SM_CXICON), ::GetSystemMetrics(SM_CYICON));
		SetIcon(hIcon, TRUE);
		HICON hIconSmall = AtlLoadIconImage(IDR_MAINFRAME, LR_DEFAULTCOLOR, ::GetSystemMetrics(SM_CXSMICON), ::GetSystemMetrics(SM_CYSMICON));
		SetIcon(hIconSmall, FALSE);

		//-------------------------------------------------------
		m_textBasicInfo.Attach(GetDlgItem(IDC_TEXT_BASICINFO));
		
		m_textInfo.Attach(GetDlgItem(IDC_TEXT_INFO));
		m_textThick.Attach(GetDlgItem(IDC_STATIC_THICK));
		
		m_textArea.Attach(GetDlgItem(IDC_TEXT_AREA));
		m_loVal.Attach(GetDlgItem(IDC_STATIC_LOVAL));
		m_upVal.Attach(GetDlgItem(IDC_STATIC_UPVAL));

		m_sliderLo.Attach(GetDlgItem(IDC_SLIDER_LO));
		m_loLimit.Attach(GetDlgItem(IDC_STATIC_LOLIMIT));
		m_upLimit.Attach(GetDlgItem(IDC_STATIC_UPLIMIT));
		m_sliderUp.Attach(GetDlgItem(IDC_SLIDER_UP));

		//-------------------------------------------------------

		return TRUE;
	}

	LRESULT OnAppAbout(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
	{
		CSimpleDialog<IDD_ABOUTBOX, FALSE> dlg;
		dlg.DoModal();
		return 0;
	}

	LRESULT OnOK(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
	{
		// TODO: Add validation code 
		EndDialog(wID);
		return 0;
	}

	LRESULT OnCancel(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
	{
		EndDialog(wID);
		return 0;
	}
	//----------------------------------------------------------------------------------------------------
	LRESULT OnBtnPathClicked(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
	{
		CFolderDialog dlg;
		if (dlg.DoModal() == IDOK)
		{
			//m_trabeImageCtrl.Clear_ui();
			GetDlgItem(IDC_BTN_FIT).EnableWindow(FALSE);
			GetDlgItem(IDC_BTN_FIT).SetWindowText(_T("Fit Size"));
			GetDlgItem(IDC_BTN_EXTRACT).EnableWindow(FALSE);
			GetDlgItem(IDC_BTN_AREA).EnableWindow(FALSE);
			GetDlgItem(IDC_BTN_THICK).EnableWindow(FALSE);

//			m_listImage.DeleteAllItems();
//			m_listCase.DeleteAllItems();
			ATL::CString strPath(dlg.m_szFolderPath);
			m_textPath.SetWindowText(strPath);
//			m_strCurPath = strPath;
			CFindFile ff;
			strPath += _T("\\*.*");
			BOOL bContinue = ff.FindFile(strPath);
			while (bContinue)
			{
				if (!ff.IsDots() && ff.IsDirectory())
				{
					m_listCase.InsertItem(m_listCase.GetItemCount(), ff.GetFileName(), 0);
					
				}
				bContinue = ff.FindNextFile();
			}
			
		} 

		return 0;
	}
	//----------------------------------------------------------------------------------------------------
};
