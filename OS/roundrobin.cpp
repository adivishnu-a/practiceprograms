#include <iostream>
#include <cstdlib>
#include <queue>
#include <cstdio>
using namespace std;


typedef struct process
{
	int id, at, bt, st, ft, pr;
	int wt, tat;
}
process;

process p[10], p1[10], temp;
queue<int> q1;

int accept(int ch);
void turnwait(int n);
void display(int n);
void ganttrr(int n);

int main()
{
    int i, n, ts, ch, j, x;
    p[0].tat = 0;
    p[0].wt = 0;
    n = accept(ch);
    printf("\nEnter the Time Slice: ");
    scanf("%d", &ts);
    ganttrr(n);
    display(n);
    return 0;
}


int accept(int ch)
{
	int i, n;

	printf("Enter the Number of Processes: ");
	scanf("%d", &n);

	if (n == 0)
	{
		printf("Invalid");
		exit(1);
	}

	cout << endl;

	for (i = 1; i <= n; i++)
	{
		printf("Enter Arrival Time of the Process P%d: ", i);
		scanf("%d", &p[i].at);
		p[i].id = i;
	}

	cout << endl;

	for (i = 1; i <= n; i++)
	{
		printf("Enter Burst Time of the Process P%d: ", i);
		scanf("%d", &p[i].bt);
	}

	for (i = 1; i <= n; i++)
	{
		p1[i] = p[i];
	}

	return n;
}

void ganttrr(int n)
{
    int i, ts, m, nextval, nextarr;
    nextval = p1[1].at;
    i = 1;
    printf("\n");

    printf(" ");
    for(int j=0; j<n; j++)
    {
        printf("------");
    }

    printf("\n|");

    for (i = 1; i <= n && p1[i].at <= nextval; i++)
    {
        q1.push(p1[i].id);
    }

    while (!q1.empty())
    {
        m = q1.front();
        q1.pop();

        if (p1[m].bt >= ts)
        {
            nextval = nextval + ts;
            printf("  P%d  |",p1[m].id);
        }
        else
        {
            nextval = nextval + p1[m].bt;
            printf("  P%d  |",p1[m].id);
        }

        if (p1[m].bt >= ts)
        {
            p1[m].bt = p1[m].bt - ts;
        }
        else
        {
            p1[m].bt = 0;
        }

        while (i <= n && p1[i].at <= nextval)
        {
            q1.push(p1[i].id);
            i++;
        }

        if (p1[m].bt > 0)
        {
            q1.push(m);
        }

        if (p1[m].bt <= 0)
        {
            p[m].ft = nextval;
        }
    }

    printf("\n ");

    for(int j=0; j<n; j++)
    {
        printf("------");
    }

    printf("\n");

}


void display(int n)
{
	int i;

    
    for (i = 1; i <= n; i++)
	{
		p[i].tat = p[i].ft - p[i].at;
		p[i].wt = p[i].tat - p[i].bt;
		p[0].tat = p[0].tat + p[i].tat;
		p[0].wt = p[0].wt + p[i].wt;
	}

	float avgtat = (float)p[0].tat / n;
	float avgwt = (float)p[0].wt / n;

	printf("\nProcess\tAT\tBT\tFT\tTAT\tWT");

	for (i = 1; i <= n; i++)
	{
		printf("\nP%d\t%d\t%d\t%d\t%d\t%d", p[i].id, p[i].at, p[i].bt, p[i].ft, p[i].tat, p[i].wt);
	}

	cout << endl;
	printf("\nAverage Turn Around Time: %.2f", avgtat);
	printf("\nAverage Waiting Time: %.2f\n", avgwt);
}