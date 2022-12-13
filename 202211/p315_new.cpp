#include <iostream>

using namespace std;

int main()
{
    int* p=new int;
    *p=5;
    cout << p << endl;
    cout << (size_t)p << endl;
    cout << *p << endl;
    delete p;
}
// 0x14d67f8e4b0
// 1431968474288
// 5