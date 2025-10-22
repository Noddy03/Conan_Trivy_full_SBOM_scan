#include <cstdlib>
#include <iostream>
#include <stdexcept>
using namespace std;

class Dati{
private:
	int valueI;
	float valueF;
public:
	Dati(){ }
	Dati(int vi, float vf) {
		if (vi < 0) { throw invalid_argument( "received negative value" ); }
		valueI = vi;
		valueF = vf;
		cout << "class Dati initialized with:" << valueI<<" & "<<valueF << endl;	
	}
};
class Test{
private:
	Dati dato;
	int valueT;	
public:	
	Test(int vi, float vf, int vt) {
		try {
			dato = Dati(vi,vf);
			valueT = vt;
			cout << "class Test initialized with value:" << valueT << endl;	
		} catch(...) {
			// stampa messaggio err e continua programma
	        //cerr<<"parametro non valido class Dati"<< endl;
			cout<<"paramentro non valido class Dati"<< endl;  
	    }
	}
};


int main(int argc, char *argv[]){
  Test var2(-6,5.5,-9);
  
  Test var1(3,2.2,1);
  
  
  //system("PAUSE");
  return EXIT_SUCCESS;
}
