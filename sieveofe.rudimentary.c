#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sieveofe.rudimentary.h"


void sieveOfEratosthenes(SharedData *sharedData) {
    // cast the input to SharedData data type
    SharedData *package;
    package = (SharedData *) sharedData;

    // initialize currNum to be the lower bound (2)
    int currNum = package->lowerBound;

    // initialize done flag to 0
    int done = 0;
    while (!done) {
        // loop as long as the currNum element of the array is not -1 and currNum is less than the (floor of sqrt(m+1)) + 1
        while (package->numbers[currNum] != -1 && currNum < package->s) {
            // if the currNum element of the array is 0
            if (package->numbers[currNum] != 0) {
                // set the element to -1, signaling "looked at"
                package->numbers[currNum] = -1;

                // declare and initialize factor to 2
                int factor = 2;
                // cross off (set to 0) every multiple of currNum so long the multiple is less than the upperBound
                while (currNum * factor < package->upperBound) {
                    package->numbers[currNum * factor] = 0;
                    // increment factor
                    factor++;
                }
            }
            ++currNum;

        }
        // we are done; end while
        done = 1;
    }
}

int main() {

    SharedData *package = malloc(sizeof(SharedData));
    package->numbers = malloc(sizeof(char) * M);
    package->lowerBound = 2;
    package->upperBound = M + 1;
    package->s = (int)floor(sqrt(M + 1)) + 1;

    // initialize every element in the array to be 1
    for (int i = 0; i < package->upperBound; ++i) {
        package->numbers[i] = 1;
    }

    sieveOfEratosthenes(package);

    // print final array
    printf("[\n");
    for (int i = 0; i < package->upperBound; ++i) {
        printf(" %d (%d),\n", i, package->numbers[i]);
    }
    printf("]\n");
}
