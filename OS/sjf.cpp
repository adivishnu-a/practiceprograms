#include <iostream>
using namespace std;

class Process 
{
    public:
    string pid;
    int burst;
    int comp;
    int wait;
    int turnaround;
};


void ComplTimeCalc(Process* pro, int n)
{
    int current_time = 0;
    for (int i = 0; i < n; i++)
    {
        current_time += pro[i].burst;
        pro[i].comp = current_time;
    }
}

void WaitTimeCalc(Process* pro, int n) 
{
    int current_time = 0;
    for (int i = 0; i < n; i++) 
    {
        pro[i].wait = current_time;
        current_time += pro[i].burst;
    }
}

void TurnAroundTimeCalc(Process* pro, int n) 
{
    for (int i = 0; i < n; i++) 
    {
        pro[i].turnaround = pro[i].comp - 0;
    }
}

void display(Process* pro, int n) 
{
    cout << "\nProcess ID\tBurst Time\tCompletion Time\tWaiting Time\tTurn Around Time" << endl;
    for (int i = 0; i < n; i++) 
    {
        cout << pro[i].pid << "\t\t" << pro[i].burst << "\t\t"
             << pro[i].comp << "\t\t" << pro[i].wait << "\t\t"
             << pro[i].turnaround << endl;
    }
}

void sort(Process* pro, int n) 
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            if (pro[i].burst > pro[j].burst) 
            {
                Process temp = pro[i];
                pro[i] = pro[j];
                pro[j] = temp;
            }
        }
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
        cout << "Enter the process id " << i + 1 << ": ";
        cin >> pro[i].pid;
        cout << "Enter theburst time for process " << i + 1 << ": ";
        cin >>  pro[i].burst;
    }
    sort(pro, n);
    ComplTimeCalc(pro, n);
    WaitTimeCalc(pro, n);
    TurnAroundTimeCalc(pro, n);
    double avg_wait = 0;
    double avg_tat = 0;
    for (int i = 0; i < n; i++) 
    {
        avg_wait = avg_wait + pro[i].wait;
        avg_tat = avg_tat + pro[i].turnaround;
    }
    avg_wait = avg_wait / n;
    avg_tat = avg_tat / n;
    display(pro, n);
    cout << endl<< "Average waiting time: " << avg_wait << endl;
    cout << "Average turn around time: " << avg_tat << endl<<endl;
    delete[] pro;
    return 0;
}
