#include "Person.h"
#include "User.h"

User* User::getPre() const {
    return pre;
}
User* User::getNext() const {
    return next;
}

void User::insertPre(User *user) {
    this->pre = user;
}

void User::insertNext(User *user) {
    this->next = user;
}

User::User() : Person() {
    headHistory = new History;
    borrowed = new BookLink;
    headHistory->next= nullptr;
    pre = nullptr;
    next = nullptr;
    this->id = 0;
}

User::User(string newUsername, string newPassword, ull id) : Person(newUsername, newPassword) {
    borrowed = new BookLink;
    headHistory = new History;
    headHistory->next= nullptr;
    pre = nullptr;
    next = nullptr;
    this->id = id;
}

User::~User() {
    History* tempHis = headHistory;
    while (tempHis) {
        History* preHis = tempHis;
        tempHis = tempHis->next;
        delete preHis;
    }
    BookLink* tempBook = borrowed;
    while (tempBook) {
        BookLink* preHis = tempBook;
        tempBook = tempBook->getNext();
        delete preHis;
    }
}

void User::print() {
    printf("ID：%llu\n",id);
    printf("账号：");
    cout << username << endl;
}

void User::borrowBook(BookLink* headBorrow) {
    BookLink* temp = headBorrow;
    while (temp->getNext() != nullptr) {
        temp->getNext()->print();
        printf("是否要借这本书:");
        int opt;
        scanf("%d",&opt);
        if (opt) {
            temp->getNext()->changeFlagBorrow(true);
            BookLink* tempBor = borrowed;
            while (tempBor->getNext() != nullptr) {
                tempBor = tempBor->getNext();
            }
            BookLink* newBorrowed = new BookLink;
            newBorrowed->insert(temp->getNext()->getBook());
            tempBor->insertNext(newBorrowed);
            newBorrowed->insertPre(tempBor);
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

Admin::Admin(string newUsername, string newPassword) : Person(newUsername, newPassword) {}

void Admin::changeBook(BookLink* headMain) {
    printf("请先查询书籍：\n");
    SortLink* temp;
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
                temp->getNext()->getBookLink()->changeTitle();
                break;
            case 2:
                temp->getNext()->getBookLink()->changeIsbn();
                break;
            case 3:
                temp->getNext()->getBookLink()->changeAuthor();
                break;
            case 4:
                temp->getNext()->getBookLink()->changePublish();
                break;
            case 5:
                temp->getNext()->getBookLink()->changePublishTime();
                break;
            case 6:
                temp->getNext()->getBookLink()->changePrice();
                break;
            default:
                continue;
        }
        temp = temp->getNext();
    }
}

void Admin::deleteBook(BookLink* headMain) {
    printf("请先查询书籍：\n");
    SortLink* temp;
    headMain->searchBook(temp);
    while (temp->getNext() != nullptr) {
        temp->getNext()->getBookLink()->print();
        printf("是否删除：");
        int opt;
        scanf("%d",&opt);
        if (opt) {
            temp->getBookLink()->getPre()->insertNext(temp->getBookLink()->getNext());
            temp->getBookLink()->getNext()->insertPre(temp->getBookLink()->getPre());
            BookLink* pre = temp->getBookLink();
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
    string newUsername, newPassword, againPassword;
    printf("注册账号：\n");
    printf("请输入用户名：");
    cin >> newUsername;
    printf("请输入密码：");
    cin >> newPassword;
    printf("请再次输入密码：");
    cin >> againPassword;
    while (newPassword != againPassword) {
        printf("请重新输入密码：");
        cin >> newPassword;
        printf("请再次输入密码：");
        cin >> againPassword;
    }
    User* newUser = new User(newUsername,newPassword,++cnt);
    temp->insertNext(newUser);
    newUser->insertPre(temp);
}

void Admin::deleteUser(User* userHead,ull id) {
    User* temp = userHead;
    while (temp->getNext() != nullptr) {
        if (temp->getNext()->getID() == id) {
            temp->getNext()->getNext()->insertPre(temp);
            User* tempUser = temp->getNext()->getNext();
            delete temp->getNext();
            temp->insertNext(tempUser);
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
            temp->getNext()->print();
            putchar('\n');
            break;
        }
        temp = temp->getNext();
    }
}