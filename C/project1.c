#include <stdio.h>

void TOH_move(int n, char source, char destination, char auxiliary)
{
	if (n == 1)
	{
		printf("\n Move disk 1 from rod %c to rod %c", source, destination);
		return;
	}
	TOH_move(n-1, source, auxiliary, destination);
	printf("\n Move disk %d from rod %c to rod %c", n, source, destination);
	TOH_move(n-1, auxiliary, destination, source);
}

int main()
{
	int n;
    printf(" Enter the number of disks : ");
    scanf("%d", &n);
	TOH_move(n, 'A', 'C', 'B');
	return 0;
}
