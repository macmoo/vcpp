#include <iostream>

using namespace std;

namespace myns1
{
    int a;
    void show()
    {
        cout << "myns1�� a���� : " << a << "�̴�." << endl;
    }
}
namespace myns2
{
    int a;
    void show()
    {
        cout << "myns2�� a���� : " << a << "�̴�." << endl;
    }
}
int main()
{
    myns1::a = 500;
    myns1::show();

    myns2::a = 2000;
    myns2::show();
}
// myns1�� a���� : 500�̴�.
// myns2�� a���� : 2000�̴�.