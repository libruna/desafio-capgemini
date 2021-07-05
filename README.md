# Divulga Tudo
## _Sistema de gerenciamento de anúncios_

_Divulga Tudo_ é um sistema de interface em terminal feito para que seus anúncios sejam gerenciados, possuindo as seguintes funcionalidades:

- Cadastro de anúncios
- Calculadora do alcance de visualizações
- Armazenamento de dados em arquivos

## Requisitos
Para baixar, compilar e executar o programa é necessário ter instalado os seguintes softwares na máquina. 
| Programa | Versão |
| ------ | ------ |
| DevC++ | 5.11 ou superior |
| MinGW | 3.4.2 ou superior |
| Git | 2.32.0 ou superior |

O programa faz uso de comandos de sistema específicos do Windows, sendo necessária a modificação do código no arquivo `main.cpp` para permitir compatibilidade com sistemas Linux/MacOS.

## Instalação
### Obtendo os arquivos
Para obter os arquivos, basta apenas executar no terminal o comando para clonar o repositório no diretório de preferência:
```sh
git clone https://github.com/libruna/desafio-capgemini.git
```
Ou ir até o link https://github.com/libruna/desafio-capgemini e baixar os arquivos do repositório pelas opções __Code > Download ZIP__
### Execução
Estando no Windows, preferencialmente Windows 10, é necessário apenas executar o arquivo ```Projeto1.exe``` para iniciar o programa. Para realizar edições no código, é necessário configurar a IDE DevC++.

##### Configurando o DevC++
Para configurar a versão do C++, clique em __Ferramentas > Opções do Compilador > Programas__ e adicione nos campos _gcc_ e _g++_ a flag ```-std=c++11``` e reinicie o DevC++, ignorando quaisquer mensagens de erro que surgirem.
### Compilação
Para gerar um arquivo executável, primeiramente abra o arquivo ```Projeto1.dev``` com a IDE DevC++.
Com o projeto carregado, basta ir em __Executar > Compilar e Executar__ para gerar um arquivo executável e rodar o programa.
