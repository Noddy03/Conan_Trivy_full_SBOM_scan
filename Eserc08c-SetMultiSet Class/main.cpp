#include <cstdlib>
#include <iostream>
#include "persona.h"
#include "gruppo.h"
using namespace std;

int main(int argc, char *argv[]){
 {
  Persona p1("Mario");           
  Persona p2;    
  Persona p3("Anna");       
  cout << p1  << endl; 
  Gruppo g;
  //g.addPersona1(p1); //p1 passato per copia
  g.addPersona2(p1);   //p1 passato per reference
  g.addPersona2(p3);   //p3 passato per reference
  g.addPersona2(Persona("Tizio"));
  //addPersona3 è preferibile ad addPersona1 e addPersona2
  //si evita di fare costruttori di copia nel caso ci sia allocazione dimanica
  //normalmente il main ha visibilità solo della classe Gruppo
  g.addPersona3("Giovanni");
  
  g.addPPersona(&p1);
  cout << g << endl;
  g.remPersona(p1);
  cout << g << endl;          
 }
 system("PAUSE"); return EXIT_SUCCESS;
}
