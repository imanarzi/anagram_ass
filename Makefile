CC = gcc
CFLAGS = -Wall -std=c99

all: test_dictionary anagram

dictionary.o: dictionary.c dictionary.h 
	$(CC) $(CFLAGS) -c dictionary.c

test_dictionary.o: test_dictionary.c dictionary.o dictionary.h
	$(CC) $(CFLAGS) -c test_dictionary.c
	
test_dictionary: test_dictionary.o 
	$(CC) $(CFLAGS) -o test_dictionary dictionary.o test_dictionary.o 

anagram.o: anagram.c dictionary.o dictionary.h
	$(CC) $(CFLAGS) -c anagram.c

anagram: anagram.o
	$(CC) $(CFLAGS) -o anagram anagram.o dictionary.o

clean:
	rm *.o test_dictionary anagram
