//Marco Barozzi 167018
#include <iostream>
#include <string>
#include <map>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;


bool under5(const int i){ return i<5;}

int main(int argc, char** argv) {
	//init list
	list<int> l = {1,2,3,4,5,6,7,8,9};
	//init vector
	vector<int> v(10);
	iota(v.begin(), v.end(), 0);
	
	//se il conteuto fosse un vector
	auto iterV = remove_if (v.begin(), v.end(), under5);
	v.erase(iterV, v.end());
	for(const& item : v){
		cout << "["<<item<<"]";
	}
	cout << endl;

	
	//se in contenuto fosse una lista (uguale a vector): uso unica espressione
	l.erase( remove_if(l.begin(), l.end(), under5) , l.end());
	for(const& item : l){
		cout << "["<<item<<"]";
	}
	cout << endl;
	
	
	return 0;
}

