#include <iostream>  
#include "Person.h"    

PersonList shallowCopyPersonList(PersonList pl);

int main() {
    PersonList originalList;
    originalList.numPeople = 2;
    originalList.people = new Person[originalList.numPeople];
    originalList.people[0].name = "Mike";
    originalList.people[0].age = 22;
    originalList.people[1].name = "Michael";
    originalList.people[1].age = 29;

    PersonList copiedList = shallowCopyPersonList(originalList);

    std::cout << "Original PersonList:" << std::endl;
    for (int i = 0; i < originalList.numPeople; ++i) {
        std::cout << "Person " << i + 1 << ": " << originalList.people[i].name << ", Age: " << originalList.people[i].age << std::endl;
    }

    originalList.people[0].name = "Charlie";
    originalList.people[0].age = 27;

    std::cout << "\nCopied PersonList after modifying original:" << std::endl;
    for (int i = 0; i < copiedList.numPeople; ++i) {
        std::cout << "Person " << i + 1 << ": " << copiedList.people[i].name << ", Age: " << copiedList.people[i].age << std::endl;
    }

    delete[] originalList.people;  
    return 0;
}