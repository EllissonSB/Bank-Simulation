#ifndef PESSOA_H
#define PESSOA_H 
#include <cstring>
#include <string>
using std::string;

#include <iostream>
using std::ostream;

class Pessoa 
{
  friend ostream &operator<<(ostream &o, const Pessoa &p);
public:
  Pessoa(string nome, string cpf_cnpj, string endereco = "N/I", string email = "N/I") : nome(nome), cpf_cnpj(cpf_cnpj), endereco(endereco), email(email) {}
  Pessoa(){}
  virtual ~Pessoa() {}
  string getNome()  {return nome;}
  string getCPF_CNPJ()  { return cpf_cnpj;}
  string getEndereco()  {return endereco;}
  string getEmail()  { return email;}
  virtual string tipo()=0;
  virtual string dado()=0;
  void setNome(string no){nome=no;}
  void setCpf_cnpj(string cnp){cpf_cnpj=cnp;}
protected:
  string nome;
  string cpf_cnpj;
  string endereco;
  string email;
};

#endif