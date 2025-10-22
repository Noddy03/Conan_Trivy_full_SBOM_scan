#include <iostream>
#include <iterator>   // std::ostream_iterator
#include <list>
#include <vector>
#include <random>     // std::mt19937 & std::default_random_engine
#include <functional> // std::multiplies
#include <numeric>    // std::iota, std::accumulate, std::transform etc.
#include <algorithm>

using namespace std;

/*
 passo list by reference e con auto lo scorro pure per refence: 
 se metto item++ nel ciclo posso modificare il contenuto
 */
void stampa(list<int>& v){
	for (auto& item : v) { cout << "["<< item << "] "; } 
	cout << endl;	
}
/*
 passo list by const reference e con const auto lo scorro: 
 nel ciclo NON posso modificare il contenuto
 NOTA era sufficiente mettere const list<int>& v
 */
void stampaConst(const list<int>& v){
	for (const auto& item : v) { cout << "["<< item << "] ";  } 
	cout << endl;	
}
int myfunction (int x, int y) {return x*y;}
// random generator function:
int myrandom (int i) { return rand()%i;}

bool compare_a( const int& first, const int& second )
{ return first < second ; }

bool compare_d( const int& first, const int& second )
{ return first > second ;  }

int main(){
    list<int> l15(15);	//vector con 15 elementi
    list<int> l = { 0,1,0,1,0,1,0,1 };	//vector valori assegnati
   	stampaConst(l); 	//stampo contenuto vector
    // inizializza la lista l con numeri progressivi a partire da 4
    iota(l.begin(), l.end(), 4);
    stampa(l);

    // copia gli elementi di v in una sequenza di valori per lo standard output separati da uno spazio
    copy(l.begin(), l.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    // stampa la posizione a cui si trova il valore 7 in l
    auto found = find(l.begin(), l.end(), 7);
    if (found != l.end()) {
    	//distance: non valido per list!!
        cout << "Element 7 found at position " << distance(l.begin(), found) << "\n";
    }

    // calcola la somma degli elementi di l
    cout << "Sum: " << accumulate(l.begin(), l.end(), 0) << "\n";
    // calcola il prodotto degli elementi di l
    cout << "Prod: " << accumulate(l.begin(), l.end(), 1, myfunction) << "\n";
 
    // riposiziona gli elementi di l in ordine decrescente
    //sort(l.rbegin(), l.rend()); valido solo per i vector
    l.sort();
	cout << "Sort: "; stampaConst(l);  
   
    l.sort(compare_d) ; // sort on descending	
    cout << "Sort: "; stampaConst(l); 	
	l.sort(compare_a) ; // sort on ascending
	cout << "Sort: "; stampaConst(l); 

	// riposiziona gli elementi di l in ordine casuale
	// copiare in un vector i valori della lista
	vector<int> temp(l.begin(), l.end());
	// riposiziona gli elementi del vector temp in ordine casuale
	random_shuffle(temp.begin(), temp.end());
	// copiare (shuffled) vector nella list
	copy(temp.begin(), temp.end(), l.begin());
	cout << "Shuffle: "; stampaConst(l); 
 
    return 0;
}
