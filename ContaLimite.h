#ifndef CONTA_LIMITE_H
#define CONTA_LIMITE_H

#include "Conta.h"
#include <string>
using std::string;
#include <iostream>
using std::cout, std::endl;
#include <stdexcept>
using std::runtime_error;
#include <vector>
using std::vector;
#include <sstream>
using std::stringstream;
class ContaLimite : public Conta
{
public:
  ContaLimite(int conta, double limite = 200.0, double saldo = 0.0) : Conta(conta,saldo),limite(limite) {}
  
  virtual ~ContaLimite(){}
  void ver(double sald, double valor){
    if (sald-(valor+limite)<=0){
      throw runtime_error("Saldo Insuficiente.");
    }
  }
virtual string getTipoConta(){return "limite";}
  //sobrescrevendo método virtual retirada
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
  virtual double dados (){
    return limite;
  }
  //sobrescrevendo método virtual puro extrato
  virtual void extrato()
  {
    int i=0;
  if(tTransacoes>30){
      i=tTransacoes-30;
    }
    cout << "CONTA: " << conta << endl;
    cout << "LIMITE: " << limite << endl;
    cout << "Transações: " << endl;
    for (int i; i < tTransacoes ; i++)
      cout << Datas[i] << " " << Valores[i] << " " << Descricao[i] << endl;
    cout << "------------------------------" << endl;
    cout << "Saldo: R$ " << saldo << endl;
  }
virtual void set_dados(double d){
  limite=d;
}
private:
  double limite;
  vector<string> Datas;
  vector <double> Valores;
  vector <string> Descricao;
};

#endif