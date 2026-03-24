#include <bits/stdc++.h>
using namespace std;
class Teacher
{
public:
    string name;
    string subject;
    float salary;
    string dept;

    // methods
    void changeDept(string d)
    {
        dept = d;
        cout << "New Dept: " << dept << endl;
    }
};
int main()
{
    Teacher t1;
    t1.name = "Rajesh";
    t1.subject = "Maths";
    t1.salary = 52450.878;
    t1.dept = "Dept of Applied Mathematics";
    cout << "Name: " << t1.name << endl;
    cout << "Subject: " << t1.subject << endl;
    cout << "Dept: " << t1.dept << endl;
    cout << "Salary: " << t1.salary << endl;
    t1.changeDept("Department of ML");
    return 0;
}