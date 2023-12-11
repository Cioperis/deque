test.exe : test.c deque.h deque.o
	gcc -std=c99 -o test.exe test.c deque.o

deque.o : deque.c deque.h
	gcc -c -std=c99 deque.c