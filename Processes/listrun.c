#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include "aio.h"
#include "wait.h"
#include <sys/wait.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
    if (argc < 3) {
        // Too few arguments
        return EXIT_FAILURE;
    }

    /*
	* in argv is:
    * [0] = the name of this program
    * [1] = the name of the program we want to run
    * [2..argc-1] = an argument to pass to the program
	*/

    // For each argument, run the given program once and give it the argument
    for (int i = 2; i < argc; i++) {
        // new process with fork
        pid_t pid = fork();

        if (pid == -1) {
            // 💥 fork went wrong
            perror("fork");
            return EXIT_FAILURE;
        } else if (pid == 0) {
            // we are in the child process - now run the specified program

            // With execlp the current program is exchanged 
			// with the new one in the same process:
            execlp(argv[1], argv[1], argv[i], NULL);

            // 💥 if our program is still running here execlp has failed
            perror("execlp");
            return EXIT_FAILURE;
        } else {
            // we are in the parenting process - wait for the child process and continue after that

            int status; // Variable zum Speichern des Exitstatuses

            // wait with waitpid for the termination of the child process
            if (waitpid(pid, &status, 0) == -1) {
                // 💥 waitpid failed
                perror("waitpid");
                return EXIT_FAILURE;
            }

            // // This is how the exit status could be output:
            // if (WIFEXITED(status)) { // when the process has ended normally,
            //     // the actual exit status can be determined with WEXITSTATUS:
            //     printf("Exitstatus: %d\n", WEXITSTATUS(status));
            // }
        }
    }

    return EXIT_SUCCESS;
}
