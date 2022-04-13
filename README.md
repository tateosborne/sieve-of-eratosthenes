## sieve-of-eratosthenes
---
#### An algorithm implemented multithreading (with mutexes) in C to search through an array and cross off all the composite numbers.
---
In the header file, the number of threads, `N_THREADS`, and the number of elements in the array, `M`, are defined as macros.
Also, there is a struct, `SharedData` defined which holds the package of information that's shared between the threads.
In `main`, the threads are created and the `SharedData` values are initialized and the threads are created.
Each thread will act on the shared array and be forced to go through a mutex to allow multiple threads to work simultaneously (without acting
on the same elements). The algorithm only runs so long the current number being checked is less than or equal to the `floor(sqrt(M)) + 1`.

The final array is printed to the console where the number inside the parenthesis for each element signifies whether it's prime or not.
Example output for an `#define M = 10`:
```
[
 0 (1)
 1 (1)
 2 (-1)      // -1 means that this **prime** number was checked (and was used to calculate its multiples)
 3 (-1)
 4 (0)      // 0 means that this **composite** number was found as a result of being a multiple of a prime number
 5 (1)
 6 (0)
 7 (1)      // 1 means that this **prime** number was not crossed off as a result of the checks made by multiples of checked primes (i.e. this number > floor(sqrt(M)) + 1
 8 (0)
 9 (0)
 10 (0)
]
```
