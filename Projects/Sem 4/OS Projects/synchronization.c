#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <process.h>
#include <time.h>

#define MAX_CHAIRS 3
#define NUM_STUDENTS 5

HANDLE student_semaphores[NUM_STUDENTS];
HANDLE faculty_semaphore;
HANDLE chair_semaphore;

unsigned __stdcall stu_programming(void* student_id) {
    int student = *(int*)student_id;

    while (1) {
        // Student is programming
        printf("Student %d is programming.\n", student);
        Sleep(rand() % 5000);

        // Notify the Faculty for help
        WaitForSingleObject(chair_semaphore, INFINITE);
        DWORD result = WaitForSingleObject(faculty_semaphore, 0);
        if (result == WAIT_OBJECT_0) {
            // Faculty is available to help
            printf("Student %d is receiving help from the Faculty.\n", student);
            Sleep(rand() % 3000);
            ReleaseSemaphore(faculty_semaphore, 1, NULL);
            ReleaseSemaphore(chair_semaphore, 1, NULL);
            break;
        } else {
            // Faculty is busy, wait in the hallway
            printf("Student %d is waiting in the hallway.\n", student);
            ReleaseSemaphore(chair_semaphore, 1, NULL);
            WaitForSingleObject(student_semaphores[student], INFINITE);
        }
    }

    _endthreadex(0);
    return 0;
}

unsigned __stdcall faculty_teaching(void* arg) {
    while (1) {
        // Faculty is sleeping until notification from a student
        printf("Faculty is sleeping.\n");
        WaitForSingleObject(faculty_semaphore, INFINITE);

        // Faculty is helping the student
        printf("Faculty is helping a student.\n");
        Sleep(rand() % 3000);
        ReleaseSemaphore(student_semaphores[rand() % NUM_STUDENTS], 1, NULL);

        // Check if there are remaining students
        DWORD result = WaitForSingleObject(chair_semaphore, 0);
        if (result == WAIT_OBJECT_0) {
            // There are remaining students, continue helping
            ReleaseSemaphore(chair_semaphore, 1, NULL);
            continue;
        } else {
            // No remaining students, go back to sleep
            printf("Faculty has finished helping all students. Going back to sleep.\n");
            ReleaseSemaphore(faculty_semaphore, 1, NULL);
            WaitForSingleObject(faculty_semaphore, INFINITE);
        }
    }

    _endthreadex(0);
    return 0;
}

void rand_sleep() {
    Sleep(rand() % 5000);
}

int main() {
    srand(time(NULL));

    HANDLE students[NUM_STUDENTS];
    HANDLE faculty;

    // Initialize semaphores
    for (int i = 0; i < NUM_STUDENTS; i++) {
        student_semaphores[i] = CreateSemaphore(NULL, 0, 1, NULL);
    }
    faculty_semaphore = CreateSemaphore(NULL, 1, 1, NULL);
    chair_semaphore = CreateSemaphore(NULL, MAX_CHAIRS, MAX_CHAIRS, NULL);

    // Create student threads
    int student_ids[NUM_STUDENTS];
    for (int i = 0; i < NUM_STUDENTS; i++) {
        student_ids[i] = i;
        students[i] = (HANDLE)_beginthreadex(NULL, 0, stu_programming, (void*)&student_ids[i], 0, NULL);
    }

    // Create faculty thread
    faculty = (HANDLE)_beginthreadex(NULL, 0, faculty_teaching, NULL, 0, NULL);

// Sleep for a while to simulate the program execution
rand_sleep();

// Wait for student threads to finish
WaitForMultipleObjects(NUM_STUDENTS, students, TRUE, INFINITE);

// Terminate faculty thread
TerminateThread(faculty, 0);

// Close thread handles
for (int i = 0; i < NUM_STUDENTS; i++) {
    CloseHandle(students[i]);
    CloseHandle(student_semaphores[i]);
}
CloseHandle(faculty);
CloseHandle(faculty_semaphore);
CloseHandle(chair_semaphore);

return 0;

}