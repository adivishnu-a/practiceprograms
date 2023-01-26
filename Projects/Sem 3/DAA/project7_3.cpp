#include<iostream>
using namespace std;

int row[] = { 2, 1, -1, -2, -2, -1, 1, 2, 2 };
int col[] = { 1, 2, 2, 1, -1, -2, -2, -1, 1 };
int solno = 0;

int checkValidity(int x,int y,int sol[8][8])
{
	return(x >= 0 && x < 8 && y >= 0 && y < 8 && sol[x][y] == -1);
}

void display(int sol[8][8])
{
	solno++;
	cout << "Solution " << solno << ": " << endl;

	for(int x = 0;x < 8;x++)
	{
		for(int y = 0;y < 8;y++)
		{
			cout << sol[x][y] << "\t";
		}
		cout << endl;
	}
	cout << endl << endl;
}

void KnightsTour(int x,int y,int movei,int sol[8][8])
{
	if(solno < 5)
	{
	
		sol[x][y] = movei;
		if(movei == 8 * 8)
		{
		
			display(sol);
		}
	
		for(int k = 0;k < 8;k++)
		{
			int next_x = x + row[k];
			int next_y = y + col[k];
			if(checkValidity(next_x,next_y,sol))
			{
				KnightsTour(next_x,next_y,movei+1,sol);
			}
		}
		sol[x][y] = -1;
	}
}
int main()
{
	int sol[8][8];
	for(int i = 0;i < 8;i++)
	{
		for(int j = 0;j < 8;j++)
		{
			sol[i][j] = -1;
		}
	}
	KnightsTour(0,0,1,sol);
	if(solno == 0)
	{
		cout << "Solution does not exits" << endl;
	}
	return 0;
}