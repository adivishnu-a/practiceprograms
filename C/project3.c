#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <limits.h>
#include <math.h>

#define MAX 5
typedef bool Boolean;

typedef enum action
{
    ARRIVE, DEPART
} Action;

typedef struct plane
{
    int id, arrtime;
} Plane;

typedef Plane QueueEntry;

typedef struct queue
{
    int number, front, rear;  
    QueueEntry entry[MAX];
} Queue;

void CreateQueue(Queue *q)
{
    q->number = 0;
    q->front = 0;
    q->rear = -1;
}

int QueueSize(Queue *q)
{
    return q->number;
}

Boolean QueueFull(Queue *q)
{
    return q->number >= MAX;
}

Boolean QueueEmpty(Queue *q)
{
    return q->number <= 0;
}

void Randomize(void)
{
    //function to assign the starting pointfor pseudorandom integers
    srand((unsigned int) (time(NULL)% 10000));
}

void Append(QueueEntry x, Queue *q)
{
    if (!QueueFull(q))
    {
        q->number++;
        q->rear = (q->rear + 1) % MAX;
        q->entry[q->rear] = x;
    }
}

void Serve(QueueEntry *x, Queue *q)
{
    if (!QueueEmpty(q))
    {
        q->number--;
        *x = q->entry[q->front];
        q->front = (q->front + 1) % MAX;
    }
}


bool YesOrNo()
{
    //This function is used to check the user choice in case of saturation
    char str[4];
    scanf("%s",str);
    if (strcasecmp(str,"yes")==0)   //if user inputs YES or yes
    {
        return true;    //returning true
    }
    else    //if user inputs anything other than yes or YES
    {
        return false;   //returning false
    }  
}

void Start(int *endtime, double *arrexpect, double *deptexpect)
{
    //This function is used to accept the user input for the simulation
    bool chs;
    printf("One plane can land or depart in each unit of time. \n"
           "Up to %d planes can be waiting to land or take off at any time. \n", MAX);
    printf("How many units of time will the simulation run? ");
    scanf("%d", endtime);
    Randomize();
    do
    {
        printf("Expected number of arrivals per unit time: ");
        scanf("%lf", arrexpect);
        printf("Expected number of departures per unit time: ");
        scanf("%lf", deptexpect);
        if (*arrexpect < 0.0 || *deptexpect < 0.0)
        {
            printf("Number should not be negative \n");
            chs = false;
        }
        else if (*arrexpect + *deptexpect > 1.0)
        {
            printf("The airport will become saturated. Read new numbers? (yes/no): ");
            chs = !YesOrNo(); 
        }
        else
            chs = true;
    } while (chs == false);
}

void NewPlane(Plane *p, int *nplanes, int curtime, Action kind)
{
    //This function is used to create a new record a plane and update nplanes
    (*nplanes)++;
    p->id = *nplanes;
    p->arrtime = curtime;
    switch (kind)
    {
    case ARRIVE:
        printf(" Plane %3d ready to land. \n", *nplanes);
        break;
    case DEPART:
        printf(" Plane %3d ready to take off. \n", *nplanes);
        break;
    }
}

void Refuse(Plane p, int *nrefuse, Action kind)
{
    //This function is used to processes a plane when the queue is full
    switch (kind)
    {
    case ARRIVE:
        printf(" Plane %3d directed to another airport. \n", p.id);
        break;
    case DEPART:
        printf(" Plane %3d told to try later. \n", p.id);
        break;
    }
    (*nrefuse)++;
}

void Land(Plane p, int curtime, int *nland, int *landdelay)
{
    //This function is used to process a landing plane
    int wait;
    wait = curtime - p.arrtime;
    printf("%3d : Plane %3d landed; wait of %d units of time. \n", curtime, p.id, wait);
    (*nland)++;
    *landdelay += wait;
}

void Fly(Plane p, int curtime, int *ntakeoff, int *takeoffdelay)
{
    //This function is used to process a plane that is taking off
    int wait;
    wait = curtime - p.arrtime;
    printf("%3d : Plane %3d took off;  wait of %d units of time. \n", curtime, p.id, wait);
    (*ntakeoff)++;
    *takeoffdelay += wait;
}

void Idle(int curtime, int *idle)
{
    //This function is used to update the variables for idle runway
    printf("%3d: Runway is idle.\n", curtime);
    (*idle)++;
}

void Conclude(int nplanes, int nland, int ntakeoff,
              int nrefuse, int landdelay, int takeoffdelay,
              int idle, int endtime,
              Queue *pt, Queue *pl)
{
    //This function is used to display the output and terminate the simulation
    printf("Simulation has concluded after %d units. \n", endtime);
    printf("Total number of planes processed: %3d \n", nplanes);
    printf(" Number of planes landed:    %3d \n", nland);
    printf(" Number of planes taken off: %3d \n", ntakeoff);
    printf(" Number of planes refused use: %3d \n", nrefuse);
    printf(" Number left ready to land:  %3d \n", QueueSize(pl));
    printf(" Number left ready to take off: %3d \n", QueueSize(pt));
    if (endtime > 0)
        printf(" Percentage of time runway idle: %6.2f \n",((double)idle / endtime) * 100.0);
    if (nland > 0)
        printf(" Average wait time to land: %6.2f\n",(double)landdelay / nland);
    if (ntakeoff > 0)
        printf(" Average wait time to take off: %6.2f \n",(double)takeoffdelay / ntakeoff);
}

int PoissonRandom(double expectedvalue)
{
    //function to generate a pseudorandom integer according to the Poisson distribution. 
    int n = 0; 
    double limit, x;
    limit = exp(-expectedvalue);
    x = rand() / (double)32765;
    while (x > limit)
    {
        n++;
        x *= rand() / (double)32765;
    }
    return n;
}

int main(void)
{
    //The main() function of the program. Program execution starts here
    Queue land, takeoff;
    Queue *pl = &land;
    Queue *pt = &takeoff;
    Plane plane;
    double arrexpect, deptexpect;
    int i, idle, landdelay, takeoffdelay, nland, nplanes, nrefuse, ntakeoff, pri, curtime, endtime;
    CreateQueue(pl);
    CreateQueue(pt);
    nplanes = nland = ntakeoff = nrefuse = landdelay = takeoffdelay = idle = 0;
    Start(&endtime, &arrexpect, &deptexpect);   //taking user input
    for (curtime = 1; curtime <= endtime; curtime++)    //running the simulations
    {
        pri = PoissonRandom(arrexpect);
        for (i=1; i <= pri; i++)
        {
            NewPlane(&plane, &nplanes, curtime, ARRIVE);
            if (QueueFull(pl))
                Refuse(plane, &nrefuse, ARRIVE);
            else
                Append(plane, pl);
        }
        pri = PoissonRandom(deptexpect);
        for (i = 1; i <= pri; i++)
        { 
            NewPlane(&plane, &nplanes, curtime, DEPART);
            if (QueueFull(pt))
                Refuse(plane, &nrefuse, DEPART);
            else
                Append(plane, pt);
        }
        if (!QueueEmpty(pl))
        { 
            Serve(&plane, pl);
            Land(plane, curtime, &nland, &landdelay);
        }
        else if (!QueueEmpty(pt))
        { 
            Serve(&plane, pt);
            Fly(plane, curtime, &ntakeoff, &takeoffdelay);
        }
        else
            Idle(curtime, &idle);
    }
    Conclude(nplanes, nland, ntakeoff, nrefuse, landdelay, takeoffdelay, idle, endtime, pt, pl);
    return 0;
}