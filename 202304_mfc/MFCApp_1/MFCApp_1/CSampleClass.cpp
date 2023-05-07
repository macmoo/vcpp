// CSampleClass.cpp: 구현 파일
//6

#include "pch.h"
#include "MFCApp_1.h"
#include "CSampleClass.h"


// CSampleClass

CSampleClass::CSampleClass()
{
	iSample = 0;
}

CSampleClass::~CSampleClass()
{
}


// CSampleClass 멤버 함수


// 샘플 메소드
void CSampleClass::SampleMethod(int arg1, char arg2)
{
	// TODO: 여기에 구현 코드 추가.
	// int div = 1000 / arg1;
}


CString CSampleClass::AddString(LPCTSTR arg1, CString& arg2)
{
	// TODO: 여기에 구현 코드 추가.
	CString result = arg1 + arg2;
	arg1 = result;
	arg2 = result;
	return result;
}

void CSampleClass::TestProcFile()
{
	// TODO: 여기에 구현 코드 추가.
	CFile cFileWrite;
	cFileWrite.Open(_T(".\\test_sample.txt"), CFile::modeCreate|CFile::modeWrite);
	cFileWrite.Write(_T("Visual C++"), 20);
	cFileWrite.Close();
}

void CSampleClass::TestFileRead()
{
	// TODO: 여기에 구현 코드 추가.
	char buffer[100];
	CFile cFileWrite;
	cFileWrite.Open(_T(".\\test_sample.txt"), CFile::modeRead);
	cFileWrite.Read(buffer,100);
	TRACE("READ:%S\n", buffer);
	// --------------------------
	// SIZE
	ULONGLONG lSize = cFileWrite.GetLength();
	TRACE("SIZE:%d\n", lSize);
	cFileWrite.Close();
	// --------------------------
	// STATUS
	CFileStatus stat;
	CFile::GetStatus(_T(".\\test_sample.txt"), stat);
	TRACE("%d/%d/%d %d:%d:%d\n"
		, stat.m_ctime.GetYear()
		, stat.m_ctime.GetMonth()
		, stat.m_ctime.GetDay()
		, stat.m_ctime.GetHour()
		, stat.m_ctime.GetMinute()
		, stat.m_ctime.GetSecond());
}

void CSampleClass::TestTime()
{
	// TODO: 여기에 구현 코드 추가.
	COleDateTime cTime1;
	cTime1.SetDateTime(2010,10,30,11,22,33);
	TRACE("[Time1] %d/%d/%d %d:%d:%d\n"
		, cTime1.GetYear()
		, cTime1.GetMonth()
		, cTime1.GetDay()
		, cTime1.GetHour()
		, cTime1.GetMinute()
		, cTime1.GetSecond());

	COleDateTime cTime2 = COleDateTime::GetCurrentTime();
	TRACE("[Time2] %d/%d/%d %d:%d:%d\n"
		, cTime2.GetYear()
		, cTime2.GetMonth()
		, cTime2.GetDay()
		, cTime2.GetHour()
		, cTime2.GetMinute()
		, cTime2.GetSecond());

	COleDateTime cTime3;
	cTime3.ParseDateTime(_T("2023/01/02 11:22:33"));
	TRACE("[Time3] %d/%d/%d %d:%d:%d\n"
		, cTime3.GetYear()
		, cTime3.GetMonth()
		, cTime3.GetDay()
		, cTime3.GetHour()
		, cTime3.GetMinute()
		, cTime3.GetSecond());

	COleDateTime cTime4 = COleDateTime::GetCurrentTime();
	TRACE(cTime4.Format(_T("%Y/%m/%d %H:%M:%S\n")));
}


void CSampleClass::TestTimeCompare()
{
	// TODO: 여기에 구현 코드 추가.
	COleDateTime cur = COleDateTime::GetCurrentTime();
	COleDateTime cTime;
	cTime.SetDateTime(2023,01,02,11,22,33);
	if (cur > cTime) {
		TRACE("기준보다 크다\n");
	}
	else 
	{
		TRACE("기준보다 작다\n");
	}

	COleDateTimeSpan cSpan;
	cSpan.SetDateTimeSpan(15,0,0,0); // 일,시분초만 설정가능
	COleDateTime result;
	TRACE("[현재] %d/%d/%d %d:%d:%d\n"
		, cur.GetYear()
		, cur.GetMonth()
		, cur.GetDay()
		, cur.GetHour()
		, cur.GetMinute()
		, cur.GetSecond());
	result = cur - cSpan;
	TRACE("[15일전] %d/%d/%d %d:%d:%d\n"
		, result.GetYear()
		, result.GetMonth()
		, result.GetDay()
		, result.GetHour()
		, result.GetMinute()
		, result.GetSecond());
}
