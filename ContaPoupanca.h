#ifndef CONTA_POUPANCA_H
#define CONTA_POUPANCA_H
#include "Conta.h"
#include <string>
using std::string;
#include <iostream>
using std::cout, std::endl;
#include <stdexcept>
#include <sstream>
using std::stringstream;
using std::runtime_error;
#include <vector>
using std::vector;
class ContaPoupanca : public Conta
{
public:
  ContaPoupanca(int conta,double aniversaio, double saldo = 0.0) : Conta(conta,saldo),aniversario(aniversaio) {}
  
  virtual ~ContaPoupanca(){}
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
virtual string getTipoConta(){return "poupanca";}
 virtual double dados (){
    return aniversario;
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
  //sobrescrevendo método virtual puro extrato
  virtual void extrato()
  {
    int i =0;
    if(tTransacoes>30){
      i=tTransacoes-30;
    }
   cout << "CONTA: " << conta << endl;
    cout << "ANIVERSARIO: " << aniversario << endl;
    cout << "Transações: " << endl;
    for (int i; i < tTransacoes ; i++)
      cout << Datas[i] << " " << Valores[i] << " " << Descricao[i] << endl;
    cout << "------------------------------" << endl;
    cout << "Saldo: R$ " << saldo << endl;
  }
virtual void set_dados(double d){
  aniversario=d;
}
private:
  double aniversario;
  vector<string> Datas;
  vector <double> Valores;
  vector <string> Descricao;
};

#endif