#include "Anuncio.h"
#include "Data.h"
#include <iostream>
#include <fstream>

void Anuncio::setNome(string nome){
	this->nome = nome;
}
string Anuncio::getNome() {
	return nome;
}
void Anuncio::setCliente(string cliente){
	this->cliente = cliente;
}
string Anuncio::getCliente() {
	return cliente;
}
void Anuncio::setValorDiario(float valorDiario) {
	this->valorDiario = valorDiario;
}
float Anuncio::getValorDiario() {
	return valorDiario;
}
void Anuncio::setCliques(float cliques) {
	this->cliques = cliques;
}
float Anuncio::getCliques() {
	return cliques;
}
void Anuncio::setShares(float shares) {
	this->shares = shares;
}
float Anuncio::getShares() {
	return shares;
}
void Anuncio::setViewsTotal(float viewsTotal) {
	this->viewsTotal = viewsTotal;
}
float Anuncio::getViewsTotal() {
	return viewsTotal;
}

void Anuncio::cadastraAnuncio() {
	//cadastro de anuncios, é criado um arquivo para cada cliente
	string nome, cliente, arquivoNome;;
	int dia, mes, ano;
	float valorDiario;
	
	cout << "DIVULGA TUDO - CADASTRO DE ANUNCIOS" << endl;
	cout << "\nNome do anuncio: ";
	getline(cin, nome); 
	setNome(nome);
	cout << "Cliente: ";
	getline(cin, cliente);
	setCliente(cliente);
	arquivoNome = cliente + ".txt";
	
	cout << "Investimento por dia: ";
	cin >> valorDiario;
	setValorDiario(valorDiario);
	cout << "Dia inicial: ";
	cin >> dia;
	dataInicio.setDia(dia);
	cout << "Mes inicial: ";
	cin >> mes;
	dataInicio.setMes(mes);
	cout << "Ano inicial: ";
	cin >> ano;
	dataInicio.setAno(ano);
	cout << "Dia termino: ";
	cin >> dia;
	dataTermino.setDia(dia);
	cout << "Mes termino: ";
	cin >> mes;
	dataTermino.setMes(mes);
	cout << "Ano termino: ";
	cin >> ano;
	dataTermino.setAno(ano);
	
	//grava os dados no arquivo
	ofstream fileCliente;
	fileCliente.open(arquivoNome, ios::app);
	fileCliente << "Nome do Anuncio: " << getNome() << endl;
	fileCliente << "Nome do cliente: " << getCliente() << endl;
	fileCliente << "Valor investido por dia: " << getValorDiario() << endl;
	fileCliente << "Data inicio: " << dataInicio.getDia() << "/" << dataInicio.getMes() << "/" << dataInicio.getAno() << endl;
	fileCliente << "Data termino: " << dataTermino.getDia() << "/" << dataTermino.getMes() << "/" << dataTermino.getAno() << endl;
	fileCliente.close();
}

float Anuncio::calculaInvestimento(float valorDiario) {  //metodo para calcular a diferença entre duas datas
	
	int meses[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, aux = 0;
	float total = 0;
	
	//for que começa no mes inicial e acaba no mes de termino; percorre o array para encontrar quantos dias tem o mes
	for(int i = dataInicio.getMes(); i < dataTermino.getMes(); i++) 
		total += meses[i];
		
	//acha o dia maior e ordena para o resultado nao sair negativo
	if(dataTermino.getDia() > dataInicio.getDia()) {
		aux = dataInicio.getDia();
		dataInicio.getDia() == dataTermino.getDia();
		dataTermino.getDia() == aux;
	}
	//converte o ano para dias e soma os dias
	total += ((dataTermino.getAno() - dataInicio.getAno()) * 365) + (dataTermino.getDia() - dataInicio.getDia());
	//calcula qual o investimento total
	float investimentoTotal = total*valorDiario;
	return investimentoTotal;
}

//metodo que calcula a quantidade de views inicial
float Anuncio::calculaAlcanceInicial(float investimentoTotal) {
	float viewsInicial = 0;
	viewsInicial = (investimentoTotal * 100) * 0.3;
	return viewsInicial;
}

//metodo base parar calcular quantas novas views irao surgir em cada processo
float Anuncio::calculaViews(float views) {
	float cliques = views * 0.12;
	setCliques(getCliques() + cliques);
	float shares = cliques * 0.15;
	setShares(getShares() + shares);
	float novasViews = shares * 40;
	return novasViews;
}

//usando o metodo anterior calcula quantas novas views surgirao em cada geraçao e soma ao "viewsInicial"
float Anuncio::calculaAlcanceTotal(float viewsInicial) {
	
	float geracao2 = calculaViews(viewsInicial);
	float geracao3 = calculaViews(geracao2);
	float geracao4 = calculaViews(geracao3);

	float viewsTotal = viewsInicial + geracao2 + geracao3 + geracao4;
	
	//grava no final do arquivo com o nome do cliente
	string arquivoNome;
	arquivoNome = this->getCliente() + ".txt";
	fstream fileCliente;
	fileCliente.open(arquivoNome, ios::app);
	fileCliente << "Views total: " << (int)viewsTotal << endl;
	fileCliente.close();
	
/*	cout << "Visualizacoes inicial: " << viewsInicial << endl << "Segundo processo: " <<  geracao2 << endl
	<< "Terceiro processo: " << geracao3 << endl << "Quarto processo: "<< geracao4 << endl << "Final: "<< viewsTotal << endl; */
	return viewsTotal;
}
