#include "Node.h"

Node::Node(int d)
{
    data = d;
    next = 0;
}
Node::Node(Node &nod){
    data = nod.data;
    next = nod.next;
}

Node::Node(int d, Node* n)
{
    data = d;
    next = n;
}

int Node::getData()const{
    return data;
}
Node* Node::getNext()const{
    return next;
}
void Node::setData(int d){
   data = d;
}
void Node::setNext(Node* n){
    next = n;
}
