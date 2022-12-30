#include <iostream>

using namespace std;

int main()
{
    int x=100;
    int y=600;
    void *p; // ******

    p=&x;
    cout << *static_cast<int*>(p) << endl;

    p =&y;
    cout << *static_cast<int*>(p) << endl;
}

// 100
// 600