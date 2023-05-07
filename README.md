# vcpp

# 정리

|#|내용|비고|
|-|----|---|
|1|Compile|Ctrl + Alt + N|
| |||
| |||

</br>

# 요약

- LPCTSTR</br>
  CString클래스를 함수에 넘길경우</br>
  값으로 넘길경우는 LPCTSTR을 써야함</br>
  주소로 넘길경우는 &CString으로 써야함</br>
  CString을 함수의 반환값으로 쓸수 있다.
- 


# 참조

* https://amanhimself.dev/blog/change-color-of-hidden-files-folders-in-vscode/

# 단축키

* https://learn.microsoft.com/ko-kr/visualstudio/ide/default-keyboard-shortcuts-in-visual-studio?view=vs-2022
* https://jhnyang.tistory.com/323
* https://stackoverflow.com/questions/2279000/visual-studio-short-cut-key-duplicate-line


# 함수

|함수명|설명|비고|
|----|---|---|
|_T()|문자열을 TCHAR형으로 변환하는 마크로||
|TRACE()|문자열 출력 매크로||
|-|%d|부호있는 10진수|
|-|%X|부호없는 16진수|
|-|%S|문자열|
|"문자열".Insert(0, _T("1"))|문자열 추가||
|"문자열".Delete(2, 3)|문자열 삭제||
|"문자열".GetLength()|문자열 길이||
|"문자열".GetLength() * sizeof(TCHAR)|문자열의 바이트 길이||
|"문자열".|||
|"문자열".|||
|"문자열".|||
|"문자열".|||
||||
||||
||||


</br>

### <r>※ CFile</r>

<pre><code>void CSampleClass::TestProcFile()
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
</code></pre>

</br>

### <r>※ CTime</r>

<pre><code>void CSampleClass::TestTime()
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

</code></pre>

</br>

### <r>※ </r>

<pre><code>
</code></pre>

</br>

### <r>※ </r>

<pre><code>
</code></pre>

</br>

### <r>※ </r>

<pre><code>
</code></pre>

</br>

### <r>※ </r>

<pre><code>
</code></pre>

</br>

### <r>※ </r>

<pre><code>
</code></pre>

</br>

### <r>※ </r>

<pre><code>
</code></pre>

</br>

### <r>※ </r>

<pre><code>
</code></pre>



<style>
r { color: Red }
o { color: Orange }
g { color: Green }
b { color: Blue }
</style>