#include "Person.h"

Person::Person(string username, string password) {
    this->username = username;
    this->password = password;
}

ull Person::getID() const {
    return id;
}

string Person::getUsername() const {
    return username;
}

void Person::changePassword(string password) {
    this->password = password;
}

void Person::searchBook(BookLink* headMain) {
    BookLink* ans;
    headMain->searchBook(ans);
    while (ans->getNext() != nullptr) {
        ans->getNext()->print();
        ans = ans->getNext();
    }
}

Person::Person() {}


