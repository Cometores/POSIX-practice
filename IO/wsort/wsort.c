#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"

#define WORD_LEN 100
#define LINE_LEN (WORD_LEN+2) // for '\n' and '\0'

static int compare(const void* x, const void* y){
    return strcmp(*(char * const *)x, *(char * const *)y);
}

int main(int argc, char const *argv[])
{
    unsigned word_count = 0;
    unsigned word_arr_size = 100;

    char** word_arr = calloc(word_arr_size, sizeof(char*));
    if(!word_arr)
        exit(EXIT_FAILURE);

    char buffer[LINE_LEN];

    while(fgets(buffer, LINE_LEN, stdin)){
        size_t curr_word_len = strlen(buffer); // number of characters without '\0'

        if(curr_word_len == 101 && buffer[100] != '\n'){
            // Usage error handling. Skipping the line
            fprintf(stderr, "Wort zu lang... Ignorieren.");
            fflush(stderr); 

            // Read the line to the end
            int c;
            do{
                c = getchar();
            } while(c != EOF && c != '\n');

            continue;
        }

        if(buffer[curr_word_len-1] == '\n'){
            buffer[curr_word_len-1] = '\0';
            curr_word_len--;
        }

        // If the line was "\n," we skip it
        if(curr_word_len < 1)
            continue;
        
        char* word = strdup(buffer);
        if(!word)
            exit(EXIT_FAILURE);

        if(word_arr_size <= word_count){
            word_arr_size += 100;
            word_arr = realloc(word_arr, word_arr_size * sizeof(*word_arr));
            if(!word_arr){
                perror(NULL);
                exit(EXIT_FAILURE);
            }
        }

        word_arr[word_count] = word;
        word_count++; 
    }
    if(ferror(stdin)){
        // Error handling for fgets in while loop
        exit(EXIT_FAILURE);
    }

    qsort(word_arr, word_count, sizeof(*word_arr), compare);

    // Writing sorted words into stdout
    for(int i = 0; i < word_count; i++){
        if(puts(word_arr[i]) == EOF){
            perror(NULL);
            exit(EXIT_FAILURE);
        }
        free(word_arr[i]);
    }

    free(word_arr);

    if(fflush(stdout)){
        perror(NULL);
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}
