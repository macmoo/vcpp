#include <iostream>
#include <string>

class MyClass
{
private:
    std::string name;
    int id;
    int age;
public:
    void showData();
    void setName(std::string n);
    void setId(int t);
    void setAge(int a);
};
void MyClass::showData()
{
    std::cout << "NAME:" << name
                << ", ID:" << id
                << ", AGE:" << age
                << std::endl;
}
void MyClass::setName(std::string n)
{
    name = n;
}
void MyClass::setId(int t)
{
    id = t;
}
void MyClass::setAge(int a)
{
    if(a>0){
        age = a;
    }else{
        age = 0;
        std::cout << "Out of Bound" << std::endl;
    }
}
int main()
{
    MyClass person;
    person.setName("Mitsushige");
    person.setAge(50);
    person.setId(111);
    person.showData();
}
// NAME:Mitsushige, ID:111, AGE:50