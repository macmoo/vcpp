#include <iostream>

using namespace std;

void func1(int a);
void func2(int a);
void func3(int a);

void func4();

int main()
{
    void (*funcp[])(int) = {func1,func2,func3};
    for(int i=0;i<3;i++)
    {
        funcp[i](500);
    }
    // --------------
    void (*funcp2)() = &func4; // & 생략가능
    (*funcp2)();
}
void func1(int a)
{
    cout << "func1=" << a << endl;
}
void func2(int a)
{
    cout << "func2=" << a << endl;
}
void func3(int a)
{
    cout << "func3=" << a << endl;
}
void func4()
{
    cout << "func4" << endl;
}
// func1=500
// func2=500
// func3=500
// func4