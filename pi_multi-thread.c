#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 4

typedef struct point{
    double x;
    double y;
} point;

long int count = 0;

void *RandomPoint_in_Circle (void *thread_arg){
    long int nPoints = *(long int*)thread_arg;
    long int count_per_thread = 0;
    srand(time(NULL)); // Use current time as seed for random generator 
    point p;

    for(int i=0; i<nPoints; i++){
        p.x = (double)rand() / RAND_MAX;
        p.y = (double)rand() / RAND_MAX;
        if(p.x*p.x + p.y*p.y <= 1) count_per_thread++;
    }
    count += count_per_thread;
    pthread_exit(NULL);
}

int main(int argc, char *argv[]){
    clock_t start = clock();

    long int nPoints = atoi(argv[1]);
    long int point_per_thread = nPoints/N;   //number of point per thread
    pthread_t threads[N];

    for(int i=0; i<N; i++){
        printf("In main: creating thread %d\n", i);

        int rc = pthread_create(&threads[i], NULL, RandomPoint_in_Circle, (void*)&point_per_thread);

        if(rc){ //if (rc == 0) => success; else rc = no. ERROR
            printf("ERROR: return from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    // wait for all thread complete running
    for(int i=0; i<N; i++){
        pthread_join(threads[i], NULL);
    }

    double pi = 4*(double)count/(double)(N * point_per_thread);
    printf("pi ~= %lf\n", pi);

    clock_t end = clock();
    printf("Time = %lf\n", (double) (end - start)/ CLOCKS_PER_SEC);

    return 0;
}