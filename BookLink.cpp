#include "BookLink.h"
#include <algorithm>

BookLink::BookLink() {
    next = nullptr;
    pre = nullptr;
}

bool Book::operator < (const Book& other) const {
    return this->title < other.title;
}

void BookLink::insert(Book in) {
    book.id = in.id;
    book.title = in.getTitle();
    book.isbn_issn = in.getIsbnIssn();
    book.author = in.getAuthor();
    book.publish = in.getPublish();
    book.publishTime = in.getPublishTime();
    book.price = in.getPrice();
    book.pages = in.pages;
    book.description = in.description;
    book.time = in.time;
    book.flagBorrow = false;
}

void BookLink::insertPre(BookLink* newBook) {
    this->pre = newBook;
}
void BookLink::insertNext(BookLink* newBook) {
    this->next = newBook;
}

void BookLink::print() {
    printf("书籍信息：\n");
    printf("ID：%llu\n",book.getID());
    printf("名称：");
    cout << book.getTitle() << endl;
    printf("ISBN/ISSN：");
    cout << book.getIsbnIssn() << endl;
    printf("作者：");
    cout << book.getAuthor() << endl;
    printf("出版社：");
    cout << book.getPublish() << endl;
    printf("出版时间：");
    cout << book.getPublishTime() << endl;
    printf("页数：%llu\n",book.pages);
    printf("价格：");
    cout << book.getPrice() << endl;
    printf("借阅次数：%llu\n", book.getTime());
    printf("简介：\n");
    cout << book.description << endl;
}

void BookLink::allPrint() {
    BookLink* temp = this;
    while (temp->next != nullptr) {
        temp->next->print();
        putchar('\n');
        temp = temp->next;
    }
}

bool BookLink::check(string isbn) {
    return book.getIsbnIssn() == isbn;
}

BookLink* BookLink::getPre() const {
    return pre;
}

BookLink* BookLink::getNext() const {
    return this->next;
}

Book BookLink::getBook() const {
    return book;
}

void BookLink::insertBook(Book in) {
    BookLink* temp = this;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    BookLink* nextBook = new BookLink;
    nextBook->next = nullptr;
    nextBook->pre = temp;
    temp->next = nextBook;
    nextBook->insert(in);  // 将插入操作移到链接节点之后
    num++;
}

void BookLink::deleteBook(string isbn) {
    BookLink* temp = this->next;
    BookLink* preBook = this;
    while (!temp->check(isbn)) {
        preBook = temp;
        temp = temp->next;
    }
    preBook->next = temp->next;
    delete temp;
    num--;
}

BookLink::~BookLink() {
    Tag* temp = book.head;
    while (temp) {
        Tag* preTag = temp;
        temp = temp->next;
        delete preTag;
    }
    temp = allTag;
    while (temp) {
        Tag* preTag = temp;
        temp = temp->next;
        delete preTag;
    }
}

//修改
SortLink::SortLink() {
    object = nullptr; // maybe object = new SortLink ??
    next = nullptr;
    pre = nullptr;
}

SortLink::~SortLink() {
    delete object;
}


SortLink* SortLink::getNext() const {
    return next;
}

BookLink* SortLink::getBookLink() const {
    return object;
}

void SortLink::allPrint() {
    SortLink* temp = this;
    while (temp->next != nullptr) {
        temp->object->print();
        temp = temp->next;
    }
}

void SortLink::insertBook(BookLink* toInsert) {
    SortLink* temp = this;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    SortLink* nextBook = new SortLink;
    nextBook->next = nullptr;
    nextBook->pre = temp;
    temp->next = nextBook;
    nextBook->object = toInsert;
}

void BookLink::searchName(SortLink*& now) {
    string title;
    printf("输入你要查询的书籍名称：");
    cin >> title;
    BookLink* temp = this;
    while (temp->next->book.getTitle() != title) {
        temp = temp->next;
    }
    now->insertBook(temp->next);
}

void BookLink::searchIsbn(SortLink*& now) {
    string isbn;
    printf("输入你要查询的ISBN/ISSN：");
    cin >> isbn;
    BookLink* temp = this;
    while (temp->next->book.getIsbnIssn() != isbn) {
        temp = temp->next;
    }
    now->insertBook(temp->next);
}

void BookLink::searchAuthor(SortLink*& now) {
    string author;
    printf("输入你要查询的作者：");
    cin >> author;
    BookLink* temp = this;
    while (temp->next != nullptr) {
        if (temp->next->book.getAuthor() == author) {
            now->insertBook(temp->next);
        }
        temp = temp->next;
    }
}

void BookLink::searchPublish(SortLink*& now) {
    string publish;
    printf("输入你要查询的出版社：");
    cin >> publish;
    BookLink* temp = this;
    while (temp->next != nullptr) {
        if (temp->next->book.getPublish() == publish) {
            now->insertBook(temp->next);
        }
        temp = temp->next;
    }
}

void BookLink::searchPublishTime(SortLink*& now) {
    string publish_time;
    printf("输入你要查询的出版时间：");
    cin >> publish_time;
    BookLink* temp = this;
    while (temp->next != nullptr) {
        if (temp->next->book.getPublishTime() == publish_time) {
            now->insertBook(temp->next);
        }
        temp = temp->next;
    }
}

void BookLink::searchPrice(SortLink*& now) {
    string price_low, price_high;
    printf("输入你要查询的价格范围：\n最低：");
    cin >> price_low;
    printf("最高：");
    cin >> price_high;
    BookLink* temp = this;
    while (temp->next != nullptr) {
        if (temp->next->book.getPrice() >= price_low && temp->next->book.getPrice() <= price_high) {
            now->insertBook(temp->next);
        }
        temp = temp->next;
    }
}

void BookLink::searchTag(SortLink*& now) {
    string tag;
    printf("输入你要查询的标签：");
    cin >> tag;
    BookLink* temp = this;
    while (temp->next != nullptr) {
        Tag* head = temp->next->book.getHead();
        while (head->next != nullptr) {
            if (head->name == tag) {
                now->insertBook(temp->next);
                break;
            }
            head = head->next;
        }
        temp = temp->next;
    }
}

void BookLink::searchBook(SortLink*& headReturn) {
    printf("1.名称\n");
    printf("2.ISBN/ISSN\n");
    printf("3.作者\n");
    printf("4.出版社\n");
    printf("5.出版时间\n");
    printf("6.价格区间\n");
    printf("请选择你的操作：\n");
    SortLink* now = new SortLink; //书籍头指针
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
            searchBook(headReturn);
    }
    headReturn = now;
}
//修改结束
void BookLink::changeTitle() {
    string title;
    printf("请输入修改后的名称：");
    cin >> title;
    this->book.title = title;
}

void BookLink::changeIsbn() {
    string isbn;
    printf("请输入修改后的ISBN/ISSN：");
    cin >> isbn;
    this->book.isbn_issn = isbn;
}

void BookLink::changeAuthor() {
    string author;
    printf("请输入修改后的作者：");
    cin >> author;
    this->book.author = author;
}

void BookLink::changePublish() {
    string publish;
    printf("请输入修改后的出版社：");
    cin >> publish;
    this->book.publish = publish;
}

void BookLink::changePublishTime() {
    string publishTime;
    printf("请输入修改后的出版时间：");
    cin >> publishTime;
    this->book.publishTime = publishTime;
}

void BookLink::changePrice() {
    string price;
    printf("请输入修改后的价格：");
    cin >> price;
    this->book.price = price;
}

void BookLink::changeFlagBorrow(bool f) {
    this->book.flagBorrow = f;
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
                if (sortTemp->next->book.time < temp->next->book.time) {
                    maxTime = max(maxTime, temp->next->book.time);
                    minTime = min(minTime, temp->next->book.time);

                    BookLink* sortNew = new BookLink;
                    sortNew->book = temp->next->book;  //todo:是否是next ？ 下面那个函数也一样

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
                maxTime = max(maxTime, temp->next->book.time);
                minTime = min(minTime, temp->next->book.time);
                BookLink* sortNew = new BookLink;
                sortNew->book = temp->next->book;
                sortTemp->next = sortNew;
            }
            cnt++;
        } else {
            if (temp->next->book.time <= minTime) continue;
            BookLink* sortTemp = sortHead;
            while (sortTemp->next->book.time >= temp->next->book.time) {
                sortTemp = sortTemp->next;
            }
            BookLink* preBook = nullptr;
            BookLink* sortNew = new BookLink;
            sortNew->book = temp->next->book;

            sortNew->next = sortTemp->next;
            sortTemp->next->pre = sortNew;
            sortNew->pre = sortTemp;
            sortTemp->next = sortNew;
            while (sortTemp->next != nullptr) {
                preBook = sortTemp;
                sortTemp = sortTemp->next;
            }
            delete sortTemp;
            minTime = preBook->book.time;
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
                if (cmpPublishTime(sortTemp->next->book.publishTime, temp->next->book.publishTime)) {
                    if (cmpPublishTime(maxTime, temp->next->book.publishTime)) {
                        maxTime = temp->next->book.publishTime;
                    }
                    if (cmpPublishTime(temp->next->book.publishTime, minTime)) {
                        minTime = temp->next->book.publishTime;
                    }

                    BookLink* sortNew = new BookLink;
                    sortNew->book = temp->next->book; //todo：next？

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
                if (cmpPublishTime(temp->next->book.publishTime, minTime)) {
                    minTime = temp->next->book.publishTime;
                }
                if (cmpPublishTime(maxTime, temp->next->book.publishTime)) {
                    maxTime = temp->next->book.publishTime;
                }

                BookLink* sortNew = new BookLink;
                sortNew->book = temp->next->book;
                sortTemp->next = sortNew;
            }
            cnt++;
        } else {
            if (!cmpPublishTime(minTime, temp->next->book.publishTime)) continue;
            BookLink* sortTemp = sortHead;
            while (!cmpPublishTime(sortTemp->next->book.publishTime, temp->next->book.publishTime)) {
                sortTemp = sortTemp->next;
            }
            BookLink* preBook = nullptr;
            BookLink* sortNew = new BookLink;
            sortNew->book = temp->next->book;

            sortNew->next = sortTemp->next;
            sortTemp->next->pre = sortNew;
            sortNew->pre = sortTemp;
            sortTemp->next = sortNew;
            while (sortTemp->next != nullptr) {
                preBook = sortTemp;
                sortTemp = sortTemp->next;
            }
            delete sortTemp;
            minTime = preBook->book.publishTime;
        }

        temp = temp->next;
    }
}

void BookLink::merge(BookLink*& head1, BookLink*& head2) {
    BookLink* tail = new BookLink;
    BookLink* mergedHead = tail;  // 保留合并后链表的头部
    while (head1 != nullptr && head2 != nullptr) {
        if (head1->book < head2->book) {
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
    head1 = mergedHead->next;  // 更新 head1 为合并后链表的头部
    delete mergedHead;  // 释放临时头节点的内存
}

void BookLink::sortLexico() {
    if (this == nullptr || this->next == nullptr) return;

    BookLink* slow = this;
    BookLink* fast = this->next;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    } // 快慢指针找中点

    BookLink* head1 = this;
    BookLink* head2 = slow->next;
    slow->next = nullptr;

    head1->sortLexico();
    head2->sortLexico();

    merge(head1, head2);
}


Tag* BookLink::getAllTagHead() const {
    return allTag;
}

void BookLink::insertAllTag(string s) {
    bool flag = false;
    Tag* temp = allTag;
    while (temp->next != nullptr) {
        if (temp->name == s) {
            temp->cnt++;
            flag = true;
            break;
        }
        temp = temp->next;
    }
    if (flag) return;
    Tag* newNode = new Tag;
    newNode->name = s;
    newNode->cnt = 1;
    temp->next = newNode;
    newNode->pre = temp;
}

void BookLink::deleteAllTag(string s) {
    Tag* temp = allTag;
    while (temp->next != nullptr) {
        if (temp->next->name == s) {
            temp->next->cnt--;
            if (temp->next->cnt == 0) {
                Tag* preTag = temp->next->pre;
                preTag->next = temp->next->next;
                temp->next->next->pre = preTag;

            }
            break;
        }
        temp = temp->next;
    }
}

void BookLink::sortTag() {
    Tag* temp = this->allTag;
    Tag* sortHead = new Tag;
    sortHead->next = nullptr;
    ull maxFav = -1, minFav = ~0ull>>1;
    int cnt = 0;
    while (temp->next != nullptr) {
        if (cnt < 3) {
            Tag* sortTemp = new Tag;
            bool flag = false;
            while (sortTemp->next != nullptr) {
                if (sortTemp->next->cnt < temp->next->cnt) {
                    maxFav = max(maxFav,(ull)temp->next->cnt);
                    minFav = min(minFav,(ull)temp->next->cnt);

                    Tag* sortNew = new Tag;
                    sortNew->name = temp->next->name;
                    sortNew->cnt = temp->next->cnt;

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
                maxFav = max(maxFav,(ull)temp->next->cnt);
                minFav = min(minFav,(ull)temp->next->cnt);
                Tag* sortNew = new Tag;
                sortNew->name = temp->next->name;
                sortNew->cnt = temp->next->cnt;
                sortTemp->next = sortNew;
            }
            cnt ++;
        } else {
            if (temp->next->cnt <= minFav) continue;
            Tag* sortTemp = sortHead;
            while (sortTemp->next->cnt >= temp->next->cnt) {
                sortTemp = sortTemp->next;
            }
            Tag* preTag = nullptr;
            Tag* sortNew = new Tag;
            sortNew->name = temp->next->name;
            sortNew->cnt = temp->next->cnt;

            sortNew->next = sortTemp->next;
            sortTemp->next->pre = sortNew;
            sortNew->pre = sortTemp;
            sortTemp->next = sortNew;
            while (sortTemp->next != nullptr) {
                preTag = sortTemp;
                sortTemp = sortTemp->next;
            }
            delete sortTemp;
            minFav = preTag->cnt;
        }
        temp = temp->next;
    }
    //todo:加一个user里的函数
}
