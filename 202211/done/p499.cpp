#include <iostream>

using namespace std;
// ----------------------------------------
class C1
{
private:
    int v1, v2;
public:
    C1(){};
    C1(int x,int y);
    void show();
    C1 operator-(); // 단항연산자
    C1 operator+(C1 i);
};
C1::C1(int x,int y)
{
    v1=x;
    v2=y;
}
void C1::show()
{
    cout << "v1:" << v1 << "\tv2:" << v2 << endl;
}
C1 C1::operator-()
{
    return C1(-v1,-v2);
}
C1 C1::operator+(C1 c)
{
    return C1(v1+c.v1, v2+c.v2);
}
// ----------------------------------------
int main()
{
    std::cout << "----------------------------------------" << endl;
    C1 a(10,20), b(500,1000), c;
    c = -a;
    a.show();
    b.show();
    c.show();
    std::cout << "----------------------------------------" << endl;
    c = a+b;
    a.show();
    b.show();
    c.show();
    std::cout << "----------------------------------------" << endl;
}
// ----------------------------------------
// v1:10   v2:20
// v1:500  v2:1000
// v1:-10  v2:-20
// ----------------------------------------
// v1:10   v2:20
// v1:500  v2:1000
// v1:510  v2:1020
// ----------------------------------------