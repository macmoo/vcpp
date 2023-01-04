#include <iostream>

using namespace std;
// ----------------------------------------
class Cls
{
private:
    int v1, v2;
public:
    Cls(){ cout << "cls() 持失切" << endl; };
    Cls(int n1,int n2);
    ~Cls(){ cout << "社瑚切 v1:"<< v1 << ", v2:" << v2 << endl; }
    void show();
    Cls operator+(Cls& inst);
};
Cls::Cls(int n1,int n2)
{
    cout << "cls(int n1,int n2) 持失切" << endl;
    v1 = n1;
    v2 = n2;
}
void Cls::show()
{
    cout << "----------------------------------------" << endl;
    cout << "v1:" << v1 << endl;
    cout << "v2:" << v2 << endl;
}
Cls Cls::operator+(Cls& inst)
{
    Cls c;
    c.v1 = this->v1 + inst.v1;
    c.v2 = this->v2 + inst.v2;
    return c;
}
// ----------------------------------------
int main()
{
    cout << "----------------------------------------" << endl;
    Cls a(100,200);
    Cls b(10,20);
    Cls c;
    c = a + b;
    // a.show();
    // b.show();
    // c.show();
}
// ----------------------------------------
// cls(int n1,int n2) 持失切
// cls(int n1,int n2) 持失切
// cls() 持失切
// cls() 持失切
// 社瑚切 v1:110, v2:220
// ----------------------------------------
// v1:100
// v2:200
// ----------------------------------------
// v1:10
// v2:20
// ----------------------------------------
// v1:110
// v2:220
// 社瑚切 v1:110, v2:220
// 社瑚切 v1:10 , v2:20
// 社瑚切 v1:100, v2:200