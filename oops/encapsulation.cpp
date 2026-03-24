// Binding Data + Functions inside the single class and hiding data using private.
/*
Capsule 💊
Inside → medicine
Outside → cover
You cannot access medicine directly.

Same in C++:
data = private
functions = public
*/

#include <iostream>
using namespace std;

class Student
{
private:
    int age;

public:
    // setter
    void setAge(int a)
    {
        // Data Validation : Now wrong data cannot enter.
        if (a > 18)
            age = a;
    }

    // getter
    int getAge()
    {
        return age;
    }
};

int main()
{
    Student s;
    //  s.age; Data hidden, private and Cannot access directly
    s.setAge(20);
    cout << s.getAge();
}

// * Encapsulation is wrapping data and functions into a single unit and restricting direct access using private access modifier.