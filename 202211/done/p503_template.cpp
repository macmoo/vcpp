#include <iostream>

using namespace std;
// ----------------------------------------
template <class T>class MyTemplateClass
{
private:
    T array[5];
public:
    void func1(int x, T y) { array[x] = y;}
    T func2(int x) { return array[x]; }
};
// ----------------------------------------
int main()
{
    cout << "----------------------------------------" << endl;
    MyTemplateClass<char> varChar;
    for(int i=0;i<5;i++)
        varChar.func1(i, 'A'+i);

    for(int j=0;j<5;j++)
        cout << varChar.func2(j) << endl;

    MyTemplateClass<int> varInt;
    for(int i=0;i<5;i++)
        varInt.func1(i, 100+i);

    for(int j=0;j<5;j++)
        cout << varInt.func2(j) << endl;
}
// ----------------------------------------
// A
// B
// C
// D
// E
// ----------------------------------------
// 100
// 101
// 102
// 103
// 104
// ----------------------------------------