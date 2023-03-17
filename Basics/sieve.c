#include "stdio.h"
#include "stdbool.h"
#include "stdlib.h"

int main(int argc, char** argv){
    const int MAX = 100;
    if(MAX <= 1){
        printf("No primes.");
        return EXIT_FAILURE;
    }
    bool arr[MAX + 1];

    // Initializing array with start values
    arr[0] = false;
    arr[1] = false;
    for (int i = 2; i <= MAX; i++)
        arr[i] = true;
    
    // Computing prime numbers
    for (int i = 2; i * i <= MAX; i++){
        if(arr[i]){
            for(int e = 2 * i; e <= MAX; e += i)
                arr[e] = false;
        }
    }

    // Output
    for (int i = 2; i <= MAX; i++){
        if(arr[i])
            printf("%d\n", i);
    }

    exit(EXIT_SUCCESS);
}