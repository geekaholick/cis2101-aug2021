#include <stdio.h>
#include <string.h>
#include "Person.h"

Person createPerson(String name, char sex, String city) {
    Person p;

    strcpy(p.name, name);
    p.sex = sex;
    strcpy(p.city, city);

    return p;
}

void displayPersonInfo(Person p) {
    printf("{%s | %c | %s}", p.name, p.sex, p.city);
}