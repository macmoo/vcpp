#include <iostream>

// using namespace std;
// ----------------------------------------
class Cls1
{
protected:
    int x,y;
public:
    Cls1(int a,int b){x=a;y=b;};
    virtual void showData()=0;
};
// ----------------------------------------
class Cls2 : public Cls1
{
public:
    Cls2(int a,int b):Cls1(a,b){;}
    void showData();
};
void Cls2::showData()
{
    std::cout << "ID:[" << x << "], AGE:[" << y << "]\n";
}
// ----------------------------------------
class Cls3 : public Cls1{
public:
    Cls3(int a,int b):Cls1(a,b){;}
    void showData();
};
void Cls3::showData()
{
    std::cout << "HEIGHT:[" << x << "], WEIGHT:[" << y << "]\n";
}
// ----------------------------------------
int main()
{
    Cls1* p;
    Cls2 val_1(2020, 31);
    Cls3 val_2(172,77);

    p = &val_1;
    p->showData();

    p = &val_2;
    p->showData();
}
// ID:[2020], AGE:[31]
// HEIGHT:[172], WEIGHT:[77]