#include <stdio.h>
#include <string.h>

char string[50];
const char *pointer;

int E() 
{
	printf("%-16s E -> T E'\n", pointer);
	if (T()) 
	{ 
		if (Edash()) 
			return 1;
		else
			return 0;
	} 
	else
		return 0;
}


int Edash() 
{
	if (*pointer == '+') 
	{
		printf("%-16s E' -> + T E'\n", pointer);
		pointer++;
		if (T()) 
		{ 
			
			if (Edash()) 
				return 1;
			else
				return 0;
		} 
		else
			return 0;
	}
	else 
	{
		printf("%-16s E' -> $\n", pointer);
		return 1;
	}
}


int T() 
{
	printf("%-16s T -> F T'\n", pointer);
	if (F()) 
	{ 
		
		if (Tdash()) 
		
			return 1;
		else
			return 0;
	} 
	else
		return 0;
}


int Tdash() 
{
	if (*pointer == '*') 
	{
		printf("%-16s T' -> * F T'\n", pointer);
		pointer++;
		if (F()) 
		{ 
			
			if (Tdash()) 
				return 1;
			else
				return 0;
		} 
		else
			return 0;
	} 
	else 
	{
		printf("%-16s T' -> $\n", pointer);
		return 1;
	}
}


int F() 
{
	if (*pointer == '(') 
	{
		printf("%-16s F -> ( E )\n", pointer);
		pointer++;
		if (E()) 
		{ 
			
			if (*pointer == ')') 
			{
				pointer++;
				return 1;
			} 
			else
				return 0;
		} 
		else
			return 0;
	} 
	else if (*pointer == 'i') 
	{
		printf("%-16s F -> i\n", pointer);
		pointer++;
		return 1;
	} 
	else
		return 0;
}

int main() 
{
	puts("Enter the string");
	scanf("%s", string); 
	pointer = string;
	puts("");
	puts("Input		 Action");
	if (E() && *pointer == '\0') 
	{ 
		puts("String parsed");
		return 0;
	} 
	else 
	{
		puts("Error occured");
		return 1;
	}
}