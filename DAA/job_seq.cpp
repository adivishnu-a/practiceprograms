#include <iostream>
#include <algorithm>

const int MAX_N = 100;  // Maximum number of jobs

// Structure to represent a job
struct Job {
  char id;  // Job ID
  int dead;  // Deadine of the job
  int profit;  // Profit of the job
};

// Comparison function to sort the jobs in decreasing order of profit
bool comparison(Job a, Job b) {
  return (a.profit > b.profit);
}

// Function to find the maximum profit job sequence
void jobSequencing(Job arr[], int n) {
  // Sort the jobs in decreasing order of profit
  std::sort(arr, arr + n, comparison);

  // Array to store the results (sequence of jobs)
  char result[MAX_N];
  bool slot[MAX_N];

  // Initialize all slots to be free
  for (int i = 0; i < n; i++)
    slot[i] = false;

  // Iterate through all the jobs
  for (int i = 0; i < n; i++) {
    // Find a free slot for this job (Note that we start from the
    // deadine of the job and search for a free slot backwards)
    for (int j = std::min(n, arr[i].dead) - 1; j >= 0; j--) {
      // If the slot is free, assign this job to the slot and mark the
      // slot as occupied
      if (!slot[j]) {
        result[j] = arr[i].id;
        slot[j] = true;
        break;
      }
    }
  }

  // Print the result
  for (int i = 0; i < n; i++)
    if (slot[i])
      std::cout << result[i] << " ";
}

int main() {
  // Array of jobs
  Job arr[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27},
                {'d', 1, 25}, {'e', 3, 15} };
  int n = sizeof(arr) / sizeof(arr[0]);

  std::cout << "Following is maximum profit sequence of jobs:\n";
  jobSequencing(arr, n);

  return 0;
}
