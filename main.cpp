#include <iostream>
#include"BookLink.h"
#include"Person.h"
#include"User.h"
using namespace std;
int main() {
    Book A = {1111,"111","1099","wang","qq","2001",2,"23","sd",111};
    Book B = {2222,"222","1099","wang","qq","2001",2,"23","sd",111};
    Book C = {3333,"333","1099","wang","qq","2001",2,"23","sd",111};
    Book d = {4444,"444","1099","wang","qq","2001",2,"23","sd",111};
    //   Book f={"222","1093","wang","oo","1930","iii",100};
    BookLink* headMain = new BookLink;
    headMain->insertBook(A);
    headMain->insertBook(B);
    headMain->insertBook(C);
    headMain->insertBook(d);
    //   headMain->insertBook(f);
//    headMain->allPrint();
//    headMain->sortPublishTime();
//    headMain->sortTime();
//    headMain->allPrint();
//Person a("wa","122");
    //     a.searchBook(headMain);
//    for(int i=0;i<3;i++)
//    {
//        headMain->insertAllTag("history");
//    }
//    for(int i=0;i<2;i++)
//    {
//        headMain->insertAllTag("english");
//    }
//    for(int i=0;i<4;i++)
//    {
//        headMain->insertAllTag("chinese");
//    }
//    headMain->insertAllTag("math");
//    headMain->sortTag();
//    User u("wu","1233",1000);
//    u.searchBook(headMain);
//    headMain->allPrint();
//    u.print();
//    u.borrowBook(headMain);
//    u.returnBook();
    Admin ad("wang","11112");
    User ua("xiao ming","1000",100);
    User ub("xiao ming","1000",100);
    User uc("xiao ming","1000",300);
    User ud("xiao ming","1000",400);
    User*headuser =new User;
    ad.insertUser(headuser);
    ad.insertUser(headuser);
    ad.insertUser(headuser);
    User*tem=headuser;
    while(tem->getNext()!= nullptr)
    {
        tem->getNext()->print();
        tem=tem->getNext();
    }
    ad.deleteUser(headuser,1);
    tem=headuser;
    while(tem->getNext()!= nullptr)
    {
        tem->getNext()->print();
        tem=tem->getNext();
    }
    return 0;
}
