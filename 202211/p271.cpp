#include <iostream>

using namespace std;

int& add(int& a, int& b)
{
    static int ver;
    a *= 10;
    b *= 20;
    ver = a + b;
    return ver;
}
int main()
{
    int x, y, z;
    cout << "IN:";
    cin >> x >> y;
    z = add(x, y);
    cout << x << ", " << y << ", " << z << endl;
    z = add(x, y);
    cout << x << ", " << y << ", " << z << endl;
}

// IN:10 20 
// 100, 400, 500
// 1000, 8000, 9000