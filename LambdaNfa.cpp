#include <iostream>
#include <map>
#include <string>
#include <set>
#include <fstream>
using namespace std;

class NFA
{
	set<int> Q, F;
	set<char> Sigma;
	set<int> Q0;
	map<pair<int, char>, set<int>> delta;

public:
	NFA() { }
	NFA(set<int> Q, set<char> Sigma, map<pair<int, char>, set<int>> delta, set<int> Q0, set<int> F)
	{
		this->Q = Q;
		this->Sigma = Sigma;
		this->delta = delta;
		this->Q0 = Q0;
		this->F = F;
	}

	set<int> getQ() const { return this->Q; }
	set<int> getF() const { return this->F; }
	set<char> getSigma() const { return this->Sigma; }
	set<int> getInitialStates() {  return lTransitions(this->Q0); }
	map<pair<int, char>, set<int>> getDelta() const { return this->delta; }

	friend istream& operator >> (istream&, NFA&);

	bool isFinalState(set<int>);
	set<int> deltaStar(set<int>, string);
	set<int> lTransitions(set<int>);
};

bool NFA::isFinalState(set<int> q)
{
	for(auto i:q)

	if(F.find(i) != F.end())
        return true;
    return false;
}

set<int> NFA::deltaStar(set<int> q, string w)
{
	set<int> new_q;
	for(auto i: q)
    {for(auto j:delta[{i,(char)w[0]}])
	  new_q.insert(j);
}

	if (w.length() == 1&& w=="_")
	{
		return new_q;
	}
	else if (w.length() == 1)
	{
		return lTransitions(new_q);
	}

    new_q=lTransitions(new_q);
	return deltaStar(new_q, w.substr(1, w.length() - 1));
}

set<int> NFA::lTransitions(set<int> q)
{
 set<int> new_q;
 new_q.insert(q.begin(),q.end());

 bool ok=true;
 while(ok)
 {ok=false;
 for(auto i:deltaStar(new_q,"_"))
 if (new_q.find(i)==new_q.end())
 {
     ok=true;
     new_q.insert(i);
 }
 }
 return new_q;
}







istream& operator >> (istream& f, NFA& M)
{
	int noOfStates;
	f >> noOfStates;
	for (int i = 0; i < noOfStates; ++i)
	{
		int q;
		f >> q;
		M.Q.insert(q);
	}

	int noOfLetters;
	f >> noOfLetters;
	for (int i = 0; i < noOfLetters; ++i)
	{
		char ch;
		f >> ch;
		M.Sigma.insert(ch);
	}

	int noOfTransitions;
	f >> noOfTransitions;
	for (int i = 0; i < noOfTransitions; ++i)
	{
		int s, d;
		char ch;
		f >> s >> ch >> d;
		M.delta[{s, ch}].insert(d);
	}
int noOfInitialStates;
	f >> noOfInitialStates;
	for (int i = 0; i < noOfInitialStates; ++i)
	{
		int q;
		f>>q;
		M.Q0.insert(q);


	}

	int noOfFinalStates;
	f >> noOfFinalStates;
	for (int i = 0; i < noOfFinalStates; ++i)
	{
		int q;
		f >> q;
		M.F.insert(q);
	}

	return f;
}

int main()
{
	NFA M;

	ifstream fin("nfa.txt");
	fin >> M;
	fin.close();

	for(auto i:M.getInitialStates())
        cout<<i<<" ";
    cout<<endl;


	auto lastStates = M.deltaStar(M.getInitialStates(), "ab");



    for(auto i:lastStates)
        cout<<i<<" ";

	if (M.isFinalState(lastStates))
	{
		cout << "Cuvant acceptat";
	}
	else
	{
		cout << "Cuvant respins";
	}

	return 0;
}
