#pragma once

#include <iostream>
using namespace std;

struct  Tag {
    int num;
    string name;
    Tag *pre;
    Tag *next;
}*sum;

#define ull unsigned long long
struct Detail {
    string name;   //书本名称
    string isbn_issn;   //isbn号 issn号
    string author;   //作者
    string publish;   //出版社
    string publish_time;   //出版时间
    string price;   //价格
    ull time;  //借阅次数
    Tag *head = (Tag *) malloc(sizeof(Tag));

    Detail(); //初始化
    Detail(string nam,string isbn,string auth,string pub,string pub_time,string pri,ull tim); //插入内容
    void insert_tag(Tag *p,string s); //增加tag
    void delete_tag(Tag *p,string s); //删除tag
    void add_time(int x);   //修改借阅次数
};
#undef ull

class Book {
private:
    int num;
    Detail detail;
public:
    Book *pre;
    Book *next;

    Book(); //初始化
    void print(); //输出全部信息
    void insert(Detail in); //插入Detail
    bool check(string isbn); //验证isbn issn
    //构建
    Book *head = (Book *)malloc(sizeof(Book)); //总目录 头指针
    friend void change_book(Book *p); //修改book
    friend void insert_book(Book *p,Detail in); //增加book
    friend void delete_book(Book *p,string isbn); //减少book
    //查询
    friend void search_book(Book *p); //寻找book
    friend void search_name(Book *p,Book *now);
    friend void search_isbn(Book *p,Book *now);
    friend void search_author(Book *p,Book *now);
    friend void search_publish(Book *p,Book *now);
    friend void search_publish_time(Book *p,Book *now);
    friend void search_price(Book *p,Book *now);
    friend void search_tag(Book *p,Book *now);
    //修改
    friend void change_name(Book *now);
    friend void change_isbn(Book *now);
    friend void change_author(Book *now);
    friend void change_publish(Book *now);
    friend void change_publish_time(Book *now);
    friend void change_price(Book *now);
    //排序



};//todo:返回上级目录



// todo: 字典序排序 借阅次数前10 出版时间前10 tag数目前10