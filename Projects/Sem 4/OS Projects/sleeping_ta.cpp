#include <iostream>
#include <windows.h>

#define NUM_STUDENTS 5
#define NUM_CHAIRS 3

HANDLE students_sem;
HANDLE ta_sem;
HANDLE mutex;

int num_waiting_students = 0;

DWORD WINAPI StudentThread(LPVOID lpParam)
{
    int student_id = *(int*)lpParam;

    // Check if the TA is sleeping
    WaitForSingleObject(mutex, INFINITE);
    if (num_waiting_students == 0)
        ReleaseSemaphore(ta_sem, 1, NULL); // Wake up the TA

    if (num_waiting_students < NUM_CHAIRS)
    {
        num_waiting_students++;
        std::cout << "Student " << student_id << " is waiting." << std::endl;
        ReleaseMutex(mutex);
        WaitForSingleObject(students_sem, INFINITE); // Wait until the TA is available
        std::cout << "Student " << student_id << " is receiving help." << std::endl;
    }
    else
    {
        ReleaseMutex(mutex);
        std::cout << "No chairs available for student " << student_id << ". Will try again later." << std::endl;
    }

    return 0;
}

DWORD WINAPI TAThread(LPVOID lpParam)
{
    while (true)
    {
        WaitForSingleObject(ta_sem, INFINITE); // Wait until a student wakes up the TA

        std::cout << "TA is awake and ready to help." << std::endl;

        WaitForSingleObject(mutex, INFINITE);
        if (num_waiting_students > 0)
        {
            num_waiting_students--;
            ReleaseSemaphore(students_sem, 1, NULL); // Signal a student to receive help
        }
        ReleaseMutex(mutex);
    }
}

int main()
{
    HANDLE ta_thread;
    HANDLE student_threads[NUM_STUDENTS];
    int student_ids[NUM_STUDENTS];

    // Create semaphores and mutex
    students_sem = CreateSemaphore(NULL, 0, NUM_CHAIRS, NULL);
    ta_sem = CreateSemaphore(NULL, 0, 1, NULL);
    mutex = CreateMutex(NULL, FALSE, NULL);

    // Create the TA thread
    ta_thread = CreateThread(NULL, 0, TAThread, NULL, 0, NULL);

    // Create the student threads
    for (int i = 0; i < NUM_STUDENTS; i++)
    {
        student_ids[i] = i + 1;
        student_threads[i] = CreateThread(NULL, 0, StudentThread, &student_ids[i], 0, NULL);
    }

    // Wait for all student threads to finish
    WaitForMultipleObjects(NUM_STUDENTS, student_threads, TRUE, INFINITE);

    // Cancel the TA thread and wait for it to finish
    TerminateThread(ta_thread, 0);
    WaitForSingleObject(ta_thread, INFINITE);

    // Close handles
    CloseHandle(students_sem);
    CloseHandle(ta_sem);
    CloseHandle(mutex);

    return 0;
}
