#pragma once

//印刷工单类
class PrintWorkOrder
{
public:
	PrintWorkOrder();
	~PrintWorkOrder();

public:
	/************************************************************************/
	/*工单显示属性                                                          */
	/************************************************************************/
	long m_lSerialNum;
	CString m_strGoverAgency;
	CString m_strContact;
	CString m_strPhoneNum;

	/************************************************************************/
	/*输入数值属性                                                          */
	/************************************************************************/
	//印刷总份数
	int m_nCopyNum;
	//页数
	int m_nPageNum;
	//红头文件个数
	int m_nReadHeadNum;

	/************************************************************************/
	/*系数选择                                                              */
	/************************************************************************/
	//是否有封面
	bool m_bCover;
	//是否打号
	bool m_bMarkNum;
	//加急系数
	double m_dUrgentNum;
	//Marks
	bool m_bMarkNote;

public:
	/*Set***/
	//设置工单显示的信息
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

