
// PrintingCalculateDemoDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "PrintWorkOrder.h"

// CPrintingCalculateDemoDlg �Ի���
class CPrintingCalculateDemoDlg : public CDialogEx
{
// ����
public:
	CPrintingCalculateDemoDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_PRINTINGCALCULATEDEMO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:

	//��¼�༭���е���ֵ
	long m_nSerialNum;
	CString m_EditUnitName;
	CString m_EditContactName;
	CString m_EditPhoneNum;
	int m_EditCopyNum;
	int m_EditPageNum;
	int m_EditRedHead;
	afx_msg void OnBnClickedBninfoinput();

	//������
	PrintWorkOrder m_PrintWO;

//�Խ�����
public:
	
};
