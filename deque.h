#ifndef DEQUE_H
#define DEQUE_H

typedef struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct Deque{
    int size;
    struct Node *head;
    struct Node *tail; 
} Deque;

Deque *create();
int count(Deque *current);
void isEmpty(Deque *current);
void isFull(Deque *current);
void pushFront(int x, Deque *current);
void pushRear(int x, Deque *current);
void popFront(Deque *current);
void popRear(Deque *current);
void printFront(Deque *current);
void printRear(Deque *current);
void makeEmpty(Deque *current);
Deque *clone(Deque *current);

#endif