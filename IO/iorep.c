#include "stdio.h" 
#include "errno.h"
#include "stdlib.h" 

/* Use Ctrl + D for EOF*/

int main(int argc, char** argv){
    char read_buffer[16];

    while(1){
        fgets(read_buffer, 16, stdin);
        if(feof(stdin)){
            fputs("fgets(read_buffer, 16, stdin) (io.c: 8) read EOF.\n", stderr);
            fflush(stderr);
            return EXIT_FAILURE;
        }
        if(ferror(stdin)){
            perror("Happened in fgets(read_buffer, 16, stdin) (io.c: 8)");
            fflush(stderr);
            return EXIT_FAILURE;
        }

        fprintf(stdout, "Read: %s\n", read_buffer);
        fflush(stdout);
        if(ferror(stdout)){
            perror("");
            fflush(stderr);
            clearerr(stdout);
        }
    }
}
