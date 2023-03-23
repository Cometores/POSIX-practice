#include "stdio.h"
#include "stdlib.h"
#include "errno.h"
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

static void die(const char *msg) {
	perror(msg);
	exit(EXIT_FAILURE);
}

int main(int argc, char const *argv[]) {
	/* aktuelles verzeichnis oeffnen */
	DIR *dirp = opendir(".");
	if (dirp == NULL)
		die("opendir");

	errno = 0;
	struct dirent *entry = NULL;
	struct stat buf;

	while(1) {
		entry = readdir(dirp);
		if (entry == NULL)
			break;

		if (lstat(entry->d_name, &buf) != 0 ) {
			perror("lstat");
			continue;
		}

		if (S_ISLNK(buf.st_mode)) 
			fprintf(stdout, "%s\n", entry->d_name);
	}
	if (errno != 0) 
		die("readdir");

	if (closedir(dirp) != 0)
		die("closedir");

	return EXIT_SUCCESS;
}
