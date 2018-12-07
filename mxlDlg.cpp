
// mxlDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "mxl.h"
#include "mxlDlg.h"
#include "DlgProxy.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();
//	static UINT ThreadFirst(LPVOID _mothod);
	

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CmxlDlg 대화 상자


IMPLEMENT_DYNAMIC(CmxlDlg, CDialogEx);

CmxlDlg::CmxlDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CmxlDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pAutoProxy = NULL;
}

CmxlDlg::~CmxlDlg()
{
	// 이 대화 상자에 대한 자동화 프록시가 있을 경우 이 대화 상자에 대한
	//  후방 포인터를 NULL로 설정하여
	//  대화 상자가 삭제되었음을 알 수 있게 합니다.
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


// CmxlDlg 메시지 처리기

BOOL CmxlDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CmxlDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
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
		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CmxlDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// 컨트롤러에서 해당 개체 중 하나를 계속 사용하고 있을 경우
//  사용자가 UI를 닫을 때 자동화 서버를 종료하면 안 됩니다.  이들
//  메시지 처리기는 프록시가 아직 사용 중인 경우 UI는 숨기지만,
//  UI가 표시되지 않아도 대화 상자는
//  남겨 둡니다.

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
		outString.Format(_T("노드명 %s, 노드값 %s\n"), (LPCTSTR)pNodeList->Getitem(i)->GetnodeName(), (LPCTSTR)pNodeList->Getitem(i)->Gettext());

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
	// 프록시 개체가 계속 남아 있으면 자동화 컨트롤러에서는
	//  이 응용 프로그램을 계속 사용합니다.  대화 상자는 남겨 두지만
	//  해당 UI는 숨깁니다.
	if (m_pAutoProxy != NULL)
	{
		ShowWindow(SW_HIDE);
		return FALSE;
	}

	return TRUE;
}

