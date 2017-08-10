
// PrintingCalculateDemoDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PrintingCalculateDemo.h"
#include "PrintingCalculateDemoDlg.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CPrintingCalculateDemoDlg �Ի���



CPrintingCalculateDemoDlg::CPrintingCalculateDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPrintingCalculateDemoDlg::IDD, pParent)
	, m_nSerialNum(0)
	, m_EditUnitName(_T(""))
	, m_EditContactName(_T(""))
	, m_EditPhoneNum(_T(""))
	, m_EditCopyNum(0)
	, m_EditPageNum(0)
	, m_EditRedHead(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPrintingCalculateDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_EditSerialNum, m_EditSerialNum);
	//  DDX_Control(pDX, IDC_EditUnitame, m_EditUnitName);
	DDX_Text(pDX, IDC_EditSerialNum, m_nSerialNum);
	DDX_Text(pDX, IDC_EditUnitame, m_EditUnitName);
	DDX_Text(pDX, IDC_EditContactName, m_EditContactName);
	DDX_Text(pDX, IDC_EditPhoneNum, m_EditPhoneNum);
	DDX_Text(pDX, IDC_EditCopyNum, m_EditCopyNum);
	DDX_Text(pDX, IDC_EditPageNum, m_EditPageNum);
	DDX_Text(pDX, IDC_EditRedHead, m_EditRedHead);
}

BEGIN_MESSAGE_MAP(CPrintingCalculateDemoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BNInfoInput, &CPrintingCalculateDemoDlg::OnBnClickedBninfoinput)
END_MESSAGE_MAP()


// CPrintingCalculateDemoDlg ��Ϣ�������

BOOL CPrintingCalculateDemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	//



	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CPrintingCalculateDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CPrintingCalculateDemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CPrintingCalculateDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CPrintingCalculateDemoDlg::OnBnClickedBninfoinput()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	
	m_nSerialNum = 0;
	m_EditUnitName = _T("");
	m_EditContactName = _T("");
	m_EditPhoneNum = _T("");
	m_EditCopyNum = 0;
	m_EditPageNum = 0;
	m_EditRedHead = 0;
	UpdateData(false);
	
	m_PrintWO.ClearObject();
}

