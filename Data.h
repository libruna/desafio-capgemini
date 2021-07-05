#ifndef DATA_H
#define DATA_H
#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::string;

class Data {  //classe data para manipular data inicial e data termino
	private:
		int dia, mes, ano;
		float valorDiario;
		
	public:
		void setDia(int dia);
		int getDia();
		void setMes(int mes);
		int getMes();
		void setAno(int ano);
		int getAno();
};

#endif
