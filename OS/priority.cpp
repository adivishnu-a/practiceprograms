#include <iostream>

using namespace std;

class Process
{
    public:
    string pid;
    int burst;
    int priority;
    int comp;
    int wait;
    int tat;
};

void sort(Process* pro, int n) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (pro[j].priority > pro[j+1].priority) 
            {
                Process temp = pro[j];
                pro[j] = pro[j+1];
                pro[j+1] = temp;
            }
        }
    }
}

void calculateCompletionTime(Process* pro, int n) 
{
    int current_time = 0;
    for (int i = 0; i < n; i++) 
    {
        current_time += pro[i].burst;
        pro[i].comp = current_time;
    }
}

void calculateWaitingTime(Process* pro, int n) 
{
    int current_time = 0;
    for (int i = 0; i < n; i++)
    {
        pro[i].wait = current_time;
        current_time += pro[i].burst;
    }
}

void calculateTurnAroundTime(Process* pro, int n) 
{
    for (int i = 0; i < n; i++) 
    {
        pro[i].tat = pro[i].comp - 0;
    }
}

void display(Process* pro, int n) 
{
    cout << "Process ID\tBurst Time\tPriority\tCompletion Time\tWaiting Time\tTurn Around Time" << endl;
    for (int i = 0; i < n; i++) 
    {
        cout << pro[i].pid << "\t\t" << pro[i].burst << "\t\t"
             << pro[i].priority << "\t\t" << pro[i].comp << "\t\t"
             << pro[i].wait << "\t\t" << pro[i].tat << endl;
    }
}

int main() 
{
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;
    Process* pro = new Process[n];
    for (int i = 0; i < n; i++) 
    {
        cout << "Enter process id of process " << i + 1 << ": ";
        cin >>pro[i].pid;
        cout << "Enter burst time of process " << i + 1 << ": ";
        cin >>pro[i].burst;
        cout << "Enter priority of the process " << i + 1 << ": ";
        cin >> pro[i].priority;
    }
    sort(pro, n);
    calculateCompletionTime(pro, n);
    calculateWaitingTime(pro, n);
    calculateTurnAroundTime(pro, n);
    double avg_wait = 0;
    double avg_tat = 0;
    for (int i = 0; i < n; i++) 
    {
        avg_wait = avg_wait + pro[i].wait;
        avg_tat = avg_tat + pro[i].tat;
    }
    avg_wait = avg_wait / n;
    avg_tat = avg_tat / n;
    display(pro, n);
    cout << "\n\tAverage waiting time: " << avg_wait << endl;
    cout << "\tAverage turn around time: " << avg_tat << endl;
    delete[] pro;
    return 0;
}