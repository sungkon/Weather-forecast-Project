
// DlgProxy.cpp : 구현 파일
//

#include "stdafx.h"
#include "mxl.h"
#include "DlgProxy.h"
#include "mxlDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CmxlDlgAutoProxy

IMPLEMENT_DYNCREATE(CmxlDlgAutoProxy, CCmdTarget)

CmxlDlgAutoProxy::CmxlDlgAutoProxy()
{
	EnableAutomation();
	
	// 자동화 개체가 활성화되어 있는 동안 계속 응용 프로그램을 실행하기 위해 
	//	생성자에서 AfxOleLockApp를 호출합니다.
	AfxOleLockApp();

	// 응용 프로그램의 주 창 포인터를 통해 대화 상자에 대한
	//  액세스를 가져옵니다.  프록시의 내부 포인터를 설정하여
	//  대화 상자를 가리키고 대화 상자의 후방 포인터를 이 프록시로
	//  설정합니다.
	ASSERT_VALID(AfxGetApp()->m_pMainWnd);
	if (AfxGetApp()->m_pMainWnd)
	{
		ASSERT_KINDOF(CmxlDlg, AfxGetApp()->m_pMainWnd);
		if (AfxGetApp()->m_pMainWnd->IsKindOf(RUNTIME_CLASS(CmxlDlg)))
		{
			m_pDialog = reinterpret_cast<CmxlDlg*>(AfxGetApp()->m_pMainWnd);
			m_pDialog->m_pAutoProxy = this;
		}
	}
}

CmxlDlgAutoProxy::~CmxlDlgAutoProxy()
{
	// 모든 개체가 OLE 자동화로 만들어졌을 때 응용 프로그램을 종료하기 위해
	// 	소멸자가 AfxOleUnlockApp를 호출합니다.
	//  이러한 호출로 주 대화 상자가 삭제될 수 있습니다.
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void CmxlDlgAutoProxy::OnFinalRelease()
{
	// 자동화 개체에 대한 마지막 참조가 해제되면
	// OnFinalRelease가 호출됩니다.  기본 클래스에서 자동으로 개체를 삭제합니다.
	// 기본 클래스를 호출하기 전에 개체에 필요한 추가 정리 작업을
	// 추가하십시오.

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CmxlDlgAutoProxy, CCmdTarget)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CmxlDlgAutoProxy, CCmdTarget)
END_DISPATCH_MAP()

// 참고: IID_Imxl에 대한 지원을 추가하여
//  VBA에서 형식 안전 바인딩을 지원합니다.
//  이 IID는 .IDL 파일에 있는 dispinterface의 GUID와 일치해야 합니다.

// {E48FA626-FCAD-4106-A7F3-AD79F860587E}
static const IID IID_Imxl =
{ 0xE48FA626, 0xFCAD, 0x4106, { 0xA7, 0xF3, 0xAD, 0x79, 0xF8, 0x60, 0x58, 0x7E } };

BEGIN_INTERFACE_MAP(CmxlDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CmxlDlgAutoProxy, IID_Imxl, Dispatch)
END_INTERFACE_MAP()

// IMPLEMENT_OLECREATE2 매크로가 이 프로젝트의 StdAfx.h에 정의됩니다.
// {499EAC6E-E52D-4750-99EC-DB0853D183EA}
IMPLEMENT_OLECREATE2(CmxlDlgAutoProxy, "mxl.Application", 0x499eac6e, 0xe52d, 0x4750, 0x99, 0xec, 0xdb, 0x8, 0x53, 0xd1, 0x83, 0xea)


// CmxlDlgAutoProxy 메시지 처리기
