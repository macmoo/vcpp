#include <iostream>

using namespace std;
// ----------------------------------------
class C1
{
public:
    string name;
public:
    C1(){ cout << "������" << endl; };
    ~C1(){ cout << "�Ҹ��� name:" << name << endl; };
};
// ----------------------------------------
void func()
{
    C1 o1;
    o1.name = "obj1";
}
// ----------------------------------------
int main()
{
    std::cout << "----------------------------------------\n";
    func();
    C1 o2;
    o2.name = "obj2";
    return 0;
}
// ----------------------------------------
// ������
// �Ҹ��� name:obj1
// ������
// �Ҹ��� name:obj2
