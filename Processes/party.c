#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Aufrufen, falls Funktion fehlerschlägt*/
static void die(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

/* Aufrufen, falls Falsche Eingaben*/
static void usage(void) {
    fprintf(stderr, "Usage: party <#parallel processes> <commandlines>\n");
    exit(EXIT_FAILURE);
}

struct process {
    pid_t pid; //PID des Prozesses
    char *cmdline; //Befehl, die Prozess ausführt
};

static pid_t run(char *cmdline);
static void waitProcess(struct process *processes, size_t size);

int main(int argc, char* argv[]){
    if(argc < 3){
        usage();
    }

    // Befehlszeilenarg. <n> mit strtol parsen
    char *rem;
    errno = 0;
    long max_proc = strtol(argv[1], &rem, 10);
    if(errno != 0){
        die("strtol");
    }
    if(*rem != '\0' || max_proc <= 0) {
        usage();
    }

    const unsigned int cmd_count = argc - 2;
    
    // Normaler Zaehler, keine SEM*
    unsigned int procs = 0;
    struct process processes[cmd_count];

    for(int i = 0; i < cmd_count; ++i) {
        // warten, falls max. Anz. Prozesse erreicht
        if(procs == max_proc) {
            waitProcess(processes, i);
            --procs;
        }

        processes[i].cmdline = argv[i + 2];
        processes[i].pid = run(argv[i + 2]);
        ++procs;
    }

    //Auf verbleibende Prozesse warten
    while(procs > 0) {
        waitProcess(processes, argc - 2);
        --procs;
    }

    return EXIT_SUCCESS;
}

static pid_t run(char *cmdline){
    pid_t pid = fork();
    if(-1 == pid){
        die("fork");
    } else if(0 == pid) {
        // Kindprozess
        // Befehlzeile parsen
        char* argv[(strlen(cmdline) + 1) / 2 + 1];

        int i = 0;
        // Aufruf mit cmdline
        argv[i] = strtok(cmdline, " \t");
        while(NULL != argv[i]) {
            ++i;
            argv[i] = strtok(NULL, " \t");
        }

        execvp(argv[0], argv);
        die("execvp");
    }
    
    return pid;
}

static void waitProcess(struct process *processes, size_t size) {
    //Auf beliebigen Prozess warten
    int wstatus;
    pid_t pid = wait(&wstatus);
    if(-1 == pid){
        die("wait");
    }

    //Befehlszeile raussuchen
    char *cmdline = "<unknown>";
    //Prüfung gegen PID
    for(int i = 0; 0 != processes[i].pid; ++i){
        if (pid == processes[i].pid) {
            cmdline = processes[i].cmdline;
        }
    }

    //Terminierungsgrund ausgeben
    //Zugriff auf WEXITSTATUS nur nach WIFEXITED
    if(WIFEXITED(wstatus)) {
        if(printf("'%s' (%d) exited with status %d\n",
        cmdline, pid, WEXITSTATUS(wstatus)) < 0) {
            die("printf");
        }
    } else {
        if(printf("'%s' (%d) exited\n", cmdline, pid) < 0) {
            die("printf");
        }
    }
}