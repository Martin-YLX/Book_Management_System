#include "User.h"

void User::borrowBook(string bookTitle) {
    // history
    History* newHistory = new History;
    newHistory->title = bookTitle;
    newHistory->time++;
    head->next = newHistory;
    head = newHistory;
}

void User::searchHistory(string bookTitle) {
    History* now = head;
    while (now != nullptr) {
        if (now->title == bookTitle) printf("times:\n",now->time);
        now = now->next;
    }
}
