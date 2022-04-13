cmake_minimum_required(VERSION 3.21)
project(Sieve_of_Eratosthenes C)

set(CMAKE_C_STANDARD 11)

add_executable(sieve_of_eratosthenes
        sieveofe.tosborne.c)


add_executable(rudimentary
        sieveofe.rudimentary.c)
