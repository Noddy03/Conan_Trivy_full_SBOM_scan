#ifndef __GRUPPO_H__
#define __GRUPPO_H__
#include <set>
#include "persona.h"

class Gruppo{
private:
  set<Persona> sp;  //losanga piena 0,* 
  set<Persona*> spp;//losanga vuota 0,*           
public:
  Gruppo(); //losanga piena 0,*   
  ~Gruppo();
 // Gruppo(Persona p);//losanga piena 1,*   no Gruppo(); 
  void addPersona1(Persona p);  
  void addPersona2(const Persona& p);
  void addPersona3(string nome);
  void addPPersona(Persona* pp);
  void remPersona(const Persona& p);
  friend ostream& operator <<(ostream &os, const Gruppo& g);  
};

ostream& operator <<(ostream &os, const Gruppo& g);

#endif
