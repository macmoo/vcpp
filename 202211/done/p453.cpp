#include <iostream>

using namespace std;
// ----------------------------------------
class Cls1
{
protected:
    int x;
public:
    Cls1(int a=10){x=a;};
    void showData1(){ cout << "Cls1.showData1 => x:" << x << endl;};
    void showData4(){ cout << "Cls1.showData4 => x:" << x << endl;};
};
// ----------------------------------------
class Cls2
{
protected:
    int y;
public:
    Cls2(int a=50){y=a;};
    void showData2(){ cout << "Cls2.showData2 => y:" << y << endl;};
    void showData4(){ cout << "Cls2.showData4 => y:" << y << endl;};
};
// ----------------------------------------
class Cls3:public Cls1, public Cls2
{
protected:
    int z;
public:
    Cls3(int a=100){z=a;};
    void showData3(){ cout << "Cls3.showData3 => z:" << z << endl;};
    void showData4(){ cout << "Cls3.showData4 => z:" << z << endl;};
};
// ----------------------------------------

int main()
{
    std::cout << "----------------------------------------\n";
    Cls3 c;
    c.showData1();
    c.showData2();
    c.showData3();
    std::cout << "----------------------------------------\n";
    c.showData4();
    c.showData4();
    std::cout << "----------------------------------------\n";
    c.Cls1::showData4();
    c.Cls3::showData4();
    std::cout << "----------------------------------------\n";
}
// ----------------------------------------
// Cls1.showData1 => x:10
// Cls2.showData2 => y:50
// Cls3.showData3 => z:100
// ----------------------------------------
// Cls3.showData4 => z:100
// Cls3.showData4 => z:100
// ----------------------------------------
// Cls1.showData4 => x:10
// Cls3.showData4 => z:100
// ----------------------------------------