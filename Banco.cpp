#include <iostream>
#include <string>
using std::string;
#include "Banco.h"
#include <cstring>
#include <fstream>
#include <cstring>
using std::fstream;
using std::ofstream,std::ifstream;
using std::cout,std::endl,std::cin;
using std::ios,std::ios_base;
using std::endl;
struct PE{
  char tipo[50];
  char Nome[50];
  char cpf_cnpj[50];
  char insc[50];
  char endereco[50];
  char email[50];
};
struct CO{
  int cont;
  double sal;
  double dad;
  char tipo[50];
  char nome[50];
};

int Banco::encontrar_correntista(string a){
  for(int i=0; i<num_pessoas;i++){
    if (listaPessoas[i]==NULL){
    }
    else if(a==listaPessoas[i]->getNome()){
      return i;
    }
  }
  return -1;
}
int Banco::encontrar_conta(int a){
  for (int i=0;i<num_conta;i++){
    if (listaContas[i]==NULL){
    }
    else if(a==listaContas[i]->ptr_conta->getConta()){
      return i;
    }

  }
  return -1;
}
void Banco::cadastar_cliente(){
  string nome, cpf,nascimento,estadoCivil,endereco,email;
  cout<<"Seja bem vindo ao cadastro de clientes."<<endl;
  cout<<"Para cadastro de pessoa fisica 1 para cadastro de pessoa Juridica 0: ";
  int op_p;
  cin>>op_p;
  if(op_p==1){
    cout<<"Digite o nome: ";
    cin.ignore();
    cin>>nome;
    cout<<"Digite o cpf: ";
    cin.ignore();
    cin>>cpf;
    cout<<"Digite a data de nascimento: ";
    cin.ignore();
    cin>>nascimento;
    cout<<"Digite o endereço: ";
    cin.ignore();
    cin>>endereco;
    cout<<"Digite o Email: ";
    cin.ignore();
    cin>>email;
    listaPessoas[num_pessoas]=new PessoaFisica(nome,cpf,nascimento,endereco,email);
    cout<<"O cadastro do(a) cliente "<<listaPessoas[num_pessoas]->getNome()<<" foi efetuado com Sucesso."<<endl;
    num_pessoas++;
  }
  else{
    cout<<"Digite o nome: ";
    cin.ignore();
    cin>>nome;
    cout<<"Digite o cnpj: ";
    cin.ignore();
    cin>>cpf;
    cout<<"Digite a inscricão Estadual: ";
    cin.ignore();
    cin>>nascimento;
    cout<<"Digite o endereço: ";
    cin.ignore();
    cin>>endereco;
    cout<<"Digite o Email: ";
    cin.ignore();
    cin>>email;
    listaPessoas[num_pessoas]=new PessoaJuridica(nome,cpf,nascimento,endereco,email);
    cout<<"O cadastro do(a) cliente "<<listaPessoas[num_pessoas]->getNome()<<" foi efetuado com Sucesso."<<endl;
    num_pessoas++;
  }
}
void Banco::cadastrar_conta(){
int conta;
string nome; 
double saldo,limite,anv; 
cout << "-------------------------------------" << endl;
    cout << "Cadastro de Conta." << endl;
    cout<<"A pessoa já poussui Cadastro."<<endl;
    cout<<"Digite 1 para sim e 0 para não."<<endl;
    int opp;
    cout<<"Resposta: ";
    cin>>opp;
    if (opp==0){
      cadastar_cliente();
    }
    cout << "Opções:" << endl;
    cout << "0 - Conta Comum" << endl;
    cout << "1 - Conta Limite" << endl;
    cout << "2 - Conta Poupança" << endl;
    cout << endl << "-1 - Sair" << endl;
    cout << "Op: ";

    int op;
    cin >> op;
    switch (op)
    {
      case 0:
      cout<<"Digite o nome do correntista: ";
      cin.ignore();
      cin>>nome;
      cout<<"Digite o numero da conta: ";
      cin>>conta;
      cout<<"Digite o saldo da conta: ";
      cin>>saldo;
      listaContas[num_conta]=new D_BANCO{listaPessoas[encontrar_correntista(nome)],new ContaComum(conta,saldo)};
      num_conta++;
        break;
      case 1:{
      cout<<"Digite o nome do correntista: ";
      cin.ignore();
      cin>>nome;
      cout<<"Digite o numero da conta: ";
      cin>>conta;
      cout<<"Digite o saldo da conta: ";
      cin>>saldo;
      cout<<"Digite o limite da conta: ";
      cin>>limite;
      listaContas[num_conta]=new D_BANCO{listaPessoas[encontrar_correntista(nome)],new ContaLimite(conta,limite,saldo)};
      num_conta++;
        break;}
      case 2:
        {
       cout<<"Digite o nome do correntista: ";
      cin.ignore();
      std::getline( cin, nome );
      cout<<"Digite o numero da conta: ";
      cin>>conta;
      cout<<"Digite o saldo da conta: ";
      cin>>saldo;
      cout<<"Digite a data de aniversario da conta: ";
      cin>>anv;
      listaContas[num_conta]=new D_BANCO{listaPessoas[encontrar_correntista(nome)],new ContaPoupanca(conta,anv,saldo)};
      num_conta++;
        break;}
      case -1:
        exit(0);
        break;

      default:
        //
        break;
    }
}
void Banco::remover_conta(int conta){
  for(int i=0;i<num_conta;i++){
    if (listaContas[i]==NULL){

    }
    else if (listaContas[i]->ptr_conta->getConta()==conta){
      listaContas[i]={};
      cout<<"Conta Removida com sucesso."<<endl;
      exit(1);
      
    }
  }
  cout<<"Conta não encontrada."<<endl;
}
void Banco::consultar_conta(int conta){
  for(int i=0;i<num_conta;i++){
    if (listaContas[i]==NULL){}
    else if (listaContas[i]->ptr_conta->getConta()==conta){
     cout<<"Correntista:"<<listaContas[i]->ptr->getNome()<<endl;
     cout<<"Conta:"<<listaContas[i]->ptr_conta->getConta()<<endl;
     cout<<"Tipo de conta: ";listaContas[i]->ptr_conta->getTipoConta();
     cout<<"Saldo de conta: "<<listaContas[i]->ptr_conta->getSaldo()<<endl;
     break;
    }

}
  cout<<"Conta não encontrada."<<endl;
}
void Banco::att_conta(int conta){
  int sad;
  double limite;
  for(int i=0;i<num_conta;i++){
    if (listaContas[i]==NULL){
    }
    else if (listaContas[i]->ptr_conta->getConta()==conta){
      if(listaContas[i]->ptr_conta->getTipoConta()=="comum"){
        cout<<"Digite o novo saldo: ";
        cin>>sad;
        listaContas[i]->ptr_conta->setSaldo(sad);
      }
      else if (listaContas[i]->ptr_conta->getTipoConta()=="limite"){
        cout<<"Digite o novo saldo: ";
        cin>>sad;
        listaContas[i]->ptr_conta->setSaldo(sad);
        cout<<"Digite o novo limite: ";
        cin>>limite;
        listaContas[i]->ptr_conta->set_dados(limite);
      }
      else if(listaContas[i]->ptr_conta->getTipoConta()=="poupanca") {
      cout<<"Digite o novo saldo: ";
      cin>>sad;
      cout<<"Digite o novo aniversario: ";
      cin>>limite;
      listaContas[i]->ptr_conta->set_dados(limite);
      }
      exit(0);
      
    }
}
}
void Banco::listar_contas(){
   for(int i=0;i<num_conta;i++){
     if (listaContas[i]==NULL){

     }
     else{cout<<"Correntista:"<<listaContas[i]->ptr->getNome()<<endl;
     cout<<"Conta:"<<listaContas[i]->ptr_conta->getConta()<<endl;
     cout<<"Tipo de conta: ";listaContas[i]->ptr_conta->getTipoConta();
     cout<<"Saldo de conta: "<<listaContas[i]->ptr_conta->getSaldo()<<endl;
   }}
}
void Banco::listar_pessoas(){
  for (int i=0;i<num_pessoas;i++){
    if(listaPessoas[i]==NULL){

    }
    else{cout<<"Nome do Cliente: "<<listaPessoas[i]->getNome()<<endl;
  }}
}
void Banco::salvar_dados(){
  fstream file_pessoas("pessoas.dat", ios::out);
  fstream file_contas("contas.dat",ios::out);
  file_contas.seekp(0);
  file_pessoas.seekp(0);
  for (int i=0;i<num_pessoas;i++){
    if (listaPessoas[i]==NULL){}
    else{
    PE teste;
    strcpy(teste.tipo, listaPessoas[i]->tipo().c_str());
    strcpy(teste.Nome, listaPessoas[i]->getNome().c_str());
    strcpy(teste.cpf_cnpj, listaPessoas[i]->getCPF_CNPJ().c_str());
    strcpy(teste.endereco, listaPessoas[i]->getEndereco().c_str());
    strcpy(teste.email, listaPessoas[i]->getEmail().c_str());
    strcpy(teste.insc,listaPessoas[i]->dado().c_str());
     file_pessoas.write(reinterpret_cast<char *>(&teste),sizeof(teste));
  }}
  for (int j=0;j<num_conta;j++){
    if (listaContas[j]==NULL){}
    else{
    CO teste2;
    strcpy(teste2.tipo,listaContas[j]->ptr_conta->getTipoConta().c_str());
    strcpy(teste2.nome,listaContas[j]->ptr->getNome().c_str());
    teste2.sal=listaContas[j]->ptr_conta->getSaldo();
    teste2.cont=listaContas[j]->ptr_conta->getConta();
    teste2.dad=listaContas[j]->ptr_conta->dados();
    file_contas.write(reinterpret_cast<char *>(&teste2),sizeof(teste2));
  }}

}
void Banco::transferir(double valor, int con,int dest){
  listaContas[encontrar_conta(con)]->ptr_conta->transfer(valor);
  listaContas[encontrar_conta(dest)]->ptr_conta->receber(valor);
  
}
void Banco::depositar(int con, double valor){
  listaContas[con]->ptr_conta->operator<<(valor);
}
void Banco::sacar(int con, double valor){
  listaContas[con]->ptr_conta->operator>>(valor);
  }
void Banco::ext(int con){
  listaContas[con]->ptr_conta->extrato();
}  
double Banco::saldo(int con){
  return listaContas[con]->ptr_conta->getSaldo();
}
void Banco::listar_contas_co(string nome){
  for (int i=0;i<num_conta;i++){
    if (listaPessoas[i]==NULL){

    }
    else{
      if (listaContas[i]->ptr->getNome()==nome){
        cout<<"Conta Nº: "<<listaContas[i]->ptr_conta->getConta()<<endl;;
      }
    }
  }
}
void Banco::ler_dados(){
  fstream file_pessoas("pessoas.dat", ios::in);
  fstream file_contas("contas.dat",ios::in);
  CO teste2;
  PE teste;
  file_pessoas.seekg(0);
  file_contas.seekg(0);
  char f[50]="Fisica",j[50]="Juridica", c_m[50]="comum",c_l[50]="limite",c_p[50]="poupanca";
  while (true)
  {
    file_pessoas.read(reinterpret_cast<char *> (&teste),sizeof(teste));

    if (file_pessoas.eof())
      break;
    if ((strcasecmp(teste.tipo,f))==0){
      listaPessoas[num_pessoas]=new PessoaFisica(teste.Nome,teste.cpf_cnpj,teste.insc,teste.endereco,teste.email);
      num_pessoas++;
    }
    else{
      listaPessoas[num_pessoas]=new PessoaJuridica(teste.Nome,teste.cpf_cnpj,teste.insc,teste.endereco,teste.email);
      num_pessoas++;
    }
  }
  while (true){
    file_contas.read(reinterpret_cast<char *>(&teste2),sizeof(teste2));
    if (file_contas.eof())
      break;
    if ((strcasecmp(teste2.tipo,c_m))==0){
      listaContas[num_conta]=new D_BANCO{listaPessoas[encontrar_correntista(teste2.nome)],new ContaComum(teste2.cont,teste2.sal)};
   // new D_BANCO{listaPessoas[encontrar_correntista(nome)],new ContaComum(conta,saldo)};
      num_conta++;
    }
    else if ((strcasecmp(teste2.tipo,c_l))==0){
      listaContas[num_conta]=new D_BANCO{listaPessoas[encontrar_correntista(teste2.nome)],new ContaLimite(teste2.cont,teste2.dad,teste2.sal)};
      num_conta++;
    }
    else {
      listaContas[num_conta]=new D_BANCO{listaPessoas[encontrar_correntista(teste2.nome)],new ContaPoupanca(teste2.cont,teste2.dad,teste2.sal)};
      num_conta++;
    }
  }
}
