#include "stdio.h"
#include "stdbool.h"
#include "stdlib.h"

int main(int argc, char** argv){
    const int max = 100;
    if(max <= 1){
        printf("No primes.");
        return EXIT_FAILURE;
    }
    bool arr[max + 1];

    // Initializing array with start values
    arr[0] = false;
    arr[1] = false;
    for (int i = 2; i <= max; i++)
        arr[i] = true;
    
    // Computing prime numbers
    for (int i = 2; i * i <= max; i++){
        if(arr[i]){
            for(int e = 2 * i; e <= max; e += i)
                arr[e] = false;
        }
    }

    // Output
    for (int i = 2; i <= max; i++){
        if(arr[i])
            printf("%d\n", i);
    }

    exit(EXIT_SUCCESS);
}