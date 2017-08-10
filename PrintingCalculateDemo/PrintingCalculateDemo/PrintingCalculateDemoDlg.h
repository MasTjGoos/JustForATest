
// PrintingCalculateDemoDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "PrintWorkOrder.h"

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
	int m_EditCopyNum;
	int m_EditPageNum;
	int m_EditRedHead;
	afx_msg void OnBnClickedBninfoinput();

	//工单类
	PrintWorkOrder m_PrintWO;

//自建函数
public:
	
};
