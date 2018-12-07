
// mxlDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "mxl.h"
#include "mxlDlg.h"
#include "DlgProxy.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();
//	static UINT ThreadFirst(LPVOID _mothod);
	

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CmxlDlg ��ȭ ����


IMPLEMENT_DYNAMIC(CmxlDlg, CDialogEx);

CmxlDlg::CmxlDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CmxlDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pAutoProxy = NULL;
}

CmxlDlg::~CmxlDlg()
{
	// �� ��ȭ ���ڿ� ���� �ڵ�ȭ ���Ͻð� ���� ��� �� ��ȭ ���ڿ� ����
	//  �Ĺ� �����͸� NULL�� �����Ͽ�
	//  ��ȭ ���ڰ� �����Ǿ����� �� �� �ְ� �մϴ�.
	if (m_pAutoProxy != NULL)
		m_pAutoProxy->m_pDialog = NULL;
}

void CmxlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICVIEW, maps);
}

BEGIN_MESSAGE_MAP(CmxlDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_CLOSE()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CmxlDlg �޽��� ó����

BOOL CmxlDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CmxlDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CmxlDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		CDC memDC;
		memDC.CreateCompatibleDC(maps.GetDC());
		CBitmap	bitmap;
		bitmap.LoadBitmap(IDB_BITMAP1);
		memDC.SelectObject(&bitmap);

		CStatic *staticSize = (CStatic*)GetDlgItem(IDC_PICVIEW);
		CRect RECT;
		staticSize->GetClientRect(rect);
		int iwidth = rect.Width();
		int iheight = rect.Height();
		maps.GetDC()->StretchBlt(0, 0, iwidth, iheight, &memDC, 0, 0, 149, 220, SRCCOPY);
		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CmxlDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// ��Ʈ�ѷ����� �ش� ��ü �� �ϳ��� ��� ����ϰ� ���� ���
//  ����ڰ� UI�� ���� �� �ڵ�ȭ ������ �����ϸ� �� �˴ϴ�.  �̵�
//  �޽��� ó����� ���Ͻð� ���� ��� ���� ��� UI�� ��������,
//  UI�� ǥ�õ��� �ʾƵ� ��ȭ ���ڴ�
//  ���� �Ӵϴ�.

void CmxlDlg::OnClose()
{
	if (CanExit())
		CDialogEx::OnClose();
}
/*
UINT ThreadFirst(LPVOID inval)
{
	int val = (int)inval;

	MSXML2::IXMLDOMDocument2Ptr pDoc;

	MSXML2::IXMLDOMNodeListPtr pNodeList;
	pDoc.CreateInstance(__uuidof(MSXML2::DOMDocument));

	DWORD startTick = GetTickCount();
	pDoc->put_async(VARIANT_FALSE);

	HRESULT hr = pDoc->load((_variant_t)"http://www.kma.go.kr/wid/queryDFSRSS.jsp?zone=1159068000");

	pNodeList = pDoc->selectNodes(L"//data ");

	CString outTotalString;
	CStringArray array;
	array.SetSize(160);
	for (int i = 0; i < 8; i++)
	{
		CString outString;
		outString.Format(_T("���� %s, ��尪 %s\n"), (LPCTSTR)pNodeList->Getitem(i)->GetnodeName(), (LPCTSTR)pNodeList->Getitem(i)->Gettext());

		outTotalString.Append(outString);
		array[i] = outString;
	}
	AfxMessageBox(array[0]);
	//	Sleep(1000);2
	return 0;
}
*/

UINT ThreadFirst(LPVOID inval)
{
	CoInitializeEx(NULL, COINIT_MULTITHREADED);
	MSXML2::IXMLDOMDocument2Ptr pDoc;

	MSXML2::IXMLDOMNodeListPtr pNodeList;
	pDoc.CreateInstance(__uuidof(MSXML2::DOMDocument));

	DWORD startTick = GetTickCount();
	pDoc->put_async(VARIANT_FALSE);

	HRESULT hr = pDoc->load((_variant_t)"http://www.kma.go.kr/wid/queryDFSRSS.jsp?zone=1159068000");

	CString outTotalString;
	CStringArray array;
	array.SetSize(160);
	for (int i = 0; i < 3; i++)
	{
		CString outString;
		
		pNodeList = pDoc->selectNodes(L"//hour");
		outString.Format(_T("%s\n"), (LPCTSTR)pNodeList->Getitem(i*8)->Gettext());
		outTotalString.Append(outString);
		array[i*8] = outString;
		pNodeList = pDoc->selectNodes(L"//temp");
		outString.Format(_T("%s\n"), (LPCTSTR)pNodeList->Getitem(i*8)->Gettext());
		outTotalString.Append(outString);
		array[i * 8+1] = outString;
		pNodeList = pDoc->selectNodes(L"//sky");
		outString.Format(_T("%s\n"), (LPCTSTR)pNodeList->Getitem(i * 8)->Gettext());
		outTotalString.Append(outString);
		array[i * 8+2] = outString;
		pNodeList = pDoc->selectNodes(L"//pty");
		outString.Format(_T("%s\n"), (LPCTSTR)pNodeList->Getitem(i * 8)->Gettext());
		outTotalString.Append(outString);
		array[i * 8+3] = outString;
		pNodeList = pDoc->selectNodes(L"//pop");
		outString.Format(_T("%s\n"), (LPCTSTR)pNodeList->Getitem(i * 8)->Gettext());
		outTotalString.Append(outString);
		array[i * 8+4] = outString;
		pNodeList = pDoc->selectNodes(L"//r12");
		outString.Format(_T("%s\n"), (LPCTSTR)pNodeList->Getitem(i * 8)->Gettext());
		outTotalString.Append(outString);
		array[i * 8+5] = outString;
		pNodeList = pDoc->selectNodes(L"//s12");
		outString.Format(_T("%s\n"), (LPCTSTR)pNodeList->Getitem(i * 8)->Gettext());
		outTotalString.Append(outString);
		array[i * 8+6] = outString;
		pNodeList = pDoc->selectNodes(L"//reh");
		outString.Format(_T("%s\n"), (LPCTSTR)pNodeList->Getitem(i * 8)->Gettext());
		outTotalString.Append(outString);
		array[i * 8+7] = outString;
	}


	AfxMessageBox(array[23]);

	return 0;
}


void CmxlDlg::OnOK()
{

	AfxBeginThread(ThreadFirst, this);

}


void CmxlDlg::OnCancel()
{
	if (CanExit())
		CDialogEx::OnCancel();
}

BOOL CmxlDlg::CanExit()
{
	// ���Ͻ� ��ü�� ��� ���� ������ �ڵ�ȭ ��Ʈ�ѷ�������
	//  �� ���� ���α׷��� ��� ����մϴ�.  ��ȭ ���ڴ� ���� ������
	//  �ش� UI�� ����ϴ�.
	if (m_pAutoProxy != NULL)
	{
		ShowWindow(SW_HIDE);
		return FALSE;
	}

	return TRUE;
}

