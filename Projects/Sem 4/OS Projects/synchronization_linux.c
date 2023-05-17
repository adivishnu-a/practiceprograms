#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define MAX_CHAIRS 3
#define NUM_STUDENTS 5

sem_t student_semaphores[NUM_STUDENTS];
sem_t faculty_semaphore;
sem_t chair_semaphore;

void* stu_programming(void* student_id) {
    int student = *(int*)student_id;

    while (1) {
        // Student is programming
        printf("Student %d is programming.\n", student);
        sleep(rand() % 5);

        // Notify the Faculty for help
        sem_wait(&chair_semaphore);
        if (sem_trywait(&faculty_semaphore) == 0) {
            // Faculty is available to help
            printf("Student %d is receiving help from the Faculty.\n", student);
            sleep(rand() % 3);
            sem_post(&faculty_semaphore);
            sem_post(&chair_semaphore);
            break;
        } else {
            // Faculty is busy, wait in the hallway
            printf("Student %d is waiting in the hallway.\n", student);
            sem_post(&chair_semaphore);
            sem_wait(&student_semaphores[student]);
        }
    }

    pthread_exit(NULL);
}

void* faculty_teaching(void* arg) {
    while (1) {
        // Faculty is sleeping until notification from a student
        printf("Faculty is sleeping.\n");
        sem_wait(&faculty_semaphore);

        // Faculty is helping the student
        printf("Faculty is helping a student.\n");
        sleep(rand() % 3);
        sem_post(&student_semaphores[rand() % NUM_STUDENTS]);

        // Check if there are remaining students
        if (sem_trywait(&chair_semaphore) == 0) {
            // There are remaining students, continue helping
            sem_post(&chair_semaphore);
            continue;
        } else {
            // No remaining students, go back to sleep
            printf("Faculty has finished helping all students. Going back to sleep.\n");
            sem_post(&faculty_semaphore);
            sem_wait(&faculty_semaphore);
        }
    }

    pthread_exit(NULL);
}

void rand_sleep() {
    sleep(rand() % 5);
}

int main() {
    srand(time(NULL));

    pthread_t students[NUM_STUDENTS];
    pthread_t faculty;

    // Initialize semaphores
    sem_init(&faculty_semaphore, 0, 1);
    sem_init(&chair_semaphore, 0, MAX_CHAIRS);

    for (int i = 0; i < NUM_STUDENTS; i++) {
        sem_init(&student_semaphores[i], 0, 0);
    }

    // Create student threads
    int student_ids[NUM_STUDENTS];
    for (int i = 0; i < NUM_STUDENTS; i++) {
        student_ids[i] = i;
        pthread_create(&students[i], NULL, stu_programming, (void*)&student_ids[i]);
    }

    // Create faculty thread
    pthread_create(&faculty, NULL, faculty_teaching, NULL);

    // Sleep for a while to simulate the program execution
    rand_sleep();

    // Wait for student threads to finish
    for (int i = 0; i < NUM_STUDENTS; i++) {
        pthread_join(students[i], NULL);
    }

    // Terminate faculty thread
    pthread_cancel(faculty);

    // Destroy semaphores
    sem_destroy(&faculty_semaphore);
    sem_destroy(&chair_semaphore);
    for (int i = 0; i < NUM_STUDENTS; i++) {
sem_destroy(&student_semaphores[i]);
}

return 0;

}