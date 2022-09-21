#include <iostream>
using namespace std;

int main()
{
        int a[20], i, num, n, cnt=0, pos;
        cout<<"Enter array Size : ";
        cin>>n;
        cout<<"Enter array Elements : " << endl;
        for(i=0; i<n; i++)
        {
                cout<<" ";
                cin>>a[i];
        }
        cout<<"Enter Element to be Searched : ";
        cin>>num;
        for(i=0; i<n; i++)
        {
                if(a[i]==num)
                {
                        cnt=1;
                        pos=i+1;
                        break;
                }
        }
        if(cnt==0)
        {
                cout<<"Element Not Found..!!";
        }
        else
        {
                cout<<"Element "<<num<<" Found At Position "<<pos;
        }
        return 0;
}