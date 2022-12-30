#include <iostream>

using namespace std;

void chkAdd()
{
    int a;
    int b[10];

    cout<<"변수a의 주소:"<<&a<<endl;
    cout<<"배열b의 주소:"<<b<<endl;
    cout<<"함수chkAdd의 주소:"<<&chkAdd<<endl;

    cout<<"변수a의 주소:"<<(size_t)&a<<endl;
    cout<<"배열b의 주소:"<<(size_t)b<<endl;
    cout<<"함수chkAdd의 주소:"<<(size_t)&chkAdd<<endl;
}
int main()
{
    chkAdd();
}

// 변수a의 주소:0x8d6dbff75c
// 배열b의 주소:0x8d6dbff730
// 함수chkAdd의 주소:1

// 변수a의 주소:607431685980
// 배열b의 주소:607431685936
// 함수chkAdd의 주소:140701697841104