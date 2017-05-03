
// MFCGUIClusterSimDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCGUIClusterSim.h"
#include "MFCGUIClusterSimDlg.h"
#include "afxdialogex.h"
#include "AddNodeFrame.h"
#include <String>
#include <Windows.h>
#include <wingdi.h>
#include <cstring>
#include <vector>


using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();
	

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCGUIClusterSimDlg dialog



CMFCGUIClusterSimDlg::CMFCGUIClusterSimDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCGUICLUSTERSIM_DIALOG, pParent)
	, m_EchoText(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCGUIClusterSimDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_ECHO_AREA, m_EchoText);
}

BEGIN_MESSAGE_MAP(CMFCGUIClusterSimDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT1, &CMFCGUIClusterSimDlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &CMFCGUIClusterSimDlg::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BTN_ADD, &CMFCGUIClusterSimDlg::OnBnClickedBtnAdd)
	ON_STN_CLICKED(IDC_ECHO_AREA, &CMFCGUIClusterSimDlg::OnStnClickedEchoArea)
	ON_BN_CLICKED(IDOK, &CMFCGUIClusterSimDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CMFCGUIClusterSimDlg message handlers

BOOL CMFCGUIClusterSimDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	
	


	//Print to screen
	CString text = FillNodes();
	SetDlgItemText(IDC_EDIT1, /*(CString)"test"*/text);

	//moved to Add button click
	//CString slave = FillSlave();
	//SetDlgItemText(IDC_EDIT2, /*(CString)"test2"*/slave);

	m_OkCount = 0;//test For Button

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCGUIClusterSimDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCGUIClusterSimDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCGUIClusterSimDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMFCGUIClusterSimDlg::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	// TODO:  Add your control notification handler code here
}

void CMFCGUIClusterSimDlg::OnEnChangeEdit2()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	// TODO:  Add your control notification handler code here
}

CString CMFCGUIClusterSimDlg::FillNodes()
{
	//create cstrings to fill master
	CString nodeText;
	Master master;
	//one master instance

	Processor pros("Master", "i5", "7500",24, 3.80, 3.40, 6.0, 4, 4, 65.0,0,85);
	std::string pMaster = pros.getData();
	CString text(pMaster.c_str());
	nodeText = text;
	
	return CString(nodeText);
}


CString CMFCGUIClusterSimDlg::FillSlave()
{

	//create cstrings to fill slaves
	CString nodeText;
	Node N;

	//Vector of Slaves
	vector<Processor> Nodes;

	Processor newNode("Slave", "i5", "7500", 16, 3.80, 3.40, 6.0, 4, 4, 65.0, 0, 85);
	Nodes.push_back(newNode);//Adds Object to vector

	for (int i = 0; i < 1; i++) {
		
		
		std::string pN = newNode.getData() + "\r\n";
		CString text(pN.c_str());

		nodeText = text;
		return CString(nodeText);

	}

	//Two instances of a processor
	//Processor pros2("Slave1", "i5", "7500",16, 3.80, 3.40, 6.0, 4, 4, 65.0,0,85);
	//Processor pros3("Slave2", "i5", "7500",3.80, 3.40, 6.0, 4, 4, 65.0);
	//std::string pN = pros2.getData() + "\r\n";
	//CString text(pN.c_str());
	//nodeText = text;
}

void CMFCGUIClusterSimDlg::OnBnClickedBtnAdd()
{
	// TODO: Add your control notification handler code here

	//CString slave = FillSlave();
	//SetDlgItemText(IDC_EDIT2, /*(CString)"test2"*/slave);
	
	//AddNodeFrame Add;
	//Add.Create;
	//Add.DoModal;
	//AddFrame Add;
	//Add.DoModal();


	// Test Below code.
	m_OkCount++;

	CString slave = FillSlave();
	SetDlgItemText(IDC_EDIT2, /*(CString)"test2"*/slave);

	//processors test. 
	//end of test 
	
	m_EchoText.Format(_T("%d"), m_OkCount); //anding number to counter
	// without UpdateData() status area will _NOT_ be updated.
	UpdateData(FALSE);

}


void CMFCGUIClusterSimDlg::OnStnClickedEchoArea()//Set to not visible
{
	// TODO: Add your control notification handler code here
}

void CMFCGUIClusterSimDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}
