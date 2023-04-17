#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

static bool isDebug = false;

static int cmp(const void *a, const void *b) {
	const int *x = a;
	const int *y = b;

	if (*x < *y) {
		return -1;
	} else if (*x == *y) {
		return 0;
	} else {
		return +1;
	}
}

int main(void) {
	const int len = 10;
	int array[len];

	srand(4711); //Initialize RNG 
	for(int i = 0; i < len; i++) {
		array[i] = rand() % 42;

		/*
		 * Debug output, thus no basic functionality and therefore does 
		 * not require error handling
		 */
		if (isDebug)
			fprintf(stderr, "%d\n", array[i]);
	}
	if(isDebug)
		fprintf(stderr, "\n");


	// qsort:
	//    Length of the individual list elements
	//    Array            \             Comparison function
	//      |               \           /
	//    vvvvv       vvvvvvvvvvvvvv  vvv
	qsort(array, len, sizeof(*array), cmp);
	//           ^^^
	//           Number of elements in the array


	for(int i = 0; i < len; i++) {
		if (printf("%d\n", array[i]) < 0) {
			perror("printf");
			exit(EXIT_FAILURE);
		}
	}
	if (fflush(stdout) != 0) {
		perror("fflush");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
