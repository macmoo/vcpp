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
    name="�̼���";
    cout << "Customer������ȣ��" << endl;
}
Customer::~Customer()
{
    cout << "Customer�Ҹ���ȣ��" << endl;
}
// ----------------------------------------
void disp(Customer c);
// ----------------------------------------
int main()
{
    std::cout << "----------------------------------------\n";
    Customer taro;
    taro.number=1010;
    taro.name="�ٳ�ī Ÿ��";
    
    cout << "Disp()ȣ��" << endl;
    disp(taro);
}
// ----------------------------------------
void disp(Customer c)
{
    cout << "����ȣ:" << c.number << endl;
    cout << "��    ��:" << c.name   << endl;
}
// ----------------------------------------
// Customer������ȣ��
// Disp()ȣ��
// ����ȣ:1010
// ��    ��:�ٳ�ī Ÿ��
// Customer�Ҹ���ȣ��
// Customer�Ҹ���ȣ��