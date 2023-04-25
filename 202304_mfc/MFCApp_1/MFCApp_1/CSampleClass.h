#pragma once

// CSampleClass 명령 대상

class CSampleClass : public CObject
{
public:
	CSampleClass();
	virtual ~CSampleClass();
	// 샘플 메소드
	void SampleMethod(int arg1, char arg2);
	int iSample;
};


