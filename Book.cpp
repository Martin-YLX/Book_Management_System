#include "BookLink.h"

Book::Book() {
    head = new Tag;
}

Book::Book(string tit, string isbn, string auth, string pub, string pub_time, string pri, ull tim) {
    title = tit;
    isbn_issn = isbn;
    author = auth;
    publish = pub;
    publish_time = pub_time;
    price = pri;
    time = tim;
    head = new Tag;
}

void Book::insertTag(string s) {
    Tag* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    Tag* next = new Tag;
    next->name = s;
    next->next = nullptr;
    temp->next = next;
    next->pre = temp;
    head->num++;
}

void Book::deleteTag(string s) {
    Tag* temp = head->next;
    Tag* pre = head;
    while (temp != nullptr && temp->name != s) {
        pre = temp;
        temp = temp->next;
    }
    if (temp != nullptr) {
        pre->next = temp->next;
        if (temp->next != nullptr) {
            temp->next->pre = pre;
        }
        delete temp;
        head->num--;
    }
}

void Book::addTime(int x) {
    time += x;
}

string Book::getTitle() const {
    return title;
}

string Book::getIsbnIssn() const {
    return isbn_issn;
}

string Book::getAuthor() const {
    return author;
}

string Book::getPublish() const {
    return publish;
}

string Book::getPublishTime() const {
    return publish_time;
}

string Book::getPrice() const {
    return price;
}

ull Book::getTime() const {
    return time;
}

Tag* Book::getHead() const {
    return head;
}