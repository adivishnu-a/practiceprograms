#include <bits/stdc++.h>
#include <string>
#include <iostream>
using namespace std;

void LongestPrefixSuffix(char* pattern, int M, int* lps)
{
	int len = 0;
	lps[0] = 0; 
	int i = 1;
	while (i < M) {
		if (pattern[i] == pattern[len]) 
		{
			len++;
			lps[i] = len;
			i++;
		}
		else 
		{
			if (len != 0) 
			{
				len = lps[len - 1];
			}
			else 
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}

void CalcKMP(char* pattern, char* text)
{
	int M = strlen(pattern);
	int N = strlen(text);	
	int lps[M];
	LongestPrefixSuffix(pattern, M, lps);
	int i = 0; 
	int j = 0; 
	while ((N - i) >= (M - j)) 
	{
		if (pattern[j] == text[i]) 
		{
			j++;
			i++;
		}
		if (j == M) {
			printf("%d %d\n", i-j+1,i+j-M);
			
			j = lps[j - 1];
		}
		else if (i < N && pattern[j] != text[i]) 
		{
			if (j != 0)
				j = lps[j - 1];
			else
				i = i + 1;
		}
	}
}

int main()
{
	char text[100];
	char pattern[100];
	cin>>text;
	cin>>pattern;
	CalcKMP(pattern, text);
	return 0;
}