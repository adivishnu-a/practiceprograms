#include <iostream>
using namespace std;

class item
{
    int x;
    public:
    item(int a)
    {
        x=a;
    }
    item(const item &i)
    {
        x=i.x;
    }
    int getdata()
    {
        return x;
    }
};

int main()
{
    int inp;
    cout<<"Enter any number : ";
    cin>>inp;
    item obj1(inp);
    item obj2=obj1;
    cout<<"The value of x in obj1 is: "<<obj1.getdata()<<endl;
    cout<<"The value of x in obj2 is: "<<obj2.getdata()<<endl;
    return 0;
}