
// PrintingCalculateDemoDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "PrintWorkOrder.h"
#include "afxcmn.h"

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
	CString m_EditFilename;
	CString m_EditOperater;

	int m_EditCopyNum;
	int m_EditPageNum;
	int m_EditRedHead;
	afx_msg void OnBnClickedBninfoinput();

	//������
	PrintWorkOrder m_PrintWO;

	//�������ļ��ж�ȡ�Ĳ���
	int m_nPageLimitOne;
	int m_nPageLimitTwo;

	double m_dCoefficientOne;
	double m_dCoefficientTwo;
	double m_dCoefficientThree;

	int m_nBookBind;
	int m_nMarkNum;


//�Խ�����
public:
	void ReadSystemSettingFromIni();

	//�Ű�Ƽ�
	void CalculateTypeSet();
	//ӡˢ�Ƽ�
	void CalculatePrintPrice();
	//װ���Ƽ�
	void CalculateBindPrice();
	//ֽ�żƼ�
	void CalculatePaperPrice();
	//ӡˢ�ܼۼ���
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
