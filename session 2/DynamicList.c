#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int Boolean;

typedef struct {
    int *items;
    int count;
    int max;
} List;

List createList(int max);
void initList(List *list);              //version 4
void insertFront(List *list, int item);
void insertRear(List *list, int item);
Boolean deleteItem(List *list, int item);
Boolean deleteFront(List *list);
Boolean deleteRear(List *list);
void display(List list);

int main() {
    List myList = createList(3);

    display(myList);
    insertFront(&myList, 5);
    display(myList);
    insertFront(&myList, 3);
    display(myList);
    insertFront(&myList, 2);
    display(myList);
    insertRear(&myList, -7);
    display(myList);
    insertFront(&myList, 10);
    display(myList);

    return 0;
}

List createList(int max) {
    List list;

    list.max = max;
    list.count = 0;
    list.items = (int *) malloc(sizeof(int)*max);

    return list;
}

void initList(List *list) {
    list = (List *) malloc(sizeof(List));

    list->count = 0;
    list->max = 4;
    list->items = (int *) malloc(sizeof(int)*list->max);
}

void insertFront(List *list, int item) {
    int i;
    if(list->count >= list->max) {
        list->max *= 2;
        list->items = realloc(list->items, list->max);
    }

    for(i = list->count; i > 0; --i) {
        list->items[i] = list->items[i-1];
    }
    list->items[i] = item;
    list->count++;
}

void insertRear(List *list, int item) {
    if(list->count >= list->max) {
        list->max *= 2;
        list->items = realloc(list->items, list->max);
    }

    list->items[list->count++] = item;
}

Boolean deleteItem(List *list, int item) {
    int i, pos;

    for(i=0; i<list->count; ++i) {
        if(list->items[i] == item) {
            pos=i;
            break;
        }
    }

    if(i<list->count) {
        for(i=pos; i<list->count-1; ++i) {
            list->items[i] = list->items[i+1];
        }
        list->count--;
        return TRUE;
    } else {
        return FALSE;
    }
    
}
Boolean deleteFront(List *list) {
    int i;
    if(list->count <= 0) {
        return FALSE;
    } else {
        for(i=0; i<list->count-1; ++i) {
            list->items[i] = list->items[i+1];
        }
        list->count--;
        return TRUE;
    }
}

Boolean deleteRear(List *list) {
    if(list->count <= 0) {
        return FALSE;
    } else {
        list->count--;
        return TRUE;
    }
}

void display(List list) {
    int i;
    printf("{");
    for(i=0; i<list.count; ++i) {
        printf("%d", list.items[i]);
        if(list.count-1 > i) {
            printf(", ");
        }
    }
    printf("} Count: %d; Max: %d\n", list.count, list.max);
}
