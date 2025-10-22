#include <iostream>
#include <iterator>   // std::ostream_iterator
#include <vector>
#include <random>     // std::mt19937 & std::default_random_engine
#include <functional> // std::multiplies
#include <numeric>    // std::iota, std::accumulate, std::transform etc.
#include <algorithm>

using namespace std;

/*
 passo vector by reference e con auto lo scorro pure per refence: 
 se metto item++ nel ciclo posso modificare il contenuto
 */
void stampa(vector<int>& v){
	for (auto& item : v) { cout << "["<< item << "] "; } 
	cout << endl;	
}
/*
 passo vector by const reference e con const auto lo scorro: 
 nel ciclo NON posso modificare il contenuto
 NOTA era sufficiente mettere const vector<int>& v
 */
void stampaConst(const vector<int>& v){
	for (const auto& item : v) { cout << "["<< item << "] ";  } 
	cout << endl;	
}

int myfunction (int x, int y) {return x*y;}
// random generator function:
int myrandom (int i) { return rand()%i;}

int main(){
    //vector<int> v(15);	//vector con 15 elementi
    vector<int> v = { 0,1,0,1,0,1,0,1 };	//vector valori assegnati
    //list<int> v = { 0,1,0,1,0,1,0,1 };	//list valori assegnati
   	stampaConst(v); 	//stampo contenuto vector
    // inizializza il vettore v con numeri progressivi a partire da 4
    iota(v.begin(), v.end(), 4);
    stampa(v);

    // copia gli elementi di v in una sequenza di valori per lo standard output separati da uno spazio
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    //copio gli elemento su un altro vector (non valido per list)
  	vector<int> vcopy (3);
  	copy ( v.begin(), v.begin()+3, vcopy.begin() );
	cout << "contenuto di vcopy:";
	stampaConst(vcopy);
    
    // stampa la posizione a cui si trova il valore 5 in v
    auto found = find(v.begin(), v.end(), 5);
    if (found != v.end()) {
    	//distance: non valido per list!!
        cout << "Element 5 found at position " << distance(v.begin(), found) << "\n";
    }

    // calcola la somma degli elementi di v
    cout << "Sum: " << accumulate(v.begin(), v.end(), 0) << "\n";
    // calcola il prodotto degli elementi di v
    cout << "Prod: " << accumulate(v.begin(), v.end(), 1, myfunction) << "\n";

    // riposiziona gli elementi di v in ordine decrescente
    sort(v.rbegin(), v.rend());
	cout << "Sort: "; stampaConst(v);  	
	
    // riposiziona gli elementi di v in ordine crescente
    sort(v.begin(), v.end());
	cout << "Sort: "; stampaConst(v); 	
	
	// riposiziona gli elementi di v in ordine casuale
	shuffle (v.begin(), v.end(), default_random_engine());
	cout << "Shuffle: "; stampaConst(v); 
	// using myrandom:
  	random_shuffle (v.begin(), v.end(), myrandom);
	cout << "random_Shuffle: "; stampaConst(v); 
	// cambia l'ordine degli elementi di v in modo casuale
    shuffle(v.begin(), v.end(), mt19937{random_device{}()});
    cout << "Shuffle Mersenne Twister: "; stampaConst(v); 
    
    return 0;
}
