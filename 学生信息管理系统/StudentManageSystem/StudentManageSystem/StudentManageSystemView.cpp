
// StudentManageSystemView.cpp : CStudentManageSystemView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CScrollView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CStudentManageSystemView ����/����

CStudentManageSystemView::CStudentManageSystemView()
{
	// TODO: �ڴ˴���ӹ������

}

CStudentManageSystemView::~CStudentManageSystemView()
{
}

BOOL CStudentManageSystemView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CScrollView::PreCreateWindow(cs);
}

// CStudentManageSystemView ����

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
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}

void CStudentManageSystemView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();
	CStudentManageSystemDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CSize sizeTotal,sizePage, sizeLine;
	// TODO: �������ͼ�ĺϼƴ�С
	sizeTotal.cx = 100;
	sizeTotal.cy = ((pDoc->students.GetSize() * 20)>1000) ? (pDoc->students.GetSize() * 20) : 1000;
	RECT rect;
	GetClientRect(&rect); //��ȡ�Ӵ��ڵĴ�С
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


// CStudentManageSystemView ��ӡ

BOOL CStudentManageSystemView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CStudentManageSystemView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CStudentManageSystemView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CStudentManageSystemView ���

#ifdef _DEBUG
void CStudentManageSystemView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CStudentManageSystemView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CStudentManageSystemDoc* CStudentManageSystemView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CStudentManageSystemDoc)));
	return (CStudentManageSystemDoc*)m_pDocument;
}
#endif //_DEBUG


// CStudentManageSystemView ��Ϣ�������


void CStudentManageSystemView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
