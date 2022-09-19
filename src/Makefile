CC = gcc -std=c11
CFLAGS = 
LIBS = -lcheck -lsubunit -lrt -lpthread -lm
TARGET = ../bin/doubly_linked_lists

all: $(TARGET) run

$(TARGET): ../obj/doubly_linked_lists.o
	$(CC) $(CFLAGS) ../obj/doubly_linked_lists.o -o $@

../obj/doubly_linked_lists.o: doubly_linked_lists.c
	$(CC) $(CFLAGS) -c doubly_linked_lists.c -o $@

run:
	./$(TARGET)

clean:	
	rm -rf $(TARGET)
	rm -rf *.o *.so *.a fizz *.gc* *.info report *.out *.gcda *.so *.gcno *.info
	rm -rf ../obj/*.o ../obj/*.so ../obj/*.a ../obj/fizz ../obj/*.gc* ../obj/*.info ../obj/report ../obj/*.out ../obj/*.gcda ../obj/*.so ../obj/*.gcno ../obj/*.info

rebuild: clean all

.PHONY: all clean test rebild doubly_linked_lists.a

