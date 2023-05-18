
#include <iostream>
using namespace std;

class complexnum
{
private:
    int real;
    int imaginary;

public:
    complexnum(int real, int imaginary)
    {
        this->real = real;
        this->imaginary = imaginary;
    }

    void add(complexnum c2)
    {
        this->real = this->real + c2.real;
        this->imaginary = this->imaginary + c2.imaginary;
    }
    void multiply(complexnum c2)
    {
        int temp = this->real;
        this->real = this->real * c2.real - this->imaginary * c2.imaginary;
        this->imaginary = temp * c2.imaginary + this->imaginary * c2.real;
    }
    void print()
    {
        cout << real << " + " << imaginary << "i" << endl;
    }
};

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    complexnum c1(a, b);
    c1.print();
    complexnum c2(c, d);
    // c1.add(c2);
    // c1.print();
    // c2.print();
    c1.multiply(c2);
    c1.print();
    c2.print();
}