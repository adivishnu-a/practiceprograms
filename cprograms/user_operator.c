#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a, b;
	char op;
	system("cls");
	printf("Enter an integer: ");
	scanf("%d",&a);
	printf("Enter another integer: ");
	scanf("%d",&b);
	printf("Select + for addition, - for subtraction, * for multiplication or / for division: ");
	scanf("\n%c",&op);
	switch(op)
	{
		case '+':
			printf("Result is: %d",(a+b));
			break;
		case '-':
			printf("Result is: %d",(a-b));
			break;
		case '*':
			printf("Result is: %d",(a*b));
			break;
		case '/':
			printf("Result is: %d",(a/b));
			break;
		case '%':
			printf("Result is: %d",(a%b));
			break;
		default:
			printf("Wrong selection");
	}
	return 0;
}