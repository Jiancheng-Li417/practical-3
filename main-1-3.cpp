#include <iostream>  
#include "Person.h"    

PersonList createPersonList(int n);
PersonList deepCopyPersonList(PersonList pl);

int main() {
    PersonList originalList = createPersonList(2);
    originalList.people[0].name = "Mike";
    originalList.people[0].age = 33;
    originalList.people[1].name = "Michael";
    originalList.people[1].age = 29;

    PersonList copiedList = deepCopyPersonList(originalList);

    std::cout << "Original PersonList:" << std::endl;
    for (int i = 0; i < originalList.numPeople; ++i) {
        std::cout << "Person " << i + 1 << ": " << originalList.people[i].name << ", Age: " << originalList.people[i].age << std::endl;
    }
  
    std::cout << "\nCopied PersonList:" << std::endl;
    for (int i = 0; i < copiedList.numPeople; ++i) {
        std::cout << "Person " << i + 1 << ": " << copiedList.people[i].name << ", Age: " << copiedList.people[i].age << std::endl;
    }

    delete[] originalList.people;
    delete[] copiedList.people;
    return 0;
}
