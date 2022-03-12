/*
Classe feita para criar um objeto que armazenasse as ligações da lista de adjacência de um determinado vértice

Sobre os atributos:
- vertice: contém o número do segundo vértice da ligação da aresta;
- peso: contém o peso da aresta que esdtá ligando os dois vértices;
- log: ponteiro para o obejto EscritaLog que monta o arquivo de Log.txt.

Sobre os métodos:
- ItemLista(int v, int p): sobre carga de contrutores, primeiro contrutor da classe que recebe o segundo vértice da aresta e o peso da mesma,
	 e segundo contrutor é vazio;
- ~ItemLista(): destrutor da classe, apenas destrói o objeto;
- int getVertice(): retorna o número do segundo vértice da aresta;
- void setVertice(int v): atribui ao objeto o número do vértice;
- int getPeso(): retorna o peso da aresta;
- void setPeso(int p): atribui ao objeto o peso da aresta.
*/
#pragma once //utilizado em todos os cabeçalhos para evitar que o compialdor abra o arquivo mais de uma vez
#include "EscritaLog/EscritaLog.h"

class ItemLista
{
protected:
	EscritaLog* log; //ponteiro para o obejto EscritaLog que monta o arquivo de Log.txt
private:
	int vertice; //vértice adjacênte
	int peso; //peso da aresta
public:
	ItemLista(int v, int p); //sobrecarga de contrutores, primeiro contrutor da classe que recebe o segundo vértice da aresta e o peso da mesma, e segundo contrutor é vazio;
	ItemLista();
	~ItemLista(); //destrutor da classe, apenas destrói o objeto;
	int getVertice(); //retorna o número do segundo vértice da aresta;
	void setVertice(int v); //atribui ao objeto o número do vértice, passado por parâmetro
	int getPeso(); //retorna o peso da aresta;
	void setPeso(int p); //atribui ao objeto o peso da aresta, passado por parâmetro
};