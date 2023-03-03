#include <iostream>
using namespace std;

// Node structure for a process
struct ProcessNode {
    int processId; // Process ID
    int burstTime; // Burst time
    int arrivalTime; // Arrival time
    int completionTime; // Completion time
    int waitTime; // Wait time
    int turnAroundTime; // Turn around time
    ProcessNode* next; // Pointer to next process node
};

// Class for implementing a queue using a linked list
class ProcessQueue {
private:
    ProcessNode* front; // Pointer to the front of the queue
    ProcessNode* rear; // Pointer to the rear of the queue
public:
    ProcessQueue() { // Constructor to initialize front and rear pointers to NULL
        front = NULL;
        rear = NULL;
    }
    
    // Function to add a new process to the rear of the queue
    void enqueue(int processId, int burstTime, int arrivalTime) {
        ProcessNode* newProcess = new ProcessNode;
        newProcess->processId = processId;
        newProcess->burstTime = burstTime;
        newProcess->arrivalTime = arrivalTime;
        newProcess->completionTime = 0;
        newProcess->waitTime = 0;
        newProcess->turnAroundTime = 0;
        newProcess->next = NULL;
        
        if (rear == NULL) { // If the queue is empty, set both front and rear pointers to the new process
            front = rear = newProcess;
        }
        else { // Otherwise, add the new process to the rear of the queue
            rear->next = newProcess;
            rear = newProcess;
        }
    }
    
    // Function to remove the process at the front of the queue and return its details
    ProcessNode* dequeue() {
        if (front == NULL) { // If the queue is empty, return NULL
            return NULL;
        }
        else {
            ProcessNode* removedProcess = front;
            front = front->next;
            if (front == NULL) { // If the queue is now empty, set the rear pointer to NULL as well
                rear = NULL;
            }
            return removedProcess;
        }
    }
    
    // Function to check if the queue is empty
    bool isEmpty() {
        return front == NULL;
    }
};

int main() {
    ProcessQueue processQueue; // Initialize the process queue
    ProcessQueue p;
    
    int numberOfProcesses; // Number of processes
    cout << "Enter the number of processes: ";
    cin >> numberOfProcesses;
    
    // Loop to read the details of each process and add it to the queue
for (int i = 0; i < numberOfProcesses; i++) {
    int process_id, burstTime;
    cout << "Enter the process ID and burst time for process " << i + 1 << ": ";
    cin >> process_id >> burstTime;
    p.enqueue(process_id, burstTime, i); // Add the new process to the queue
}

// Loop to process each process in the queue
int current_time = 0, prev=0; // Initialize the current time to 0
float turnsum=0, waitsum=0;
while (!p.isEmpty()) { // Keep processing processes until the queue is empty
    ProcessNode* current_process = p.dequeue(); // Get the next process from the front of the queue
    current_process->completionTime = current_time + current_process->burstTime; // Calculate the completion time of the process
    current_process->turnAroundTime = current_process->completionTime; // Calculate the turn around time of the process
    current_process->waitTime = prev;
    //Calculate the wait time of the process
    turnsum+=current_process->turnAroundTime;
    waitsum+=current_process->waitTime;
    current_time = current_process->completionTime; // Update the current time to the completion time of the process
    // Print the details of the processed process
    cout << "Process " << current_process->processId << ": " << endl;
    cout << "Completion time = " << current_process->completionTime << endl;
    cout << "Turn around time = " << current_process->turnAroundTime << endl;
    cout << "Wait time = " << current_process->waitTime << endl;
    cout << endl;

    prev=current_process->completionTime;
    
    delete current_process; // Free the memory allocated for the processed process
}

float turnavg=turnsum/numberOfProcesses;
float waitavg=waitsum/numberOfProcesses;
cout<<"Average Turn Around Time: "<<turnavg<<endl<<"Average Wait Time: "<<waitavg<<endl;

return 0;
}