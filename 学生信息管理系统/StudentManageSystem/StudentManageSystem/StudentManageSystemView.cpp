
// StudentManageSystemView.cpp : CStudentManageSystemView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "StudentManageSystem.h"
#endif

#include "StudentManageSystemDoc.h"
#include "StudentManageSystemView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CStudentManageSystemView

IMPLEMENT_DYNCREATE(CStudentManageSystemView, CScrollView)

BEGIN_MESSAGE_MAP(CStudentManageSystemView, CScrollView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CScrollView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CStudentManageSystemView 构造/析构

CStudentManageSystemView::CStudentManageSystemView()
{
	// TODO: 在此处添加构造代码

}

CStudentManageSystemView::~CStudentManageSystemView()
{
}

BOOL CStudentManageSystemView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CScrollView::PreCreateWindow(cs);
}

// CStudentManageSystemView 绘制

void CStudentManageSystemView::OnDraw(CDC* pDC)
{
	CStudentManageSystemDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	for (int i = 0; i < pDoc->students.GetSize(); i++) {
		pDC->TextOutW(10, 20 * i, pDoc->students[i].id);
		pDC->TextOutW(110, 20 * i, pDoc->students[i].name);
		pDC->TextOutW(210, 20 * i, pDoc->students[i].sex);
		pDC->TextOutW(310, 20 * i, pDoc->students[i].date);
		pDC->TextOutW(410, 20 * i, pDoc->students[i].origin);
		pDC->TextOutW(510, 20 * i, pDoc->students[i].address);
	}
	if (pDoc->students.GetSize() > 0) {
		CBrush black(RGB(255, 255, 255)), *pblack;
		pblack = pDC->SelectObject(&black);
		pDC->SetROP2(R2_XORPEN);
		pDC->Rectangle(0, pDoc->index * 20, 700, (pDoc->index + 1) * 20);
		pDC->SetROP2(R2_COPYPEN);
		pDC->SelectObject(pblack);
	}
	// TODO: 在此处为本机数据添加绘制代码
}

void CStudentManageSystemView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();
	CStudentManageSystemDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CSize sizeTotal,sizePage, sizeLine;
	// TODO: 计算此视图的合计大小
	sizeTotal.cx = 100;
	sizeTotal.cy = ((pDoc->students.GetSize() * 20)>1000) ? (pDoc->students.GetSize() * 20) : 1000;
	RECT rect;
	GetClientRect(&rect); //获取视窗口的大小
	sizePage.cx = rect.right - rect.left - 10;
	sizePage.cy = rect.bottom - rect.top - 20;
	sizeLine.cx = 10;
	sizeLine.cy = 20;
	SetScrollSizes(MM_TEXT, sizeTotal, sizePage, sizeLine);
	Invalidate();

}
void CStudentManageSystemView::OnSize(UINT nType, int cx, int cy)
{
	CScrollView::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	CStudentManageSystemDoc* pDoc = GetDocument();

	// TODO: calculate the total size of this view
	CSize sizeTotal, sizePage, sizeLine;
	sizeTotal.cx = 100;
	sizeTotal.cy = ((pDoc->students.GetSize() * 20)>1000)? (pDoc->students.GetSize() * 20):1000;
	sizePage.cx = cx - 10;
	sizePage.cy = cy - 20;
	sizeLine.cx = 10;
	sizeLine.cy = 20;

	SetScrollSizes(MM_TEXT, sizeTotal, sizePage, sizeLine);

}


// CStudentManageSystemView 打印

BOOL CStudentManageSystemView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CStudentManageSystemView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CStudentManageSystemView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CStudentManageSystemView 诊断

#ifdef _DEBUG
void CStudentManageSystemView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CStudentManageSystemView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CStudentManageSystemDoc* CStudentManageSystemView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CStudentManageSystemDoc)));
	return (CStudentManageSystemDoc*)m_pDocument;
}
#endif //_DEBUG


// CStudentManageSystemView 消息处理程序


void CStudentManageSystemView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CStudentManageSystemDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (pDoc->students.GetSize() > 0) {
		if (point.y > (pDoc->students.GetSize() * 20))
			pDoc->index = pDoc->index;
		else
			pDoc->index = point.y / 20;
		pDoc->students[pDoc->index].select = 1;
		InvalidateRect(NULL);
	}
	CScrollView::OnLButtonDown(nFlags, point);
}
