#include <iostream>

using namespace std;
// ----------------------------------------
class MyClass
{
public:
    int num1,num2;
};
// ----------------------------------------
int main()
{
    std::cout << "----------------------------------------\n";
    MyClass obj1;

    int MyClass::* dp;

    dp = &MyClass::num1;
    obj1.*dp = 100;
    cout << "num1:" << obj1.num1 << endl;
    cout << "num2:" << obj1.num2 << endl;

    dp = &MyClass::num2;
    obj1.*dp = 200;
    cout << "num1:" << obj1.num1 << endl;
    cout << "num2:" << obj1.num2 << endl;
}
// ----------------------------------------
// num1:100
// num2:6126
// num1:100
// num2:200