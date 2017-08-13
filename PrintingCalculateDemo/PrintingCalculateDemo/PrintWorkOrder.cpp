#include "stdafx.h"
#include "PrintWorkOrder.h"


PrintWorkOrder::PrintWorkOrder()
{
	m_lSerialNum = 0;
	m_strGoverAgency = _T("");
	m_strContact = _T("");
	m_strPhoneNum = _T("");
	m_strFilename = _T("");
	m_strOperater = _T("");


	m_nCopyNum = 0;
	m_nPageNum = 0;
	m_nReadHeadNum = 0;

	//排版
	m_nTypesetPrice = 0.0;
	//印刷
	m_nPrintPrice = 0.0;
	//装订
	m_nBindPrice = 0.0;
	//纸费
	m_nPaperPrice = 0.0;
	//总计
	m_nTotalPrice = 0.0;
}


PrintWorkOrder::~PrintWorkOrder()
{
}


void PrintWorkOrder::SetWorkOrderShowInfo(long lSerialNum,
	CString strGoverAgency,
	CString strContact,
	CString strPhoneNum,
	CString strFileName,
	CString strOperater
	)
{
	m_lSerialNum = lSerialNum;
	m_strGoverAgency = strGoverAgency;
	m_strContact = strContact;
	m_strPhoneNum = strPhoneNum;
	m_strFilename = strFileName;
	m_strOperater = strOperater;

}

void PrintWorkOrder::SetPrintingNum(int nCopyNum, int nPageNum, int nReaHeadNum)
{
	m_nCopyNum = nCopyNum;
	m_nPageNum = nPageNum;
	m_nReadHeadNum = nReaHeadNum;
}

void PrintWorkOrder::WhetherSetCover(bool bCover)
{
	m_bCover = bCover;
}

void PrintWorkOrder::WhetherSetMarkNum(bool bMarkNum)
{
	m_bMarkNum = bMarkNum;
}

void PrintWorkOrder::SetUrgentNum(double UrgentNum)
{
	m_dUrgentNum = UrgentNum;
}

void PrintWorkOrder::WhetherSetMarkNote(bool bMarkNote)
{
	m_bMarkNote = bMarkNote;
}

/*Get*/

bool PrintWorkOrder::GetCover()
{
	return m_bCover;
}

bool PrintWorkOrder::GetMarkNum()
{
	return m_bMarkNum;
}

double PrintWorkOrder::GetUrgentNum()
{
	return m_dUrgentNum;
}

bool PrintWorkOrder::GetMarkNote()
{
	return m_bMarkNote;
}

void PrintWorkOrder::ClearObject()
{
	m_lSerialNum = 0;
	m_strGoverAgency = _T("");
	m_strContact = _T("");
	m_strPhoneNum = _T("");
	m_strFilename = _T("");
	m_strOperater = _T("");

	//份数，页数
	m_nCopyNum = 0;
	m_nPageNum = 0;
	m_nReadHeadNum = 0;

	/*计价**/
	//排版
	m_nTypesetPrice = 0.0;
	//印刷
	m_nPrintPrice = 0.0;
	//装订
	m_nBindPrice = 0.0;
	//纸费
	m_nPaperPrice = 0.0;
	//总计
	m_nTotalPrice = 0.0;
}