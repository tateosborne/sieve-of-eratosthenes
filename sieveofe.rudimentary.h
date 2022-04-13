#ifndef SIEVE_OF_ERATOSTHENES_SIEVEOFE_RUDIMENTARY_H
#define SIEVE_OF_ERATOSTHENES_SIEVEOFE_RUDIMENTARY_H

#define M 50

typedef struct {
    char *numbers;
    int lowerBound;
    int upperBound;
    int s;
} SharedData;


void sieveOfEratosthenes(SharedData *sharedData);

#endif //SIEVE_OF_ERATOSTHENES_SIEVEOFE_RUDIMENTARY_H
