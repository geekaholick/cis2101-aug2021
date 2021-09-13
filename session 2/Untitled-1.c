#include <stdio.h>
#include <stdlib.h>

typedef int Type;

typedef struct node {
    Type data;
    struct node *next;
} NodeType, *NodePtr;

//void insertFront(NodeType **list, Type item);
void insertFront(NodePtr *list, Type item);
NodePtr insertFront2(NodePtr list, Type item);
void insertRear(NodePtr *list, Type item);
void insertRear2(NodePtr *list, Type item);
void deleteItem(NodePtr *list, Type item);
void deleteFront(NodePtr *list);
void deleteRear(NodePtr *list);
void display(NodePtr list);

int main() {
    NodePtr myList = NULL;

    display(myList);
    insertFront(&myList, 10);
    display(myList);
    insertFront(&myList, 5);
    display(myList);
    myList = insertFront2(myList, 6);
    display(myList);

    return 0;
}

void insertFront(NodePtr *list, Type item) {
    NodePtr temp = (NodePtr) malloc(sizeof(NodeType));

    if(temp != NULL) {
        temp->next = *list;
        *list = temp;
        temp->data = item;
    }
}

NodePtr insertFront2(NodePtr list, Type item) {
    NodePtr temp = (NodePtr) malloc(sizeof(NodeType));

    if(temp != NULL) {
        temp->next = list;
        temp->data = item;
    }

    return temp;
}
//pointer to a pointer to a node
void insertRear(NodePtr *list, Type item) {
    NodePtr *current;
    NodePtr temp = (NodePtr) malloc(sizeof(NodeType));

    if(temp != NULL) {
        for(current = list; *current != NULL; current = &(*current)->next) {}
        temp->next = NULL;
        *current = temp;
        temp->data = item;
    }
}
//pointer to a node
void insertRear2(NodePtr *list, Type item) {
    NodePtr current;
    NodePtr temp = (NodePtr) malloc(sizeof(NodeType));

    if(temp != NULL) {
        for(current = *list; current != NULL && current->next != NULL; current = current->next) {}
        temp->next = NULL;
        temp->data = item;
        if(current == NULL) {
            *list = temp;
        } else {
            current->next = temp;
        }
    }
}

void deleteItem(NodePtr *list, Type item) {
    NodePtr *current, temp;

    if(*list != NULL) {
        for(current = list; *current != NULL && (*current)->data != item; current = &(*current)->next) {}
        if(*current != NULL) {
            temp = *current;
            *current = temp->next; // *current = (*current)->next
            free(temp);
        }
    }  
}

void display(NodePtr list) {
    printf("[");

    for(;list != NULL; list = list->next) {
        printf("%d", list->data);
        if(list->next != NULL) {
            printf(" -> ");
        }
    }

    printf("]\n");
}