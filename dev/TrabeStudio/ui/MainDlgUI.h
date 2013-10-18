#pragma once


template <class T>
class ATL_NO_VTABLE CMainDlgUI
{
public:              
	enum { IDD = IDD_MAINDLG };

	//-------------------------------------------------------
	//select path
	CStatic m_textPath;
	CListViewCtrl m_listCase, m_listImage;

	void InitUI() throw()
	{
		//-------------------------------------------------------
		//initialize controls
		m_textPath.Attach(GetDlgItem(IDC_TEXT_PATH));
		m_listCase.Attach(GetDlgItem(IDC_LIST_CASE));
		m_listImage.Attach(GetDlgItem(IDC_LIST_IMAGE));

		//-------------------------------------------------------
		

	}
    
    void DumpUI() throw()
	{

	}

};
