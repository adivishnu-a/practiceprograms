#include <iostream>
#include <string>
using namespace std;

struct process {
    string pid; 
    int burst_time;
    int completion_time; 
    int wait_time; 
    int turn_around_time; 
    process* next; 
};

class ProcessQueue {
private:
    process* front; 
    process* rear; 
public:
    ProcessQueue() { 
        front = NULL;
        rear = NULL;
    }
    
    void enqueue(string pid, int burst_time) {
        process* new_process = new process;
        new_process->pid.assign(pid);
        new_process->burst_time = burst_time;
        new_process->next = NULL;
        
        if (rear == NULL) { 
            front = rear = new_process;
        }
        else { 
            rear->next = new_process;
            rear = new_process;
        }
    }
    
    process* dequeue() {
        if (front == NULL) { 
            return NULL;
        }
        else {
            process* removed_process = front;
            front = front->next;
            if (front == NULL) { 
                rear = NULL;
            }
            return removed_process;
        }
    }
    
    bool is_empty() {
        return front == NULL;
    }
};

int main() {
    ProcessQueue q; 
    
    int n; 
    cout << "Enter the number of processes: ";
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        string pid; 
        int burst_time;
        cout << "Enter the process ID of process " << i + 1 << ": ";
        cin >> pid;
        cout << "Enter the burst time for process " << i + 1 << ": ";
        cin >> burst_time;
        q.enqueue(pid, burst_time); 
    }
    
    int current_time = 0; 
    int prev_complete=0;
    int wait_sum=0, turn_sum=0;
    cout<<endl<<"PID\tBT\tCT\tWT\tTAT"<<endl;
    cout<<"---\t--\t--\t--\t---"<<endl;
    while (!q.is_empty()) { 
        process* current = q.dequeue(); 
        current->completion_time = current_time + current->burst_time; 
        current->turn_around_time = current->completion_time; 
        current->wait_time = prev_complete; 
        current_time = current->completion_time; 
        
        wait_sum=wait_sum+current->wait_time;
        turn_sum=turn_sum+current->turn_around_time;

        cout<<current->pid<<"\t"<<current->burst_time<<"\t"
        <<current->completion_time<<"\t"<<current->wait_time
        <<"\t"<<current->turn_around_time<<endl;

        prev_complete = current->completion_time;
    
        delete current; 
    }
    float avg_wait=(float)wait_sum/n;
    float avg_turn=(float)turn_sum/n;
    cout<<endl<<"Average Waiting Time : "<<avg_wait<<endl;
    cout<<"Average Turn Around Time : "<<avg_turn<<endl<<endl;
    return 0;
}

