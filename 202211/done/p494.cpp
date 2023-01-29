#include <iostream>

using namespace std;
// ----------------------------------------
class Cls
{
private:
    int v;
public:
    Cls(){};
    Cls(int p);
    void show();
    int func();
};
Cls::Cls(int p)
{
    v = p;
}
void Cls::show()
{
    cout << "val:" << v << endl;
}
int Cls::func()
{
    return v;
}
Cls operator+(int p1, Cls p2)
{
    return Cls(p1 + p2.func());
}
// ----------------------------------------
int main()
{
    std::cout << "----------------------------------------" << endl;
    Cls a(100), b;
    b = 1000 + a;
    a.show();
    b.show();
}
// ---------------------------------------
// val:100
// val:1100