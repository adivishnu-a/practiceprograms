#include <iostream>
using namespace std;

class complex 
{
    int real, imaginary;
    public:
        void getdata(int a, int b)
        {
            real=a;
            imaginary=b;
        }
        
        void putdata()
        {
            cout<<endl<<"The number is "<<real<<" + "<<imaginary<<"i";
        }
        
        friend complex add(complex, complex);
};

complex add(complex c1, complex c2)
{
    complex c3;
    c3.real=c1.real+c2.real;
    c3.imaginary=c1.imaginary+c2.imaginary;
    return c3;
}

int main()
{
    int a, b;
    complex obj1, obj2;
    cout<<"Enter the real part of first complex number : ";
    cin>>a;
    cout<<"Enter the imaginary part of first complex number : ";
    cin>>b;
    obj1.getdata(a,b);
    cout<<"Enter the real part of second complex number : ";
    cin>>a;
    cout<<"Enter the imaginary part of second complex number : ";
    cin>>b;
    obj2.getdata(a,b);
    complex obj3;
    obj3 = add(obj1, obj2);
    cout<<endl<<"The sum of given two complex numbers is ";
    obj3.putdata();
    return 0;
}