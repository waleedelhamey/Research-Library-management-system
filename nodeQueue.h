//
// Created by Pc on 5/27/2020.
//

#ifndef RESEARCH_LIBRARY_MANAGEMENT_SYSTEM_NODEQUEUE_H
#define RESEARCH_LIBRARY_MANAGEMENT_SYSTEM_NODEQUEUE_H
#include <bits/stdc++.h>
#include "Book.h"
using namespace std;

class nodeQueue {
public:
    string copyDate,Borrower,borrowDate;
    bool isBorrow;
    int daysToReturn;
    nodeQueue *next;
    nodeQueue(){
        copyDate=Borrower=borrowDate="";
        daysToReturn=0;
        isBorrow=false;
        next=nullptr;
    }
    nodeQueue(  string  cpDate,  string borrower,  string brDate,  int dtr,
                bool  isborrow=false, nodeQueue *ptr = nullptr) {
        copyDate=cpDate;
        Borrower=borrower;
        borrowDate=brDate;
        daysToReturn=dtr;
        isBorrow=isborrow;
        next=ptr;
    }
    nodeQueue(nodeQueue *newCopy) {//copy constructor
        copyDate=newCopy->copyDate;
        Borrower=newCopy->Borrower;
        borrowDate=newCopy->borrowDate;
        daysToReturn=newCopy->daysToReturn;
        isBorrow=newCopy->isBorrow;
        next=newCopy->next;
    }
    void operator=( const nodeQueue* newCopy){
        copyDate=newCopy->copyDate;
        Borrower=newCopy->Borrower;
        borrowDate=newCopy->borrowDate;
        daysToReturn=newCopy->daysToReturn;
        isBorrow=newCopy->isBorrow;
        next=newCopy->next;
    }
    nodeQueue* getNext(){
        return next;
    }
    void setNext(nodeQueue* newCopy){
        next=newCopy;
    }
    friend ostream& operator<< ( ostream &stream, nodeQueue* b ) {
        cout<<b->copyDate<<' '<<b->Borrower<<' '<<b->borrowDate<<' '<<b->daysToReturn<<' '<<b->isBorrow<<' '<<endl;
        return stream;
    }
};


#endif //RESEARCH_LIBRARY_MANAGEMENT_SYSTEM_NODEQUEUE_H
