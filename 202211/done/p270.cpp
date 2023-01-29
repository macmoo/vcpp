#include <iostream>

using namespace std;
int& add(int& a, int& b)
{
    a *= 10;
    b *= 20;
    return a;
}
int main()
{
    int x, y, z;
    cout << "입력:";
    cin >> x >> y;
    cout << "BEFORE => x:"<< x << ", y:" << y << ", z:" << z << endl;
    z = add(x, y);
    cout << "AFTER => x:"<< x << ", y:" << y << ", z:" << z << endl;
}