CC = gcc
CFLAGS = -I.

DEPS = CHLinkedList.h
OBJ = CHLinkedList.o CHLinkedListAppendTests.o AllTests.o CuTest.o CuTestTest.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

listTests: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *.o *~