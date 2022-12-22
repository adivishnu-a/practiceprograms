#include <iostream>
using namespace std;
class Complex
{
    private:
        int real;
        int img;
    public:
        Complex (int r=0, int i=0)
        {
            real = r;
            img = i;
        }
        void display ()
        {
            cout << real << "+" << img<<"i"<<endl;
        }
        friend Complex operator + (Complex c1, Complex c2);
};

Complex operator + (Complex c1, Complex c2)
{
    Complex obj;
    obj.real = c1.real + c2.real;
    obj.img = c1.img + c2.img;
    return obj;
}

int main ()
{
    Complex c1(5, 2), c2(4, 3);
    cout<<"The first complex number is : ";
    c1.display();
    cout << "The second complex number is : ";
    c2.display();
    Complex c3 = c1 + c2;
    cout << "The sum of complex numbers is : ";
    c3.display();
}