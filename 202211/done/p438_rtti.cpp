#include <iostream>
#include <typeinfo>

// ----------------------------------------
class Cls1
{
protected:
    int x,y;
public:
    Cls1(int a,int b){x=a;y=b;};
    virtual void showData() = 0;
};
// ----------------------------------------
class Cls2:public Cls1
{
public:
    Cls2(int a, int b):Cls1(a,b){;}
    void showData();
};
// ----------------------------------------
void Cls2::showData()
{
    std::cout << "ID:[" << x << "]\nAGE:["<< y <<"]\n\n";
}
// ----------------------------------------
class Cls3:public Cls1
{
public:
    Cls3(int a,int b):Cls1(a,b){;}
    void showData();
};
// ----------------------------------------
void Cls3::showData()
{
    std::cout << "HEIGHT:[" << x << "]\nWEIGHT:["<< y <<"]\n\n";
}
// ----------------------------------------
int main()
{
    Cls1* p;
    Cls2 val_1(2020, 31);
    Cls3 val_2(175, 40);

    p = &val_1;
    if(typeid(*p) == typeid(Cls2))
        std::cout << "Cls2�� ��ü\n";
    else
        std::cout << "Cls3�� ��ü\n";

    p = &val_2;
    if(typeid(*p) == typeid(Cls2))
        std::cout << "Cls2�� ��ü\n";
    else
        std::cout << "Cls3�� ��ü\n";
}
// Cls2�� ��ü
// Cls3�� ��ü