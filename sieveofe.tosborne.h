#ifndef SIEVE_OF_ERATOSTHENES_SIEVEOFE_TOSBORNE_H
#define SIEVE_OF_ERATOSTHENES_SIEVEOFE_TOSBORNE_H

#define N_THREADS 10
#define M 1000000000

typedef struct {
    char *numbers;
    int lowerBound;
    int upperBound;
    int s;
    pthread_mutex_t *mutex;
} SharedData;


void *sieveOfEratosthenes(void *sharedData);

#endif //SIEVE_OF_ERATOSTHENES_SIEVEOFE_TOSBORNE_H
