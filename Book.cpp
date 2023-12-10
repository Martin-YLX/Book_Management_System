#include "BookLink.h"

Book::Book() {
    head = new Tag;
    flagBorrow = false;
}

Book::Book(ull id,string tit, string isbn, string auth, string pub, string pub_time, ull pag, string pri, string des, ull tim) {
    title = tit;
    isbn_issn = isbn;
    author = auth;
    publish = pub;
    publishTime = pub_time;
    pages = pag;
    price = pri;
    description = des;
    time = tim;
    head = new Tag;
    flagBorrow = false;
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
    head->cnt++;
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
        head->cnt--;
    }
}

void Book::addTime(int x) {
    time += x;
}

ull Book::getID() const {
    return id;
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
    return publishTime;
}

string Book::getPrice() const {
    return price;
}

ull Book::getPages() const {
    return pages;
}

ull Book::getTime() const {
    return time;
}

string Book::getDes() const {
    return description;
}

bool Book::getFlagBorrow() const {
    return flagBorrow;
}

Tag* Book::getHead() const {
    return head;
}
/*
Book Book::createBookFromString(const string& line) {
    Book newBook;
    istringstream linestream(line);

    linestream >> newBook.id >> newBook.isbn_issn >> newBook.title >> newBook.author
               >> newBook.publish >> newBook.publishTime >> newBook.pages
               >> newBook.price >> newBook.description >> ws;

    return newBook;
}
*/
#define CSV_DELIMITER ','
Book Book::createBookFromString(const string& line) {
    istringstream iss(line);
    string id, title, isbn_issn, author, publish, publishTime, pages, price, description, time;

    getline(iss, id, CSV_DELIMITER);
    getline(iss, isbn_issn, CSV_DELIMITER);
    getline(iss, title, CSV_DELIMITER);
    getline(iss, author, CSV_DELIMITER);
    getline(iss, publish, CSV_DELIMITER);
    getline(iss, publishTime, CSV_DELIMITER);
    getline(iss, price, CSV_DELIMITER);
    getline(iss, pages, CSV_DELIMITER);
    getline(iss, description, CSV_DELIMITER);

    // Convert necessary fields to appropriate types
    ull bookId = stoull(id);
    ull numPages = stoull(pages);
    ull borrowTime = stoull(time);

    // Assuming your Book constructor looks like this (modify as needed)
    Book newBook(bookId, title, isbn_issn, author, publish, publishTime, numPages, price, description, borrowTime);

    return newBook;
}
