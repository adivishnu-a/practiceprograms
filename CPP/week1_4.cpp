#include <iostream>
using namespace std;

int main()
{
    int n,i,fact=1;
    cout<<"Enter any number : ";
    cin>>n;
    for(i=1;i<=n;i++)
    {
        fact=fact*i;
    }
    cout<<"The factorial of "<<n<<" is "<<fact;
    return 0;
}