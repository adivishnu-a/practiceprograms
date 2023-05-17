#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_STUDENTS 5
#define NUM_CHAIRS 3

sem_t students_sem;
sem_t ta_sem;
pthread_mutex_t mutex;

int num_waiting_students = 0;

void *student(void *arg)
{
    int student_id = *(int *)arg;

    // Check if the TA is sleeping
    pthread_mutex_lock(&mutex);
    if (num_waiting_students == 0)
        sem_post(&ta_sem); // Wake up the TA
    if (num_waiting_students < NUM_CHAIRS)
    {
        num_waiting_students++;
        printf("Student %d is waiting.\n", student_id);
        pthread_mutex_unlock(&mutex);
        sem_wait(&students_sem); // Wait until the TA is available
        printf("Student %d is receiving help.\n", student_id);
    }
    else
    {
        pthread_mutex_unlock(&mutex);
        printf("No chairs available for student %d. Will try again later.\n", student_id);
    }

    pthread_exit(NULL);
}

void *ta(void *arg)
{
    while (1)
    {
        sem_wait(&ta_sem); // Wait until a student wakes up the TA

        printf("TA is awake and ready to help.\n");

        pthread_mutex_lock(&mutex);
        if (num_waiting_students > 0)
        {
            num_waiting_students--;
            sem_post(&students_sem); // Signal a student to receive help
        }
        pthread_mutex_unlock(&mutex);
    }
}

int main()
{
    pthread_t ta_thread;
    pthread_t student_threads[NUM_STUDENTS];
    int student_ids[NUM_STUDENTS];

    // Initialize semaphores and mutex
    sem_init(&students_sem, 0, 0);
    sem_init(&ta_sem, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    // Create the TA thread
    pthread_create(&ta_thread, NULL, ta, NULL);

    // Create the student threads
    for (int i = 0; i < NUM_STUDENTS; i++)
    {
        student_ids[i] = i + 1;
        pthread_create(&student_threads[i], NULL, student, &student_ids[i]);
    }

    // Wait for all student threads to finish
    for (int i = 0; i < NUM_STUDENTS; i++)
    {
        pthread_join(student_threads[i], NULL);
    }

    // Cancel the TA thread and wait for it to finish
    pthread_cancel(ta_thread);
    pthread_join(ta_thread, NULL);

    // Destroy semaphores and mutex
    sem_destroy(&students_sem);
    sem_destroy(&ta_sem);
    pthread_mutex_destroy(&mutex);

    return 0;
}
