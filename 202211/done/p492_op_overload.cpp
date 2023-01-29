#include <iostream>

using namespace std;
// ----------------------------------------
class C1
{
private:
    int v1, v2;
public:
    C1(){}
    C1(int n1,int n2);
    void show();
    C1 operator+(C1 o);
};
C1::C1(int n1,int n2)
{
    v1=n1;
    v2=n2;
}
void C1::show()
{
    cout << "val1:" << v1 << endl;
    cout << "val2:" << v2 << endl;
}
C1 C1::operator+(C1 o)
{
    C1 c;
    c.v1 = this->v1 + o.v1;
    c.v2 = this->v2 + o.v2;
    return c;
}
// ----------------------------------------
int main()
{
    C1 a(100,200), b(500, 1000), c;
    c = a+b;

    cout << "----------------------------------------\n";
    cout << "a:\n";
    a.show();

    cout << "----------------------------------------\n";
    cout << "b:\n";
    b.show();

    cout << "----------------------------------------\n";
    cout << "c:\n";
    c.show();
}
// ----------------------------------------
// a:
// val1:100
// val2:200
// ----------------------------------------
// b:
// val1:500
// val2:1000
// ----------------------------------------
// c:
// val1:600
// val2:1200