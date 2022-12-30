#include <iostream>

using namespace std;

void print(int *a, int cnt)
{
    cout << "------------------------" << endl;
    for(int i=0;i<cnt;i++)
    {
        cout << *(a+i) << endl;
    }
}

int main()
{
    int arr[5]={1,2,3,4,5};
    int brr[5]={1,2,3,4,5};
    int* const p = arr; // 포인터가 정수
    print(arr,5);

    *(p+1)=500;
    print(arr,5);

    // p = &arr[2]; // ERROR
    // ---------------------------
    const int* q = brr; // 포인터가 참조하는 곳이 정수
    // print(q,5); // ERROR=>인수가 const이 아니면 안됨
    // *(q+1) = 400; // ERROR
    q = arr;
}
// ------------------------
// 1
// 2
// 3
// 4
// 5
// ------------------------
// 1
// 500
// 3
// 4
// 5