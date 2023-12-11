#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include "deque.h"

int main(){
    Deque *test = create();

    pushFront(10, test);
    printFront(test);
    isEmpty(test);
    popFront(test);
    isEmpty(test);
    pushRear(240, test);
    printRear(test);
    popRear(test);
    printFront(test);
    pushRear(324, test);
    pushRear(326, test);
    pushFront(123, test);
    pushRear(3223, test);
    pushFront(45, test);
    popRear(test);
    printRear(test);

    return 0;
}
