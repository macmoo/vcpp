#include <iostream>

using namespace std;

template <typename T> void func(T a, T b)
{
    cout << "a + b = " << a + b << endl;
}
template <typename T> void func(T a, T b, T c)
{
    cout << "a + b + c = " << a + b + c<< endl;
}
int main()
{
    int x=10, y=20, z=30;
    func(x,y);
    func(x,y,z);
}
// a + b = 30
// a + b + c = 60