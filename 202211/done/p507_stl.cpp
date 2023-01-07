#include <iostream>
#include <vector>

using namespace std;
// ----------------------------------------
int main()
{
    cout << "----------------------------------------" << endl;
    vector<int> intvt;
    vector<int>::iterator p;

    intvt.push_back(100);
    intvt.push_back(500);
    intvt.push_back(1000);

    for(p=intvt.begin(); p != intvt.end(); ++p)
        cout << *p << endl;
}
// ----------------------------------------
// 100
// 500
// 1000
// ----------------------------------------
