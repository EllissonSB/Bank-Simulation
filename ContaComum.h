#ifndef CONTA_COMUM_H
#define CONTA_COMUM_H

#include "Conta.h"

#include <iostream>
#include <string>
using std::string;
using std::cerr;
using std::cout, std::endl;
#include <stdexcept>
using std::runtime_error;
#include <vector>
using std::vector;
#include <sstream>
using std::stringstream;
class ContaComum : public Conta
{
public:
  ContaComum(int conta, double saldo = 0.0) : Conta(conta,saldo) {}
  void ver(double sald, double valor){
    if (sald-valor<=0){
      throw runtime_error("Saldo Insuficiente.");
    }
  }
  virtual void operator >>(double valor){
    try{
      ver(saldo,valor);
      saldo-=valor;
      time_t ttime = time(0);
  tm *local_time = localtime(&ttime);
  stringstream ss;
  ss<<local_time->tm_mday<<"/"<<1+local_time->tm_mon<<"/"<<1900+local_time->tm_year<<endl;
  Datas.push_back(ss.str());
  Valores.push_back(valor);
  Descricao.push_back("Saque");
  tTransacoes++;
    }
    catch (runtime_error &e){
      cerr << e.what() << endl; //avisando
    }
  }
  virtual void transfer(double valor){
    try{ver(saldo,valor);
    saldo-=valor;
    time_t ttime = time(0);
  tm *local_time = localtime(&ttime);
  stringstream ss;
  ss<<local_time->tm_mday<<"/"<<1+local_time->tm_mon<<"/"<<1900+local_time->tm_year<<endl;
  Datas.push_back(ss.str());
  Valores.push_back(valor);
  Descricao.push_back("Envio de Transferencia");
  tTransacoes++;}
  catch (runtime_error &e){
      cerr << e.what() << endl; //avisando
    }
  }
  virtual void receber (double valor){
    saldo+=valor;
    time_t ttime = time(0);
  tm *local_time = localtime(&ttime);
  stringstream ss;
  ss<<local_time->tm_mday<<"/"<<1+local_time->tm_mon<<"/"<<1900+local_time->tm_year<<endl;
  Datas.push_back(ss.str());
  Valores.push_back(valor);
  Descricao.push_back("Recebimento de Transferencia");
  tTransacoes++;
  }  
  virtual void operator <<(double valor){
    saldo+=valor;
    time_t ttime = time(0);
  tm *local_time = localtime(&ttime);
  stringstream ss;
  ss<<local_time->tm_mday<<"/"<<1+local_time->tm_mon<<"/"<<1900+local_time->tm_year<<endl;
  Datas.push_back(ss.str());
  Valores.push_back(valor);
  Descricao.push_back("Deposito");
  tTransacoes++;
  }
  virtual void set_dados(double d){
    cout<<"a";
  }
  virtual double dados(){return 0;}
  virtual string getTipoConta(){return "comum";}
  virtual ~ContaComum(){}
  //sobrescrevendo método virtual puro extrato
  virtual void extrato()
  {
    int i=0;
    if(tTransacoes>30){
      i=tTransacoes-30;
    }
    cout << "CONTA: " << conta << endl;
    cout << "Transações: " << endl;
    for (int i ; i< tTransacoes ; i++)
      cout << Datas[i] << " " << Valores[i] << " " << Descricao[i] << endl;
    cout << "------------------------------" << endl;
    cout << "Saldo: R$ " << saldo << endl;

  }
  private :
  vector<string> Datas;
  vector <double> Valores;
  vector <string> Descricao;
};

#endif