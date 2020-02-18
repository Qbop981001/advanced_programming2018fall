// Filename.cpp : 实现文件
//

#include "stdafx.h"
#include "StudentManageSystem.h"
#include "Filename.h"
#include "afxdialogex.h"


// CFilename 对话框

IMPLEMENT_DYNAMIC(CFilename, CDialogEx)

CFilename::CFilename(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, m_Filename(_T(""))
{

}

CFilename::~CFilename()
{
}

void CFilename::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_Filename);
}


BEGIN_MESSAGE_MAP(CFilename, CDialogEx)
END_MESSAGE_MAP()


// CFilename 消息处理程序
