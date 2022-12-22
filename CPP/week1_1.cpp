#include <iostream>
using namespace std;

int main()
{
    int a,b;
    char ch;
    cout<<"Enter the two integers : ";
    cin>>a>>b;
    cout<<"Enter the operator : ";
    cin>>ch;
    cout<<"The result of "<< a << " " << ch << " " << b << " = ";
    switch(ch)
    {
        case '+':cout<<a+b;
                 break;
        case '-':cout<<a-b;
                 break;
        case '*':cout<<a*b;
                 break;
        case '/':cout<<a/b;
                 break;
        case '%':cout<<a%b;
                 break;
        default:cout<<"Invalid operator";
    }
    return 0;
}