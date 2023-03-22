#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <limits.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define CMD_MAX 100

static void die(const char *msg) {
perror(msg);
exit(EXIT_FAILURE);
}

static void usage(void) {
fprintf(stderr, "Usage: hupsi <n>\n");
exit(EXIT_FAILURE);
}

struct process {
    pid_t pid;
    struct process *next;
    time_t start_time;
    char *command;
};

static pid_t run(char* cmdline);
static void waitProcess(void);
static struct process *head;

int main(int argc, char* argv[]){
    if(argc != 2){
        usage();
    }

    char *end;
    errno = 0;
    long max_proc = strtol(argv[1], &end, 10);
    if(errno != 0)
        die("strtol");
    if(*end !='\0' || max_proc <= 0)
        usage();
    
    int procs = 0;
    char buf[CMD_MAX + 2]; //'\0' und '\n'

    while(fgets(buf, CMD_MAX + 2, stdin)){
        //Auf max n Prozesse prüfen
        while(procs > max_proc){
            waitProcess();
            procs--;
        }

        struct process* proc = calloc(1, sizeof(struct process));
        if(!proc)
            die("calloc");
        
        proc->command = strdup(buf);
        if(!proc->command)
            die("strdup");

        proc->pid = run(buf);
        proc->start_time = time(NULL); 
        proc->next = head;
        
        head = proc;
        procs++;
    }
    if(ferror(stdin))
        die("fgets");

    while(procs > 0){
        waitProcess;
        procs--;
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
        die("execlp");
    }
    
    return pid;
}

static void waitProcess() {
    //Auf beliebigen Prozess warten
    int wstatus;
    pid_t pid = wait(&wstatus);
    if(-1 == pid)
        die("wait");

    //Befehlszeile raussuchen
    char *cmdline = "<unknown>";
    //Prüfung gegen PID
    while(head != NULL){
        if(head->pid == pid){
            cmdline = head->command;
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
