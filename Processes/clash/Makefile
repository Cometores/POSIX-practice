CFLAGS=-Wall -std=c11 -pedantic -D_XOPEN_SOURCE=700
CC=gcc

clash_my: clash_my.o plist_my.o 
	$(CC) -o prog clash_my.o plist_my.o 

plist_my.o: plist.c plist.h 
	$(CC) $(CFLAGS) -c plist.c 

main.o: clash.c plist.h 
	$(CC) $(CFLAGS) -c clash.c