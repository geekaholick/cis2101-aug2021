#ifndef STACKCURSORBASED_H
#define STACKCURSORBASED_H
#define MAX 100

#include "Person.h"

typedef Person Type;
typedef int Position;
typedef int StackList;

typedef struct {
    Person elem;
    Position next;
} CNode;

typedef struct {
    CNode data[MAX];
    Position avail;
} VSpace;


// initVSpace()
// allocSpace()
// freeSpace()
// push()
// pop()
// peek()

/************************************************************************************************
 * Create a function that would insert a new person based on the order of the city in ASC order. 
 * Top must always have the smallest value.
 * Utilize the functions push, pop, and peek.
 * HINT: You could use also another stack/temporary stack.
 * **********************************************************************************************/

/************************************************************************************************
 * Create a function that would extract (remove from the original list) the person living from a
 * specified city.
 * Utilize the concept of stack but will not use the functions push, pop, and peek.
 * HINT: You could use also another stack/temporary stack.
 * **********************************************************************************************/

// visualization
// display

#endif
