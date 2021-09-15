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

void initVSpace(VSpace *vs);
Position allocSpace(VSpace *vs);
void freeSpace(VSpace *vs, Position index);
void push(VSpace *vs, StackList *stack, Person p);
void pop(VSpace *vs, StackList *stack);
Person peek(VSpace vs, StackList stack);

void insertSortedByCity(VSpace *vs, StackList *list, Person p);
/************************************************************************************************
 * Create a function that would insert a new person based on the order of the city in ASC order. 
 * Top must always have the smallest value.
 * Utilize the functions push, pop, and peek.
 * HINT: You could use also another stack/temporary stack.
 * **********************************************************************************************/

StackList extractPersonByCity(VSpace *vs, StackList *list, String city);
/************************************************************************************************
     * Create a function that would extract (remove from the original list) the person living from a
     * specified city.
     * Utilize the concept of stack but will not use the functions push, pop, and peek.
     * HINT: You could use also another stack/temporary stack.
 * **********************************************************************************************/

// visualization
// display

#endif
