#include <iostream>

using namespace std;

namespace myns1
{
    int a;
    void show()
    {
        cout << "myns1의 a값은 : " << a << "이다." << endl;
    }
}
namespace myns2
{
    int a;
    void show()
    {
        cout << "myns2의 a값은 : " << a << "이다." << endl;
    }
}
int main()
{
    myns1::a = 500;
    myns1::show();

    myns2::a = 2000;
    myns2::show();
}
// myns1의 a값은 : 500이다.
// myns2의 a값은 : 2000이다.