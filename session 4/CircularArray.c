#include <stdio.h>
#define MAX 10

typedef int Type;

typedef struct {
    Type data[MAX];
    int front;
    int rear;
} CircularArrayQueue, List;

List createQueue();
int isEmpty(List list);
int isFull(List list);

void enqueue(List *list, Type item);
void dequeue(List *list); 

//optional
void visualizeQueue(List list);
void displayList(List list);

int main() {
    List myList = createQueue();

    visualizeQueue(myList);
    displayList(myList);
    enqueue(&myList, 10);
    enqueue(&myList, 7);
    enqueue(&myList, 8);
    visualizeQueue(myList);
    displayList(myList);
    dequeue(&myList);
    visualizeQueue(myList);
    displayList(myList);

    return 0;
}

List createQueue() {
    List caq;
    int i;
    
    for(i=0; i<MAX; ++i) {
        caq.data[i] = 0;
    }

    caq.front = 0;      // 6
    caq.rear = MAX-1;   // 5

    return caq;
}

void visualizeQueue(List list) {
    int i;
    for(i=0; i<MAX; ++i) {
        printf("%5d", list.data[i]);
    }
    printf("\n");
    for(i=0; i<MAX; ++i) {
        printf("%5d", i);
    }
    printf("\n");
    printf("Front: %d\nRear: %d\n", list.front, list.rear);
}

void displayList(List list) {
    printf("{");
    for( ; list.front != (list.rear + 1)%MAX; list.front = (list.front + 1) % MAX) {
        printf("%d ", list.data[list.front]);
    }
    printf("}\n");
}

int isEmpty(List list) {
    return (list.rear+1)%MAX == list.front;
}

int isFull(List list) {
    return (list.rear+2)%MAX == list.front;
}

void enqueue(List *list, Type item) {
    if(!isFull(*list)) {                        // if(isFull(*list) != 1)
        list->rear = (list->rear + 1) % MAX;
        list->data[list->rear] = item;
    }
}

void dequeue(List *list) {
    if(!isEmpty(*list)) {
        list->front = (list->front + 1) % MAX;
    }
}