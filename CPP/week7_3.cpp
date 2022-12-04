#include <iostream>
using namespace std;
class Complex
{
    private:
        int real;
        int img;
    public:
        Complex (int r, int i)
        {
            real = r;
            img = i;
        }
        Complex operator + (Complex obj)
        {
            obj.real = real + obj.real;
            obj.img = img + obj.img;
            return obj;
        }
        void display ()
        {
            cout << real << "+" << img<<"i"<<endl;
        }
};

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