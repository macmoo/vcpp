#include <iostream>

using namespace std;
// ----------------------------------------
class MyClass
{
public:
    int num1;
    void func(int x);
};
void MyClass::func(int x)
{
    cout << "num1:" << num1 << endl;
    cout << "x:" << x << endl;
}
// ----------------------------------------
int main()
{
    std::cout << "----------------------------------------\n";
    MyClass obj1;

    int MyClass::* dp;
    void (MyClass::* fp)(int x);

    dp = &MyClass::num1;
    obj1.*dp = 100;

    fp = &MyClass::func;
    (obj1.*fp)(500);
}
// ----------------------------------------
// num1:100
// x:500