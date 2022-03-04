#include <iostream>
using std::cout,std::cin,std::endl;
#include "Banco.h"
int main() {
  Banco a("Banco_Qualquer","12.504.401-0001/25","Banco1","Campina","bancao@gmail.com");
  a.ler_dados();
  a.listar_contas();
  cout<<endl;
  a.listar_contas_co("ellisson");
 int op;
  while (true){
    cout<<"Seja Bem vindo ao Banco Qualquer"<<endl;
    cout<<"Digite 0 para visão do gerente"<<endl;
    cout<<"Digite 1 para visão do correntista"<<endl;
    cout<<"Digite 2 para sair"<<endl;
    cout<<"Digite a opção: ";
    cin>>op;
    switch (op){
      case 0:{
      while (true){
        int op_g;
        if (op_g==4){
          break;
        }
        cout<<endl;
        cout<<"Seja Bem Vindo a visão do gerente"<<endl;
        cout<<"Digite 0 para Abrir uma conta"<<endl;
        cout<<"Digite 1 para Consultar uma conta"<<endl;
        cout<<"Digite 2 para Atualizar uma conta"<<endl;
        cout<<"Digite 3 para fechar uma conta"<<endl;
        cout<<"Digite 4 para sair"<<endl;
        cout<<"Digite a opção: ";
        cin>>op_g;
        switch (op_g){
          case 0:
            a.cadastrar_conta();
          break;
          case 1:{
            int cont;
            cout<<endl;
            cout<<"Digite a conta a ser buscada: ";
            cin>>cont;
            while (true){
              if (a.encontrar_conta(cont)==-1){
                cout<<"Conta não encontrada."<<endl;
                cout<<"digite novamente: ";
                cin>>cont;
              }
              else{ break;}
            }
            a.consultar_conta(cont);
          break;}
          case 2:{
            int cont;
               cout<<endl;
            cout<<"Digite a conta a ser alterada: ";
            cin>>cont;
            while (true){
              if (a.encontrar_conta(cont)==-1){
                cout<<"Conta não encontrada."<<endl;
                cout<<"digite novamente: ";
                cin>>cont;
              }
              else{ break;}
            }
            a.att_conta(cont);
          break;}
          case 3:{
            int cont;
               cout<<endl;
            cout<<"Digite a conta a ser fechada: ";
            cin>>cont;
            while (true){
              if (a.encontrar_conta(cont)==-1){
                cout<<"Conta não encontrada."<<endl;
                cout<<"digite novamente: ";
                cin>>cont;
              }
              else{ break;}
            }
            a.remover_conta(cont);
          break;}
          case 4:
          cout<<"Saindo..."<<endl;
          break;
          default:
          exit(0);
          break;
        }
      }
      break;}
      case 1:{
      int conttt;
      cout<<endl;
      cout<<"Seja Bem vindo a visão do correntista;"<<endl;
      cout<<"Digite a conta: ";
      cin>>conttt;
      while (true){
      if (a.encontrar_conta(conttt)==-1){
                cout<<"Conta não encontrada."<<endl;
                cout<<"digite novamente: ";
                cin>>conttt;
              }
      else{
        break;
      }
      }
      while(true){
        int op_c;
        if (op_c==5){
          break;
        }
        cout<<endl;
        cout<<"Digite 0 para Retirada"<<endl;
        cout<<"Digite 1 para Depositar"<<endl;
        cout<<"Digite 2 para Transferir"<<endl;
        cout<<"Digite 3 para Saldo"<<endl;
        cout<<"Digite 4 para ver extrato"<<endl;
        cout<<"Digite 5 para sair"<<endl;
        cout<<"Digite a opção: ";
        switch (op_c){
        case 0:{
          double c;
          cout<<"Digite o valor para saque: ";
          cin>>c;
          a.sacar(conttt, c);
          cout<<"Saque no valor de "<<c<<"Efetuado com sucesso."<<endl;
        break;}
        case 1:{
          double c;
          cout<<"Digite o valor para Depositar: ";
          cin>>c;
          a.depositar(conttt, c);
          cout<<"Deposito no valor de "<<c<<"Efetuado com sucesso."<<endl;
        break;}
        case 2:{
        double c;
        int cc;
        cout<<"Digite a conta que vai receber a Transferencia: ";
        cin>>cc;
        while (true){
      if (a.encontrar_conta(cc)==-1){
                cout<<"Conta não encontrada."<<endl;
                cout<<"digite novamente: ";
                cin>>cc;
              }
      else{
        break;
      }}
        cout<<"Digite o valor para Transferencia: ";
        cin>>c;
        a.transferir(c,conttt, cc);
        break;}
        case 3:{
          cout<<"O seu saldo é:"<<a.saldo(conttt);
        break;}
        case 4:{
            a.ext(conttt);
        break;}
        case 5:{
          cout<<"Saindo..."<<endl;
        break;}}
        //Depositar, Retirar, Transferir, Ver Saldo e Extrato
      }
      break;
      }
      case 2:{
      cout<<endl;
      cout<<"Saindo;"<<endl;
      a.salvar_dados();
      exit(0);
      break;}
      default:{
        //
        a.salvar_dados();
        break;}
    }
  }
}