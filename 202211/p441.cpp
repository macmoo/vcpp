#include <iostream>

// using namespace std;
// ----------------------------------------
class SuperClass
{
public:
    virtual void Disp();
};
// ----------------------------------------
void SuperClass::Disp()
{
    std::cout << "��ǰ���� ��ϵǾ� ���� �ʴ�.\n";
}
// ----------------------------------------
class SubClassA : public SuperClass
{
public:
    void Disp();
};
// ----------------------------------------
void SubClassA::Disp()
{
    std::cout << "��ǰ���� PRODUCTS�̴�.\n";
}
// ----------------------------------------
class SubClassB : public SuperClass
{
public:
    void Disp();
};
// ----------------------------------------
void SubClassB::Disp()
{
    std::cout << "��ǰ���� MANUFACTURE�̴�.\n";
}
// ----------------------------------------
class SubClassC : public SuperClass
{
public:
    void Disp();
};
// ----------------------------------------
void SubClassC::Disp()
{
    std::cout << "��ǰ���� GOODS�̴�.\n";
}
// ----------------------------------------
int main()
{
    SuperClass* obj[3];

    SubClassA a;
    SubClassB b;
    SubClassC c;

    obj[0] = &a;
    obj[1] = &b;
    obj[2] = &c;

    std::cout << "********************************\n";
    for(int i = 0 ; i < 3 ; i++)
    {
        obj[i] -> Disp();
        std::cout << "********************************\n";
    }
}
// ********************************
// ��ǰ���� PRODUCTS�̴�.
// ********************************
// ��ǰ���� MANUFACTURE�̴�.
// ********************************
// ��ǰ���� GOODS�̴�.
// ********************************