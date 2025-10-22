//Marco Barozzi 167018
#include <iostream>
#include <string>
#include <map>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

class Giardino{
	private:
		string nome;
		int estensione;
		string localita;
	public:
		Giardino (string _nome, int _estensione, string _localita){
			nome=_nome;
			estensione=_estensione;
			localita=_localita;
		}
	int getestensione ()const { return estensione; }
	friend ostream& operator << (ostream& os, const Giardino& g);
};

ostream& operator << (ostream& os, const Giardino& g){
	os<<"Nome Giardino: "<<g.nome<<endl;
	os<<"Estensione [mq]: "<<g.estensione<<endl;
	os<<"Localita: "<<g.localita<<endl;
}

bool under120(const Giardino& g){ return g.getestensione()<120;}

int main(int argc, char** argv) {
	
	map<int, list <Giardino> > dato;
	map<int, list <Giardino> > ::iterator mit;
	list <Giardino>:: iterator vit;
	
	dato[1].push_back(Giardino ("G1",100, "L1"));
	dato[2].push_back(Giardino ("G2",200, "L2"));
	dato[3].push_back(Giardino ("G3",300, "L3"));
	
	//stampo i dati
	for (mit=dato.begin(); mit!=dato.end();mit++){
		for (vit=mit->second.begin(); vit!=mit->second.end();vit++){
			cout<<*vit<<endl;
		}
	}
	//se in contenuto fosse una lista
	for (mit=dato.begin(); mit!=dato.end();mit++){
		mit->second.remove_if(under120);
	}	
	cout << "RIMOZIONE DA LISTA" << endl;
	
	for (mit=dato.begin(); mit!=dato.end();mit++){
		for (vit=mit->second.begin(); vit!=mit->second.end();vit++){
			cout<<*vit<<endl;
		}
	}
	cout << "======================" << endl;
	//se il contenuto fosse un vector
	map<int, vector <Giardino> > dato1;
	map<int, vector <Giardino> > ::iterator mit1;
	vector <Giardino>:: iterator vit1;
	
	dato1[1].push_back(Giardino ("G1",100, "L1"));
	dato1[2].push_back(Giardino ("G2",200, "L2"));
	dato1[3].push_back(Giardino ("G3",300, "L3"));

	//stampo i dati
	for (mit1=dato1.begin(); mit1!=dato1.end();mit1++){
		for (vit1=mit1->second.begin(); vit1!=mit1->second.end();vit1++){
			cout<<*vit1<<endl;
		}
	}
	cout << "RIMOZIONE DA VECTOR" << endl;
	for (mit1=dato1.begin(); mit1!=dato1.end();mit1++){
		mit1->second.remove_if(under120);
	}
	/*for (mit1=dato1.begin(); mit1!=dato1.end();mit1++){
		mit1->second.erase(
			remove_if(mit1->second.begin(), mit1->second.end(),under120), mit1->second.end()
		);
	}*/

	//stampo i dati
	for (mit1=dato1.begin(); mit1!=dato1.end();mit1++){
		for (vit1=mit1->second.begin(); vit1!=mit1->second.end();vit1++){
			cout<<*vit1<<endl;
		}
	}
		
	return 0;
}

