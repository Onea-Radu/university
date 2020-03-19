#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
#include <iostream>
using namespace std;
class LinkedList
{
    Node* start;
    Node* end;
    int dimensiune;

    public:
         LinkedList();
         LinkedList(LinkedList &);
         ~LinkedList();
         void insert(int);
         bool find(int)const;
         int size()const;
         Node* getStart()const;
         void setStart(Node*);
         Node* getEnd()const;
         void setEnd(Node*);
         friend LinkedList operator +(LinkedList const &, LinkedList const &);
         friend LinkedList operator *(LinkedList const &, LinkedList const &);
         friend LinkedList operator -(LinkedList const &, LinkedList const &);
         friend istream& operator >>(istream&,LinkedList &);
         friend ostream& operator <<(ostream&,LinkedList const &);
};

#endif // LINKEDLIST_H
