#include <iostream>

using namespace std;

int main()
{
    int arr[5]={10,20,30,40,50};
    int* p=arr;
    int* q=arr;
    cout << "----------------------------" << endl;
    cout << "value of arr[0]=" << arr[0] << endl;
    cout << "value of arr[0]=" << *p << endl;
    cout << "value of arr[1]=" << *(p+1) << endl;
    cout << "value of arr[1]=" << *p+1 << endl;
    cout << "value of arr[2]=" << *(++p) << endl;
    // addr
    cout << "----------------------------" << endl;
    cout << "address of arr[0]" << q << endl;
    cout << "address of arr[0]" << arr << endl;
    cout << "address of arr[0]" << &arr[0] << endl;
    cout << "----------------------------" << endl;
    cout << "address of arr[1]" << q+1 << endl;
    cout << "address of arr[1]" << arr+1 << endl;
    cout << "address of arr[1]" << &arr[1] << endl;
    cout << "----------------------------" << endl;
}

// ----------------------------
// value of arr[0]=10
// value of arr[0]=10
// value of arr[1]=20
// value of arr[1]=11
// value of arr[2]=20
// ----------------------------
// address of arr[0]0x3bc95ff690
// address of arr[0]0x3bc95ff690
// address of arr[0]0x3bc95ff690
// ----------------------------
// address of arr[1]0x3bc95ff694
// address of arr[1]0x3bc95ff694
// address of arr[1]0x3bc95ff694
// ----------------------------
