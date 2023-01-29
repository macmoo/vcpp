#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// ----------------------------------------
// ----------------------------------------
int main()
{
    cout << "----------------------------------------" << endl;
    vector<int> intvt;
    vector<int>::iterator p;
    int temp=-1;
    for(int i=0;i<10;i++)
    {
        temp *= -1;
        intvt.push_back(i*temp);
    }

    for(p=intvt.begin();p!=intvt.end();++p)
        cout << *p << " ";
    cout << "\n----------------------------------------" << endl;
    reverse(intvt.begin(), intvt.end());
    for(p=intvt.begin();p!=intvt.end();++p)
        cout << *p << " ";
    cout << "\n----------------------------------------" << endl;
    sort(intvt.begin(), intvt.end());
    for(p=intvt.begin();p!=intvt.end();++p)
        cout << *p << " ";
    cout << "\n----------------------------------------" << endl;
}
// ----------------------------------------
// 0 -1 2 -3 4 -5 6 -7 8 -9
// ----------------------------------------
// -9 8 -7 6 -5 4 -3 2 -1 0
// ----------------------------------------
// -9 -7 -5 -3 -1 0 2 4 6 8
// ----------------------------------------
