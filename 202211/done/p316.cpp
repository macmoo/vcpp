#include <iostream>

using namespace std;
void add(int* pp, int b)
{
    int total=0;
    for(int i=0;i<b;i++)
    {
        total=total+*(pp+i);
    }
    cout << total << '\n';
}
int main()
{
    int* p;
    int a;
    cout << "Size of Arr:" << flush;
    cin >> a;

    p = new int[a];

    for(int i=0;i<a;i++)
    {
        cout << i + 1 << "��°�� ���� �Է��ض�:" << flush;
        cin >> *(p+i);
    }
    add(p, a);
    delete[] p;
}

// Size of Arr:5
// 1��°�� ���� �Է��ض�:1
// 2��°�� ���� �Է��ض�:2
// 3��°�� ���� �Է��ض�:3
// 4��°�� ���� �Է��ض�:4
// 5��°�� ���� �Է��ض�:5
// 15