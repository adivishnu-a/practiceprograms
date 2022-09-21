#include<stdio.h>
int main()
{	
	int n;
	printf("Enter any number from 0 to 1000 = ");
	scanf("%d",&n);
	if(n>=0 && n<=9)
	{ 
        printf("%d is a Single Digit Number",n);
	}
	else if(n>=10 && n<=99)
	{ 
        printf("%d is a Two Digit Number",n);
	}
	else if(n>=100 && n<=999)
	{ 
        printf("%d is a Three Digit Number",n);
	}
    else
    {
        printf("Number exceeds 1000");
    }
	return 0;

}