#pragma once

//ӡˢ������
class PrintWorkOrder
{
public:
	PrintWorkOrder();
	~PrintWorkOrder();

public:
	/************************************************************************/
	/*������ʾ����                                                          */
	/************************************************************************/
	long m_lSerialNum;
	CString m_strGoverAgency;
	CString m_strContact;
	CString m_strPhoneNum;

	/************************************************************************/
	/*������ֵ����                                                          */
	/************************************************************************/
	//ӡˢ�ܷ���
	int m_nCopyNum;
	//ҳ��
	int m_nPageNum;
	//��ͷ�ļ�����
	int m_nReadHeadNum;

	/************************************************************************/
	/*ϵ��ѡ��                                                              */
	/************************************************************************/
	//�Ƿ��з���
	bool m_bCover;
	//�Ƿ���
	bool m_bMarkNum;
	//�Ӽ�ϵ��
	double m_dUrgentNum;
	//Marks
	bool m_bMarkNote;

public:
	/*Set***/
	//���ù�����ʾ����Ϣ
	void SetWorkOrderShowInfo(long lSerialNum,
							  CString strGoverAgency,
	                          CString strContact,
	                          CString strPhoneNum);

	void SetPrintingNum(int nCopyNum, int nPageNum, int nReaHeadNum);

	void WhetherSetCover(bool bCover);

	void WhetherSetMarkNum(bool bMarkNum);

	void WhetherSetUrgentNum(double UrgentNum);

	void WhetherSetMarkNote(bool bMarkNote);

	/*Get******/

	bool GetCover();

	bool GetMarkNum();

	bool GetUrgentNum();

	bool GetMarkNote();

	void ClearObject();

};

