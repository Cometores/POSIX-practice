#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include "aio.h"
#include "wait.h"

int main(int argc, char** argv){ 
    int max_arg = 100; // NEEDS to be at least 2, or while() below could access unallocated memory
    char* token[max_arg];

    if(argc < 2){ 
        // no program to execute, abort
        exit(EXIT_FAILURE);
    }

    { // Limits visibility of i
        int i = 0;

        // argv[0] is OUR (excufoe) program's name
        token[i++] = strtok(argv[1], " "); // token[0] - program we want to execute

        if(token[0] == NULL){ 
            // argv[1] is empty string
            exit(EXIT_FAILURE);
        }

        while(token[i] = strtok(NULL, " ")){
            i++;
            if(i >= max_arg)
                exit(EXIT_FAILURE);
        }

        pid_t child;

        if(i == 1){ //i == 0 was already caught above
            child = fork();

            if(child == -1){
                exit(EXIT_FAILURE);
            }else if(child == 0){
                execlp(token[0], token[0], NULL); //don't forget to add programme name and NULL
                exit(EXIT_FAILURE); // Error handling for execlp
            }
            else{
                wait(NULL);
            }
        }
        else{
            for(int e = 1; e < i; e++){
                child = fork();

                if(child == -1){
                    exit(EXIT_FAILURE);
                }else if(child == 0){
                    execlp(token[0], token[0], token[e], NULL); 
                    exit(EXIT_FAILURE); // Error handling for execlp
                }else{
                    wait(NULL);
                }
            }
        }
    } //Limits visibility of i

    exit(EXIT_SUCCESS);
}