#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include "sieveofe.tosborne.h"


void *sieveOfEratosthenes(void *tinfo) {
    // cast tinfo to SharedData
    SharedData *package = (SharedData *) tinfo;
    // declare and initialize currNum to the lowerBound
    int currNum = package->lowerBound;

    // declare and initialize the done flag to 0 (false)
    int done = 0;
    while (!done) {
        // lock the mutex
        pthread_mutex_lock(package->mutex);

        // look for the next prime: while array[currNum] <= 0 AND currNum < upperBound, increment currNum
        while (package->numbers[currNum] <= 0 && currNum < package->upperBound) {
            ++currNum;
        }
        // if currNum is greater than the floor(sqrt(M + 1)) + 1, then this thread is done
        if (currNum > package->s) {
            pthread_mutex_unlock(package->mutex);
            done = 1;

        // otherwise, this thread has found the next prime to use for crossing off
        } else {
            // set array[currNum] to -1
            package->numbers[currNum] = -1;
        }

        // unlock the mutex
        pthread_mutex_unlock(package->mutex);

        // if not done
        if (!done) {
            // declare factor to 2
            int factor = 2;

            // while currNum * factor of currNum is less than the upper bound
            while (currNum * factor < package->upperBound) {
                // cross off the multiple of currNum
                package->numbers[currNum * factor] = 0;
                // increment factor
                ++factor;
            }
        }
    }

    // exit thread
    pthread_exit(NULL);
}

int main() {
    // declare and initialize the mutex
    pthread_mutex_t mutexLock;
    pthread_mutex_init(&mutexLock, NULL);

    // declare the references for each thread
    pthread_t tid[N_THREADS];

    // create the package that will hold all the information each thread will share
    SharedData *package = malloc(sizeof(SharedData));
    package->numbers = malloc(sizeof(char) * M);
    package->lowerBound = 2;
    package->upperBound = M + 1;
    package->s = (int) floor(sqrt(M + 1)) + 1;
    package->mutex = &mutexLock;

    // initialize every element in the array to be 1
    for (int i = 0; i < package->upperBound; ++i) {
        package->numbers[i] = 1;
    }

    // create the threads and have them act on the function using the package of data
    for (int i = 0; i < N_THREADS; ++i) {
        pthread_create(&tid[i], NULL, sieveOfEratosthenes, package);
    }

    // wait for all the threads to finish their jobs
    for (int i = 0; i < N_THREADS; ++i) {
        pthread_join(tid[i], NULL);
    }

    // destroy the mutex as it's not needed anymore
    pthread_mutex_destroy(package->mutex);

    // print final array
    printf("[\n");
    for (int i = 0; i < package->upperBound; ++i) {
        printf(" %d (%d),\n", i, package->numbers[i]);
    }
    printf("]\n");
}
