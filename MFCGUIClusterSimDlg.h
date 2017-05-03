
// MFCGUIClusterSimDlg.h : header file
//

#pragma once
#include "Node.h"
#include "Cluster.h"

// CMFCGUIClusterSimDlg dialog
class CMFCGUIClusterSimDlg : public CDialogEx
{
// Construction
public:
	CMFCGUIClusterSimDlg(CWnd* pParent = NULL);	// standard constructor
	int m_OkCount;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCGUICLUSTERSIM_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
	CString FillNodes();
	CString FillSlave();
private:
	CString m_EchoText;
public:
	afx_msg void OnBnClickedBtnAdd();
	afx_msg void OnStnClickedEchoArea();
	afx_msg void OnBnClickedOk();
};
