
// PrintingCalculateDemoDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "PrintingCalculateDemo.h"
#include "PrintingCalculateDemoDlg.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CPrintingCalculateDemoDlg 对话框



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


// CPrintingCalculateDemoDlg 消息处理程序

BOOL CPrintingCalculateDemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码
	
	//读取配置文件中的参数
	ReadSystemSettingFromIni();

	//初始化记录列表
	m_RecordList.SetExtendedStyle(LVS_EX_FLATSB
		| LVS_EX_FULLROWSELECT
		| LVS_EX_ONECLICKACTIVATE
		| LVS_EX_GRIDLINES
		);
	m_RecordList.InsertColumn(0, _T("序号"), 0, 40, 0);
	m_RecordList.InsertColumn(1, _T("文件名称"), 0, 50, 0);
	m_RecordList.InsertColumn(2, _T("总价"), 0, 100, 0);
	m_RecordList.InsertColumn(3, _T("份数"), 0, 100, 0);
	m_RecordList.InsertColumn(4, _T("页数"), 0, 100, 0);
	m_RecordList.InsertColumn(5, _T("红头数"), 0, 100, 0);
	m_RecordList.InsertColumn(6, _T("加急系数"), 0, 100, 0);
	m_RecordList.InsertColumn(7, _T("封皮"), 0, 100, 0);
	m_RecordList.InsertColumn(8, _T("打号"), 0, 100, 0);
	m_RecordList.InsertColumn(9, _T("是否彩印"), 0, 100, 0);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CPrintingCalculateDemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CPrintingCalculateDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//清空编辑框中数值
void CPrintingCalculateDemoDlg::OnBnClickedBninfoinput()
{
	// TODO:  在此添加控件通知处理程序代码
	
	if (MessageBox(_T("确定清空编辑框数据吗？"), _T("提示"), MB_YESNO | MB_DEFBUTTON2) == IDYES)
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



//计价函数
void CPrintingCalculateDemoDlg::OnBnClickedBncalculate()
{
	// TODO:  在此添加控件通知处理程序代码
	//判断数值
	if (m_PrintWO.m_nTotalPrice != 0)
	{
		AfxMessageBox(_T("请不要重复计算，重置编辑框！"));
	}

	//获取界面上的数值
	UpdateData(true);
	
	if (m_nSerialNum == 0)
	{
		AfxMessageBox(_T("未填写文件号！"));
		return;
	}

	if (m_EditContactName == _T("") && m_EditPhoneNum == _T("") && m_EditUnitName == _T(""))
	{
		AfxMessageBox(_T("联系人信息不全！"));
		return;
	}

	if (m_EditFilename == _T(""))
	{
		AfxMessageBox(_T("文件名不能为空！"));
		return;
	}

	if (m_EditOperater == _T(""))
	{
		AfxMessageBox(_T("经办人不能为空！"));
		return;
	}

	if (m_EditCopyNum == 0 && m_EditPageNum == 0)
	{
		AfxMessageBox(_T("印制份数和页数不能为零！"));
		return;
	}

	
	//为PrintWo对象传入参数(基本信息)
	m_PrintWO.SetWorkOrderShowInfo(m_nSerialNum, m_EditUnitName, m_EditContactName, 
									m_EditPhoneNum, m_EditFilename, m_EditOperater);
	//（印刷关键数据）
	m_PrintWO.SetPrintingNum(m_EditCopyNum, m_EditPageNum, m_EditRedHead);

	//加急系数
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

	//备注信息
	if (m_CheckMarkNote.GetCheck())
	{
		m_PrintWO.WhetherSetMarkNote(true);
	}
	else
	{
		m_PrintWO.WhetherSetMarkNote(false);
	}

	//计算各个阶段价格
	CalculateTypeSet();
	CalculatePrintPrice();
	CalculateBindPrice();
	CalculatePaperPrice();
	//计算总价
	CalculateTotalPrice();

	//在编辑框中显示计价结果
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
	/*列表*/
	/************************************************************************/
	int count = 0;
	m_RecordList.InsertItem(count, _T(""));
	//序号
	str = _T("");
	str.Format("%d", m_PrintWO.m_lSerialNum);
	m_RecordList.SetItemText(count, 0, str);
	
	//联系人
	m_RecordList.SetItemText(count, 1, m_PrintWO.m_strFilename);

	//印刷总价
	str = _T("");
	str.Format("%0.2f", m_PrintWO.m_nTotalPrice);
	m_RecordList.SetItemText(count, 2, str);
	
	//份数
	str = _T("");
	str.Format("%d", m_PrintWO.m_nCopyNum);
	m_RecordList.SetItemText(count, 3, str);

	//页数
	str = _T("");
	str.Format("%d", m_PrintWO.m_nPageNum);
	m_RecordList.SetItemText(count, 4, str);

	//红头数
	str = _T("");
	str.Format("%d", m_PrintWO.m_nReadHeadNum);
	m_RecordList.SetItemText(count, 5, str);

	//加急系数
	str = _T("");
	str.Format("%0.2f", m_PrintWO.m_dUrgentNum);
	m_RecordList.SetItemText(count, 6, str);

	//封皮
	if (m_PrintWO.m_bCover)
	{
		m_RecordList.SetItemText(count, 7, _T("是"));
	}
	else
	{
		m_RecordList.SetItemText(count, 7, _T("否"));
	}

	//打号
	if (m_PrintWO.m_bMarkNum)
	{
		m_RecordList.SetItemText(count, 8, _T("是"));
	}
	else
	{
		m_RecordList.SetItemText(count, 8, _T("否"));
	}

	

	//是否彩印
	if (m_PrintWO.m_bMarkNote)
	{
		m_RecordList.SetItemText(count, 9, _T("是"));
	}
	else
	{
		m_RecordList.SetItemText(count, 9, _T("否"));
	}

	UpdateData(false);
}


//有封面
void CPrintingCalculateDemoDlg::OnBnClickedCoveryes()
{
	// TODO:  在此添加控件通知处理程序代码
	m_PrintWO.WhetherSetCover(true);
}

//无封面
void CPrintingCalculateDemoDlg::OnBnClickedCoverno()
{
	// TODO:  在此添加控件通知处理程序代码
	m_PrintWO.WhetherSetCover(false);
}


//有打号
void CPrintingCalculateDemoDlg::OnBnClickedMarknumyes()
{
	// TODO:  在此添加控件通知处理程序代码
	m_PrintWO.WhetherSetMarkNum(true);
}

//无打号
void CPrintingCalculateDemoDlg::OnBnClickedMarknumno()
{
	// TODO:  在此添加控件通知处理程序代码
	m_PrintWO.WhetherSetMarkNum(false);
}

//读取配置文件中的参数
void CPrintingCalculateDemoDlg::ReadSystemSettingFromIni()
{
	CString path;
	GetModuleFileName(NULL, path.GetBufferSetLength(MAX_PATH + 1), MAX_PATH);
	path.ReleaseBuffer();
	int pos = path.ReverseFind('\\');
	path = path.Left(pos);

	//文件路径
	CString strSystemPath = path;
	strSystemPath += "\\ConfigSetting.ini";
	strSystemPath.Replace(_T("\\"), _T("\\\\"));


	//获得用户对于系统参数的配置
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

//计算排版计价
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
		AfxMessageBox(_T("印刷份数数值有误！"));
	}

	//排版计价
	m_PrintWO.m_nTypesetPrice = m_PrintWO.m_nPageNum * 14 * temp + m_PrintWO.m_nReadHeadNum * 6;
}

//计算印刷计价
void CPrintingCalculateDemoDlg::CalculatePrintPrice()
{
	//对开数
	int nLargePaper = 0;
	nLargePaper = int(m_PrintWO.m_nPageNum / 8.0)+ 1;

	//印刷计算
	m_PrintWO.m_nPrintPrice = m_PrintWO.m_nReadHeadNum * 75 + nLargePaper * 70;
}

//装订打号计价
void CPrintingCalculateDemoDlg::CalculateBindPrice()
{
	
	//装订打号计算
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

//印刷纸张计价
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

	//纸张价格计算
	m_PrintWO.m_nPaperPrice = (AbsSheet + MorePaper) * 0.9;
}

//总价
void CPrintingCalculateDemoDlg::CalculateTotalPrice()
{
	//封皮计算
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