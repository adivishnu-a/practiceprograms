#include<iostream>
using namespace std;

inline int sum(int x,int y)
{
    return x+y;
}

int main()
{
    int a,b;
    int ans;
    cout<<"Enter any number : ";
    cin>>a;
    cout<<"Enter another number : ";
    cin>>b;
    ans=sum(a,b);
    cout<<"Sum = "<<ans<<endl;
}