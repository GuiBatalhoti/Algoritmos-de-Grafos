/*
Classe feita para representar um grafo.

Sobre os atributos:
- lista: um vector de vector de "ItemLista", para implementar a lista de adjacência de um grafo. É organizado da seguinte maneira, 
		o elemento 0 do vector de vector, por exemplo, representa o primero vértice do grafo e sua respectiva lista de ligações. Logo,
		O i-ésimo elemento do vector de vector representa o vértice i+1 do grafo, e este i-ésimo elemento armazena a lsitad e ligações do vértice i+1.
		Para melhor entender o vector de "ItemLista", verificar os comentários no arquivo "ItemLista.h". Porém, este armazena em seu i-ésimo elemento
		um vértice e o respectivo peso de sua aresta.
- nVertices: número de vértices do grafo;
- log: ponteiro para o obejto EscritaLog que monta o arquivo de Log.txt.

Sobre os métodos:
- Grafo(std::vector<std::vector<ItemLista>> lista, int nVertices): contrutor da classe que recebe um vector de vector de "ItemLista" como parâmetro para o grafo;
- ~Grafo(): destrutor da classe apenas destrói o objeto;
- std::vector<ItemLista> getListaVerticeAdjacente(int v): retorna a lista de ligações de um determinado vértice passado por parâmetro;
- ItemLista getVerticePeso(int v1, int v2): retorna o "ItemLista" da ligação entre dois vétices;
- int getNumVertices(): retorna o número de vértices do grafo;
- void setNumVertices(): atribui o número de vértices ao objeto Grafo, recebido como parâmetro;
- std::vector<std::vector<ItemLista>> getLista(): retorna a lista de adjacência do grafo.
*/
#pragma once //utilizado em todos os cabeçalhos para evitar que o compialdor abra o arquivo mais de uma vez
#include <vector> //uso da estrutura "vector" built-in ao invés de um vetor[], por suas funções internas
#include "EscritaLog/EscritaLog.h"
#include "ItemLista/ItemLista.h"

class Grafo
{
private:
	std::vector<std::vector<ItemLista>> lista; /*vector de vector de "ItemLista", para implementar a lista de adjacência de um grafo. É organizado da seguinte maneira, 
		o elemento 0 do vector de vector, por exemplo, representa o primero vértice do grafo e sua respectiva lista de ligações. Logo,
		O i-ésimo elemento do vector de vector representa o vértice i+1 do grafo, e este i-ésimo elemento armazena a lsitad e ligações do vértice i+1.
		Para melhor entender o vector de "ItemLista", verificar os comentários no arquivo "ItemLista.h". Porém, este armazena em seu i-ésimo elemento
		um vértice e o respectivo peso de sua aresta.*/
	int nVertices; //número de vértices do grafo;
	EscritaLog* log; //ponteiro para o obejto EscritaLog que monta o arquivo de Log.txt.
public:
	Grafo();
	Grafo(std::vector<std::vector<ItemLista>> lista, int nVertices); //contrutor da classe que recebe um vector de vector de "ItemLista" como parâmetro para o grafo e o npumero de vértices do grafo;
	~Grafo(); //destrutor da classe apenas destrói o objeto;
	int getNumVertices(); //retorna o número de vértices do grafo;
	void setNumVertices(int n); //atribui o número de vértices ao objeto Grafo, recebido como parâmetro;
	std::vector<ItemLista> getListaVerticeAdjacente(int v); //retorna a lista de ligações de um determinado vértice passado por parâmetro;
	ItemLista getVerticePeso(int v1, int v2); //retorna o "ItemLista" da ligação entre dois vétices;
	std::vector<std::vector<ItemLista>> getLista(); //retorna a lista de adjacência do grafo, passando por parâmetro o vértice e seu adjacênte
};