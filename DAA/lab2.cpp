//Quick Sort
#include <iostream>
using namespace std;

void swap(int *a, int *b);
int partition(int array[], int left, int right);
void quickSort(int array[], int left, int right);
void display(int arr[], int size);

int main() 
{
    int i, n, arr[20];
    cout << "Enter the size of the array : ";
    cin >> n;
    cout << "Enter the Array elements : " << endl;
    for(i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    cout << endl << "The Given Array is : " << endl;
    display(arr, n);
    quickSort(arr, 0, n - 1);
    cout << endl << "The Sorted Array is : " << endl;
    display(arr, n);
}

void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int array[], int left, int right) 
{
    int pivot = array[right];
    int i = (left - 1);
    int j;
    for (j = left; j < right; j++) 
    {
        if (array[j] <= pivot) 
        {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[right]);
    return (i + 1);
}

void quickSort(int array[], int left, int right) 
{
    if (left < right) 
    {
        int pivot = partition(array, left, right);
        quickSort(array, left, pivot - 1);
        quickSort(array, pivot + 1, right);
    }
}

void display(int arr[], int size) 
{
    int i;
    for (i = 0; i < size; ++i) 
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}