

#include <iostream>
using namespace std;

class student
{
public:
    int rollnumber;
    int age;
    static int totalstudents;
    student()
    {
        totalstudents++;
    }

    student(int rollnumber, int age)
    {
        this->age = age;
        this->rollnumber = rollnumber;
        totalstudents++;
    }

    void display()
    {
        cout << "Age: " << age << endl;
        cout << "Rollnumber: " << rollnumber << endl;
        cout << "Totalstudents: " << totalstudents << endl;
    }
};

int student ::totalstudents = 0;

int main()
{
    student s1(200, 20);
    s1.display();
    student s2, s3, s4;
    s4.display();
    cout << student ::totalstudents << endl;
}
