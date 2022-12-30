#include <iostream>

using namespace std;

void func1(int a, int b);

int main()
{
    int x=500;
    int y=1000;
    void (*p)(int a, int b); // 함수포인터의 선언
    // p = func1; // OK
    p = &func1; // OK
    p(x,y);
}
void func1(int a, int b)
{
    cout << a << endl;
    cout << b << endl;
}

// 500 
// 1000