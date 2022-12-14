#include <iostream>

using namespace std;

template <typename T1, typename T2>
void print(T1 a,T2 b)
{
    cout << "1 :: a=" << a << ", b=" << b << endl;
}
template <typename T1>
void print(T1 a, double b)
{
    cout << "2 :: a=" << a << ", b(double)=" << b << endl;
}
// template다중정의
template<>
void print(int a, double b)
{
    cout << "3 :: a=(int)" << a << ", b(double)=" << b << endl;
}
int main()
{
    print(1, 2);
    print(1.0, 2.0);
    print(1, 2.0);
}

// 1 :: a=1, b=2
// 2 :: a=1, b(double)=2
// 3 :: a=(int)1, b(double)=2

// 17행이
// void print(int a, int b) 일 경우
// 3 :: a=(int)1, b(double)=2
// 2 :: a=1, b(double)=2
// 2 :: a=1, b(double)=2
