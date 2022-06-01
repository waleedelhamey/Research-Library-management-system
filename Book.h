//
// Created by Pc on 5/27/2020.
//

#ifndef RESEARCH_LIBRARY_MANAGEMENT_SYSTEM_BOOK_H
#define RESEARCH_LIBRARY_MANAGEMENT_SYSTEM_BOOK_H
#include <bits/stdc++.h>
#include "nodeQueue.h"
using namespace std;

class Book {
private:
    nodeQueue* head;
    nodeQueue* tail;

public:
    int size;
    string bookName,bookISBN;
    int numberOfCopies;
    Book *next;
//    ~Book (){
//        while (head->next != nullptr) {
//            nodeQueue* temp = head;
//            head = head->next;
//            delete temp;
//        }
//        size=0;
//    }
    void setHead(nodeQueue *newCopy){
        this->head=newCopy;
    }
    void setTail(nodeQueue *newCopy){
        this->tail=newCopy;
    }
    nodeQueue* getHead(){
        return this->head;
    }
    nodeQueue* getTail(){
        return this->tail;
    }
    int libraryInventory(){
        return size;
    }
    void addingBookBorrow(int idx, nodeQueue newCopy){
        if(size==0){//Empty list
            nodeQueue* Copy = new nodeQueue(newCopy);
            head=tail=Copy;

        }
        else if(idx>size){
            cerr<<"Index out of bonds \n";
            return;
        }
        else if(idx == 0)
            insertAtFront(newCopy);
        else if(idx == size){
            nodeQueue* current = head;
            push_back(newCopy,current);
        }
        else{
            int i=0;
            nodeQueue* current = head;
            insertAtCertainPosition(idx,newCopy,i,current);
        }
        size++;
    }
    void push_back(nodeQueue newCopy ,nodeQueue* current){
        if(current->getNext()==NULL){
            nodeQueue* n = new nodeQueue(newCopy);
            current->setNext(n);
            n->setNext(NULL);
            return;
        }
        push_back(newCopy,current->getNext());
    }
    void insertAtFront(nodeQueue newCopy){
        nodeQueue *n = new nodeQueue(newCopy);
        n->setNext(head);
        head = n;

    }
    void insertAtCertainPosition(int idx,nodeQueue newCopy ,int i,nodeQueue*current){
        if(i+1==idx){
            nodeQueue* n = new nodeQueue(newCopy);
            n->setNext(current->getNext());
            current->setNext(n);
            return;
        }
        insertAtCertainPosition(idx,newCopy,i+1,current->getNext());
    }
    void addingBookReturn(int idx) {
        if(size==0){
            cerr<<"Empty list \n";
            return;
        }
        else if(idx==0) {
            nodeQueue* current = head;
            head=head->getNext();
            delete current;
        }
        else if(idx==size-1) {
            nodeQueue* current = head;
            while(current->getNext()!=tail){
                current=current->getNext();
            }
            tail=current;
            tail->setNext(nullptr);
            current=current->getNext();
            delete current;
        }
        else {
            nodeQueue* target = head;
            for(int i=0;i<idx-1;++i){
                target=target->getNext();
            }
            nodeQueue* prev = target;
            target=target->getNext();//Right position
            prev->setNext(target->getNext());
            delete target;
        }
        size--;
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    Book(){
        bookName=bookISBN="";
        numberOfCopies=0;
        head = tail = new nodeQueue();
        size=0;
        next=nullptr;
    }
    Book(const  string & bkName,const  string & bkISBN,
         const  int & noCopies, Book *ptr = nullptr) {
        bookName=bkName;
        bookISBN=bkISBN;
        numberOfCopies=noCopies;
        next=ptr;
    }
    Book(Book *book) {
        bookName=book->bookName;
        bookISBN=book->bookISBN;
        numberOfCopies=book->numberOfCopies;
        head=book->getHead();
        tail=book->getTail();
        size=book->size;
        next=book->next;
    }
    void operator=( const Book* book){
        bookName=book->bookName;
        bookISBN=book->bookISBN;
        numberOfCopies=book->numberOfCopies;
        next=book->next;
    }
    Book* getNext(){
        return next;
    }
    void setNext(Book* newBook){
        next=newBook;
    }
    friend ostream& operator<< ( ostream &stream, Book* b ) {
        cout<<b->bookName<<' '<<b->bookISBN<<' '<<b->numberOfCopies<<' '<<endl;
        nodeQueue* temp = b->getHead();
        while(temp!= nullptr){
            cout<<temp;
            temp=temp->getNext();
        }
        return stream;
    }
};


#endif //RESEARCH_LIBRARY_MANAGEMENT_SYSTEM_BOOK_H
