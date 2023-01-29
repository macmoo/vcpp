#include <iostream>

using namespace std;

int main()
{
    int a;
    int *p=&a;

    a=10;
    cout << a << '\n';
    cout << *p << '\n';

    *p=20;
    cout << a << '\n';
    cout << *p << '\n';
}

// 10
// 10
// 20
// 20