CC = gcc -std=c11
CFLAGS = -Wall -Werror -Wextra
LIBS = -lcheck -lsubunit -lrt -lpthread -lm
TARGET = ../../bin/doubly_linked_lists

all: list_lib.a

$(TARGET): ../../obj/doubly_linked_lists.o
	$(CC) $(CFLAGS) ../../obj/doubly_linked_lists.o -o $@

../../obj/doubly_linked_lists.o: doubly_linked_lists.c
	$(CC) $(CFLAGS) -fPIC -c doubly_linked_lists.c -o $@

../../obj/main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o $@

list_lib.a: ../../obj/doubly_linked_lists.o ../../obj/main.o
	$(CC) $(CFLAGS) -shared ../../obj/*.o -o liblist_functions.so
	$(CC) $(CFLAGS) ../../obj/*.o -L. -llist_functions -o main
	ar rcs $@ $^
	ranlib $@
	rm ../../obj/main.o
	rm ../../obj/doubly_linked_lists.o

clean:	
	rm -rf $(TARGET) file.bin
	rm -rf *.o *.so *.a fizz *.gc* *.info report *.out *.gcda *.so *.gcno *.info main
	rm -rf ../../obj/*.o ../../obj/*.so ../../obj/*.a ../../obj/*.out

rebuild: clean all

.PHONY: all clean test rebild doubly_linked_lists.a

