#include <iostream>

using namespace std;
// ----------------------------------------
class Customer
{
public:
    int number;
    string name;
    Customer(int n);
    Customer(const Customer &obj); // ���� ������
    ~Customer();
};
Customer::Customer(int n)
{
    number=n;
    name="�̼���";
    cout << "Customer������ȣ��" << endl;
}
Customer::Customer(const Customer &obj)
{
    number=obj.number+1;
    name=obj.name;
    cout << "Customer���������ȣ��" << endl;
}
Customer::~Customer()
{
    cout << "Customer�Ҹ���ȣ�� number:" << number << endl;
}
// ----------------------------------------
void disp(Customer c);
// ----------------------------------------
int main()
{
    std::cout << "----------------------------------------\n";
    Customer taro(100);
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
// Customer���������ȣ��
// ����ȣ:101
// ��    ��:�ٳ�ī Ÿ��
// Customer�Ҹ���ȣ�� number:101
// Customer�Ҹ���ȣ�� number:100
// ----------------------------------------
// �ʱ�ȭ -> ��������� ȣ��O
//  ClassA a;
//  ClassB b = a;
// ����   -> ��������� ȣ��X
//  ClassB b = a;
//  b = a;