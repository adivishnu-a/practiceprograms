#include <iostream>
#include <cstdlib>
#include <queue>
#include <cstdio>
using namespace std;

typedef struct process
{
    int at, bt, st, ft, pr, tt;
    int wt, tat;
} process;

process p[10], temp;
queue<int> q1;

int accept();
void display(int n);
void ganttrr(int n, int ts);
int ts;

int main()
{
    int i, n;

    n = accept();

    cout << "\nEnter the Time Quantum: ";
    cin >> ts;

    ganttrr(n, ts);

    display(n);

    return 0;
}

int accept()
{
    int i, n;
    cout<<"Enter the Number of Processes: ";
    cin>>n;

    cout << endl;

    for (i = 1; i <= n; i++)
    {
        cout<<"Enter Arrival Time of the Process P"<<i<<" :";
        cin>>p[i].at;
        cout<<"Enter Burst Time of the Process P"<<i<<" :";
        cin>>p[i].bt;
        p[i].tt = p[i].bt;
        cout<<endl;
    }
}

void ganttrr(int n, int ts)
{
    int i, m, nextval, curtime = 0, remain = n;
    queue<int> q;
    vector<int> order;
    bool flag = false;
    
    for (i = 1; i <= n; i++)
    {
        p[i].st = -1; // -1 means not started
        p[i].pr = i;
    }
    
    nextval = p[1].at;
    i = 1;
    
    while (remain > 0)
    {
        for (i = 1; i <= n; i++)
        {
            if (p[i].at <= nextval && p[i].st == -1)
            {
                q.push(i);
                p[i].st = nextval;
            }
        }
        
        if (q.empty())
        {
            nextval++;
            continue;
        }
        
        m = q.front();
        q.pop();
        order.push_back(m); // add process to execution order
        
        if (p[m].bt > ts)
        {
            p[m].bt -= ts;
            nextval += ts;
        }
        else
        {
            nextval += p[m].bt;
            p[m].bt = 0;
            p[m].ft = nextval;
            remain--;
        }
        
        for (i = 1; i <= n; i++)
        {
            if (p[i].at <= nextval && p[i].st == -1 && i != m)
            {
                q.push(i);
                p[i].st = nextval;
            }
        }
        
        if (p[m].bt > 0)
        {
            q.push(m);
        }
    }
    
    // generate the execution sequence
    cout << "Execution Order: ";
    for (i = 0; i < order.size(); i++)
    {
        cout << "P" << order[i];
        if (i != order.size() - 1)
        {
            cout << " -> ";
        }
    }
    cout << endl;
}

void display(int n) {
    float avg_tat = 0, avg_wt = 0;

    cout << "\nProcess\tArrival Time\tBurst Time\tCompletion Time\tWait Time\tTurnaround Time\n";
    for (int i = 1; i <= n; i++) {
        p[i].tat = p[i].ft - p[i].at;
        p[i].wt = p[i].tat - p[i].tt;
        avg_tat += p[i].tat;
        avg_wt += p[i].wt;

        cout << "P" << i << "\t" << p[i].at << "\t\t" << p[i].tt << "\t\t"
             << p[i].ft << "\t\t" << p[i].wt << "\t\t" << p[i].tat << endl;
    }

    avg_tat /= n;
    avg_wt /= n;

    cout << "\nAverage Turnaround Time: " << avg_tat;
    cout << "\nAverage Waiting Time: " << avg_wt << endl;
}

void roundRobin(process p[], int n, int timeQuantum) {
    int i, j, k, time = 0;
    queue<int> q;
    bool done[n] = {false};

    // Sort processes by arrival time
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (p[i].at > p[j].at) {
                swap(p[i], p[j]);
            }
        }
    }

    q.push(0);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (p[curr].bt <= timeQuantum) {
            time += p[curr].bt;
            p[curr].bt = 0;
        } else {
            time += timeQuantum;
            p[curr].bt -= timeQuantum;
        }

        for (i = 1; i < n; i++) {
            if (!done[i] && p[i].at <= time) {
                q.push(i);
            }
        }

        if (p[curr].bt == 0) {
            p[curr].ft = time;
            p[curr].tat = p[curr].ft - p[curr].at;
            p[curr].wt = p[curr].tat - p[curr].st;
            done[curr] = true;
        } else {
            p[curr].st = time - timeQuantum;
            p[curr].wt = p[curr].st - p[curr].at;
            q.push(curr);
        }
    }
}
