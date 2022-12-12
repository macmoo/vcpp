#include <iostream>

using namespace std;

void show(const int &a)
{
    cout << a << endl;
}

int main()
{
    const int x = 500;
    show(x);
    show(100);
}