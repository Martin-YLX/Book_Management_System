#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

class BookLink;
class SortLink;

struct Tag {
    int cnt;
    string name;
    Tag* pre;
    Tag* next;
};

#define ull unsigned long long

class Book {
private:
    ull id;
    string title;
    string isbn_issn;
    string author;
    string publish;
    string publishTime;
    string price;
    ull pages;
    string description;
    ull time;
    bool flagBorrow;

    static Book createBookFromString(const string& line);

    Tag* head;

public:
    Book(); // 初始化
    Book(ull id,string tit, string isbn, string auth, string pub, string pub_time, ull pages, string pri, string des, ull tim); // 插入内容
    void insertTag(string s); // 增加 tag
    void deleteTag(string s); // 删除 tag
    void addTime(int x); // 修改借阅次数

    bool operator < (const Book& other) const;

    ull getID() const;
    string getTitle() const;
    string getIsbnIssn() const;
    string getAuthor() const;
    string getPublish() const;
    string getPublishTime() const;
    string getPrice() const;
    ull getPages() const;
    ull getTime() const;
    string getDes() const;
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
    //void readXlsFile(const string fileName);
    //void readCsvFile(const string fileName);

    BookLink(); // 初始化
    void print(); // 输出全部信息
    void allPrint();
    void insert(Book in); // 插入 Detail
    void insertPre(BookLink* newBook);
    void insertNext(BookLink* newBook);
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

class SortLink {
private:
    BookLink* object;
    SortLink* pre;
    SortLink* next;
public:

};















































