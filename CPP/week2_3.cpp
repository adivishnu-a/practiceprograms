#include<iostream>
using namespace std;

int factorial(int n)
{
    if(n > 2)
    {
        return n * factorial(n - 1);
    }
    else
    {
        return n;
    }
}

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;
    cout << "The factorial of " << num << " is " << factorial(num) << endl;
    return 0;
}