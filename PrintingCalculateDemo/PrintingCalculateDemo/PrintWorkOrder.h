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
	CString m_strFilename;
	CString m_strOperater;

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

	//阶段计价数据
	//排版
	double m_nTypesetPrice;
	//印刷
	double m_nPrintPrice;
	//装订
	double m_nBindPrice;
	//纸费
	double m_nPaperPrice;
	//总计
	double m_nTotalPrice;

public:
	/*Set***/
	//设置工单显示的信息
	void SetWorkOrderShowInfo(long lSerialNum,
							  CString strGoverAgency,
	                          CString strContact,
	                          CString strPhoneNum,
							  CString strFileName,
							  CString strOperater
							  );

	void SetPrintingNum(int nCopyNum, int nPageNum, int nReaHeadNum);

	void WhetherSetCover(bool bCover);

	void WhetherSetMarkNum(bool bMarkNum);

	void SetUrgentNum(double UrgentNum);

	void WhetherSetMarkNote(bool bMarkNote);

	/*Get******/

	bool GetCover();

	bool GetMarkNum();

	double GetUrgentNum();

	bool GetMarkNote();

	void ClearObject();

};

