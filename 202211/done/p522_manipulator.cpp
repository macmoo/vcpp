// ----------------------------------------
// https://en.cppreference.com/w/cpp/io/manip
// ----------------------------------------
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int num = 1234;
    cout << "----------------------------------------" << endl;
    cout << showbase << dec << num << endl;        //1234
    cout << showbase << oct << num << endl;        //02322
	cout << showbase << hex << num << endl;        //0x4d2

    cout << noshowbase << dec << endl;            //ÃÊ±âÈ­&ÁÙ¸ÂÃã

    cout << showpos << num << endl;                //+1234
    cout << noshowpos << num << endl;            //1234
    cout << endl;                                //ÁÙ¸ÂÃã
    cout << "----------------------------------------" << endl;

    cout << uppercase << hex << num << endl;    //4D2
    cout << nouppercase << hex << num << endl;    //4d2

    cout << noshowbase << dec << endl;            //ÃÊ±âÈ­&ÁÙ¸ÂÃã

    cout << setw(6) << left << -num << endl;    //-1234
    cout << setw(6) << internal << -num << endl;//- 1234
    cout << setw(6) << right << -num << endl;    // -1234
    cout << endl;                                //ÁÙ¸ÂÃã
    cout << "----------------------------------------" << endl;

    float decimal1 = 10.0f;
    float decimal2 = 10.12f;

    cout << noshowpoint << decimal1 << " " << decimal2 << endl; //10      10.12
    cout << showpoint << decimal1 << " " << decimal2 << endl;    //10.0000 10.1200

    cout << fixed << decimal2 << endl;                //10.120000
    cout << scientific << decimal2 << endl;            //1.012000e+01

    bool boolean = true;
    cout << fixed << endl;                                    //ÁÙ¸ÂÃã
    cout << "----------------------------------------" << endl;

    cout << boolalpha << boolean << endl;            //true
    cout << noboolalpha << boolean << endl;            //1
    cout << endl;                                    //ÁÙ¸ÂÃã
    cout << "----------------------------------------" << endl;

    cout << setfill('*') << setw(6) << num << endl;    //**1234
    cout << endl;                                    //ÁÙ¸ÂÃã
    cout << "----------------------------------------" << endl;

    cout << setprecision(7) << decimal2 << endl;    //10.1199999
    cout << "----------------------------------------" << endl;
    return 0;
}
// ----------------------------------------
// 1234
// 02322
// 0x4d2

// +1234
// 1234

// ----------------------------------------
// 4D2
// 4d2

// -1234
// - 1234
//  -1234

// ----------------------------------------
// 10 10.12
// 10.0000 10.1200
// 10.120000
// 1.012000e+01

// ----------------------------------------
// true
// 1

// ----------------------------------------
// **1234

// ----------------------------------------
// 10.1199999
// ----------------------------------------

