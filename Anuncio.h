#ifndef ANUNCIO_H
#define ANUNCIO_H
#include "Data.h"
#include <iostream>

using std::cout;		using std::ofstream;
using std::endl;		using std::ifstream;
using std::cin;			using std::ios;
using std::string;		using std::fstream;

class Anuncio { //classe principal anuncio
	private:
		string nome, cliente; 
		float valorDiario, viewsTotal, cliques, shares;
		Data dataInicio, dataTermino;  //instanciando o objeto data
		
	public:
		//métodos da classe anuncio com get e set para acessar as variáveis privadas
		void setNome(string nome);
		string getNome();
		void setCliente(string cliente);
		string getCliente();
		void setValorDiario(float valorDiario);
		float getValorDiario();
		void setCliques(float cliques);
		float getCliques();
		void setShares(float shares);
		float getShares();
		void setViewsTotal(float viewsTotal);
		float getViewsTotal();
		
		void cadastraAnuncio();
		float calculaInvestimento(float valorDiario);
		float calculaAlcanceInicial(float investimentoTotal);
		float calculaViews(float views);
		float calculaAlcanceTotal(float viewsInicial);
};

#endif
