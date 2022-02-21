#include <stdio.h>
#include <stdlib.h> 
int main()
{  
    int b=0,n,i,r, f=1; 
    system("cls");
    printf("Enter the number to convert: ");    
    scanf("%d",&n);    
    for(i=0;n>0;i++)    
    {    
        r=n%2;
        b=r*f + b;
        f=f*10;
        n=n/2;    
    }    
    printf("Binary of Given Number is = %d", b);    
    return 0;  
}