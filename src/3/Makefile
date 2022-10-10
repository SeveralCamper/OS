CC = gcc -std=c11
CFLAGS = -Wall -Wextra
LIBS = -lcheck -lsubunit -lrt -lpthread -lm
TARGET = ../../bin/systype

all: $(TARGET) run

$(TARGET): ../../obj/systype.o
	$(CC) $(CFLAGS) ../../obj/systype.o -o $@

../../obj/systype.o: systype.c
	$(CC) $(CFLAGS) -c systype.c -o $@

run:
	./$(TARGET)

clean:	
	rm -rf $(TARGET) test.dat
	rm -rf *.o *.so *.a fizz *.gc* *.info report *.out *.gcda *.so *.gcno *.info
	rm -rf ../../obj/*.o ../../obj/*.so ../../obj/*.a ../../obj/*.out

rebuild: clean all

.PHONY: all clean test rebild systype.a