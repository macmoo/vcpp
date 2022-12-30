#include <iostream>

using namespace std;

enum Code {
    Gunma       = 10,
    Saitama     = 11,
    Chiba       = 12,
    Tokyo       = 13,
    Kanagawa    = 14,
    Niigata     = 15,
    Toyama      = 16
};
int main()
{
    for( Code item : {Gunma, Saitama, Chiba, Tokyo, Kanagawa, Niigata, Toyama} ){
        cout << item << endl;
    }
    Code cd; 
    cout << cd << endl; // trash value
    cd = Chiba;
    cout << cd << endl; // 12
    cout << Code::Kanagawa; // 14
    cout << sizeof cd;
}
// 10
// 11
// 12
// 13
// 14
// 15
// 16
// 676
// 12
// 14
// 144