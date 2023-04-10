#include "errno.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "sys/types.h"
#include "sys/wait.h"
#include "unistd.h"
#include "stdbool.h"

#include "plist.h"

#define MAX_LINE 1337

static void die(const char *s) {
    perror(s);
    exit(EXIT_FAILURE);
}

static void print_prompt(void) {
    size_t len = 4096;
    char *cwd = NULL;

    while (1) {
        cwd = realloc(cwd, len);
        if (cwd == NULL)
            die("realloc");

        // GETCWD: determines the path name of the working directory
        // char *getcwd(char *buffer, size_t size);
        // Returned value:
        // - if successful - returns a pointer to the buffer
        // - if unsuccesful - returns a NULL and sets errno
        // - - ERANGE - size is greater than 0, but less than the length of the working directory's path name,
        //     plus 1 for the terminating NULL.
        if (getcwd(cwd, len) != NULL)
            break;

        if (errno != ERANGE)
            die("getcwd");

        len *= 2;
    }

    printf("%s: ", cwd);
    fflush(stdout);
    free(cwd);
}

static void print_exitstatus(char *buf, int status) {
    if (WIFEXITED(status)){
        printf("Exitstatus [%s] = %d\n", buf, WEXITSTATUS(status));
    } else {
        printf("No exitstatus [%s]\n", buf); 
    }
}

static int print_job(pid_t pid, const char *buf) {
    printf("%d %s\n", (int)pid, buf);
    return 0;
}

static void collect_zombies(void) {
    pid_t pid;
    int status;
    
    while ((pid = waitpid(-1, &status, WNOHANG)) != 0) {
        if (pid < 0) {
            if (errno == ECHILD) {
                // ECHILD - ich habe kein Kind ???
                break;
            }
            die("waitpid");
        }

        char buf[MAX_LINE + 1];
        if (removeElement(pid, buf, sizeof(buf)) < 0)
            continue;
            
        print_exitstatus(buf, status);
    }
}

int main(void) {
    while (1) {
        collect_zombies();
        print_prompt();

        // Read input line
        char buf[MAX_LINE + 1 /* " \0 " */];

        if (fgets(buf, sizeof(buf), stdin) == NULL) {
            if (feof(stdin))
                break;
            die("fgets");
        }

        // Discard overlong lines
        if (strlen(buf) == MAX_LINE && buf[MAX_LINE - 1] != '\n') {
            fprintf(stderr, "Input line too long\n");

            int c;
            do {
                c = fgetc(stdin);
            } while (c != EOF && c != '\n');
            continue;
        }

        // Skip empty lines
        if (strlen(buf) < 2) 
            continue;

        buf[strlen(buf) - 1] = '\0';

        bool background = false;
        if (buf[strlen(buf) - 1] == '&') {
            buf[strlen(buf) - 1] == '\0';
            background = true;
        }

        char cpy[sizeof(buf)];
        strcpy(cpy, buf);

        // Tokenize arguments
        int i = 0;
        char *argv[MAX_LINE / 2 + 1 + 1 /* NULL */];

        argv[i++] = strtok(buf, "\t");
        while ((argv[i++] = strtok(NULL, " \t")) != NULL)
            continue;

        if (argv[0] == NULL)
            continue;

        // cd
        if (!strcmp(argv[0], "cd")){
            if (argv[1] == NULL || argv[2] != NULL) {
                fprintf(stderr, "usage: cd <directory>\n"); // optional
            } else if (chdir(argv[1])) {
                perror("chdir");
            }
            continue;
        }

        // jobs
        if (!strcmp(argv[0], "jobs")) {
            if (argv[1] != NULL) {
                fprintf(stderr, "usage: jobs\n"); // optional
            } else {
                walkList(print_job);
            }
            continue;
        }

        pid_t pid = fork();
        if (pid < 0) {
            die("fork"); // a proper shell would use perror+continue
        } else if (pid == 0) {
            execvp(argv[0], argv);
            die("exec");
        }

        if (background) {
            if (-2 == insertElement(pid, cpy)) {
                // insertElement does not set errno (according to plist.h)
                fprintf(stderr, "out of memory");
                exit(EXIT_FAILURE);
            }
        } else {
            int status;
            if (waitpid(pid, &status, 0) < 0) {
                die("waitpid");
            }
            print_exitstatus(cpy, status);
        }
    }
}
