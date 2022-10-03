CC = gcc -std=c17
CFLAGS = -Wall -Werror -Wextra
LIBS = -lcheck -lsubunit -lrt -lpthread -pthread -lm
TARGET = ../../bin/systype

all: $(TARGET) run

$(TARGET): ../../obj/systype.o
	$(CC) $(CFLAGS) $(LIBS) ../../obj/systype.o -o $@

../../obj/systype.o: systype.c
	$(CC) $(CFLAGS) $(LIBS) -c systype.c -o $@

run:
	./$(TARGET)

clean:	
	rm -rf $(TARGET) test.dat
	rm -rf *.o *.so *.a fizz *.gc* *.info report *.out *.gcda *.so *.gcno *.info
	rm -rf ../../obj/*.o ../../obj/*.so ../../obj/*.a ../../obj/*.out

rebuild: clean all

.PHONY: all clean test rebild systype.a