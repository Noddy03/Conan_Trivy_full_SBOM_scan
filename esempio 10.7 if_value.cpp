#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

bool isEven(int n) {
    return (n % 2 == 0);
}


int main() {
	//vector valori assegnati 
	vector<int> v = { 0,1,2,5,5,6 };	
	for(auto item: v){ cout << "["<<item<<"]"; }
	cout << endl;
	// conta gli elementi pari
	cout << "Even numbers: ";
	cout << count_if(v.begin(), v.end(), isEven) << endl;
	
	// trova il primo elemento pari
	auto it = find_if(v.begin(), v.end(), isEven);
    cout << "First Even number: " << *it << endl;
  
  	for(auto item: v){ cout << "["<<item<<"]"; }
	cout << endl;
	  
    cout << "Remove first Even number" << endl;
    v.erase( remove_if (v.begin(), v.end(), isEven) );
	for(auto item: v){ cout << "["<<item<<"]"; }
	cout << endl;
		
	//solo nel caso di liste uso del metodo remove_if
	list<int> w = { 0,1,2,5,5,6 };	
	for(auto item: w){ cout << "["<<item<<"]"; }
	cout << endl;
	w.remove_if (isEven); 
	for(auto item: w){ cout << "["<<item<<"]"; }
	cout << endl;
	
    return 0;
}
