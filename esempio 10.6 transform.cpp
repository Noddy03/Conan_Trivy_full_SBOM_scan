#include <iostream>
#include <iterator>   // std::ostream_iterator
#include <vector>
#include <list>
#include <random>     // std::mt19937 & std::default_random_engine
#include <functional> // std::multiplies
#include <numeric>    // std::iota, std::accumulate, std::transform etc.
#include <algorithm>

using namespace std;
// funzione predicato per numeri interi
bool isEven(int n) {
    return (n % 2 == 0);
}
bool isOdd(int n) {
    return (n % 2 != 0);
}

void stampaConst(const vector<int>& v){
	for (const auto& item : v) { cout << "["<< item << "] ";  } 
	cout << endl;	
}
void stampaConst(const list<bool>& v){
	for (const auto& item : v) { cout << "["<< item << "] ";  } 
	cout << endl;	
}

void cambiaDispari(vector<int>& v) {
transform(v.begin(),v.end(),v.begin(), [](int item){
		if ( item%2 != 0 ){ return 0; }
		return item;
	});
}
void cambiaPari1(vector<int>& v){
transform(v.begin(),v.end(),v.begin(), [](int item){
		if(!(item%2)){
			return 0;
		}else{
			return item;
		}
	});
}
void cambiaPari2(vector<int>& v){
replace_if(v.begin(),v.end(), [](int item) -> bool { return item%2==0; }, 0);
}


int main(){
	vector<int> v = { 3,8,1,2,7,0,4 };	//vector valori assegnati
	list<bool> l(v.size());				//list con dimensione assegnata
    // popola la lista l con valori booleani true/false 
	//se il corrispondente elemento in v è pari/dispari.
    transform(v.begin(), v.end(), l.begin(), isEven);
    stampaConst(v);
    stampaConst(l);
    // conta il numero di elementi pari in v
    cout << "Even numbers: " << count_if(v.begin(), v.end(), isEven) << "\n";
    // calcola il numero di elementi dispari in v (not_fn richiede C++17)
    cout << "Odd numbers: "  << count_if(v.begin(), v.end(), isOdd) << "\n";
    
    stampaConst(v);
	//cambiaDispari(v);
	//cambiaPari1(v);
	cambiaPari2(v);
    stampaConst(v);
    
    return 0;
}
