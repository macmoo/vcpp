#include <iostream>

using namespace std;

void chkAdd()
{
    int a;
    int b[10];

    cout<<"����a�� �ּ�:"<<&a<<endl;
    cout<<"�迭b�� �ּ�:"<<b<<endl;
    cout<<"�Լ�chkAdd�� �ּ�:"<<&chkAdd<<endl;

    cout<<"����a�� �ּ�:"<<(size_t)&a<<endl;
    cout<<"�迭b�� �ּ�:"<<(size_t)b<<endl;
    cout<<"�Լ�chkAdd�� �ּ�:"<<(size_t)&chkAdd<<endl;
}
int main()
{
    chkAdd();
}

// ����a�� �ּ�:0x8d6dbff75c
// �迭b�� �ּ�:0x8d6dbff730
// �Լ�chkAdd�� �ּ�:1

// ����a�� �ּ�:607431685980
// �迭b�� �ּ�:607431685936
// �Լ�chkAdd�� �ּ�:140701697841104