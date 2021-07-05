#include <iostream>

using std::cout;	
using std::endl;	
using std::cin;		

float calculaViews(float views) {
	float cliques = views * 0.12;
	float shares = cliques * 0.15;
	float novasViews = shares * 40;
	return novasViews;
}

int main() {
	float investimento = 0;
	cout << "Quanto deseja investir no anuncio?" << endl << "Valor em reais: ";
	cin >> investimento;
	float geracao1 = investimento*30;
	float geracao2 = calculaViews(geracao1);
	float geracao3 = calculaViews(geracao2);
	float geracao4 = calculaViews(geracao3);

	float viewsTotal = geracao1 + geracao2 + geracao3 + geracao4;
	
	cout << "Alcance total aproximado de " << (int)viewsTotal << " pessoas";
	return 0;
}
