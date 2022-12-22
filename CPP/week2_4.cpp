#include<iostream>
using namespace std;

void pattern(int a)
{
    if(a<1)
        return;
    pattern(a-1);
    cout << a << " ";
    pattern(a-1);
}

int main()
{
    int n = 4;
    pattern(n);
    return 0;
}