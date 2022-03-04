#ifndef CONTA_H
#define CONTA_H

#include <string>
using std::string;
#include<iostream>
using std::ostream;
class Conta {
public:
  Conta(int conta, double saldo = 0.0): conta(conta),saldo(saldo) { tTransacoes = 0; }
  
  virtual ~Conta() {}
  virtual void operator >>(double valor)=0;
  virtual void operator <<(double valor)=0;
  virtual void transfer(double valor)=0;
  virtual void receber(double valor)=0;
  virtual double dados()=0;
  virtual void set_dados(double d)=0;
  //é igual nos 3 tipos de conta. Não precisa ser virtual
  //deve ser virtual puro porque cada classe derivada deve implementar do seu jeito. A classe se torna abstrata porque este método é virtual puro
  virtual string getTipoConta()=0;
  virtual void extrato() = 0;
  int getConta()const {return conta;}
  double getSaldo()const {return saldo;}
  void setSaldo(double s){saldo=s;}
protected:
  int conta;
  double saldo;
  //definição de um registro restrito à classe e derivadas
  //Por questões de simplificação, definimos a "lista" de transações como um array de 200 elementos
  int tTransacoes;


};

#endif