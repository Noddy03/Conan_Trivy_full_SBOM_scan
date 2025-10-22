#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

/*
gli errori di runtime sono quegli errori che NON possono essere rilevati in fase di compilazione, 
perché si manifestano solo durante la fase di esecuzione del programma e solo in alcune particolari circostanze, 
ossia al veri..casi di “eventi eccezionali”. 
Alcuni esempi di errori di runtime sono: 
 - divisione per 0; 
 - l’utilizzo di un pathname non valido o che fa riferimento ad una periferica che in un certo momento risulta scollegata; 
 - overflow su un tipo di dato da parte di un’operazione aritmetica; 
 - un’operazione di casting non valido (ad esempio, quando si ha l’inserimento in input da parte dell’utente di una stringa di testo non
interpretabile come un numero e che viene assegnata ad una variabile di tipo numerico).

Si tratta di errori pericolosi perché se non gestiti, possono generare anomalie di funzionamento che possono
determinare persino il blocco inaspettato del programma (crash dell’applicazione). La gestione di questo tipo di
errori non è banale ed è per questo che per facilitarla i linguaggi di programmazione ad oggetti (OOP) mettono a
disposizione il meccanismo delle eccezioni.

LE ECCEZIONI
Quando si verifica un errore di runtime i linguaggi OOP, si dice, possono “sollevare” o permettono di “lanciare”
(in inglese, to throw) un’eccezione. Ciò in generale di traduce nella creazione di un oggetto che appartiene ad
una classe particolare, dipendente dallo specifico errore di runtime che si è verificato.
Questo meccanismo, infatti, prevede che quando viene sollevata un’eccezione, il flusso di esecuzione del programma
viene sospeso nel punto in cui si è verificato l’errore e salta in un altro punto del codice in cui esso viene
gestito. Nel linguaggio C++ ciò viene realizzato utilizzando il costruttto try-catch.

try{
  //istruzioni a rischio errori di runtime
} catch(TipoErrore1){
  //istruzioni che gestiscono le eccezioni di tipo 'TipoErrore1'
}

try è la parola chiave che introduce il blocco in cui si possono inserire le istruzioni che si vuole tenere
“sotto controllo” perché durante l’esecuzione potrebbero generare degli errori di runtime.
catch è la parola chiave che introduce un blocco in grado di riconoscere e “catturare” un certo tipo di
eccezione e che contiene le istruzioni per gestire l’errore di runtime che l’ha generata.
Un bloccco try può avere ad esso associati uno o più blocchi catch: quando all’interno di un blocco try
viene sollevata o lanciata un’eccezione, il flusso di esecuzione del programma salta ai suoi blocchi catch,
partendo dal primo e proseguendo verso gli altri finché non si trova un blocco catch (se esiste) che
cattura il tipo di eccezione sollevata. Quando si entra in un blocco catch, alla sua uscita il flusso del
programma prosegue oltre l’ultimo blocco catch.

Un’eccezione può essere o sollevata direttamente dall’istruzione in corrispondenza della quale si verifica
l’errore, oppure se per una certa istruzione ciò non è previsto dal linguaggio, può essere lanciata
esplicitamente con un’istruzione throw con la seguente sintassi:

throw espressione;

throw è la parola chiave con cui è possibile lanciare un’eccezione per segnalare il fatto che si è verificato
un errore. L’eccezione viene “marcata” opportunamente, per permettere il suo riconoscimento da parte dei blocchi catch.
*/

int main(int argc, char *argv[]){
	double x, y;
	try {
		cout<<"Inserisci il dividendo: ";
		cin>>x;
		cout<<"Inserisci il divisore: ";
		cin>>y;
		//monitora il verificarsi dell'errore di runtime di divisione per zero
		if(y==0) {
			//lancia un'eccezione di tipo 'costante stringa'
			throw "Divisione per zero!";
		}
		cout<<x/y<<endl;
	}
	//individua e cattura un'eccezione di tipo 'costante stringa'
	catch (const char* messaggio) {
		cerr<<messaggio<< endl;
	}
  	system("PAUSE");
  	return EXIT_SUCCESS;
}
