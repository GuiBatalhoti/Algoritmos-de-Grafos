/*
Classe criada para implementar o Algoritmo de Dijkstra passado em aula.

Sobre os atributos:
- grafo: grafo passado para performar o algoritmo;
- raiz: vértice origem escolhido pelo usuário;
- numVertices: número de vértices do grafo;
- abertos: vector de vértices não processados;
- visitados: vector de vértices já processados;
- distancia: organizado da seguinte maneira: o i-ésimo elemento do vector é a distância do vértice i até a raiz;
- verticePai: organizado da seguinte maneira: o i-ésimo elemento do vector é o antecessor do vértice i;
- log: ponteiro para o obejto EscritaLog que monta o arquivo de Log.txt.

Sobre os métodos:
- Dijkstra(int numVertices, int raiz, Grafo grafo): construtor que recebe como parâmetro o número de vértices do grafo, a raiz escolhida e o grafo lido. Inicializa os vectors aberto, visistatos e distância;
- ~Dijkstra(): apenas destrói o obejeto;
- void Relaxa(int vAtual, int vAdjacente, int i): recebe como parâmetro o vértice atual, seu adjacente e a posição na lista ligada de adjacência. Faz o relaxamento das arestas para verificar se é possivel melhorar o caminho atual, passado em aula;
- void ImprimeCaminhos(int vFinal): imprime os caminhos da raiz até o vértice final passado como parâmetro;
- void Algoritmo(): performa o algoritmo de Dijkstra;
- int ExtrairMinimo(): método passado em aula que extrai a menor distância dos vértices ainda não processados.
*/

#pragma once //utilizado em todos os cabeçalhos para evitar que o compilador abra o arquivo mais de uma vez
#include <iostream>
#include <vector> //uso da estrutura "vector" built-in ao invés de um vetor, por suas funções internas
#include <limits> //uso da constante "INT_MAX" para as distâncias
#include "Grafo/Grafo.h"
#include "ItemLista/ItemLista.h"
#include "EscritaLog/EscritaLog.h"

class Dijkstra
{
private:
	Grafo grafo; //grafo passado para performar o algoritmo
	int raiz; //vértice origem escolhido pelo usuário
	int numVertices; //número de vértices do grafo
	std::vector<int> abertos; //vector de vértices não processado
	std::vector<int> visitados; //vector de vértices já processados
	std::vector<int> distancia; //organizada da seguinte maneira: o i-ésimo elemento do vector é a distância do vértice i até a raiz
	std::vector<int> verticePai; //organizada da seguinte maneira: o i-ésimo elemento do vector é o antecessor do vértice i
	EscritaLog* log; //ponteiro para o obejto EscritaLog que monta o arquivo de Log.txt

public:
	Dijkstra(int numVertices, int raiz, Grafo grafo); //cosntrutor que recebe como parâmetro o número de vértices do grafo, a raiz escolhida e o grafo lido. Inicializa os vectors aberto, visistatos e distância;
	~Dijkstra(); //apenas destrói o objeto;
	void Relaxa(int vAtual, int vAdjacente, int i); //recebe como parâmetro o vértice atual, seu adjacente e a posição na lista ligada de adjacência. Faz o relaxamento das arestas para verificar se é possível melhorar o caminho atual, passado em aula;
	void ImprimeCaminhos(int vFinal); //imprime os caminhos da raiz até o vértice final passado como parâmetro;
	void Algoritmo(); //performa o algoritmo de Dijkstra;
	int ExtrairMinimo(); //método passado em aula que extrai a menor distância dos vértices ainda não processados.
};