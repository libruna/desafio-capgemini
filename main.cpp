#include <iostream>
#include <fstream>
#include "Anuncio.h"
#include "Data.h"

using std::cout;		using std::ofstream;
using std::endl;		using std::ifstream;
using std::cin;			using std::ios;
using std::string;		using std::ofstream;

void menu() {
	cout << "\n1 >> Cadastrar Anuncio." << endl;
	cout << "2 >> Pesquisar cliente." << endl;
	cout << "3 >> Sair." << endl;
}

int main() {
	
	Anuncio anuncio;  //instanciando o objeto "anuncio"
	
	int op, i = 0, cont = 0;
	string arquivoNome, nome_cliente, nome_anuncio;
	
	while(op != 3) {
		menu();
		cin >> op;
		switch(op) {
			case 1: {
				//cadastro de anuncios
				system("cls");
				cin.ignore();
				anuncio.cadastraAnuncio();
				float alcance_inicial = anuncio.calculaAlcanceInicial(anuncio.calculaInvestimento(anuncio.getValorDiario()));
				anuncio.calculaAlcanceTotal(alcance_inicial);
				break;
			}
			case 2: {
				//pesquisa o cliente, se encontrar, pesquisa pelo nome do anuncio, se encontrado, imprime as informaçoes
				system("cls");
				cin.ignore();
				cout << "Digite o nome do cliente: ";
				getline(cin, nome_cliente);
		
				arquivoNome = nome_cliente + ".txt";
				ifstream fileCliente;
				fileCliente.open(arquivoNome);
				string linha;
				
				if(fileCliente.is_open()) {
					cout << "Digite o nome do anuncio que deseja visualizar: ";
					cin >> nome_anuncio;
					while(getline(fileCliente, linha)) {
						if(linha == nome_anuncio) {
							cont = i;
						}
						if(cont + 1 == i) 
							cout << linha << endl;
						if(cont + 2 == i) 
							cout << linha << endl;
						if(cont + 3 == i) 
							cout << linha << endl;
						if(cont + 4 == i) 
							cout << linha << endl;
						if(cont + 5 == i) 
							cout << linha << endl;
						i++;
					}
				}
				else {
					cout << "\n\tO cliente não existe no sistema!" << endl;
				}
				break;
			}
			case 3: {
				system("cls");
				cout << "Saindo..." << endl;
				exit(3);
				break;
			}
		}
	}
	
	return 0;
}

//fim
