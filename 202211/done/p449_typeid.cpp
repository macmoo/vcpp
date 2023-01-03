#include <iostream>
#include <typeinfo>
// ----------------------------------------
class C1
{
public:
    int x,y;
    C1(int n1,int n2){x=n1;y=n2;}
    // 이 형식(순수가상함수)가 아니면 동작 안함
    // 가상테이블을 만들지 않아서?
    virtual void vFunc()=0;
    // virtual void vFunc(); : 동작안함
};
// ----------------------------------------
class C2 : public C1
{
public:
    C2(int n1=0, int n2=0):C1(n1,n2){;}
    void disp1() { std::cout << "Disp1 : x + y = " << x+y << std::endl; }
    void vFunc() { ; }
};
// ----------------------------------------
class C3 : public C1{
public:
    C3(int n1=0, int n2=0):C1(n1,n2){;}
    void disp2() { std::cout << "Disp2 : x * y = " << x*y << std::endl; }
    void vFunc() { ; }
};
// ----------------------------------------
void check(C1* obj)
{
    std::cout << "----------------------------------------\n";
    // std::cout << "name:" <<  (char*)typeid(*obj). << std::endl;
    std::cout << "name:" <<  typeid(*obj).name() << std::endl;
    
    if(typeid(*obj) == typeid(C2))
        static_cast<C2*>(obj)->disp1();

    if(typeid(*obj) == typeid(C3))
        static_cast<C3*>(obj)->disp2();
}
// ----------------------------------------
int main()
{
    C2 o2(10,20);
    C3 o3(10,20);

    std::cout << "----------------------------------------\n";
    std::cout << "name:" <<  typeid(C2).name() << std::endl;
    std::cout << "name:" <<  typeid(o2).name() << std::endl;

    std::cout << "----------------------------------------\n";
    std::cout << "name:" <<  typeid(C3).name() << std::endl;
    std::cout << "name:" <<  typeid(o3).name() << std::endl;

    check(&o2);
    check(&o3);
}
// ----------------------------------------
// name:2C2
// name:2C2
// ----------------------------------------
// name:2C3
// name:2C3
// ----------------------------------------
// name:2C2
// Disp1 : x + y = 30
// ----------------------------------------
// name:2C3
// Disp2 : x * y = 200
// ----------------------------------------