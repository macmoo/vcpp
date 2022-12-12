#include <iostream>
#include <cstring>
#include <string.h>

using namespace std;

int main()
{
	// ----------------------------
	char str_1[11];
	strcpy_s(str_1,"Visual C++");
	cout << str_1 << endl;
	// ----------------------------
	char str_2[10];
	char str_3[10] = "12345";
	strncpy_s(str_2, str_3, 3);
	cout << str_2 << endl; // 123
	// ----------------------------
	char str_4[10] = "111";
	char str_5[10] = "222";
	strcat_s(str_4, str_5);
	cout << str_4 << endl; // 111222
	// ----------------------------
	char str_1_2[100] = "Visual C++";
	int a = strcmp(str_1, str_1_2);
	cout << a << endl; // 0
	// ----------------------------
	char q1[100] = "AABAAA";
	char q2[100] = "AAAAAA";
	if(strncmp(q1, q2, 3) > 0) // 앞에서 3문자까지만 비교
		cout << "Str1 is bigger\n";
	else
		cout << "Str2 is bigger\n";
	// ----------------------------
	char q3[100] = "Visual Studio community";
	char *p;
	p = strchr(q3, 'S');
	cout << p << "\n"; // Studio community
	p = strstr(q3, "dio");
	cout << p << "\n"; // dio community
	// ----------------------------
	cout << endl;
}
