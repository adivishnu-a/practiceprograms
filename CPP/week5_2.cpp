#include <iostream>
using namespace std;
class num1;
class num2;

class num1
{
    int x;
    public:
    void getdata()
    {
        cout<<"Enter the first number: ";
        cin>>x;
    }
    void putdata()
    {
        cout<<"The first number is: "<<x<<endl;
    }
    friend void maximum(num1,num2);
};

class num2
{
    int y;
    public:
    void getdata()
    {
        cout<<"Enter the second number: ";
        cin>>y;
    }
    void putdata()
    {
        cout<<"The second number is: "<<y<<endl;
    }
    friend void maximum(num1,num2);
};

void maximum(num1 obj1,num2 obj2)
{
    if(obj1.x>obj2.y)
    {
        cout<<obj1.x<<" is greater than "<<obj2.y<<endl;
    }
    else
    {
        cout<<obj2.y<<" is greater than "<<obj1.x<<endl;
    }
}

int main()
{
    num1 obj1;
    num2 obj2;
    obj1.getdata();
    obj2.getdata();
    obj1.putdata();
    obj2.putdata();
    maximum(obj1,obj2);
    return 0;
}