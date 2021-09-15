#include <stdio.h>
#include <string.h>
#include "StackCursorBased.h"

void initVSpace(VSpace *vs) {
    int i;
    for(i=MAX-1; i>=0; --i) {
        vs->data[i].next = i-1;
    }
    vs->avail = MAX-1;
}

Position allocSpace(VSpace *vs) {
    Position avail = vs->avail;

    if(avail != -1) {
        vs->avail = vs->data[avail].next;
    }

    return avail;
}

void freeSpace(VSpace *vs, Position index) {
    if(index != -1 && index < MAX) {
        vs->data[index].next = vs->avail;
        vs->avail = index;
    }
}

void push(VSpace *vs, StackList *stack, Person p) {
   Position temp = allocSpace(vs);

   if(temp != -1) {
       vs->data[temp].elem = p;
       vs->data[temp].next = *stack;
       *stack = temp;
   }
}

void pop(VSpace *vs, StackList *stack) {
    Position temp;
    if(*stack != -1) {
        temp = *stack;
        *stack = vs->data[temp].next;
        freeSpace(vs, temp);
    }
}

Person peek(VSpace vs, StackList stack) {
    return vs.data[stack].elem;
}

void insertSortedByCity(VSpace *vs, StackList *list, Person p) {
    Position temp = allocSpace(vs);
    StackList tempStack = -1;
    Person currentPerson;

    if(temp != -1) {
        while(*list != -1) {
            currentPerson = peek(*vs, *list);
            if(strcmp(currentPerson.city, p.city) < 0) {
                push(vs, &tempStack, currentPerson);
                pop(vs, list);
            } else {
                break;
            }
        }
        push(vs, list, p);
        while(tempStack != -1) {
            push(vs, list, peek(*vs, tempStack));
            pop(vs, &tempStack);
        }
    }
}

StackList extractPersonByCity(VSpace *vs, StackList *list, String city) {
    StackList extractedPersons = -1;
    StackList tempStack = -1;
    Person currentPerson;
    Position tempP;

    while(*list != -1) {
        currentPerson = vs->data[*list].elem;
        //separting the content of the list to either the extracted or the temp
        if(strcmp(currentPerson.city, city) == 0) {
            tempP = vs->data[*list].next;
            vs->data[*list].next = extractedPersons;
            *list = tempP;
            extractedPersons = *list;
        } else {
            tempP = vs->data[*list].next;
            vs->data[*list].next = tempStack;
            *list = tempStack;
            tempStack = tempP;
        }  
    }

    //returning all from temp to list
    while(tempStack != -1) {
        tempP = vs->data[tempStack].next;
        vs->data[tempStack].next = *list;
        *list = tempStack;
        tempStack = tempP;
    }

    return extractedPersons;    
}

// list ("Maria - Cebu", "Kirk - Danao", "Robine - Balamban", "Van - Cebu", "Joana - Carcar")
// list ("Kirk - Danao", "Robine - Balamban", "Joana - Carcar")
// extracted ("Maria - Cebu",  "Van - Cebu")