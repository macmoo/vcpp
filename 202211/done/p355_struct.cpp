#include <iostream>

using namespace std;

struct MyData
{
    int age;
    double height;
    double weight;
};

int main()
{
    // cout << "AGE:";
    // cin >> dt1.age;

    // cout << "HEIGHT:";
    // cin >> dt1.height;

    // cout << "WEIGHT:";
    // cin >> dt1.weight;
    MyData dt1 = {20, 172.5, 61.9};

    cout << "DT1 :: AGE=>" << dt1.age
        << ", HEIGHT=>" << dt1.height
        << ", WEIGHT=>" << dt1.weight
        << endl;

    MyData dt2;
    dt2 = dt1;
    cout << "DT2 :: AGE=>" << dt2.age
        << ", HEIGHT=>" << dt2.height
        << ", WEIGHT=>" << dt2.weight
        << endl;

    
}
// AGE:1
// HEIGHT:2
// WEIGHT:3
// AGE=>1, HEIGHT=>2, WEIGHT=>3
// DT2 :: AGE=>1, HEIGHT=>2, WEIGHT=>3
