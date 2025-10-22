#include <cstdlib>
#include <iostream>
#include "gruppo.h"
using namespace std;

Gruppo::Gruppo(){
  sp.clear(); //inutile 
  cout<<"creato gruppo"<<endl;        
}
Gruppo::~Gruppo(){
   cout<<"distrutto gruppo"<<endl;          
}
void Gruppo::addPersona1(Persona p){
   sp.insert(p);  
}
void Gruppo::addPersona2(const Persona& p){
   sp.insert(p);       
}
void Gruppo::addPersona3(string nome){
   //sp.insert(nome); //ok se costruttore Persona non explicit
   sp.insert(Persona(nome));
}
void Gruppo::addPPersona(Persona* pp){
   spp.insert(pp);  
}
void Gruppo::remPersona(const Persona& p){
   set<Persona>::iterator iter;
   iter = sp.find(p);
   if(iter!=sp.end()){
      sp.erase(iter);                
   }   
}
ostream& operator <<(ostream &os, const Gruppo& g){
  set<Persona>::iterator iter;
  set<Persona*>::iterator piter;
  os<<"{ ";
  for(iter=g.sp.begin(); iter!=g.sp.end(); ++iter){
      os << *iter <<" ";  
  }
  for(piter=g.spp.begin(); piter!=g.spp.end(); ++piter){
      os << "["<< **piter <<"] ";  
  }    
  os <<"}";
  return os;     
}
