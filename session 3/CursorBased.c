#include <stdio.h>
#define MAX 10

typedef int Type;
typedef int Position;
typedef int List;

typedef struct {
    Type elem;
    Position next;
} NodeType;

typedef struct {
    NodeType data[MAX];
    Position avail;
} VSpace;

void initHeap(VSpace *vs) {
    int i;
    for(i=MAX-1; i>=0; --i) {
        vs->data[i].elem = 0;
        vs->data[i].next = i-1;
    }
    vs->avail = MAX-1;
}

void vizualizeSpace(VSpace vs) {
    int i;
    printf("%15s | %15s | %15s\n", "INDEX", "ELEM", "NEXT");
    for(i=0; i<MAX; i++) {
        printf("%15d | %15d | %15d\n", i, vs.data[i].elem, vs.data[i].next);
    }
    printf("Available: %d\n", vs.avail);
}

void displayList(VSpace vs, List list) {
    int i;
    printf("{");
    for(i=list; i != -1; i = vs.data[i].next) {
        printf("%d ", vs.data[i].elem);
    }
    printf("}\n");
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
        vs->data[index].elem = 0;
        vs->data[index].next = vs->avail;
        vs->avail = index;
    }
}

void insertFront(VSpace *vs, List *list, Type item) {
    Position temp = allocSpace(vs);

    if(temp != -1) {
        vs->data[temp].elem = item;
        vs->data[temp].next = *list;
        *list = temp;
    }
}

void deleteFront(VSpace *vs, List *list) {
    Position temp = *list;

    if(*list != -1) {
        *list = vs->data[*list].next;
        freeSpace(vs, temp);
    }
}


int main() {
    List listA = -1;
    List listB = -1;
    VSpace mySpace;

    initHeap(&mySpace);
    vizualizeSpace(mySpace);
    displayList(mySpace, listA);
    displayList(mySpace, listB);
    insertFront(&mySpace, &listA, 1);
    insertFront(&mySpace, &listB, 100);
    insertFront(&mySpace, &listB, 200);
    insertFront(&mySpace, &listA, 2);
    insertFront(&mySpace, &listB, 300);
    insertFront(&mySpace, &listA, 3);
    vizualizeSpace(mySpace);
    displayList(mySpace, listA);
    displayList(mySpace, listB);
    deleteFront(&mySpace, &listB);
    vizualizeSpace(mySpace);
    displayList(mySpace, listA);
    displayList(mySpace, listB);
    

    return 0;
}