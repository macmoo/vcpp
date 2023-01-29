#include <iostream>

using namespace std;
// ----------------------------------------
class Cls1
{
private:
    int val1;
    int val2;
    int val3=300;
public:
    int val4=400;
    void set(const int p1, const int p2)
    {
        val1 = p1;
        val2 = p2;
    }
    friend class Cls2; // FRIEND?Å¥?ûò?ä§
};
// ----------------------------------------
class Cls2
{
public:
    void disp(const Cls1 o)
    {
        cout << o.val1 << endl;
        cout << o.val2 << endl;
    }
};
// ----------------------------------------
class Cls3
{
private:
    int n;
public:
    Cls3(int v){n=v;}
    int getN(){return n;}
    void memF(){cout << "MEMBER -> n:" << n << endl;}
    friend void friendF(Cls3 c);
};
// ----------------------------------------
void normalF(Cls3 c)
{
    // cout << "Normal -> c.n:" << c.n << endl; // access Î∂àÍ??
    cout << "Normal -> c.getN():" << c.getN() << endl;
}
void friendF(Cls3 c)
{
    cout << "Friend -> c.n :" << c.n << endl;
}
// ----------------------------------------
int main()
{
    std::cout << "----------------------------------------\n";
    Cls1 c1;
    c1.set(100,200);

    Cls2 c2;
    c2.disp(c1);
    std::cout << "----------------------------------------\n";
    // cout << c1.val3 << endl; // access Î∂àÍ??
    cout << c1.val4 << endl;
    std::cout << "----------------------------------------\n";
    Cls3 c3(500);
    c3.memF();
    friendF(c3);
    normalF(c3);
    std::cout << "----------------------------------------\n";
}
// ----------------------------------------
// 100
// 200
// ----------------------------------------
// 400
// ----------------------------------------
// MEMBER -> n:500
// Friend -> c.n :500
// Normal -> c.getN():500
// ----------------------------------------