#include <iostream>

using namespace std;
// ----------------------------------------
class C1
{
public:
    string name;
public:
    C1(){ cout << "持失切" << endl; };
    ~C1(){ cout << "社瑚切 name:" << name << endl; };
};
// ----------------------------------------
void func()
{
    C1 o1;
    o1.name = "obj1";
}
// ----------------------------------------
int main()
{
    std::cout << "----------------------------------------\n";
    func();
    C1 o2;
    o2.name = "obj2";
    return 0;
}
// ----------------------------------------
// 持失切
// 社瑚切 name:obj1
// 持失切
// 社瑚切 name:obj2
