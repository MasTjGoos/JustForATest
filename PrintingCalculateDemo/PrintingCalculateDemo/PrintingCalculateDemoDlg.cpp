
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
	, m_EditFilename(_T(""))
	, m_EditOperater(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_nPageLimitOne = 0;
	m_nPageLimitTwo = 0;

	m_dCoefficientOne = 0.0;
	m_dCoefficientTwo = 0.0;
	m_dCoefficientThree = 0.0;

	m_nBookBind = 0;
	m_nMarkNum = 0;

	m_PrintWO.ClearObject();

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
	DDX_Control(pDX, IDC_CombUrgentNum, m_CombUrgentNum);
	DDX_Control(pDX, IDC_CHECKMarkNote, m_CheckMarkNote);
	DDX_Control(pDX, IDC_RecordList, m_RecordList);
	DDX_Text(pDX, IDC_EditFilename, m_EditFilename);
	DDX_Text(pDX, IDC_EditOperater, m_EditOperater);
}

BEGIN_MESSAGE_MAP(CPrintingCalculateDemoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BNInfoInput, &CPrintingCalculateDemoDlg::OnBnClickedBninfoinput)
	ON_BN_CLICKED(IDC_BNCalculate, &CPrintingCalculateDemoDlg::OnBnClickedBncalculate)
	ON_BN_CLICKED(IDC_CoverYes, &CPrintingCalculateDemoDlg::OnBnClickedCoveryes)
	ON_BN_CLICKED(IDC_CoverNo, &CPrintingCalculateDemoDlg::OnBnClickedCoverno)
	ON_BN_CLICKED(IDC_MarkNumYes, &CPrintingCalculateDemoDlg::OnBnClickedMarknumyes)
	ON_BN_CLICKED(IDC_MarkNumNo, &CPrintingCalculateDemoDlg::OnBnClickedMarknumno)
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
	
	//��ȡ�����ļ��еĲ���
	ReadSystemSettingFromIni();

	//��ʼ����¼�б�
	m_RecordList.SetExtendedStyle(LVS_EX_FLATSB
		| LVS_EX_FULLROWSELECT
		| LVS_EX_ONECLICKACTIVATE
		| LVS_EX_GRIDLINES
		);
	m_RecordList.InsertColumn(0, _T("���"), 0, 40, 0);
	m_RecordList.InsertColumn(1, _T("�ļ�����"), 0, 50, 0);
	m_RecordList.InsertColumn(2, _T("�ܼ�"), 0, 100, 0);
	m_RecordList.InsertColumn(3, _T("����"), 0, 100, 0);
	m_RecordList.InsertColumn(4, _T("ҳ��"), 0, 100, 0);
	m_RecordList.InsertColumn(5, _T("��ͷ��"), 0, 100, 0);
	m_RecordList.InsertColumn(6, _T("�Ӽ�ϵ��"), 0, 100, 0);
	m_RecordList.InsertColumn(7, _T("��Ƥ"), 0, 100, 0);
	m_RecordList.InsertColumn(8, _T("���"), 0, 100, 0);
	m_RecordList.InsertColumn(9, _T("�Ƿ��ӡ"), 0, 100, 0);

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


//��ձ༭������ֵ
void CPrintingCalculateDemoDlg::OnBnClickedBninfoinput()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	
	if (MessageBox(_T("ȷ����ձ༭��������"), _T("��ʾ"), MB_YESNO | MB_DEFBUTTON2) == IDYES)
	{
		m_nSerialNum = 0;
		m_EditUnitName = _T("");
		m_EditContactName = _T("");
		m_EditPhoneNum = _T("");
		m_EditCopyNum = 0;
		m_EditPageNum = 0;
		m_EditRedHead = 0;
		m_EditFilename = _T("");
		m_EditOperater = _T("");

		UpdateData(false);

		m_PrintWO.ClearObject();
	}
}



//�Ƽۺ���
void CPrintingCalculateDemoDlg::OnBnClickedBncalculate()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//�ж���ֵ
	if (m_PrintWO.m_nTotalPrice != 0)
	{
		AfxMessageBox(_T("�벻Ҫ�ظ����㣬���ñ༭��"));
	}

	//��ȡ�����ϵ���ֵ
	UpdateData(true);
	
	if (m_nSerialNum == 0)
	{
		AfxMessageBox(_T("δ��д�ļ��ţ�"));
		return;
	}

	if (m_EditContactName == _T("") && m_EditPhoneNum == _T("") && m_EditUnitName == _T(""))
	{
		AfxMessageBox(_T("��ϵ����Ϣ��ȫ��"));
		return;
	}

	if (m_EditFilename == _T(""))
	{
		AfxMessageBox(_T("�ļ�������Ϊ�գ�"));
		return;
	}

	if (m_EditOperater == _T(""))
	{
		AfxMessageBox(_T("�����˲���Ϊ�գ�"));
		return;
	}

	if (m_EditCopyNum == 0 && m_EditPageNum == 0)
	{
		AfxMessageBox(_T("ӡ�Ʒ�����ҳ������Ϊ�㣡"));
		return;
	}

	
	//ΪPrintWo���������(������Ϣ)
	m_PrintWO.SetWorkOrderShowInfo(m_nSerialNum, m_EditUnitName, m_EditContactName, 
									m_EditPhoneNum, m_EditFilename, m_EditOperater);
	//��ӡˢ�ؼ����ݣ�
	m_PrintWO.SetPrintingNum(m_EditCopyNum, m_EditPageNum, m_EditRedHead);

	//�Ӽ�ϵ��
	switch (m_CombUrgentNum.GetCurSel())
	{
	case 0:
		m_PrintWO.SetUrgentNum(1.3);
		break;
	case 1:
		m_PrintWO.SetUrgentNum(1.5);
		break;
	case 2:
		m_PrintWO.SetUrgentNum(2.0);
		break;
	}

	//��ע��Ϣ
	if (m_CheckMarkNote.GetCheck())
	{
		m_PrintWO.WhetherSetMarkNote(true);
	}
	else
	{
		m_PrintWO.WhetherSetMarkNote(false);
	}

	//��������׶μ۸�
	CalculateTypeSet();
	CalculatePrintPrice();
	CalculateBindPrice();
	CalculatePaperPrice();
	//�����ܼ�
	CalculateTotalPrice();

	//�ڱ༭������ʾ�Ƽ۽��
	CEdit*  pEdit = (CEdit*)GetDlgItem(IDC_TypeSetPrice);
	CString str = _T("");
	str.Format("%0.3f", m_PrintWO.m_nTypesetPrice);
	pEdit->SetWindowText(str);

	str = _T("");
	pEdit = (CEdit*)GetDlgItem(IDC_PrintPrice);
	str.Format("%0.3f", m_PrintWO.m_nPrintPrice);
	pEdit->SetWindowText(str);

	str = _T("");
	pEdit = (CEdit*)GetDlgItem(IDC_Bindprice);
	str.Format("%0.3f", m_PrintWO.m_nBindPrice);
	pEdit->SetWindowText(str);

	str = _T("");
	pEdit = (CEdit*)GetDlgItem(IDC_PaperPrice);
	str.Format("%0.3f", m_PrintWO.m_nPaperPrice);
	pEdit->SetWindowText(str);

	str = _T("");
	pEdit = (CEdit*)GetDlgItem(IDC_TotalPrice);
	str.Format("%0.2f", m_PrintWO.m_nTotalPrice);
	pEdit->SetWindowText(str);

	/************************************************************************/
	/*�б�*/
	/************************************************************************/
	int count = 0;
	m_RecordList.InsertItem(count, _T(""));
	//���
	str = _T("");
	str.Format("%d", m_PrintWO.m_lSerialNum);
	m_RecordList.SetItemText(count, 0, str);
	
	//��ϵ��
	m_RecordList.SetItemText(count, 1, m_PrintWO.m_strFilename);

	//ӡˢ�ܼ�
	str = _T("");
	str.Format("%0.2f", m_PrintWO.m_nTotalPrice);
	m_RecordList.SetItemText(count, 2, str);
	
	//����
	str = _T("");
	str.Format("%d", m_PrintWO.m_nCopyNum);
	m_RecordList.SetItemText(count, 3, str);

	//ҳ��
	str = _T("");
	str.Format("%d", m_PrintWO.m_nPageNum);
	m_RecordList.SetItemText(count, 4, str);

	//��ͷ��
	str = _T("");
	str.Format("%d", m_PrintWO.m_nReadHeadNum);
	m_RecordList.SetItemText(count, 5, str);

	//�Ӽ�ϵ��
	str = _T("");
	str.Format("%0.2f", m_PrintWO.m_dUrgentNum);
	m_RecordList.SetItemText(count, 6, str);

	//��Ƥ
	if (m_PrintWO.m_bCover)
	{
		m_RecordList.SetItemText(count, 7, _T("��"));
	}
	else
	{
		m_RecordList.SetItemText(count, 7, _T("��"));
	}

	//���
	if (m_PrintWO.m_bMarkNum)
	{
		m_RecordList.SetItemText(count, 8, _T("��"));
	}
	else
	{
		m_RecordList.SetItemText(count, 8, _T("��"));
	}

	

	//�Ƿ��ӡ
	if (m_PrintWO.m_bMarkNote)
	{
		m_RecordList.SetItemText(count, 9, _T("��"));
	}
	else
	{
		m_RecordList.SetItemText(count, 9, _T("��"));
	}

	UpdateData(false);
}


//�з���
void CPrintingCalculateDemoDlg::OnBnClickedCoveryes()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_PrintWO.WhetherSetCover(true);
}

//�޷���
void CPrintingCalculateDemoDlg::OnBnClickedCoverno()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_PrintWO.WhetherSetCover(false);
}


//�д��
void CPrintingCalculateDemoDlg::OnBnClickedMarknumyes()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_PrintWO.WhetherSetMarkNum(true);
}

//�޴��
void CPrintingCalculateDemoDlg::OnBnClickedMarknumno()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_PrintWO.WhetherSetMarkNum(false);
}

//��ȡ�����ļ��еĲ���
void CPrintingCalculateDemoDlg::ReadSystemSettingFromIni()
{
	CString path;
	GetModuleFileName(NULL, path.GetBufferSetLength(MAX_PATH + 1), MAX_PATH);
	path.ReleaseBuffer();
	int pos = path.ReverseFind('\\');
	path = path.Left(pos);

	//�ļ�·��
	CString strSystemPath = path;
	strSystemPath += "\\ConfigSetting.ini";
	strSystemPath.Replace(_T("\\"), _T("\\\\"));


	//����û�����ϵͳ����������
	m_nPageLimitOne = GetPrivateProfileInt(_T("PageLimitOne"), _T("Value"), 0, strSystemPath);
	m_nPageLimitTwo = GetPrivateProfileInt(_T("PageLimitTwo"), _T("Value"), 0, strSystemPath);
	m_nBookBind = GetPrivateProfileInt(_T("BookBind"), _T("Value"), 0, strSystemPath);
	m_nMarkNum = GetPrivateProfileInt(_T("MarkNumber"), _T("Value"), 0, strSystemPath);

	char szBuf[2560];
	int Len = 0;
	CString str;
	Len = GetPrivateProfileString(_T("CoefficientOne"), _T("Value"), _T("?"), szBuf, 2550, strSystemPath);
	str = szBuf;
	m_dCoefficientOne = atof(szBuf);

	Len = GetPrivateProfileString(_T("CoefficientTwo"), _T("Value"), _T("?"), szBuf, 2550, strSystemPath);
	str = szBuf;
	m_dCoefficientTwo = atof(szBuf);

	Len = GetPrivateProfileString(_T("CoefficientThree"), _T("Value"), _T("?"), szBuf, 2550, strSystemPath);
	str = szBuf;
	m_dCoefficientThree = atof(szBuf);

}

//�����Ű�Ƽ�
void CPrintingCalculateDemoDlg::CalculateTypeSet()
{
	double temp = 0.0;
	if (m_PrintWO.m_nCopyNum > 0 && m_PrintWO.m_nCopyNum <= m_nPageLimitOne)
	{
		temp = m_dCoefficientOne;
	}
	else if (m_PrintWO.m_nCopyNum > m_nPageLimitOne && m_PrintWO.m_nCopyNum <= m_nPageLimitTwo)
	{
		temp = m_dCoefficientTwo;
	}
	else if (m_PrintWO.m_nCopyNum > m_nPageLimitTwo)
	{
		temp = m_dCoefficientThree;
	}
	else
	{
		AfxMessageBox(_T("ӡˢ������ֵ����"));
	}

	//�Ű�Ƽ�
	m_PrintWO.m_nTypesetPrice = m_PrintWO.m_nPageNum * 14 * temp + m_PrintWO.m_nReadHeadNum * 6;
}

//����ӡˢ�Ƽ�
void CPrintingCalculateDemoDlg::CalculatePrintPrice()
{
	//�Կ���
	int nLargePaper = 0;
	nLargePaper = int(m_PrintWO.m_nPageNum / 8.0)+ 1;

	//ӡˢ����
	m_PrintWO.m_nPrintPrice = m_PrintWO.m_nReadHeadNum * 75 + nLargePaper * 70;
}

//װ����żƼ�
void CPrintingCalculateDemoDlg::CalculateBindPrice()
{
	
	//װ����ż���
	if (m_PrintWO.m_bMarkNum == true)
	{
		m_PrintWO.m_nBindPrice = m_nBookBind + m_nMarkNum;
	}
	else if (m_PrintWO.m_bMarkNum == false)
	{
		m_PrintWO.m_nBindPrice = m_nBookBind;
	}
	else
	{
		m_PrintWO.m_nBindPrice = m_nBookBind;
	}
}

//ӡˢֽ�żƼ�
void CPrintingCalculateDemoDlg::CalculatePaperPrice()
{
	int TempSheet = 0;
	int AbsSheet = 0;
	int MorePaper = 0;
	if (m_PrintWO.m_nPageNum % 2 == 0)
	{
		TempSheet = m_PrintWO.m_nPageNum / 2;
	}
	else
	{
		TempSheet = (m_PrintWO.m_nPageNum + 1) / 2;
	}

	AbsSheet = int((TempSheet + m_PrintWO.m_nReadHeadNum) * m_PrintWO.m_nCopyNum / 16) + 1;
	MorePaper = (TempSheet + m_PrintWO.m_nReadHeadNum) * 5;

	//ֽ�ż۸����
	m_PrintWO.m_nPaperPrice = (AbsSheet + MorePaper) * 0.9;
}

//�ܼ�
void CPrintingCalculateDemoDlg::CalculateTotalPrice()
{
	//��Ƥ����
	int TempPriceCover = 0;
	if (m_PrintWO.m_bCover = true)
	{
		TempPriceCover = m_PrintWO.m_nCopyNum * 2;
	}
	else
	{
		TempPriceCover = 0;
	}

	m_PrintWO.m_nTotalPrice = (m_PrintWO.m_nTypesetPrice +
								m_PrintWO.m_nPrintPrice +
								m_PrintWO.m_nBindPrice) * m_PrintWO.GetUrgentNum()
								+ m_PrintWO.m_nPaperPrice;
	m_PrintWO.m_nTotalPrice = m_PrintWO.m_nTotalPrice * 1.05 + TempPriceCover;

	if (m_PrintWO.m_bMarkNote == true)
	{
		m_PrintWO.m_nTotalPrice = m_PrintWO.m_nTotalPrice * 2;
	}
	else
	{
		m_PrintWO.m_nTotalPrice = m_PrintWO.m_nTotalPrice * 1;
	}

}