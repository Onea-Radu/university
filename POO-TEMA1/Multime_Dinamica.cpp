#include "Multime_Dinamica.h"
#include "LinkedList.h"
#include "Node.h"
#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>
#include <fstream>
using namespace std;
ifstream fin("date.txt");
Multime_Dinamica::Multime_Dinamica()
{
    nrElemente = 0;
}
Multime_Dinamica::Multime_Dinamica(Multime_Dinamica &multi){
    multime = multi.multime;
    nrElemente = multi.nrElemente;
}
Multime_Dinamica::Multime_Dinamica(LinkedList l,int d){
    multime = l;
    nrElemente = d;
}
Multime_Dinamica::~Multime_Dinamica()
{
            delete(&multime);
            delete(&nrElemente);
}
void Multime_Dinamica::removeDuplicates(LinkedList lista){
    set<int> s;
    //LinkedList result = *(new LinkedList());
    Node* n = lista.getStart();
    s.insert(n->getData());
    Node* nod = n->getNext();
    while(nod!=0){
        if(s.find(nod->getData()) != s.end())
        {
            n->setNext(nod->getNext());
        }
        else
            {
              s.insert(nod->getData());
              n = n->getNext();
            }
        nod = n->getNext();
    }
}
Multime_Dinamica operator +(Multime_Dinamica const &multi1, Multime_Dinamica const &multi2){
    LinkedList l;
    l = multi1.multime + multi2.multime;
    Multime_Dinamica::removeDuplicates(l);
    Multime_Dinamica m(l,l.size());
    return m;
}
Multime_Dinamica operator *(Multime_Dinamica const &multi1, Multime_Dinamica const &multi2){
    LinkedList l;
    l = multi1.multime * multi2.multime;
    Multime_Dinamica::removeDuplicates(l);
    Multime_Dinamica m(l,l.size());
    return m;
}
Multime_Dinamica operator -(Multime_Dinamica const &multi1, Multime_Dinamica const &multi2){
    LinkedList l;
    l = multi1.multime - multi2.multime;
    Multime_Dinamica::removeDuplicates(l);
    Multime_Dinamica m(l,l.size());
    return m;
}
istream& operator >>(istream& f, Multime_Dinamica &m){
    f>>m.multime;
    Multime_Dinamica::removeDuplicates(m.multime);
    m.nrElemente = m.multime.size();
    return f;
}
ostream& operator <<(ostream& f, Multime_Dinamica const &m){
    f<<m.multime;
    return f;
}
void Multime_Dinamica::describe(){
    int n;
    /* Multime_Dinamica m1;
     Multime_Dinamica m2;
     Multime_Dinamica m3;
     cin>>m1;
     cin>>m2;
     cin>>m3;
     cout<<m1;
     cout<<m2;
     cout<<m3;*/
    fin>>n;
    Multime_Dinamica* obiecte[5];
    for(int i=0;i<n;i++){
        Multime_Dinamica *m = new Multime_Dinamica();
        fin>>(*m);
        obiecte[i]=m;
        cout<<*obiecte[i];
    }
    cout<<'\n';
    for(int j=0;j<n;j++){
        cout<<*obiecte[j];
    }

   /* for(int j=0;j<n;j++){
        //cout<<obiecte[j];
       // cout<<" ";
        cout<<*obiecte[j];
    }*/
    /*cout<<obiecte[0]+obiecte[1];
    cout<<obiecte[0]*obiecte[1];
    cout<<obiecte[0]-obiecte[1];*/
}
