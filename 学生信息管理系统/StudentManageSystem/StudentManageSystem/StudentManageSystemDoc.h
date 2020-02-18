
// StudentManageSystemDoc.h : CStudentManageSystemDoc 类的接口
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
protected: // 仅从序列化创建
	CStudentManageSystemDoc();
	DECLARE_DYNCREATE(CStudentManageSystemDoc)

// 特性
public:
	CArray<Student, Student&> students;
	int index=0;
// 操作
public:

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CStudentManageSystemDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
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
