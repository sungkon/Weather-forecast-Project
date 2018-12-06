
// mxlDlg.h : 헤더 파일
//

#pragma once

class CmxlDlgAutoProxy;


// CmxlDlg 대화 상자
class CmxlDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CmxlDlg);
	friend class CmxlDlgAutoProxy;

// 생성입니다.
public:
	CmxlDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.
	virtual ~CmxlDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_MXL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	CmxlDlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();



	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	virtual void OnOK();
	virtual void OnCancel();
	DECLARE_MESSAGE_MAP()
};
