#include <iostream>

using namespace std;

void calcAdd(int& a)
{
    a += 100;
}
void calcMinus(int* a)
{
    *a -= 10;
}

void addArr(int a[])
{
    int total = 0;
    for(int i = 0; i < 5; i++)
    {
        total = total + a[i];
    }
    cout << total << endl;
}

void addArr2(int* p)
{
    int total = 0;
    for(int i = 0; i < 5; i++)
    {
        total = total + p[i];
    }
    cout << total << endl;
}
int main()
{
    int x = 1;
    int y[5] = {10, 10, 10, 10, 10};

    calcAdd(x);
    cout << x << endl;

    calcMinus(&x);
    cout << x << endl;

    addArr(y);
    addArr(y);
}
