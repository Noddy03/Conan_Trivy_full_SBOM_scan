#include <cstdlib>
#include <iostream>
#include <string>
#include "string.h"
using namespace std;

/*
  Un blocco try/catch viene utilizzato per rilevare le eccezioni. 
  Il codice nella sezione try è il codice che può generare un'eccezione e il codice nella clausola catch gestisce l'eccezione.
  È possibile utilizzare più clausole di catch per gestire più tipi di eccezioni. Se sono presenti più clausole catch, 
  il meccanismo di gestione delle eccezioni tenta di farli corrispondere in ordine di aspetto nel codice.
  
  Propagazione delle eccezioni
  Un’eccezione non necessariamente deve essere gestita all’interno della stessa funzione in cui viene sollevata o
  lanciata, ma al contrario è opportuno che questa gestione avvenga al suo esterno, all’interno di una funzione chiamante. 
  Spesso, infatti, accade che la sua gestione dipende e può essere diversa a seconda del punto in cui
  quella funzione viene chiamata. Questo è reso possibile dal meccanismo proprio delle eccezioni, il quale
  prevede che un’eccezione sollevata in una funzione e che non venga in essa gestita, sia propagata all’indietro
  verso il chiamante, si dice risalendo lo stack delle chiamate, 
*/

int compare(int a, int b) {
    if (a < 0 || b < 0) { //individua l'errore di runtime
        //lancia l'eccezione utilizzando una stringa
		throw "ERR a or b negative";
    }
    return a == b;
}

int compareADV(int a, int b) {
    if (a < 0 ) {
        throw "ERR a negative";
    }
    if (b < 0) {
    	//soluzione per ritornare una "stringa" con dettagli sul valore errato
    	string message = "ERR b negative: ";
        cerr << message << b << endl;
    }    
    return a == b;
}

void test1() {
    try {
        cout << compare(-1, 0) << endl;
        //una volta sollevata una eccezione il programma non prosegue con le istruzioni successive
        cout << "FINE PROGRAMMA" << endl;
    } catch (const char* errorMessage) { //intercetta un'eccezione di tipo costante stringa
        cout << errorMessage << endl;
    }
}

void test2() {
	//attenzione non è gestito il catch dell'errore e questo blocca l'esecuzione del programma
	cout << compare(-1, 0) << endl;
}


void test3() {
    try {
    	cout << "5==5 : "<<compare(5, 5) << endl;
    	cout << "FINE Confronto 1" << endl;
        //cout << compare(-1, 0) << endl;
        //oppure con messaggio personalizzato
        //cout << "-3==6 : "<< compareADV(-3, 6) << endl;
        cout << "6==-3 : "<< compareADV(6, -3) << endl;
        //una volta sollevata una eccezione il programma non prosegue con le istruzioni successive
       cout << "FINE Confronto 2" << endl;
    } catch (const char* errorMessage) {
        cout << errorMessage << endl;
    }
}


int main(int argc, char *argv[]){
  //test1();
  //test2();
  cout << string("bla bla bla") + to_string(12);
  test3();
  system("PAUSE");
  return EXIT_SUCCESS;
}
