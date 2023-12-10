#include "Person.h"
#include "User.h"

User* User::getPre() {
    return pre;
}
User* User::getNext() {
    return next;
}

void User::insertPre(User *user) {
    this->pre = user;
}

void User::insertNext(User *user) {
    this->next = user;
}


User::User(string username, string password, ull id) : Person(username, password) {
    headHistory = nullptr;
    pre = nullptr;
    next = nullptr;
    this->id = id;
}

void User::print() {
    printf("ID：%llu\n",id);
    printf("账号：");
    cout << username << endl;
}

void User::borrowBook(BookLink* headBorrow) {
    //BookLink* ans = borrowed; // getNext()?
    //headMain->searchBook(ans);
    BookLink* temp = headBorrow;
    while (temp->getNext() != nullptr) {
        temp->getNext()->print();
        printf("是否要借这本书:");
        int opt;
        scanf("%d",&opt);
        if (opt) {
            temp->getNext()->changeFlagBorrow(true);
            // history
            History *tempHis = headHistory;
            while (tempHis->next != nullptr) {
                tempHis = tempHis->next;
            }
            History *newHistory = new History;
            newHistory->book = temp->getNext()->getBook();
            newHistory->time++;
            newHistory->next = nullptr;
            tempHis->next = newHistory;
        }
        temp = temp->getNext();
    }
}

void User::returnBook() {
    BookLink* temp = borrowed;
    while (temp->getNext() != nullptr) {
        temp->getNext()->print();
        printf("是否要还书：");
        int opt;
        scanf("%d",&opt);
        if (opt) {
            temp->getNext()->changeFlagBorrow(false);
        }
        temp = temp->getNext();
    }
}

void User::searchBook(BookLink* headMain) {
    Person::searchBook(headMain);
}

void Visitor::searchBook(BookLink* headMain) {
    Person::searchBook(headMain);
}

void Admin::changeBook(BookLink* headMain) {
    printf("请先查询书籍：\n");
    BookLink* temp;
    headMain->searchBook(temp);
    while (temp->getNext() != nullptr) {
        printf("请选择修改的元素：\n");
        printf("1.名称\n");
        printf("2.ISBN/ISSN\n");
        printf("3.作者\n");
        printf("4.出版社\n");
        printf("5.出版时间\n");
        printf("6.价格\n");
        printf("请选择你的操作：\n");
        int opt;
        scanf("%d",&opt);
        switch (opt) {
            case 1:
                temp->getNext()->changeTitle();
                break;
            case 2:
                temp->getNext()->changeIsbn();
                break;
            case 3:
                temp->getNext()->changeAuthor();
                break;
            case 4:
                temp->getNext()->changePublish();
                break;
            case 5:
                temp->getNext()->changePublishTime();
                break;
            case 6:
                temp->getNext()->changePrice();
                break;
            default:
                continue;
        }
        temp = temp->getNext();
    }
}

void Admin::deleteBook(BookLink* headMain) {
    printf("请先查询书籍：\n");
    BookLink* temp;
    headMain->searchBook(temp);
    while (temp->getNext() != nullptr) {
        temp->getNext()->print();
        printf("是否删除：");
        int opt;
        scanf("%d",&opt);
        if (opt) {
            temp->getPre()->insertNext(temp->getNext());
            temp->getNext()->insertPre(temp->getPre());
            BookLink* pre = temp;
            temp = temp->getNext();
            delete pre;
        } else temp = temp->getNext();
    }
}

#define ull unsigned long long
ull cnt = 0;

void Admin::insertUser(User* userHead) {
    User* temp = userHead;
    while (temp->getNext() != nullptr) {
        temp = temp->getNext();
    }
    cin >> username >> password;
    User* newUser = new User(username,password,++cnt);
    temp->insertNext(newUser);
    newUser->insertPre(temp);
}

void Admin::deleteUser(User* userHead,ull id) {
    User* temp = userHead;
    while (temp->getNext() != nullptr) {
        if (temp->getNext()->getID() == id) {
            temp->getPre()->insertNext(temp->getNext());
            temp->getNext()->insertPre(temp->getPre());
            delete temp;
            break;
        }
        temp = temp->getNext();
    }
}

void Admin::resetUser(User* userHead,ull id) {
    User* temp = userHead;
    while (temp->getNext() != nullptr) {
        if (temp->getNext()->getID() == id) {
            temp->getNext()->changePassword("123456");
            break;
        }
        temp = temp->getNext();
    }
}

void Admin::searchUser(User* userHead,ull id) {
    User* temp = userHead;
    while (temp->getNext() != nullptr) {
        if (temp->getNext()->getID() == id) {
            temp->print();
            putchar('\n');
            break;
        }
        temp = temp->getNext();
    }
}