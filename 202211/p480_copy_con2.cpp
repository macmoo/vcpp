#include <iostream>

using namespace std;
// ----------------------------------------
class Customer
{
public:
    int number;
    string name;
    Customer(int n);
    Customer(const Customer &obj); // 복사 생성자
    ~Customer();
};
Customer::Customer(int n)
{
    number=n;
    name="미설정";
    cout << "Customer생성자호출" << endl;
}
Customer::Customer(const Customer &obj)
{
    number=obj.number+1;
    name=obj.name;
    cout << "Customer복사생성자호출" << endl;
}
Customer::~Customer()
{
    cout << "Customer소멸자호출 number:" << number << endl;
}
// ----------------------------------------
void disp(Customer c);
// ----------------------------------------
int main()
{
    std::cout << "----------------------------------------\n";
    Customer taro(100);
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
// Customer복사생성자호출
// 고객번호:101
// 이    름:다나카 타로
// Customer소멸자호출 number:101
// Customer소멸자호출 number:100
// ----------------------------------------
// 초기화 -> 복사생성자 호출O
//  ClassA a;
//  ClassB b = a;
// 대입   -> 복사생성자 호출X
//  ClassB b = a;
//  b = a;