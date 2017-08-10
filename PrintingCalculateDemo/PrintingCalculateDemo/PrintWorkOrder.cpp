#include "stdafx.h"
#include "PrintWorkOrder.h"


PrintWorkOrder::PrintWorkOrder()
{
	m_lSerialNum = 0;
	m_strGoverAgency = _T("");
	m_strContact = _T("");
	m_strPhoneNum = _T("");

	m_nCopyNum = 0;
	m_nPageNum = 0;
	m_nReadHeadNum = 0;
}


PrintWorkOrder::~PrintWorkOrder()
{
}


void PrintWorkOrder::SetWorkOrderShowInfo(long lSerialNum,
	CString strGoverAgency,
	CString strContact,
	CString strPhoneNum)
{
	m_lSerialNum = lSerialNum;
	m_strGoverAgency = strGoverAgency;
	m_strContact = strContact;
	m_strPhoneNum = strPhoneNum;
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

void PrintWorkOrder::WhetherSetUrgentNum(double UrgentNum)
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

bool PrintWorkOrder::GetUrgentNum()
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

	m_nCopyNum = 0;
	m_nPageNum = 0;
	m_nReadHeadNum = 0;
}