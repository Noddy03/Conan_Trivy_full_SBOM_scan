#include <cstdlib>
#include <iostream>
#include "persona.h"
using namespace std;

Persona::Persona(){
 nome="NN";
 cout <<"creato def:"<<nome<<endl;                    
}
Persona::Persona(string _nome){
 nome=_nome;
 cout <<"creato spec:"<<nome<<endl;                         
}
Persona::Persona(const Persona& p){
 nome=p.nome;
 cout <<"creato copia:"<<nome<<endl;                
}
Persona::~Persona(){
 cout <<"distrutta:"<<nome<<endl;                   
}
bool Persona::operator <(const Persona& p) const{
  return nome<p.nome;   
}
ostream& operator <<(ostream &os, const Persona& p){
  return os<<p.nome;         
}
