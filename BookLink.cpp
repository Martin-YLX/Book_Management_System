#include "BookLink.h"

BookLink::BookLink() {
    next = nullptr;
    pre = nullptr;
}

void BookLink::insert(Book in) {
    detail.title = in.getTitle();
    detail.isbn_issn = in.getIsbnIssn();
    detail.author = in.getAuthor();
    detail.publish = in.getPublish();
    detail.publish_time = in.getPublishTime();
    detail.price = in.getPrice();
}

void BookLink::print() {
    printf("书籍信息：\n");
    printf("名称：\n");
    cout << detail.title << endl;
    printf("ISBN/ISSN：\n");
    cout << detail.isbn_issn << endl;
    printf("作者：\n");
    cout << detail.author << endl;
    printf("出版社：\n");
    cout << detail.publish << endl;
    printf("出版时间：\n");
    cout << detail.publish_time << endl;
    printf("价格：\n");
    cout << detail.price << endl;
    printf("借阅次数：%llu\n", detail.getTime());
}

bool BookLink::check(string isbn) {
    return detail.getIsbnIssn() == isbn;
}

void BookLink::insertBook(Book in) {
    BookLink* temp = this;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    BookLink* next = new BookLink;
    next->insert(in);
    next->next = nullptr;
    temp->next = next;
    next->pre = temp;
    num++;
}

void BookLink::deleteBook(string isbn) {
    BookLink* temp = this;
    BookLink* pre;
    while (!temp->check(isbn)) {
        pre = temp;
        temp = temp->next;
    }
    pre->next = temp->next;
    delete temp;
    num--;
}

void BookLink::searchName(BookLink* now) {
    string title;
    printf("输入你要查询的书籍名称：");
    cin >> title;
    BookLink* temp = this;
    while (temp->detail.getTitle() != title) {
        temp = temp->next;
    }
    now->insertBook(temp->detail);
}

void BookLink::searchIsbn(BookLink* now) {
    string isbn;
    printf("输入你要查询的ISBN/ISSN：");
    cin >> isbn;
    BookLink* temp = this;
    while (temp->detail.getIsbnIssn() != isbn) {
        temp = temp->next;
    }
    now->insertBook(temp->detail);
}

void BookLink::searchAuthor(BookLink* now) {
    string author;
    printf("输入你要查询的作者：");
    cin >> author;
    BookLink* temp = this;
    while (temp->next != nullptr) {
        if (temp->detail.getAuthor() == author) {
            now->insertBook(temp->detail);
        }
        temp = temp->next;
    }
}

void BookLink::searchPublish(BookLink* now) {
    string publish;
    printf("输入你要查询的出版社：");
    cin >> publish;
    BookLink* temp = this;
    while (temp->next != nullptr) {
        if (temp->detail.getPublish() == publish) {
            now->insertBook(temp->detail);
        }
        temp = temp->next;
    }
}

void BookLink::searchPublishTime(BookLink* now) {
    string publish_time;
    printf("输入你要查询的出版时间：");
    cin >> publish_time;
    BookLink* temp = this;
    while (temp->next != nullptr) {
        if (temp->detail.getPublishTime() == publish_time) {
            now->insertBook(temp->detail);
        }
        temp = temp->next;
    }
}

void BookLink::searchPrice(BookLink* now) {
    string price_low, price_high;
    printf("输入你要查询的价格范围：\n最低：");
    cin >> price_low;
    printf("最高：");
    cin >> price_high;
    BookLink* temp = this;
    while (temp->next != nullptr) {
        if (temp->detail.getPrice() >= price_low && temp->detail.getPrice() <= price_high) {
            now->insertBook(temp->detail);
        }
        temp = temp->next;
    }
}

void BookLink::searchTag(BookLink* now) {
    string tag;
    printf("输入你要查询的标签：");
    cin >> tag;
    BookLink* temp = this;
    while (temp->next != nullptr) {
        Tag* head = temp->detail.getHead();
        while (head->next != nullptr) {
            if (head->name == tag) {
                now->insertBook(temp->detail);
                break;
            }
            head = head->next;
        }
        temp = temp->next;
    }
}

void BookLink::changeName(BookLink* now) {
    BookLink* temp = now;
    BookLink* pre;
    while (temp->next != nullptr) {
        temp->print();
        string name;
        printf("请输入修改后的名称：");
        cin >> name;
        temp->detail.title = name;
        pre = temp;
        temp = temp->next;
        delete pre;
    }
}

void BookLink::changeIsbn(BookLink* now) {
    BookLink* temp = now;
    BookLink* pre;
    while (temp->next != nullptr) {
        temp->print();
        string isbn;
        printf("请输入修改后的ISBN/ISSN：");
        cin >> isbn;
        temp->detail.isbn_issn = isbn;
        pre = temp;
        temp = temp->next;
        delete pre;
    }
}

void BookLink::changeAuthor(BookLink* now) {
    BookLink* temp = now;
    BookLink* pre;
    while (temp->next != nullptr) {
        temp->print();
        string author;
        printf("请输入修改后的作者：");
        cin >> author;
        temp->detail.author = author;
        pre = temp;
        temp = temp->next;
        delete pre;
    }
}

void BookLink::changePublish(BookLink* now) {
    BookLink* temp = now;
    BookLink* pre;
    while (temp->next != nullptr) {
        temp->print();
        string publish;
        printf("请输入修改后的出版社：");
        cin >> publish;
        temp->detail.publish = publish;
        pre = temp;
        temp = temp->next;
        delete pre;
    }
}

void BookLink::changePublishTime(BookLink* now) {
    BookLink* temp = now;
    BookLink* pre;
    while (temp->next != nullptr) {
        temp->print();
        string publish_time;
        printf("请输入修改后的出版时间：");
        cin >> publish_time;
        temp->detail.publish_time = publish_time;
        pre = temp;
        temp = temp->next;
        delete pre;
    }
}

void BookLink::changePrice(BookLink* now) {
    BookLink* temp = now;
    BookLink* pre;
    while (temp->next != nullptr) {
        temp->print();
        string price;
        printf("请输入修改后的价格：");
        cin >> price;
        temp->detail.price = price;
        pre = temp;
        temp = temp->next;
        delete pre;
    }
}

void BookLink::changeBook() {
    printf("1.修改名称\n");
    printf("2.修改ISBN/ISSN\n");
    printf("3.修改作者\n");
    printf("4.修改出版社\n");
    printf("5.修改出版时间\n");
    printf("6.修改价格\n");
    printf("请选择你的操作：\n");
    BookLink *now = new BookLink; //修改书籍头指针
    int opt;
    scanf("%d",&opt);
    switch (opt) {
        case 1:
            searchName(now);
            changeName(now);
            break;
        case 2:
            searchIsbn(now);
            changeIsbn(now);
            break;
        case 3:
            searchAuthor(now);
            changeAuthor(now);
            break;
        case 4:
            searchPublish(now);
            changePublish(now);
            break;
        case 5:
            searchPublishTime(now);
            changePublishTime(now);
            break;
        case 6:
            searchPrice(now);
            changePrice(now);
            break;
        default:
            printf("请重新选择\n");
            changeBook();
    }
}

void BookLink::searchBook() {
    printf("1.名称\n");
    printf("2.ISBN/ISSN\n");
    printf("3.作者\n");
    printf("4.出版社\n");
    printf("5.出版时间\n");
    printf("6.价格区间\n");
    printf("请选择你的操作：\n");
    BookLink *now = new BookLink; //修改书籍头指针
    int opt;
    scanf("%d",&opt);
    switch (opt) {
        case 1:
            searchName(now);
            break;
        case 2:
            searchIsbn(now);
            break;
        case 3:
            searchAuthor(now);
            break;
        case 4:
            searchPublish(now);
            break;
        case 5:
            searchPublishTime(now);
            break;
        case 6:
            searchPrice(now);
            break;
        default:
            printf("请重新选择\n");
            searchBook();
    }

    BookLink *temp = now;
    BookLink *pre;
    while (temp->next != nullptr) {
        temp->print();
        pre = temp;
        temp = temp->next;
        delete pre;
    }
}

void BookLink::sortTime() {
    BookLink* temp = this;
    BookLink* sortHead = new BookLink;
    sortHead->next = nullptr;
    ull maxTime = -1, minTime = ~0ull>>1;
    int cnt = 0;
    while (temp->next != nullptr) {
        if (cnt < 10) {
            BookLink* sortTemp = sortHead;
            bool flag = false;
            while (sortTemp->next != nullptr) {
                if (sortTemp->next->detail.time < temp->next->detail.time) {
                    maxTime = max(maxTime, temp->next->detail.time);
                    minTime = min(minTime, temp->next->detail.time);

                    BookLink* sortNew = new BookLink;
                    sortNew->detail = temp->next->detail;  //todo:是否是next ？ 下面那个函数也一样
                    sortNew->next = sortTemp->next;
                    sortTemp->next->pre = sortNew;
                    sortNew->pre = sortTemp;
                    sortTemp->next = sortNew;
                    flag = true;
                    break;
                }
                sortTemp = sortTemp->next;
            }
            if (!flag) {
                maxTime = max(maxTime, temp->next->detail.time);
                minTime = min(minTime, temp->next->detail.time);
                BookLink* sortNew = new BookLink;
                sortNew->detail = temp->next->detail;
                sortTemp->next = sortNew;
            }
            cnt++;
        } else {
            if (temp->next->detail.time <= minTime) continue;
            BookLink* sortTemp = sortHead;
            while (sortTemp->next->detail.time >= temp->next->detail.time) {
                sortTemp = sortTemp->next;
            }
            BookLink* pre = nullptr;
            BookLink* sortNew = new BookLink;
            sortNew->detail = temp->next->detail;
            sortNew->next = sortTemp->next;
            sortTemp->next->pre = sortNew;
            sortNew->pre = sortTemp;
            sortTemp->next = sortNew;
            while (sortTemp->next != nullptr) {
                pre = sortTemp;
                sortTemp = sortTemp->next;
            }
            delete sortTemp;
            minTime = pre->detail.time;
        }
        temp = temp->next;
    }
}

bool BookLink::cmpPublishTime(string a,string b) {  // a < b
    for (int i = 0;i < min(a.length(),b.length());i++) {
        if (a[i] < b[i]) return true;
        if (a[i] > b[i]) return false;
    }
    return false; //不相等就false
}

void BookLink::sortPublishTime() {
    BookLink* temp = this;
    BookLink* sortHead = new BookLink;
    sortHead->next = nullptr;
    string maxTime = "0";
    string minTime = "99999999999";
    int cnt = 0;

    while (temp->next != nullptr) {
        if (cnt < 10) {
            BookLink* sortTemp = sortHead;
            bool flag = false;
            while (sortTemp->next != nullptr) {
                if (cmpPublishTime(sortTemp->next->detail.publish_time, temp->next->detail.publish_time)) {
                    if (cmpPublishTime(maxTime, temp->next->detail.publish_time)) {
                        maxTime = temp->next->detail.publish_time;
                    }
                    if (cmpPublishTime(temp->next->detail.publish_time, minTime)) {
                        minTime = temp->next->detail.publish_time;
                    }

                    BookLink* sortNew = new BookLink;
                    sortNew->detail = temp->next->detail; //todo：next？
                    sortNew->next = sortTemp->next;
                    sortTemp->next->pre = sortNew;
                    sortNew->pre = sortTemp;
                    sortTemp->next = sortNew;
                    flag = true;
                    break;
                }
                sortTemp = sortTemp->next;
            }
            if (!flag) {
                if (cmpPublishTime(temp->next->detail.publish_time, minTime)) {
                    minTime = temp->next->detail.publish_time;
                }
                if (cmpPublishTime(maxTime, temp->next->detail.publish_time)) {
                    maxTime = temp->next->detail.publish_time;
                }

                BookLink* sortNew = new BookLink;
                sortNew->detail = temp->next->detail;
                sortTemp->next = sortNew;
            }
            cnt++;
        } else {
            if (!cmpPublishTime(minTime, temp->next->detail.publish_time)) continue;
            BookLink* sortTemp = sortHead;
            while (!cmpPublishTime(sortTemp->next->detail.publish_time, temp->next->detail.publish_time)) {
                sortTemp = sortTemp->next;
            }
            BookLink* pre = nullptr;
            BookLink* sortNew = new BookLink;
            sortNew->detail = temp->next->detail;
            sortNew->next = sortTemp->next;
            sortTemp->next->pre = sortNew;
            sortNew->pre = sortTemp;
            sortTemp->next = sortNew;
            while (sortTemp->next != nullptr) {
                pre = sortTemp;
                sortTemp = sortTemp->next;
            }
            delete sortTemp;
            minTime = pre->detail.publish_time;
        }

        temp = temp->next;
    }
}

void BookLink::merge(BookLink*& head1, BookLink*& head2) {
    BookLink* tail = new BookLink;
    while (head1 != nullptr && head2 != nullptr) {
        if (head1->detail.title < head2->detail.title) {
            tail->next = head1;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }
    if (head1 != nullptr) {
        tail->next = head1;
    } else {
        tail->next = head2;
    }
    head1 = tail->next;
}

void BookLink::sortLexico() {
    if (this == nullptr || this->next == nullptr) return;
    BookLink* slow = this;
    BookLink* fast = this->next;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    } //快慢指针找中点
    BookLink* head1 = this;
    BookLink* head2 = slow->next;
    slow->next = nullptr;
    head1->sortLexico();
    head2->sortLexico();
    merge(head1, head2);
}



