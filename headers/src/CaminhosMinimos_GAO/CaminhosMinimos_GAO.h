/*
Classe criada para performar o algoritmo de Caminhos Mínimos passado em aula.

Sobre os atributos:
- gf: grafo passado para performar o algoritmo;
- ordemtopologica: armazena a ordem topológica do grafo;
- distancia: organizado da seguinte maneira: o i-ésimo elemento do vector é a distância do vértice i até a raiz;
- verticePai: organizado da seguinte maneira: o i-ésimo elemento do vector é o antecessor do vértice i;
- raizTopologica: armazena o primeiro vértice da ardem topológica;
- log: ponteiro para o obejto EscritaLog que monta o arquivo de Log.txt.

Sobre os métodos:
- CaminhosMinimos_GAO(Grafo grafo): construtor que recebe como parâmetro o grafo lido, e inicializa os vectors de distância, verticePai, e a ordem topológica.
- ~CaminhosMinimos_GAO(): destrutor da classe apenas destrói a classe;
- void Relaxa(int vAtual, int vAdjacente, int i): recebe como parâmetro o vértice atual, seu adjacente e a posição na lista ligada de adjacência. Faz o relaxamento das arestas para verificar se é possivel melhorar o caminho atual, passado em aula;
- void Algoritmo(): performa o algoritmo de Caminhos Mínimos;
- void ImprimeCaminhos(int vFinal): imprime os caminhos da raiz até o vértice final passado como parâmetro;
- int getPrimeiroVertice(): retorna o primero vértice da ordem topológica.
*/

#pragma once //utilizado em todos os cabeçalhos para evitar que o compialdor abra o arquivo mais de uma vez
#include <iostream>
#include <vector> //uso da estrutura "vector" built-in ao invés de um vetor, por suas funções internas
#include <limits> //uso da contante "INT_MAX" para as distâncias
#include "Grafo/Grafo.h"
#include "ItemLista/ItemLista.h"
#include "BuscaProfundidade/BuscaProfundidade.h"
#include "EscritaLog/EscritaLog.h"

class CaminhosMinimos_GAO
{
private:
	Grafo gf; //grafo passado para performar o algoritmo;
	std::vector<int> ordemTopologica; //armazena a ordem topológica do grafo;
	std::vector<int> distancia; //organizado da seguinte maneira: o i-ésimo elemento do vector é a distância do vértice i até a raiz;
	std::vector<int> verticePai; //organizada da seguinte maneira: o i-ésimo elemento do vector é o antecessor do vértice i
	int raizTopologica; //armazena o primeiro vértice da ardem topológica;
	EscritaLog* log; //ponteiro para o obejto EscritaLog que monta o arquivo de Log.txt.

public:
	CaminhosMinimos_GAO(Grafo grafo); //construtor que recebe como parâmetro o grafo lido, e inicializa os vectors de distância, verticePai, e a ordem topológica.
	~CaminhosMinimos_GAO(); //destrutor da classe apenas destrói a classe;
	void Relaxa(int vAtual, int vAdjacente, int i); //recebe como parâmetro o vértice atual, seu adjacente e a posição na lista ligada de adjacência. Faz o relaxamento das arestas para verificar se é possível melhorar o caminho atual, passado em aula;
	void Algoritmo(); //performa o algoritmo de Caminhos Mínimos;
	void ImprimeCaminhos(int vFinal); //imprime os caminhos da raiz até o vértice final passado como parâmetro;
	int getPrimeiroVertice(); //retorna o primero vértice da ordem topológica.
};