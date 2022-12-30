#include <iostream>

using namespace std;

int main()
{
    char c='a';
    int i=10;
    double d=1.23;
    void *p;

    p=&c;
    cout << *static_cast<char*>(p) << endl;

    p=&i;
    cout << *static_cast<int*>(p) << endl;

    p=&d;
    cout << *static_cast<double*>(p) << endl;
}
// a
// 10
// 1.23