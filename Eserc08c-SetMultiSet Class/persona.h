#ifndef __PERSONA_H__
#define __PERSONA_H__

#include <string>
using namespace std;
class Persona{
private:
   string nome;     
public:
   Persona();
   Persona(string _nome);
   Persona(const Persona& p);
   ~Persona(); 
   bool operator <(const Persona& p) const;
   friend ostream& operator <<(ostream &os, const Persona& p);         
};

ostream& operator <<(ostream &os, const Persona& p);

#endif
