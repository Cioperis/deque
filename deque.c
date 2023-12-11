#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deque.h"

Deque *create(){
    Deque *current;
    current = malloc(sizeof(Deque));
    current -> head = NULL;
    current -> tail = NULL;
    current -> size = 0;
    printf("Deque initialized successfully.\n");

    return current;
}

int count(Deque *current){
    return current -> size;
}

void isEmpty(Deque *current){
    if(count(current) == 0){
        printf("Deque is full.\n");
    }
    else{
        printf("Deque is empty.\n");
    }
}

void isFull(Deque *current){
    if(count(current) != 0){
        printf("Deque is full.\n");
    }
    else{
        printf("Deque is empty.\n");
    }
}

void pushFront(int x, Deque *current){
    Node *temp1;
    temp1 = malloc(sizeof(Node));
    temp1 -> data = x;
    temp1 -> next = NULL;
    temp1 -> prev = NULL;

    if(current -> size == 0){
        current -> head = temp1;
        current -> tail = temp1;
        current -> size++;
    }
    else{
        Node *temp2;
        temp2 = current -> head;
        temp1 -> next = current -> head;
        temp2 -> prev = temp1;
        current -> head = temp1;
        current -> size++;
    }

    printf("Element pushed to the head.\n");
}

void pushRear(int x, Deque *current){
    Node *temp1;
    temp1 = malloc(sizeof(Node));
    temp1 -> data = x;
    temp1 -> next = NULL;
    temp1 -> prev = NULL;

    if(current -> size == 0){
        current -> head = temp1;
        current -> tail = temp1;
        current -> size++;
    }
    else{
        Node *temp2;
        temp2 = current -> tail;
        temp2 -> next = temp1;
        temp1 -> prev = current -> tail;
        current -> tail = temp1;
        current -> size++;
    }

    printf("Element pushed to the back.\n");
}

void popFront(Deque *current){
    if(current -> size == 0){
        printf("Deque is empty.\n");
        return;
    }
    else if(current -> size == 1){
        free(current -> head);
        current -> head = NULL;
        current -> tail = NULL;
        current -> size--;
        printf("Front element removed.\n");
    }
    else{
        Node *temp = (current -> head) -> next;
        temp -> prev = NULL;
        free(current -> head);
        current -> head = temp;
        current -> size--;
        printf("Front element removed.\n");
    }
}

void popRear(Deque *current){
    if(current -> size == 0){
        printf("Deque is empty!\n");
    }
    else if(current -> size == 1){
        free(current -> head);
        current -> head = NULL;
        current -> tail = NULL;
        current -> size--;
        printf("Rear element removed.\n");
    }
    else{
        Node *temp = (current -> tail) -> prev;
        temp -> next = NULL;
        free(current -> tail);
        current -> tail = temp;
        current -> size--;
        printf("Rear element removed.\n");
    }
}

void printFront(Deque *current){
    if(current -> size == 0){
        printf("Deque is empty.\n");
    }
    else{
        printf("Deque's front element = %d.\n", current -> head -> data);
    }
}

void printRear(Deque *current){
    if(current -> size == 0){
        printf("Deque is empty!\n");
    }
    else{
        printf("Deque's rear element = %d.\n", current -> tail -> data);
    }
}

void makeEmpty(Deque *current){
    while(current -> head != NULL){
        Node *temp = current -> head;
        current -> head = temp -> next;
        free(temp);
    }
    current -> size = 0;
    free(current);
    printf("Deque voided successfully.\n");
}

Deque *clone(Deque *current){
    if(current -> size != 0){
        Deque *clonedDeque;

        clonedDeque = memcpy(clonedDeque, current, sizeof(Deque));

        Node *temp = current -> head;

        while(temp != NULL){
            Node *nodeCopy = memcpy(nodeCopy, temp, sizeof(Node));
            temp = temp -> next;
        }

        printf("Deque cloned successfully.\n");
        return clonedDeque;
    }
    else{
        printf("Deque is empty, failed to clone.\n");
    }
}