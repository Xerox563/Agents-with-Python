/*
In C++, Access Modifiers control
- Who can access variables
- Who can access functions
- Who can access class members
*/

// * Public
/*
 - Members declared as public can be accessed from anywhere.
✔ inside class
✔ outside class
✔ in main()
✔ in other classes
*/

// * Private
/*
 - Members declared as private can only be accessed inside the class.
✔ accessible inside class functions
✔ not outside the class
✔ not accessible in main()
✔ not in other classes
*/
#include <iostream>  // alllows input/output
using namespace std; // no need to write std::cout, std::cin

// class Student
// {
// private:
//     int age;

// public:
//     void setAge(int val)
//     {
//         age = val;
//     }
//     void show()
//     {
//         cout << "Age is Below " << endl;
//         cout << age << endl;
//     }
// };

// int main()
// {
//     Student s;
//     s.setAge(67);
//     s.show();
// }
// * Protected
/*
Protected members can be accessed:
- inside class
- inside derived class (child class)
- Not outside class
*/

class Parent
{
protected:
    int money;
};

class Child : public Parent
{
public:
    void setMoney(int m)
    {
        money = m;
    }
    void show()
    {
        cout << "Money in Bank Account is --" << endl;
        cout << money << endl;
    }
};

int main()
{
    Child c;
    c.setMoney(30240);
    c.show();
}

/*
✔ What is default access modifier in class?
→ private

✔ What is default in struct?
→ public

✔ Why private used?
→ data hiding / encapsulation

✔ Where protected used?
→ inheritance
*/