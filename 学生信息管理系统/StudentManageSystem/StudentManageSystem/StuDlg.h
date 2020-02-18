#pragma once


// StuDlg 对话框

class StuDlg : public CDialogEx
{
	DECLARE_DYNAMIC(StuDlg)

public:
	StuDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~StuDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_id;
	afx_msg void OnLbnSelchangeList1();
	CString m_name;
	CString m_sex;
	CString m_date;
	CString m_origin;
	CString m_address;
};
