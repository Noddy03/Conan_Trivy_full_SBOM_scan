#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <random>     // std::default_random_engine
#include <functional> // std::multiplies

using namespace std;

class Dati{
private:
	int valore;
public:
	Dati(int v) {
		valore = v; 
	}		
	friend ostream& operator <<(ostream& os, const Dati& d);
	bool operator ==(const Dati& d) {
		return valore==d.valore;
	}
	bool operator <(const Dati& d) {
		return valore<d.valore;
	}	
	friend int sumIntDati(int x, Dati d);
};
ostream& operator <<(ostream& os, const Dati& d){
	return os << d.valore;
}
void stampa(vector<Dati>& v){
	for (auto& item : v) { cout << "["<< item << "] "; } 
	cout << endl;	
}

int myfunction (int x, int y) {return x*y;}
int sumIntDati(int x, Dati d) { return x+d.valore; }

int main() {
	list<int> l = { 1,2,5,6,1,5 };
	//stampa
    for (auto& item : l) {
		cout << "["<< item << "] ";
	}
	cout << endl;
	// calcola la somma degli elementi di l
    cout << "Sum: " << accumulate(l.begin(), l.end(), 0) << "\n";
    // calcola il prodotto degli elementi di l
    cout << "Prod: " << accumulate(l.begin(), l.end(), 1, myfunction) << "\n";
	// calcola il prodotto degli elementi di v
    cout << "Product: "<< accumulate(l.begin(), l.end(), 1, multiplies<int>()) << "\n";
    
    //======================================
    vector<Dati> v;
    //inizializzo valori
    v.push_back(Dati(4));
    v.push_back(Dati(7));
    v.push_back(Dati(1));
    v.push_back(Dati(8));

	cout << endl;
	//ricerca
	auto found = find(v.begin(), v.end(), 7);
    if (found != v.end()) {
        cout << "Element 7 found at position " << distance(v.begin(), found) << "\n";
    }
	// calcola la somma degli elementi di v 
	//sommo ad un intero una istanza della classe Dati => necessaria una funzione specifica
    cout << "Sum: " << accumulate(v.begin(), v.end(), 0, sumIntDati) << "\n";

	// riposiziona gli elementi di v in ordine decrescente
    sort(v.rbegin(), v.rend());
	cout << "Sort: "; stampa(v);  	
	
    // riposiziona gli elementi di v in ordine crescente
    sort(v.begin(), v.end());
	cout << "Sort: "; stampa(v); 	
	
	// riposiziona gli elementi di v in ordine casuale
	shuffle (v.begin(), v.end(), default_random_engine());
	cout << "Shuffle: "; stampa(v); 
     
    return 0;
}
