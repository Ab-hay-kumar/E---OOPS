#include <iostream>
using namespace std;

class Fraction
{
public:
    int numerator;
    int denominator;

    Fraction(int numerator, int denominator)
    {
        this->numerator = numerator;
        this->denominator = denominator;
    }

    void simplify()
    {
        int mini = min(this->numerator, this->denominator);
        int j = 1;
        for (int i = 1; i <= mini; i++)
        {
            if (numerator % i == 0 && denominator % i == 0)
            {
                j = i;
            }
        }
        numerator = numerator / j;
        denominator = denominator / j;
    }

    Fraction add(Fraction F2)
    {
        this->numerator = this->numerator * F2.denominator + this->denominator * F2.numerator;
        this->denominator = this->denominator * F2.denominator;
        simplify();
        Fraction fnew(numerator, denominator);
        fnew.simplify();
        return fnew;
    }

    // operator overloading("*" operator)
    Fraction operator*(Fraction F2)
    {
        int n = numerator * F2.numerator;
        int d = denominator * F2.denominator;
        Fraction fnew(n, d);
        fnew.simplify();
        return fnew;
    }
    // operator overloading("+=" operator)
    Fraction operator+=(Fraction F2)
    {
        Fraction f3 = add(F2);
        f3.simplify();
        return f3;
    }

    void display()
    {
        cout << numerator << " / " << denominator << endl;
    }
};

int main()
{
    Fraction f1(5, 9);
    Fraction f2(6, 8);
    f1.display();
    f2.display();
    // f1.add(f2);
    // f1.display();
    // Fraction f3 = f1*f2;
    // f3.display();
    Fraction f3 = (f1 += f2) += f2;
    f3.display();
    f2.display();
}
``