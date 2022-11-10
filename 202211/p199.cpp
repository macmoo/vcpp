#include <iostream>

using namespace std;

int main()
{
	char str[] = "Visual C++";
	for(int i = 0 ; str[i] != '\0' ; ++i )
	{
		cout << (int)(unsigned char)str[i] << '\n';
	}	
}