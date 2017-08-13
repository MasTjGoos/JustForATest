
// PrintingCalculateDemoDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "PrintWorkOrder.h"
#include "afxcmn.h"

// CPrintingCalculateDemoDlg 对话框
class CPrintingCalculateDemoDlg : public CDialogEx
{
// 构造
public:
	CPrintingCalculateDemoDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_PRINTINGCALCULATEDEMO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:

	//记录编辑框中的数值
	long m_nSerialNum;
	CString m_EditUnitName;
	CString m_EditContactName;
	CString m_EditPhoneNum;
	CString m_EditFilename;
	CString m_EditOperater;

	int m_EditCopyNum;
	int m_EditPageNum;
	int m_EditRedHead;
	afx_msg void OnBnClickedBninfoinput();

	//工单类
	PrintWorkOrder m_PrintWO;

	//从配置文件中读取的参数
	int m_nPageLimitOne;
	int m_nPageLimitTwo;

	double m_dCoefficientOne;
	double m_dCoefficientTwo;
	double m_dCoefficientThree;

	int m_nBookBind;
	int m_nMarkNum;


//自建函数
public:
	void ReadSystemSettingFromIni();

	//排版计价
	void CalculateTypeSet();
	//印刷计价
	void CalculatePrintPrice();
	//装订计价
	void CalculateBindPrice();
	//纸张计价
	void CalculatePaperPrice();
	//印刷总价计算
	void CalculateTotalPrice();
	
	afx_msg void OnBnClickedBncalculate();
	afx_msg void OnBnClickedCoveryes();
	afx_msg void OnBnClickedCoverno();
	afx_msg void OnBnClickedMarknumyes();
	afx_msg void OnBnClickedMarknumno();
	CComboBox m_CombUrgentNum;
	CButton m_CheckMarkNote;
	CListCtrl m_RecordList;
	
};
