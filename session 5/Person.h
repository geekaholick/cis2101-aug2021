#ifndef PERSON_H
#define PERSON_H

typedef char String[30];

typedef struct {
    String name;
    char sex;
    String city;
} Person;

Person createPerson(String name, char sex, String city);
void displayPersonInfo(Person p);
    // {name | sex | city}
#endif
