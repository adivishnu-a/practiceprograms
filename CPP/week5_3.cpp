#include <iostream>
using namespace std;
class class_1;
class class_2;

class class_1
{
    int x;
    public:
    void getdata()
    {
        cout<<"Enter the first number: ";
        cin>>x;
    }
    friend void swap(class_1,class_2);
};

class class_2
{
    int y;
    public:
    void getdata()
    {
        cout<<"Enter the second number: ";
        cin>>y;
    }
    friend void swap(class_1,class_2);
};

void swap(class_1 obj1,class_2 obj2)
{
    cout<<"Before Swapping:"<<endl;
    cout<<"First number : "<<obj1.x<<"     Second number : "<<obj2.y;
    int temp;
    temp=obj1.x;
    obj1.x=obj2.y;
    obj2.y=temp;
    cout<<"\n\nAfter Swapping"<<endl;
    cout<<"First number : "<<obj1.x<<"     Second number : "<<obj2.y;
}

int main()
{
    class_1 obj1;
    class_2 obj2;
    obj1.getdata();
    obj2.getdata();
    swap(obj1,obj2);
    return 0;
}