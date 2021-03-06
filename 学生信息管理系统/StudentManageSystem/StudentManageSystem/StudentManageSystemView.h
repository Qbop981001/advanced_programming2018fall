
// StudentManageSystemView.h : CStudentManageSystemView 类的接口
//

#pragma once


class CStudentManageSystemView : public CScrollView
{
protected: // 仅从序列化创建
	CStudentManageSystemView();
	DECLARE_DYNCREATE(CStudentManageSystemView)

// 特性
public:
	CStudentManageSystemDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 构造后第一次调用
	virtual void OnSize(UINT nType, int cx, int cy);
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CStudentManageSystemView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // StudentManageSystemView.cpp 中的调试版本
inline CStudentManageSystemDoc* CStudentManageSystemView::GetDocument() const
   { return reinterpret_cast<CStudentManageSystemDoc*>(m_pDocument); }
#endif

