#include <iostream>

using namespace std;
// ----------------------------------------
void* operator new(size_t objSize)
{
    cout << objSize << " byte allocated." << endl;
    return (malloc(objSize));
}
// ----------------------------------------
void* operator new[](size_t objSize)
{
    cout << objSize << " byte(array) allocated." << endl;
    return (malloc(objSize));
}
// ----------------------------------------
void operator delete(void* p)
{
    cout << hex << p << " memory deleted." << endl;
}
// ----------------------------------------
void operator delete[](void* p)
{
    cout << hex << p << " memory(array) deleted." << endl;
}
// ----------------------------------------
int main()
{
    cout << "----------------------------------------" << endl;
    int *p1 = (int *)new int;
    int *p2 = (int *)new int[100];

    delete   p1;
    delete[] p2;
    cout << "----------------------------------------" << endl;
}
// ----------------------------------------
// 4 byte allocated.
// 400 byte(array) allocated.
// 000002589CC4EAE0 memory deleted.
// 000002589CC58450 memory(array) deleted.
// ----------------------------------------