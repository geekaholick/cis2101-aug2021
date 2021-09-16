#ifndef PERSON_H
#define PERSON_H

#define MAX_LIST 20
#define MAX_VSPACE 30

typedef char String[30];

typedef struct {
    String name;
    char sex;
    String city;
} Person;

typedef struct {
    Person data[MAX_LIST];
    int count;
} PersonStaticArrayList;

typedef struct {
    Person *data;
    int count;
    int max;
} PersonDynamicArrayList, *PersonDynamicArrayListPointer;

typedef struct node{
    Person elem;
    struct node *next;
} PersonNode, *PersonLinkedList;

typedef int Position;
typedef int PersonCusorBasedList;

typedef struct {
    Person elem;
    Position next;
} CNode;

typedef struct {
    CNode data[MAX_VSPACE];
    Position avail;
} VSpace;


Person createPerson(String name, char sex, String city);
void displayPersonInfo(Person p);

/* Static Array List*/
void init_SAL(PersonStaticArrayList *list);
void insert_first_SAL(PersonStaticArrayList *list, Person p);
void insert_last_SAL(PersonStaticArrayList *list, Person p);
void insert_at_SAL(PersonStaticArrayList *list, Person p, int index);
void delete_first_SAL(PersonStaticArrayList *list);
void delete_last_SAL(PersonStaticArrayList *list);
void delete_by_sex_SAL(PersonStaticArrayList *list, char sex); // all ocurrences
void display_SAL(PersonStaticArrayList list);

/* Dynamic Array List - v1 
 * Doubles the maximum size of the array when full.
 */
void init_DAL(PersonDynamicArrayList *list);
void insert_first_DAL(PersonDynamicArrayList *list, Person p);
void insert_last_DAL(PersonDynamicArrayList *list, Person p);
void insert_at_DAL(PersonDynamicArrayList *list, Person p, int index);
void delete_first_DAL(PersonDynamicArrayList *list);
void delete_last_DAL(PersonDynamicArrayList *list);
void delete_by_city_DAL(PersonDynamicArrayList *list, String city); // first ocurrence
void display_DAL(PersonDynamicArrayList list);

/* Dynamic Array List - v2 
 * Doubles the maximum size of the array when full.
 * The Dynamic Array List must also be created in the heap.
 */
void init_DAL_2(PersonDynamicArrayList **list);
void insert_first_DAL_2(PersonDynamicArrayList *list, Person p);
void insert_last_DAL_2(PersonDynamicArrayList *list, Person p);
void insert_at_DAL_2(PersonDynamicArrayList *list, Person p, int index);
void delete_first_DAL_2(PersonDynamicArrayList *list);
void delete_last_DAL_2(PersonDynamicArrayList *list);
void delete_by_name_DAL_2(PersonDynamicArrayList *list, String name); // last ocurrence
void display_DAL_2(PersonDynamicArrayList list);

/* Singly Linked List */
void insert_first_LL(PersonLinkedList *list, Person p);
void insert_last_LL(PersonLinkedList *list, Person p);
void insert_after_LL(PersonLinkedList *list, Person p, String name);
void delete_first_LL(PersonLinkedList *list);
void delete_last_LL(PersonLinkedList *list);
void delete_by_city_LL(PersonLinkedList *list, String city); // all ocurrences
void display_LL(PersonLinkedList list);

/* Implement all VSpace conncept and Cusor Based List*/
void init_vspace(VSpace *vs);
Position alloc_space(VSpace *vs);
void free_space(VSpace *vs, Position index);
void insert_first_CBL(VSpace *vs, PersonCusorBasedList *list, Person p);
void insert_last_CBL(VSpace *vs, PersonCusorBasedList *list, Person p);
void insert_at_CBL(VSpace *vs, PersonCusorBasedList *list, Person p, int index);
void delete_first_CBL(VSpace *vs, PersonCusorBasedList *list);
void delete_last_CBL(VSpace *vs, PersonCusorBasedList *list);
void delete_by_sex_CBL(VSpace *vs, PersonCusorBasedList *list, char sex); // all ocurrences
void display_CBL(VSpace vs, PersonCusorBasedList list);
#endif
