#include "LinkedList.h"
#include "Node.h"
#include <iostream>
using namespace std;
LinkedList::LinkedList()
{
    start = 0;
    end = 0;
    dimensiune = 0;

}
LinkedList::LinkedList(LinkedList &lista){
    start = 0;
    end = 0;
    dimensiune = 0;

    Node* s = lista.start;
    while(s!=0)
    {
	insert(s->getData());
        s = s->getNext();
    }
}

LinkedList::~LinkedList()
{
    Node* s = start;
    while(s!=0)
    {
        Node* adrCurr = s->getNext();
        delete(s);
        s = adrCurr;
    }
}
void LinkedList::setStart(Node* n){
    start = n;
}
void LinkedList::setEnd(Node* n){
    end = n;
}
Node* LinkedList::getStart()const{
    return start;
}
Node* LinkedList::getEnd()const{
    return end;
}

void LinkedList::insert(int info){
    if(dimensiune == 0){
        start = new Node(info);
        end = start;
        dimensiune = 1;
    }else{
        Node* s = new Node(info);
        end->setNext(s);
        end = s;
        dimensiune++;
    }
}

bool LinkedList::find(int info)const{
    Node* s = start;
    while(s!=0){
        if(s->getData() == info) return true;
        s = s->getNext();
    }
    return false;
}
int LinkedList::size()const{
    return dimensiune;
}

LinkedList operator +(LinkedList const &list1, LinkedList const &list2){
    LinkedList result;
    result = list1;
    Node* s = list2.getStart();
    while(s!=0){
        result.insert(s->getData());
        s = s->getNext();
    }
    return result;
}
LinkedList operator *(LinkedList const &list1, LinkedList const &list2){
    LinkedList result;
    Node* s = list1.getStart();
    while(s!=0){
        if(list2.find(s->getData()))
        {
            result.insert(s->getData());
        }
    }
    return result;

}
LinkedList operator -(LinkedList const &list1, LinkedList const &list2){
    LinkedList result;
    Node* s = list1.getStart();
    while(s!=0){
        if(!list2.find(s->getData()))
        {
            result.insert(s->getData());
        }
    }
    return result;
}
istream& operator >>(istream& f,LinkedList &lista){
    int n,j;
    f>>n;
    for(int i=0;i<n;i++){
        f>>j;
        lista.insert(j);
    }
    return f;
}
ostream& operator << (ostream& g,LinkedList const &lista){
    Node* s = lista.getStart();
    while(s!=0){
        g<<s->getData();
        g<<" ";
        s = s->getNext();
    }

    g<<endl;
    return g;
}

