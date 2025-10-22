#include <cstdlib>
#include <iostream>
#include <stdexcept>
//http://www.cplusplus.com/reference/stdexcept/
using namespace std;

//divisione per soli valori interi positivi
int divideINT(int a, int b) {
    if (a < 0 || b < 0) {
        throw invalid_argument( "received negative value" );
    }
    return a/b;
}

//divisione per soli valori interi positivi con valore massimo sotto il 10
int divideINT2(int a, int b) {
    if (a < 0 || b < 0) {
        throw invalid_argument( "received negative value" );
    }
    if (b==0){
		throw overflow_error( "division by 0" );
	}
    if (a > 9 || b > 9) {
        throw out_of_range( "out of range value" );
    }	
    return a/b;
}

void test1() {
	int a = 5, b = -6;
    try {
        cout << a << "/" << b << "=" << divideINT(a, b) << endl;
    } catch( const invalid_argument& e ) {
    	//cout << e << endl; //bind ERROR
    	cout << e.what() << endl; // stampa messaggio
        cout << "a or b negative" << endl;
    }
}
/*
  Poiché le clausole di catch vengono provate in ordine, assicurarsi di scrivere prima clausole di cattura più specifiche, 
  altrimenti il codice di gestione delle eccezioni potrebbe non essere mai chiamato.
  NOTA: possibile ordine catch diverso da ordine throw 
*/
void test2() {
	int a = 5, b = 0; 
	//a=7 & b=5  => ok
	//a=5 & b=0  => overflow_error
	//a=15 & b=5 => out_of_range
	
    try {
        cout << a << "/" << b << "=" << divideINT2(a, b) << endl;
    } catch( const invalid_argument& e ) {
    	cout << e.what() << endl; 
        cout << "a or b negative" << endl;
    }  catch( const out_of_range& e ) {
    	cout << e.what() << endl; 
        cout << "a or b greather than 9" << endl;
        //return;
    } catch( const overflow_error& e ) {
    	cout << e.what() << endl;
        cout << "b nullo" << endl;
    } 
    // oppure posso stampare l'eccezione sollevata
    try {
        cout << a << "/" << b << "=" << divideINT2(a, b) << endl;
    } catch(exception &e) {
    	cout << e.what() << endl;
    }
    //intercettato l'errore posso continuare con il mio codice
    cout << "prossima istruzione"<<endl;
}

/*
 Un'altra possibilità è il gestore catch-all, che catturerà qualsiasi oggetto lanciato
*/
void test3() {
	int a = 15, b = 5; 
	//a=7 & b=5  => ok
	//a=5 & b=0  => overflow_error
	//a=15 & b=5 => out_of_range
	
    try {
        cout << a << "/" << b << "=" << divideINT2(a, b) << endl;
    } catch( ... ) {
        cout << "errore nei dati" << endl;
    } 
    //intercettato l'errore posso continuare con il mio codice
    cout << "prossima istruzione"<<endl;
}

int main(int argc, char *argv[]){
  //test1();
  test2();
  //test3();
  
  
  //system("PAUSE");
  return EXIT_SUCCESS;
}
