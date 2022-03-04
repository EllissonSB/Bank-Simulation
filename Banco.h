#ifndef BANCO_H
#define BANCO_H 

#include "Pessoa_fisica.h"

#include "ContaComum.h"
#include "ContaPoupanca.h"
#include "ContaLimite.h"
#include <string>
using std::string;
#include <fstream>
using std::fstream;
struct D_BANCO {
  Pessoa *ptr;
  Conta *ptr_conta;
};
#include <iostream>
using std::cout, std::endl;
#include "Pessoa_Juridica.h"
class Banco: public PessoaJuridica
{
  public:
  Banco(string nome, string cnpj, string inscricaoEstadual, string endereco,string email):PessoaJuridica(nome,cnpj,inscricaoEstadual,endereco,email){}
  void cadastrar_conta();//feito
  void remover_conta(int num_conta);//feito
  void consultar_conta(int num_conta);//feito
  void att_conta(int num_conta);//+-
  void cadastar_cliente();//feito
  int encontrar_correntista(string);//feito
  int encontrar_conta(int);//feito
  void listar_contas();//feito
  void listar_pessoas();//feito
  void listar_contas_co(string nome);//feito
  void salvar_dados();//feito
  void ler_dados();//feito
  void transferir(double valor, int con,int dest);//fazendo
  void depositar(int con,double valor);
  void sacar(int con,double valor);
  double saldo(int con);
  void ext(int con);
  protected:
  Pessoa *listaPessoas[100];
  D_BANCO *listaContas[100];
  int num_conta=0;
  int num_pessoas=0;
};
#endif