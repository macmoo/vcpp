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
    std::cout << "제품명이 등록되어 있지 않다.\n";
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
    std::cout << "제품명은 PRODUCTS이다.\n";
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
    std::cout << "제품명은 MANUFACTURE이다.\n";
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
    std::cout << "제품명은 GOODS이다.\n";
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
// 제품명은 PRODUCTS이다.
// ********************************
// 제품명은 MANUFACTURE이다.
// ********************************
// 제품명은 GOODS이다.
// ********************************