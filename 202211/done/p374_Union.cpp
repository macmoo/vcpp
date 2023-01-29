#include <iostream>

using namespace std;

union MyData
{
    int v1;
    short int v2;
    short int v3;
};
int main()
{
    MyData dt;
    dt.v1 = 100;
    cout << "v1:"<<dt.v1 << endl;
    cout << "v2:"<<dt.v2 << endl;
    cout << "v3:"<<dt.v3 << endl;
    cout << "-------------------"<<endl;
    dt.v1 = 32768;
    cout << "v1:"<<dt.v1 << endl;
    cout << "v2:"<<dt.v2 << endl;
    cout << "v3:"<<dt.v3 << endl;
    cout << "-------------------"<<endl;
    dt.v2 = 20;
    cout << "v1:"<<dt.v1 << endl;
    cout << "v2:"<<dt.v2 << endl;
    cout << "v3:"<<dt.v3 << endl;
}
// v1:100
// v2:100
// v3:100
// -------------------
// v1:32768
// v2:-32768
// v3:-32768
// -------------------
// v1:20
// v2:20
// v3:20