/*
OOP = Object Oriented Programming

It is a programming style where we write programs using: class and object
Instead of writing everything in functions (like C),
we group data + functions together.

Why Oops needed ?
- Old language (C) → Procedural programming
  - Data not secure [encapsulation]
  - Large code difficult to manage [clases + object]
  - No reusability [inheritance]

Interview question:
Why OOP is better than procedural programming?
Answer:
OOP provides encapsulation, inheritance, polymorphism and abstraction which make code secure, reusable and easy to maintain.

eg:
car has data : speed,color,model & Functions: start(), stop(), brake()
so we make : Class - car and object - myCar

class Car {
   data
   functions
};

Car c1;

| Real world | OOP      |
| ---------- | -------- |
| Car type   | Class    |
| My car     | Object   |
| Color      | Data     |
| Drive      | Function |

*/

#include <bits/stdc++.h>
using namespace std;

class Student
{
public:
    int age;    // properties
    void show() // methods : function written inside the class
    {
        cout << "Age : " << age << endl;
    }
};

int main()
{
    Student s1;
    s1.age = 20;
    s1.show();
}

/*
 ek baar class bnado [blueprint]: which has properties + methods, uskae baad toh bs usi blueprint ko use krkae object bnalo
 aap ek class bna lo for teachers [blueprint]
 - uskae baad usi bleuprint class ko reuse krkae new teachers[objects] bnate rho
 - code reusability

 eg: amazon product[name,price,rating ,description,image] : iski class bna li ho and then amazon k different different products isi same class ko reuse krkae bnaaye gyae ho .
*/