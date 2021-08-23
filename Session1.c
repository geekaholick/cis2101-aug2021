#include <stdio.h>
#include <stdlib.h>
#define MAX 5

//version 1 and 2
typedef struct {
    int items[MAX];
    int count;
} AList;

//version 3 and 4
typedef struct {
    int *items;
    int count;
    int max;
} AListDynamic;

void insert1(AList *list, int item);
AList insert2(AList list, int item);
void display(AList list);

int main() {
    AList mylist;

    mylist.count = 0;

    display(mylist);
    insert1(&mylist, 2);
    display(mylist);
    mylist = insert2(mylist, 10);
    display(mylist);
    
    return 0; 
}  

void insert1(AList *list, int item) {
    if(MAX>list->count) {
        list->items[list->count++] = item;
    }
}

AList insert2(AList list, int item) {
    if(MAX>list.count) {
        list.items[list.count++] = item;
    }
    
    return list;
} 

void display(AList list) {
    int i;
    printf("{");
    for(i=0; i<list.count; ++i) {
        printf("%d", list.items[i]);
        if(i < list.count-1) {
            printf(", ");
        }
    }
    printf("}\n");
}
