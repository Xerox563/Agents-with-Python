/*
- Constructor is a special funcion which has the same name as the class name , no return type and which is called automatically when the object of class is created and
- used to initialize the value
*/

#include <bits/stdc++.h>
using namespace std;
class Student
{
public:
    int age;

public:
    string name;

    Student()
    {
        name = "Amit";
        cout << "Constrcutor Called !!" << endl;
    }
    void setter(int x)
    {
        age = x;
    }
    void getter()
    {
        cout << "Age: " << age << endl;
    }
};

// Parameterized Constructor : Constructor that takes arguments is called parameterized constructor.Used when we want to give values at object creation.
class B
{
public:
    int x;

    B(int a)
    {
        x = a;
    }
};

// Default Constructor
class A
{
public:
    A()
    {
        cout << "Default";
    }
};

class Test
{
public:
    Test()
    {
        cout << "Constructor Called !!" << endl;
    }
    ~Test()
    {
        cout << "Destructor Called !!" << endl;
    }
};

int main()
{
    // Student s1;
    // cout << s1.name << endl;
    // s1.setter(34);
    // s1.getter();
    // B obj(10);
    Test t;
    return 0;
}

// Desctructor : same name , no return , no parameters , is called automatically when object is destroyed + it is used to free the memory.
// Destructor runs when program ends.
/*
Use case:
✔ Free memory
✔ Close file
✔ Delete pointer
✔ Database close
✔ Resource cleanup
✔ When destructor called? → object destroy
✔ Can destructor have parameter? → No
✔ Can multiple destructor? → No
✔ Can destructor be private? → Yes
✔ Default destructor? → Yes
*/