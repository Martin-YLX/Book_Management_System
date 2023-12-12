#include "Person.h"

Person::Person(string newUsername, string newPassword) {
    this->username = newUsername;
    this->password = newPassword;
}

ull Person::getID() const {
    return id;
}

string Person::getUsername() const {
    return username;
}

void Person::changePassword(string newPassword) {
    this->password = newPassword;
}

//修改
void Person::searchBook(BookLink* headMain) {
    SortLink* temp;
    headMain->searchBook(temp);
    temp->allPrint();
}

Person::Person() {
    this->username = "";
    this->password = "";
}


