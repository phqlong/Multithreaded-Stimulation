#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 1

typedef struct point{
    double x;
    double y;
} point;

int RandomPoint_in_Circle (long int nPoints){
    int count = 0;
    srand(time(NULL)); // Use current time as seed for random generator 
    point p;

    for(int i=0; i<nPoints; i++){
        p.x = (double)rand() / RAND_MAX;
        p.y = (double)rand() / RAND_MAX;
        if(p.x*p.x + p.y*p.y <= 1) count++;
    }
    return count;
}

int main(int argc, char *argv[]){
    clock_t start = clock();

    long int nPoints = atoi(argv[1]);
    double pi = 4*(double)RandomPoint_in_Circle(nPoints)/nPoints;
    printf("pi ~= %lf\n", pi);

    clock_t end = clock();
    printf("Time = %lf\n", (double) (end - start)/ CLOCKS_PER_SEC);

    return 0;
}