#include <iostream>

using namespace std;

int* add(int* a, int* b)
{
    static int ver;
    *a *= 10;
    *b *= 20;
    return a;
}
int main()
{
    int x, y, *z;
    cout << "입력:" << endl;
    cin >> x >> y;

    z = add(&x, &y);
    cout << x << ", " << y << ", " << *z << endl;
}
// 10 20
// ->
// 100, 400, 100