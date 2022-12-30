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
        cout << i + 1 << "번째의 값을 입력해라:" << flush;
        cin >> *(p+i);
    }
    add(p, a);
    delete[] p;
}

// Size of Arr:5
// 1번째의 값을 입력해라:1
// 2번째의 값을 입력해라:2
// 3번째의 값을 입력해라:3
// 4번째의 값을 입력해라:4
// 5번째의 값을 입력해라:5
// 15