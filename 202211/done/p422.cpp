#include <iostream>
#include <string>
// using namespace std;
// -----------------------------------
class Class1
{
protected:
    std::string name;
    int id;
    int age;
public:
    Class1(std::string,int t,int n);
    void ShowData();
};
// -----------------------------------
class Class2: public Class1
{
private:
    std::string address;
public:
    Class2(std::string s,int t,int n, std::string a);
    void ShowData();
};
// -----------------------------------
Class1::Class1(std::string s,int t,int n)
{
    name = s;
    id = t;
    age = n;
}
// -----------------------------------
void Class1::ShowData()
{
    std::cout << "\n이름은 [" << name << "]이다.\n";
    std::cout << "ID는 ["<<id<<"]\n";
    std::cout << "나이는 ["<<age<<"]\n";
}
// -----------------------------------
Class2::Class2(std::string s,int t,int n,std::string a):Class1(s,t,n)
{
    address = a;
}
// -----------------------------------
void Class2::ShowData()
{
    std::cout << "\n이름은 [" << name << "]이다.\n";
    std::cout << "ID는 ["<<id<<"]\n";
    std::cout << "나이는 ["<<age<<"]\n";
    std::cout << "주소는 ["<<address<<"]\n";
}
// -----------------------------------
int main()
{
    std::string valName = "곽";
    std::string valAddress = "도쿄도 토요스4-10";
    int valAge = 40;
    int valId = 1001;

    Class2 person(valName, valId, valAge, valAddress);
    person.ShowData();

    Class2* p2;
    p2 = &person;
    p2->ShowData();

}
// -----------------------------------