#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

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
};
ostream& operator <<(ostream& os, const Dati& d){
	return os << d.valore;
}


int main() {
    vector<Dati> v;
    //inizializzo valori
    v.push_back(Dati(4));
    v.push_back(Dati(7));
    v.push_back(Dati(1));
	//stampa
    for (auto& item : v) {
		cout << "["<< item << "] ";
	}
	cout << endl;
	//ricerca
	auto found = find(v.begin(), v.end(), 7);
    if (found != v.end()) {
        cout << "Element 7 found at position " << distance(v.begin(), found) << "\n";
    }

     
    return 0;
}
