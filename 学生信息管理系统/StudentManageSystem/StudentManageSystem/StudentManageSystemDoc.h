
// StudentManageSystemDoc.h : CStudentManageSystemDoc ��Ľӿ�
//


#pragma once

struct Student
{
	CString id;
	CString name;
	CString sex;
	CString date;
	CString origin;
	CString address;
	bool select=0;
};


class CStudentManageSystemDoc : public CDocument
{
protected: // �������л�����
	CStudentManageSystemDoc();
	DECLARE_DYNCREATE(CStudentManageSystemDoc)

// ����
public:
	CArray<Student, Student&> students;
	int index=0;
// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CStudentManageSystemDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnAdd();
	afx_msg void OnRevise();
	afx_msg void OnDelete();
	afx_msg void OnSortbyid();
	afx_msg void OnSortbyname();
	afx_msg void OnFileSaveAs();
	afx_msg void OnFileOpen();
};
