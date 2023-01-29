#include <iostream>

void f(const int *p)
{
    int *v;
    v = const_cast<int*>(p);
    *v = 100;
}
int main()
{
    std::cout << "----------------------------------------\n";
    // ----------------------------------------
    signed char sc = -1;
    signed int  ui;
    int i;
    double d = 123.456;

    ui = static_cast<signed int>(sc);
    i = static_cast<int>(d);

    std::cout << ui << '\n';
    std::cout << i  << '\n';
    std::cout << d << '\n';
    std::cout << "----------------------------------------\n";
    // ----------------------------------------
    int data1, data2;
    int *p = &data1;

    // data1 = static_cast<int>(p); // ERROR
    // data2 = reinterpret_cast<int>(p);
    // ERROR => cast from 'int*' to 'int' loses precision 

    std::cout << data1 << '\n';
    std::cout << data2 << '\n';
    std::cout << "----------------------------------------\n";
    // ----------------------------------------
    int x = 99;
    std::cout << "BEFORE RUN:" << x << '\n';
    f(&x);
    std::cout << "AFTER RUN:" << x << '\n';
    std::cout << "----------------------------------------\n";
    // ----------------------------------------

}