#ifndef PESSOA_JURIDICA_H
#define PESSOA_JURIDICA_H 

#include "Pessoa.h"

#include <string>
using std::string;

#include <iostream>
using std::cout, std::endl;

class PessoaJuridica : public Pessoa
{
public:
  PessoaJuridica(string nome, string cnpj, string inscricaoEstadual, string endereco = "N/I", string email = "N/I") : Pessoa(nome,cnpj,endereco,email),inscricaoEstadual(inscricaoEstadual) {}
  PessoaJuridica(){ }
  virtual string tipo(){
     return "Juridica";
   }
   virtual string dado(){return inscricaoEstadual;};
private:
  string inscricaoEstadual;
};

#endif