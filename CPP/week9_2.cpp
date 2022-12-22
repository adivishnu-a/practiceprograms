#include <iostream>
using namespace std;

int main()
{
    int a,b;
    cout<<"Enter the value of a : ";cin>>a;
cout<<"Enter the value of b : ";cin>>b;
    try{
    	if (b == 0)
    	{
	    	throw b;
	    }
        float ans=(float)a/b;
        cout<<"The answer of a/b is : "<<ans<<endl;
    }
    catch (int x){
	    cout <<"Cannot divide by zero";
    }
    return 0;
}
