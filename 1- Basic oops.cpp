
#include <iostream>
using namespace std;

class Student
{
public:
    int rollNumber;

private:
    int age;

public:
    // Default constructor look like this
    Student()
    {
        cout << " Default constructor called" << endl;
    }
    // parameterized constructor
    Student(int rollNumber)
    {
        cout << " Constructor 2 called" << endl;
        /*C++ programming, this is a keyword that refers to the current instance of the class. There can be 3 main usage of this keyword in C++.
          It can be used to pass current object as a parameter to another method.
          It can be used to refer current class instance variable.*/
        this->rollNumber = rollNumber;
    }

    Student(int a, int r)
    {
        cout << "this:" << this << endl;
        cout << "constructor 3 called" << endl;
        this->age = a;
        this->rollNumber = r;
    }
    void display()
    {
        cout << "Age: " << this->age << endl;
        cout << "Rollnumber: " << this->rollNumber << endl;
    }
};

int main()
{
    Student s1(10, 1001);
    cout << "S1 : ";
    s1.display();
    Student s2(s1);
    cout << "S2 : ";
    s2.display();
    Student s3(20, 799);
    s1 = s3;
    s1.display();
}
