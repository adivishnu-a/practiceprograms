#include<iostream>
using namespace std;
#define N 8

// Below arrays detail all eight possible movements for a knight.
// It is important to avoid changing the sequence of the below arrays
int row[] = { 2, 1, -1, -2, -2, -1, 1, 2, 2 };
int col[] = { 1, 2, 2, 1, -1, -2, -2, -1, 1 };
int solno = 0;

/*A utility function to check if i,j
are valid indexes for N*N chessboard*/
int issafe(int x,int y,int sol[N][N])
{
	/*Returns 1 if x,y are valid coordinates i.e, 
	lie inside the chessboard dimesnions and the
	position (x,y) is not already included in path*/
	return(x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1);
}

/*A utility function to print
the solution matrix sol[N][N]*/
void printSolution(int sol[N][N])
{
	solno++;
	cout << "Solution " << solno << ": " << endl;
	/*Here in each element of the 
	  matrix the move is stored*/
	for(int x = 0;x < N;x++)
	{
		for(int y = 0;y < N;y++)
		{
			cout << sol[x][y] << "\t";
		}
		cout << endl;
	}
	cout << endl << endl;
}
/*A recursive utility function to solve Knight Tour*/
void solveKTUtil(int x,int y,int movei,int sol[N][N])
{
	if(solno < 5)
	{
		/*Storing the next move in
		corresponding position*/
		sol[x][y] = movei;
		if(movei == N * N)
		{
			/*If movei == N*N ,it means that the
			knight have travelled all the squares
			of the chess board,print the solution*/
			printSolution(sol);
		}
		/*From the current coordinate x,y try all next moves
		,go through the first possible move,from that position
		again try all next moves,again go through the first 
		possible move from that position,if at all from a postion
		if no move is possible then back track go to the previous
		move(position) and try next move from the position,like
		this repeat until all the squares are visited,if at all
		then print the solution and after printing the solution
		also the function doesn't ends,it back tracks and from
		the previous position it try remaining moves and tries
		to find if at any solutions are possible and print them
		If at through all the moves the knight is not able to
		move through all the squares of the chess board then
		it is not considered as the solution.*/
		for(int k = 0;k < 8;k++)
		{
			int next_x = x + row[k];
			int next_y = y + col[k];
			if(issafe(next_x,next_y,sol))
			{
				solveKTUtil(next_x,next_y,movei+1,sol);
			}
		}
		sol[x][y] = -1;
	}
}
int main()
{
	int sol[N][N];
	for(int i = 0;i < N;i++)
	{
		for(int j = 0;j < N;j++)
		{
			sol[i][j] = -1;
		}
	}
	solveKTUtil(0,0,1,sol);
	if(solno == 0)
	{
		cout << "Solution does not exits" << endl;
	}
	return 0;
}