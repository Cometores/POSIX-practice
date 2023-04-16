#include <stdlib.h>
#include <stdio.h>

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

	srand(4711); /* RNG initialisieren */
	for(int i = 0; i < len; i++) {
		array[i] = rand() % 42;

		/*
		 * Debug-Ausgabe, damit keine Grundfunktionalität und benötigt
		 * somit keine Fehlerbehandlung
		 */
		fprintf(stderr, "%d\n", array[i]);
	}
	fprintf(stderr, "\n");

	// qsort:
	//    Länge der einzelnen Listenelemente
	//  das Array          \             Vergleichsfunktion
	//      |               \           /
	//    vvvvv       vvvvvvvvvvvvvv  vvv
	qsort(array, len, sizeof(*array), cmp);
	//           ^^^
	//           Anzahl der Elemente im Array

	for(int i = 0; i < len; i++) {
		if (printf("%d\n", array[i]) < 0) {
			/*
			 * Grundfunktionalität, Fehlerbehandlung notwendig!
			 */
			perror("printf");
			exit(EXIT_FAILURE);
		}
	}

	/*
	 * Wichtig da sonst eine volle Platte nicht erkannt wird, da die libc
	 * erst beim beenden wirklich nach stdout schreibt.
	 */
	if (fflush(stdout) != 0) {
		perror("fflush");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
