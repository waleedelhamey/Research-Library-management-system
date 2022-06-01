//
// Created by Pc on 5/26/2020.
//

#ifndef RESEARCH_LIBRARY_MANAGEMENT_SYSTEM_LINKEDLIST_H
#define RESEARCH_LIBRARY_MANAGEMENT_SYSTEM_LINKEDLIST_H
#include <bits/stdc++.h>
#include "Book.h"
using namespace std;
class LinkedList {
public:
    LinkedList(){
        head = tail = new Book();
        size=0;
    }
    ~LinkedList (){
        while (head->next != nullptr) {
            Book* temp = head;
            head = head->next;
            delete temp;
        }
        size=0;
    }
    void setHead(Book *newBook){
        this->head=newBook;
    }
    void setTail(Book *newBook){
        this->tail=newBook;
    }
    Book* getHead(){
        return this->head;
    }
    Book* getTail(){
        return this->tail;
    }
    int getSize(){
        return size;
    }
    void insert(int idx, Book* book){
        if(size==0){//Empty list
            Book* newBook = new Book(book);
            head=tail=newBook;
        }
        else if(idx>size){
            cerr<<"Index out of bonds \n";
            return;
        }
        else if(idx == 0)
            insertAtFront(book);
        else if(idx == size){
            Book* current = head;
            push_back(book,current);
        }
        else{
            int i=0;
            Book* current = head;
            insertAtCertainPosition(idx,book,i,current);
        }
        size++;
    }
    void push_back(Book book ,Book* current){
        if(current->getNext()==NULL){
            Book* n = new Book(book);
            current->setNext(n);
            n->setNext(NULL);
            return;
        }
        push_back(book,current->getNext());
    }
    void insertAtFront(Book book){
        Book *n = new Book(book);
        n->setNext(head);
        head = n;


    }
    void insertAtCertainPosition(int idx,Book book ,int i,Book*current){
        if(i+1==idx){
            Book* n = new Book(book);
            n->setNext(current->getNext());
            current->setNext(n);
            return;
        }
        insertAtCertainPosition(idx,book,i+1,current->getNext());
    }

    void erase(int idx) {
        if(size==0){
            cerr<<"Empty list \n";
            return;
        }
        else if(idx==0) {
            Book* current = head;
            head=head->getNext();
            delete current;
        }
        else if(idx==size-1) {
            Book* current = head;
            while(current->getNext()!=tail){
                current=current->getNext();
            }
            tail=current;
            tail->setNext(nullptr);
            current=current->getNext();
            delete current;
        }
        else {
            Book* target = head;
            for(int i=0;i<idx-1;++i){
                target=target->getNext();
            }
            Book* prev = target;
            target=target->getNext();//Right position
            prev->setNext(target->getNext());
            delete target;
        }
        size--;
    }
private:
    Book* head;
    Book* tail;
    int size;
};
#endif //RESEARCH_LIBRARY_MANAGEMENT_SYSTEM_LINKEDLIST_H
