#ifndef MULTIME_DINAMICA_H
#define MULTIME_DINAMICA_H
#include "LinkedList.h"
#include "Node.h"
#include <iostream>
using namespace std;
class Multime_Dinamica
{

    LinkedList multime;
    int nrElemente;
    public:
         Multime_Dinamica();//constructor initializare
         Multime_Dinamica(Multime_Dinamica &);//constructor copiere
         Multime_Dinamica(LinkedList,int);
        ~Multime_Dinamica();//destructor
         static void removeDuplicates(LinkedList);
         friend Multime_Dinamica operator +(Multime_Dinamica const &, Multime_Dinamica const &);
         friend Multime_Dinamica operator *(Multime_Dinamica const &, Multime_Dinamica const &);
         friend Multime_Dinamica operator -(Multime_Dinamica const &, Multime_Dinamica const &);
         friend istream& operator >>(istream&, Multime_Dinamica &);
         friend ostream& operator <<(ostream&, Multime_Dinamica const &);
         static void describe();

};


#endif // MULTIME_DINAMICA_H
