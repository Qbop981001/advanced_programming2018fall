
// StudentManageSystem.h : StudentManageSystem Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CStudentManageSystemApp:
// �йش����ʵ�֣������ StudentManageSystem.cpp
//

class CStudentManageSystemApp : public CWinApp
{
public:
	CStudentManageSystemApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CStudentManageSystemApp theApp;
