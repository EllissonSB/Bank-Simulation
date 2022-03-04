#ifndef PESSOA_FISICA_H
#define PESSOA_FISICA_H 

#include "Pessoa.h"

#include <string>
using std::string;

#include <iostream>
using std::cout, std::endl;

class PessoaFisica : public Pessoa
{
public:
  PessoaFisica(string nome, string cpf, string nascimento, string endereco = "N/I", string email = "N/I") : Pessoa(nome,cpf,endereco,email),nascimento(nascimento) {
  }
  PessoaFisica(){}
   virtual string tipo(){
     return "Fisica";
   }
   virtual string dado(){return nascimento;};
private:
  string nascimento;
};

#endif