#include <iostream>

using namespace std;

int calc(int a)
{
    return a * 1;
}
int calc(int* a)
{
    return *a * 2;
}
double calc(double* a)
{
    return *a * 3;
}
double calc(double& a)
{
    return a * 4;
}
// 위의 int calc(int a)와 겹침
// int calc(int& a)
// {
//     return a * 10;
// }
int main()
{
    int  a = 10;
    int  b = 10;
    int* c = &b;
    cout << calc(a) << endl;
    cout << calc(c) << endl;

    double  d = 20;
    double* e = &d;
    double  f = 20;
    cout << calc(e) << endl;
    cout << calc(f) << endl;
}
// 10
// 20
// 60
// 80