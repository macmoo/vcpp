#include <iostream>

using namespace std;

const int MAX_CHR=20;

struct Score
{
    char name[MAX_CHR+1];
    int scoreJpn;
    int scoreEng;
    int scoreMth;
};
struct MyData
{
    int age;
    double height;
    double weight;
};

void disp(const Score& score)
{
    cout << "[" << score.name << "]"
        << " Jpn:" << score.scoreJpn
        << ", Eng:" << score.scoreEng
        << ", Mth:" << score.scoreMth
        << endl;
}
void show(MyData* dt)
{
    cout << "AGE:" << (*dt).age
        << ", HEIGHT:" << (*dt).height
        << ", WEIGHT:" << (*dt).weight
        << endl;
}
void show2(MyData* dt)
{
    cout << "AGE:" << dt->age
        << ", HEIGHT:" << dt->height
        << ", WEIGHT:" << dt->weight
        << endl;
}
int main()
{
    Score sc[] = {
        {"와세다", 65, 72, 82},
        {"도쿄  "  , 11, 22, 33},
        {"주니치", 44, 55, 66}};

    int size = sizeof sc / sizeof *sc;
    // int size = sizeof sc / sizeof sc[0]; // OK
    cout << "-- size: " << size << endl;
    cout << "-- sizeof sc : " << sizeof sc  << endl;
    cout << "-- sizeof *sc : " << sizeof *sc  << endl;

    for(int i=0;i<size;i++)
    {
        disp(sc[i]);
    }

    // ----------------------------------
    MyData dt1 = { 11,22,33};
    show(&dt1);
    show2(&dt1);
}

// -- size: 3
// -- sizeof sc : 108
// -- sizeof *sc : 36
// [와세다] Jpn:65, Eng:72, Mth:82
// [도쿄  ] Jpn:11, Eng:22, Mth:33
// [주니치] Jpn:44, Eng:55, Mth:66
// AGE:11, HEIGHT:22, WEIGHT:33
// AGE:11, HEIGHT:22, WEIGHT:33