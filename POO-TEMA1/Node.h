#ifndef NODE_H
#define NODE_H


class Node
{
    int data;
    Node* next;
    public:
       Node(int);
       Node(int, Node*);
       Node(Node &);
       int getData()const;
       void setData(int);
       Node* getNext()const;
       void setNext(Node*);
};

#endif // NODE_H
