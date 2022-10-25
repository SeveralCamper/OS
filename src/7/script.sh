gcc -c main.c
gcc main.o -L. -llist_functions -o main
./main liblist_functions.so