#pragma once


// CFilename �Ի���

class CFilename : public CDialogEx
{
	DECLARE_DYNAMIC(CFilename)

public:
	CFilename(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CFilename();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_Filename;
};
