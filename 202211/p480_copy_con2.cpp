#include <iostream>

using namespace std;
// ----------------------------------------
class Customer
{
public:
    int number;
    string name;
    Customer(int n);
    Customer(int n); // 
    ~Customer();
};
Customer::Customer()
{
    number=0;
    name="미설정";
    cout << "Customer생성자호출" << endl;
}
Customer::~Customer()
{
    cout << "Customer소멸자호출" << endl;
}
// ----------------------------------------
void disp(Customer c);
// ----------------------------------------
int main()
{
    std::cout << "----------------------------------------\n";
    Customer taro;
    taro.number=1010;
    taro.name="다나카 타로";
    
    cout << "Disp()호출" << endl;
    disp(taro);
}
// ----------------------------------------
void disp(Customer c)
{
    cout << "고객번호:" << c.number << endl;
    cout << "이    름:" << c.name   << endl;
}
// ----------------------------------------
// Customer생성자호출
// Disp()호출
// 고객번호:1010
// 이    름:다나카 타로
// Customer소멸자호출
// Customer소멸자호출