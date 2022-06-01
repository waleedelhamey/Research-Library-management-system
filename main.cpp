#include <bits/stdc++.h>
#include "LinkedList.h"
#include "Book.h"
#include "nodeQueue.h"
using namespace std;
int main() {
    LinkedList* myLinkedList = new LinkedList() ;

    Book* book1= new Book("DS","12",3);
    nodeQueue* copy1=new nodeQueue("1/1/2015","Kamel","225445",15,true);
    nodeQueue* copy2=new nodeQueue("1/1/2015","waleed","225445",15,true);
    nodeQueue* copy3=new nodeQueue("1/1/2015","hima","225445",15,true);
    book1->addingBookBorrow(0,copy1);
    book1->addingBookBorrow(0,copy2);
    book1->addingBookBorrow(0,copy3);
    myLinkedList->insert(0,book1);
    /////////////////////////////////////////////////////////////////////////////////////////////
    Book* book2= new Book("AL","78",1);
    nodeQueue* copy4=new nodeQueue("2/3/2015","alaa","64645",15,false);
    nodeQueue* copy5=new nodeQueue("2/3/2015","bomdien","87798",15,true);
    nodeQueue* copy6=new nodeQueue("2/3/2015","sanofa","12313",15,false);
    book2->addingBookBorrow(0,copy4);
    book2->addingBookBorrow(0,copy5);
    book2->addingBookBorrow(0,copy6);
    myLinkedList->insert(0,book2);
    /////////////////////////////////////////////////////////////////////////////////////////////
    Book* book3= new Book("FS","34",2);
    nodeQueue* copy7=new nodeQueue("6/6/2022","3b3z","2138",15,false);
    nodeQueue* copy8=new nodeQueue("6/6/2022","taha","21387",15,true);
    nodeQueue* copy9=new nodeQueue("6/6/2022","ziad","+45+78",15,false);
    book3->addingBookBorrow(0,copy7);
    book3->addingBookBorrow(0,copy8);
    book3->addingBookBorrow(0,copy9);
    myLinkedList->insert(0,book3);
    /////////////////////////////////////////////////////////////////////////////////////////////
    Book* book4= new Book("SS","55",6);
    nodeQueue* copy10=new nodeQueue("7/7/2021","7a7a","3123",15,true);
    nodeQueue* copy11=new nodeQueue("7/7/2021","ta7a","15975",15,true);
    nodeQueue* copy12=new nodeQueue("7/7/2021","kaka","357648",15,false);
    book4->addingBookBorrow(0,copy10);
    book4->addingBookBorrow(0,copy11);
    book4->addingBookBorrow(0,copy12);
    myLinkedList->insert(0,book4);
    /////////////////////////////////////////////////////////////////////////////////////////////
    Book* temp  = myLinkedList->getHead();
    while(temp!= nullptr){
        cout<<temp;
        temp=temp->getNext();
    }
    return 0;
}
