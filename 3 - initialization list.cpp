#include <iostream>
using namespace std;

class Student
{
public:
    int age;
    int const Rollnumber;
    // initialization list for constant values so that
    // it can get values we assigned not any random values
    Student(int r) : Rollnumber(r)
    {
    }
    void display()
    {
        cout << this->Rollnumber << endl;
    }
};

int main()
{
    Student s1(101);
    s1.display();
}