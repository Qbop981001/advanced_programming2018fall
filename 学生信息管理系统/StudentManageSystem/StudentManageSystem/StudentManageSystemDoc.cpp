
// StudentManageSystemDoc.cpp : CStudentManageSystemDoc 类的实现
//

#include "stdafx.h"
#include "StuDlg.h"
#include "Filename.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "StudentManageSystem.h"
#endif

#include "StudentManageSystemDoc.h"

#include <propkey.h>
#include<afxpriv.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include<stdio.h>
// CStudentManageSystemDoc

IMPLEMENT_DYNCREATE(CStudentManageSystemDoc, CDocument)

BEGIN_MESSAGE_MAP(CStudentManageSystemDoc, CDocument)
	ON_COMMAND(ID_Add, &CStudentManageSystemDoc::OnAdd)
	ON_COMMAND(ID_Revise, &CStudentManageSystemDoc::OnRevise)
	ON_COMMAND(ID_Delete, &CStudentManageSystemDoc::OnDelete)
	ON_COMMAND(ID_SortByID, &CStudentManageSystemDoc::OnSortbyid)
	ON_COMMAND(ID_SortByName, &CStudentManageSystemDoc::OnSortbyname)
	ON_COMMAND(ID_FILE_SAVE_AS, &CStudentManageSystemDoc::OnFileSaveAs)
	ON_COMMAND(ID_FILE_OPEN, &CStudentManageSystemDoc::OnFileOpen)
END_MESSAGE_MAP()


// CStudentManageSystemDoc 构造/析构

CStudentManageSystemDoc::CStudentManageSystemDoc()
{
	// TODO: 在此添加一次性构造代码

}

CStudentManageSystemDoc::~CStudentManageSystemDoc()
{
}

BOOL CStudentManageSystemDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CStudentManageSystemDoc 序列化

void CStudentManageSystemDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CStudentManageSystemDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 搜索处理程序的支持
void CStudentManageSystemDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:     strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void CStudentManageSystemDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CStudentManageSystemDoc 诊断

#ifdef _DEBUG
void CStudentManageSystemDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CStudentManageSystemDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CStudentManageSystemDoc 命令


void CStudentManageSystemDoc::OnAdd()
{
	// TODO: 在此添加命令处理程序代码
	StuDlg add;
	add.DoModal();
	int i;
	Student temp;
	if (add.m_id != "") {
		for (i = 0; students.GetSize(); i++) {
			temp = students.ElementAt(i);
			if (temp.id == add.m_id) { AfxMessageBox(_T("系统中已有相同学号，不能添加!")); return; }
		}
	}
		//	AfxMessageBox(add.m_id+_T(",")+ add.m_name+ _T(",") + add.m_sex + _T(",") + add.m_date + _T(",") + add.m_origin + _T(",")+ add.m_address);
	
	temp.id = add.m_id;
	temp.name = add.m_name;
	temp.sex = add.m_sex;
	temp.date = add.m_date;
	temp.origin = add.m_origin;
	temp.address = add.m_address;
	students.Add(temp);
	index = students.GetSize() - 1;
	UpdateAllViews(NULL);
}



void CStudentManageSystemDoc::OnRevise()
{
	// TODO: 在此添加命令处理程序代码
	StuDlg revise;
	revise.DoModal();
	Student temp;
	if (students.GetSize() <= 0) AfxMessageBox(_T("学生信息为空，不能修改！"));
	else {
		if ((students[index].id != revise.m_id) && (revise.m_id != "")) temp.id = revise.m_id; 
		else temp.id = students[index].id;
		if ((students[index].name != revise.m_name)&&(revise.m_name != ""))temp.name = revise.m_name; 
		else temp.name = students[index].name;
		if ((students[index].sex != revise.m_sex) && (revise.m_sex != ""))temp.sex = revise.m_sex; 
		else temp.sex = students[index].sex;
		if ((students[index].date != revise.m_date) && (revise.m_date != ""))temp.date = revise.m_date; 
		else temp.date = students[index].date;
		if ((students[index].origin != revise.m_origin) && (revise.m_origin != ""))temp.origin = revise.m_origin; 
		else temp.origin = students[index].origin;
		if ((students[index].address != revise.m_address) && (revise.m_address != ""))temp.address = revise.m_address; 
		else temp.address = students[index].address;
		students.SetAtGrow(index, temp);
	}
	UpdateAllViews(NULL);
}


void CStudentManageSystemDoc::OnDelete()
{
	// TODO: 在此添加命令处理程序代码


	students.RemoveAt(index, 1); 
	UpdateAllViews(NULL);
}


void CStudentManageSystemDoc::OnSortbyid()
{
	// TODO: 在此添加命令处理程序代码
	int i, j, k;
	Student t;
	for (i = 0; i < students.GetSize(); i++) {
		for (k = i, j = i + 1; j < students.GetSize(); j++) if (students[j].id < students[k].id)	k = j;
		if (k != i) { t = students[k];	students[k] = students[i];	students[i] = t; }
	}
	
	UpdateAllViews(NULL);
}


void CStudentManageSystemDoc::OnSortbyname()
{
	// TODO: 在此添加命令处理程序代码
	int i, j, k;
	Student t;
	for (i = 0; i < students.GetSize(); i++) {
		for (k = i, j = i + 1; j < students.GetSize(); j++) { 
			USES_CONVERSION; 
			char *s1 = T2A(students[j].name); char *s2 = T2A(students[k].name); if (strcmp(s1,s2) < 0)	k = j; 
		}
		if (k != i) { t = students[k];	students[k] = students[i];	students[i] = t; }
	}
	UpdateAllViews(NULL);
}


void CStudentManageSystemDoc::OnFileSaveAs()
{
	// TODO: 在此添加命令处理程序代码
	
	CFilename input;
	input.DoModal();
	
	CFile fp;
	int i;
	CString filename = input.m_Filename;
//	AfxMessageBox(input.m_Filename);
	fp.Open(filename, CFile::modeWrite | CFile::modeCreate);
	fp.SeekToBegin();
	for (i = 0; i < students.GetSize(); i++) {
		CString temp;
		USES_CONVERSION;
		CString line;
		temp = students[i].id + _T(",") + students[i].name + _T(",") + students[i].sex + _T(",") + students[i].date + _T(",") + students[i].origin + _T(",") + students[i].address+_T(" ");
		char *str = T2A(temp); 
		int size = 0;
		while (str[size] != ' ') {
			size++;
		}
//		AfxMessageBox(A2T(str));
		fp.Write(str, size+1);
		fp.SeekToEnd();
	}
	fp.Close();
}


void CStudentManageSystemDoc::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
	CFilename input;
	input.DoModal();

	CFile fp;
	int i, j, k;
	CString filename = input.m_Filename;
	
	if (!fp.Open(filename, CFile::modeRead)) {
		AfxMessageBox(_T("没有找到文件"));
		return;
	}
	AfxMessageBox(input.m_Filename);
	DWORD len = fp.GetLength();

	char Buf[1000];

	Buf[len] = '\0';  //0终止字符串，用于输出。
	USES_CONVERSION;
	fp.Read(Buf, len);
//	AfxMessageBox(A2T(Buf));
	fp.Close();

	char temp[50];
	
	for (k = 0; k < len; k = i) {
		Student stu;
		for (i = k, j = 0; i < len; i++, j++) {
			if ((Buf[i] != ',') && (Buf[i] != ' ')) temp[j] = Buf[i];
			else { temp[j] = '\0';	stu.id = A2T(temp); i++; break; }
		}
		for (j = 0; i < len; i++, j++) {
			if ((Buf[i] != ',') && (Buf[i] != ' ')) temp[j] = Buf[i];
			else { temp[j] = '\0';	stu.name = A2T(temp); i++; break; }
		}
		for (j = 0; i < len; i++, j++) {
			if ((Buf[i] != ',') && (Buf[i] != ' ')) temp[j] = Buf[i];
			else { temp[j] = '\0';	stu.sex = A2T(temp); i++; break; }
		}
		for (j = 0; i < len; i++, j++) {
			if ((Buf[i] != ',') && (Buf[i] != ' ')) temp[j] = Buf[i];
			else { temp[j] = '\0';	stu.date = A2T(temp); i++; break; }
		}
		for (j = 0; i < len; i++, j++) {
			if ((Buf[i] != ',') && (Buf[i] != ' ')) temp[j] = Buf[i];
			else { temp[j] = '\0';	stu.origin = A2T(temp); i++; break; }
		}
		for (j = 0; i < len; i++, j++) {
			if ((Buf[i] != ',') && (Buf[i] != ' ')) temp[j] = Buf[i];
			else { temp[j] = '\0';	stu.address = A2T(temp); i++; break; }
		}
		students.Add(stu);
	}
	UpdateAllViews(NULL);
}
