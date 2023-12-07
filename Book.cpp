#include "Book.h"
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

// todo: Detail & Tag

Detail::Detail() {
    title = "";
    isbn_issn = "";
    author = "";
    publish = "";
    publish_time = "";
    price = "";
    time = 0;
}

#define ull unsigned long long
Detail::Detail(string tit,string isbn,string auth,string pub,string pub_time,string pri,ull tim) {
    title = tit;
    isbn_issn = isbn;
    author = auth;
    publish = pub;
    publish_time = pub_time;
    price = pri;
    time = tim;
}
#undef ull

void Detail::insert_tag(Tag *p,string s) {
    Tag *temp = p;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    Tag *next = new Tag;
    next->name = s;
    next->next = nullptr;
    temp->next = next;
    next->pre = temp;
    p->num ++;
}

void Detail::delete_tag(Tag *p, string s) {
    Tag *temp = p->next;
    Tag *pre = p;
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
        p->num--;
    }
}

void Detail::add_time(int x) {
    time += x;
}

// todo: Book

Book::Book() {
    this->next = nullptr;
}

void Book::print() {
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
    printf("借阅次数：%llu\n",detail.time);
}

void Book::insert(Detail in) {
    detail.title = in.title;
    detail.isbn_issn = in.isbn_issn;
    detail.author = in.author;
    detail.publish = in.publish;
    detail.publish_time = in.publish_time;
    detail.price = in.price;
}

bool Book::check(string isbn) {
    if (this->detail.isbn_issn == isbn) return true;
    else return false;
}

void insert_book(Book *p,Detail in) {
    Book *temp = p;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    Book *next = new Book;
    next->insert(in);
    next->next = nullptr;
    temp->next = next;
    next->pre = temp;
    p->num ++;
}

void delete_book(Book *p,string isbn) {
    Book *temp = p;
    Book *pre;
    while (!temp->check(isbn)) {
        pre = temp;
        temp = temp->next;
    }
    pre->next = temp->next;
    delete temp;
    p->num --;
}

void search_name(Book *p,Book *now) {
    string title;
    printf("输入你要查询的书籍名称：");
    cin >> title;
    Book *temp = p;
    while (temp->detail.title != title) {
        temp = temp->next;
    }
    insert_book(now,temp->detail);
}

void search_isbn(Book *p,Book *now) {
    string isbn;
    printf("输入你要查询的ISBN/ISSN：");
    cin >> isbn;
    Book *temp = p;
    while (temp->detail.isbn_issn != isbn) {
        temp = temp->next;
    }
    insert_book(now,temp->detail);
}

void search_author(Book *p,Book *now) {
    string author;
    printf("输入你要查询的作者：");
    cin >> author;
    Book *temp = p;
    while (temp->next != nullptr) {
        if (temp->detail.author == author) {
            insert_book(now,temp->detail);
        }
        temp = temp->next;
    }
}

void search_publish(Book *p,Book *now) {
    string publish;
    printf("输入你要查询的出版社：");
    cin >> publish;
    Book *temp = p;
    while (temp->next != nullptr) {
        if (temp->detail.publish == publish) {
            insert_book(now,temp->detail);
        }
        temp = temp->next;
    }
}

void search_publish_time(Book *p,Book *now) {  //todo：可添加模糊查询 年份
    string publish_time;
    printf("输入你要查询的出版时间：");
    cin >> publish_time;
    Book *temp = p;
    while (temp->next != nullptr) {
        if (temp->detail.publish_time == publish_time) {
            insert_book(now,temp->detail);
        }
        temp = temp->next;
    }
}

void search_price(Book *p,Book *now) {
    string price_low, price_high;
    printf("输入你要查询的价格范围：\n最低：");
    cin >> price_low;
    printf("最高：");
    cin >> price_high;
    Book *temp = p;
    while (temp->next != nullptr) {
        if (temp->detail.price >= price_low && temp->detail.price <= price_high) {
            insert_book(now,temp->detail);
        }
        temp = temp->next;
    }
}

void search_tag(Book *p,Book *now) {
    string tag;
    printf("输入你要查询的标签：");
    cin >> tag;
    Book *temp = p;
    while (temp->next != nullptr) {
        Tag *head = temp->detail.head;
        while (head->next != nullptr) {
            if (head->name == tag) {
                insert_book(now,temp->detail);
                break;
            }
            head = head->next;
        }
        temp = temp->next;
    }
}

void change_name(Book *now) {
    Book *temp = now;
    Book *pre;
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

void change_isbn(Book *now) {
    Book *temp = now;
    Book *pre;
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

void change_author(Book *now) {
    Book *temp = now;
    Book *pre;
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

void change_publish(Book *now) {
    Book *temp = now;
    Book *pre;
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

void change_publish_time(Book *now) {
    Book *temp = now;
    Book *pre;
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

void change_price(Book *now) {
    Book *temp = now;
    Book *pre;
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

void change_book(Book *p) {
    printf("1.修改名称\n");
    printf("2.修改ISBN/ISSN\n");
    printf("3.修改作者\n");
    printf("4.修改出版社\n");
    printf("5.修改出版时间\n");
    printf("6.修改价格\n");
    printf("请选择你的操作：\n");
    Book *now = new Book; //修改书籍头指针
    int opt;
    scanf("%d",&opt);
    switch (opt) {
        case 1:
            search_name(p,now);
            change_name(now);
            break;
        case 2:
            search_isbn(p,now);
            change_isbn(now);
            break;
        case 3:
            search_author(p,now);
            change_author(now);
            break;
        case 4:
            search_publish(p,now);
            change_publish(now);
            break;
        case 5:
            search_publish_time(p,now);
            change_publish_time(now);
            break;
        case 6:
            search_price(p,now);
            change_price(now);
            break;
        default:
            printf("请重新选择\n");
            change_book(p);
    }
}

void search_book(Book *p) {
    printf("1.名称\n");
    printf("2.ISBN/ISSN\n");
    printf("3.作者\n");
    printf("4.出版社\n");
    printf("5.出版时间\n");
    printf("6.价格区间\n");
    printf("请选择你的操作：\n");
    Book *now = new Book; //修改书籍头指针
    int opt;
    scanf("%d",&opt);
    switch (opt) {
        case 1:
            search_name(p,now);
            break;
        case 2:
            search_isbn(p,now);
            break;
        case 3:
            search_author(p,now);
            break;
        case 4:
            search_publish(p,now);
            break;
        case 5:
            search_publish_time(p,now);
            break;
        case 6:
            search_price(p,now);
            break;
        default:
            printf("请重新选择\n");
            search_book(p);
    }
    Book *temp = now;
    Book *pre;
    while (temp->next != nullptr) {
        temp->print();
        pre = temp;
        temp = temp->next;
        delete pre;
    }
}

#define ull unsigned long long
void sort_time(Book *p) {
    Book *temp = p;
    Book *sort_head = new Book;
    sort_head->next = nullptr;
    ull max_time = -1, min_time = ~0ull>>1;
    int cnt = 0;
    while (temp->next != nullptr) {
        if (cnt < 10) {
            Book *sort_temp = sort_head;
            bool flag = false;
            while (sort_temp->next != nullptr) {
                if (sort_temp->next->detail.time < temp->detail.time) {
                    max_time = max(max_time,temp->detail.time);
                    min_time = min(min_time,temp->detail.time);
                    Book *sort_new = new Book;
                    sort_new->detail = temp->detail;
                    sort_new->next = sort_temp->next;
                    sort_temp->next->pre = sort_new;
                    sort_new->pre = sort_temp;
                    sort_temp->next = sort_new;
                    flag = true;
                    break;
                }
                sort_temp = sort_temp->next;
            }
            if (!flag) {
                max_time = max(max_time,temp->detail.time);
                min_time = min(min_time,temp->detail.time);
                Book *sort_new = new Book;
                sort_new->detail = temp->detail;  //深拷贝!!
                sort_temp->next = sort_new;
            }
            cnt++;
        } else {
            if (temp->detail.time <= min_time) continue;
            Book *sort_temp = sort_head;
            while (sort_temp->next->detail.time >= temp->detail.time) {
                sort_temp = sort_temp->next;
            }
            Book *pre = nullptr;
            Book *sort_new = new Book;
            sort_new->detail = temp->detail;
            sort_new->next = sort_temp->next;
            sort_temp->next->pre = sort_new;
            sort_new->pre = sort_temp;
            sort_temp->next = sort_new;
            while (sort_temp->next != nullptr) {
                pre = sort_temp;
                sort_temp = sort_temp->next;
            }
            delete sort_temp;
            min_time = pre->detail.time;
        }
        temp = temp->next;
    }
}
#undef ull

bool cmp_publish_time(string a,string b) {  // a < b
    for (int i = 0;i < min(a.length(),b.length());i++) {
        if (a[i] < b[i]) return true;
        if (a[i] > b[i]) return false;
    }
    return false; //不相等就false
}

void sort_publish_time(Book *p) {
    Book *temp = p;
    Book *sort_head = new Book;
    sort_head->next = nullptr;
    string max_time = "0", min_time = "99999999999";
    int cnt = 0;
    while (temp->next != nullptr) {
        if (cnt < 10) {
            Book *sort_temp = sort_head;
            bool flag = false;
            while (sort_temp->next != nullptr) {
                if (cmp_publish_time(sort_temp->next->detail.publish_time,temp->detail.publish_time)) {
                    if (cmp_publish_time(max_time,temp->detail.publish_time)) {
                        max_time = temp->detail.publish_time;
                    }//max_time = max(max_time,temp->detail.time);
                    if (cmp_publish_time(temp->detail.publish_time,min_time)) {
                        min_time = temp->detail.publish_time;
                    }
                    Book *sort_new = new Book;
                    sort_new->detail = temp->detail;
                    sort_new->next = sort_temp->next;
                    sort_temp->next->pre = sort_new;
                    sort_new->pre = sort_temp;
                    sort_temp->next = sort_new;
                    flag = true;
                    break;
                }
                sort_temp = sort_temp->next;
            }
            if (!flag) {
                if (cmp_publish_time(temp->detail.publish_time,min_time)) {
                    min_time = temp->detail.publish_time;
                }//min_time = min(min_time,temp->detail.time);
                if (cmp_publish_time(max_time,temp->detail.publish_time)) {
                    max_time = temp->detail.publish_time;
                }
                Book *sort_new = new Book;
                sort_new->detail = temp->detail;  //深拷贝!!
                sort_temp->next = sort_new;
            }
            cnt++;
        } else {
            if (!cmp_publish_time(min_time,temp->detail.publish_time)) continue;
            //if (temp->detail.time <= min_time) continue;
            Book *sort_temp = sort_head;
            while (!cmp_publish_time(sort_temp->next->detail.publish_time,temp->detail.publish_time)) {
                //sort_temp->next->detail.time >= temp->detail.time
                sort_temp = sort_temp->next;
            }
            Book *pre;
            Book *sort_new = new Book;
            sort_new->detail = temp->detail;
            sort_new->next = sort_temp->next;
            sort_temp->next->pre = sort_new;
            sort_new->pre = sort_temp;
            sort_temp->next = sort_new;
            while (sort_temp->next != nullptr) {
                pre = sort_temp;
                sort_temp = sort_temp->next;
            }//删除最后一个（最小的）
            delete sort_temp;
            min_time = pre->detail.publish_time;
        }
        temp = temp->next;
    }
}



























