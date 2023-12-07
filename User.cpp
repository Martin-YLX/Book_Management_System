#include "User.h"


void User::borrow_book(string book_title) {


    //history
    History* new_history = new History;
    new_history->title = book_title;
    new_history->time ++;
    head->next = new_history;
    head = new_history;
}

void User::search_history(string book_title) {
    History* now = head;
    while (now != nullptr) {
        if (now->title == book_title) printf("times:\n",now->time);
        now = now->next;
    }
}