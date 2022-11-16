#include <iostream>
#include <cstring>

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
	cout << str_2 << endl;
	// ----------------------------
	char str_4[10] = "111";
	char str_5[10] = "222";
	strcat_s(str_4, str_5);
	cout << str_4 << endl;

	cout << endl;


}