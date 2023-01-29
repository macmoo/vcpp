#include <iostream>

using namespace std;

extern int extA;

void add()
{
    int b = 0;
    extA++;
    b++;
    cout << "extA = [" << extA << "], b = [" << b << "]\n";
}

int main()
{
    add();
    add();
    add();
}