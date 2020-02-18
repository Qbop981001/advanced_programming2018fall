// StuDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "StudentManageSystem.h"
#include "StuDlg.h"
#include "afxdialogex.h"


// StuDlg 对话框

IMPLEMENT_DYNAMIC(StuDlg, CDialogEx)

StuDlg::StuDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_id(_T(""))
	, m_name(_T(""))
	, m_sex(_T(""))
	, m_date(_T(""))
	, m_origin(_T(""))
	, m_address(_T(""))
{

}

StuDlg::~StuDlg()
{
}

void StuDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_id);
	DDX_Text(pDX, IDC_EDIT2, m_name);
	DDX_CBString(pDX, IDC_COMBO2, m_sex);
	DDX_Text(pDX, IDC_EDIT6, m_date);
	DDX_Text(pDX, IDC_EDIT7, m_origin);
	DDX_Text(pDX, IDC_EDIT5, m_address);
}


BEGIN_MESSAGE_MAP(StuDlg, CDialogEx)
//ON_LBN_SELCHANGE(IDC_LIST1, &StuDlg::OnLbnSelchangeList1)
END_MESSAGE_MAP()
//{
	// TODO: 在此添加控件通知处理程序代码
//}

// StuDlg 消息处理程序




