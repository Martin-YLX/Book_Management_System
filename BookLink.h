#pragma once

#include <iostream>
using namespace std;

class BookLink;

struct Tag {
    int cnt;
    string name;
    Tag* pre;
    Tag* next;
};

#define ull unsigned long long

class Book {
private:
    string title;
    string isbn_issn;
    string author;
    string publish;
    string publishTime;
    string price;
    ull time;
    bool flagBorrow;
    Tag* head;

public:
    Book(); // 初始化
    Book(string tit, string isbn, string auth, string pub, string pub_time, string pri, ull tim); // 插入内容
    void insertTag(string s); // 增加 tag
    void deleteTag(string s); // 删除 tag
    void addTime(int x); // 修改借阅次数

    string getTitle() const;
    string getIsbnIssn() const;
    string getAuthor() const;
    string getPublish() const;
    string getPublishTime() const;
    string getPrice() const;
    ull getTime() const;
    bool getFlagBorrow() const;

    Tag* getHead() const;

    friend class BookLink;
};

class BookLink {
private:
    int num;
    Book book;
    BookLink* pre;
    BookLink* next;
    Tag* allTag;

public:
    BookLink(); // 初始化
    void print(); // 输出全部信息
    void allPrint();
    void insert(Book in); // 插入 Detail
    bool check(string isbn); // 验证 isbn issn
    // 构建
    BookLink* getPre();
    BookLink* getNext();
    Book getBook();
    void insertBook(Book in); // 增加 Book
    void deleteBook(string isbn); // 减少 Book
    // 查询
    void searchBook(BookLink*& headReturn); // 寻找 Book
    void searchName(BookLink*& now); // 按名称查询
    void searchIsbn(BookLink*& now); // 按 ISBN 查询
    void searchAuthor(BookLink*& now); // 按作者查询
    void searchPublish(BookLink*& now); // 按出版社查询
    void searchPublishTime(BookLink*& now); // 按出版时间查询
    void searchPrice(BookLink*& now); // 按价格查询
    void searchTag(BookLink*& now); // 按标签查询
    // 修改
    void changeTitle(); // 修改名称
    void changeIsbn(); // 修改 ISBN
    void changeAuthor(); // 修改作者
    void changePublish(); // 修改出版社
    void changePublishTime(); // 修改出版时间
    void changePrice(); // 修改价格
    void changeFlagBorrow(bool f); // 修改是否借阅
    // 排序
    void sortTime(); // 按借阅次数排序
    static bool cmpPublishTime(string a, string b); // 比较出版时间
    void sortPublishTime(); // 按出版时间排序
    void merge(BookLink*& head1, BookLink*& head2); // 合并两个链表
    void sortLexico(); // 字典序排序
    //标签
    Tag* getAllTagHead() const;
    void insertAllTag(string s); //该tag书籍加一
    void deleteAllTag(string s); //该tag书籍减一
    void sortTag(); //最受欢迎的前三个tag
};
