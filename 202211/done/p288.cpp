#include <iostream>

using namespace std;

template <typename T> T calc(T dt1, T dt2)
{
    return dt1 + dt2;
}
int main()
{
    int i1, i2, add1;
    double d1, d2, add2;

    cout << "input 정수:";
    cin >> i1 >> i2;
    add1 = calc(i1, i2);
    cout << add1 << endl;

    cout << "input 실수:";
    cin >> d1 >> d2;
    add2 = calc(d1, d2);
    cout << add2 << endl;
}