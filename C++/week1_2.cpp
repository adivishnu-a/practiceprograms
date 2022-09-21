#include<iostream>
using namespace std;

int main()
{
   int i, num, n, count;
   cout << "Enter the range : ";
   cin >> n;
   cout << "The prime numbers in between the range 1 to " << n <<endl;
   for(num = 1;num<=n;num++)
   {
        count = 0;
        for(i=2;i<=num/2;i++)
        {
            if(num%i==0)
            {
                count++;
                break;
            }
        }
        if(count==0 && num!= 1)
        cout << num << " ";
   }
   return 0;
}