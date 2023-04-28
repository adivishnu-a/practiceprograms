#include <iostream>
#include <cstdlib>
#include <queue>
#include <cstdio>
#include <ctime>
using namespace std;

typedef struct process
{
    int id, at, bt, st, ft, pr;
    int wt, tat, rem;
}
process;

process p[10], p1[10], temp;
queue<int> q1;

int accept();
void turnwait(int n);
void display(int n);
void ganttp(int n);

int main()
{
int i, n;


n = accept();
ganttp(n);

display(n);

return 0;

}

int accept()
{
int i, n;


srand(time(NULL)); 

printf("Enter the Number of Processes: ");
scanf("%d", &n);

cout << endl;

for (i = 1; i <= n; i++)
{
    printf("For process %d: ",i);
    printf("Enter Arrival Time ");
    scanf("%d", &p[i].at);
    p[i].id = i;
    printf("Enter Burst Time ");
    scanf("%d", &p[i].bt);
    cout<<endl;
    p[i].pr = rand() % 10 + 1; 

    p[i].rem = p[i].bt; 
}

for (i = 1; i <= n; i++)
{
    p1[i] = p[i];
}

return n;

}

void ganttp(int n)
{
int i, ts, m, nextval, nextarr;


p[0].tat = 0;
p[0].wt = 0;

nextval = p1[1].at;
i = 1;

while (i <= n || !q1.empty())
{
    while (i <= n && p1[i].at <= nextval)
    {
        q1.push(p1[i].id);
        i++;
    }

    if (q1.empty())
    {
        nextval = p1[i].at;
    }
    else
    {
        m = q1.front();

        if (p[m].rem <= p[q1.back()].rem && p[m].pr < p[q1.back()].pr)
        {
            q1.pop();
            q1.push(m);
        }

        p[m].st = nextval;
        nextval = nextval + 1;
        p[m].rem = p[m].rem - 1;

        if (p[m].rem == 0)
        {
            p[m].ft = nextval;
            q1.pop();
        }
    }
}

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

printf("\nProcess\tAT\tBT\tFT\tTAT\tWT\tPR");

	for (i = 1; i <= n; i++)
	{
		printf("\nP%d\t%d\t%d\t%d\t%d\t%d\t%d", p[i].id, p[i].at, p[i].bt, p[i].ft, p[i].tat, p[i].wt,p[i].pr);
	}

	cout << endl;
	printf("\nAverage Turn Around Time: %.2f", avgtat);
	printf("\nAverage Waiting Time: %.2f\n", avgwt);
}