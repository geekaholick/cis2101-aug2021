#include <stdio.h>
#include "Person.h"

int main() {
    Person p1 = createPerson("Mark", 'M', "Cebu");

    displayPersonInfo(p1);
    return 0;
}