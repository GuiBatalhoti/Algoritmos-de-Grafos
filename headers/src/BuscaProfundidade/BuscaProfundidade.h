/*
Classe criada para performar o algoritmo de bsuca em profundidade fo grafo.

Sobre os atributos:
- gf: grafo a ser feita a busca;
- finalizações: armazena os tempos de finalizações dos vértices, i-ésimo elemento representa o tempo do vertice i;
- descoberta: armazena os tempos de descoberta dos vértices, i-ésimo elemento representa o tempo do vertice i;
- cores: armazena os valores definidas para as cores, Braco(não processado), Cinza(descoberto), Preto(finalziado), i-ésimo elemento representa a cor do vertice i;
- ordemFinal: armazena a ordem topológica;
- tempo: armazena o tempo do algoritmo;
- log: ponteiro para o obejto EscritaLog que monta o arquivo de Log.txt.

Sobre os métodos:
- BuscaProfundidade(Grafo grafo): construtor que recebe como parâmetro o grafo lido, e inicializa os vectors de finalizacoes, descoberta, cores.
	E inicia a busca em profundidade e a ordem topológica;
- ~BuscaProfundidade(): destrutor da classe apenas destrói a classe;
- void DFS_Visit(int u): visita os vértices adjacentes, recebe um vértice "u" como parâmetro;
- void ordemFInal(): monta a ordem topológica do grafo;
- std::vector<int> getOrdemFinal(): retorna a ordem topológica do grafo.
*/

#pragma once //utilizado em todos os cabeçalhos para evitar que o compialdor abra o arquivo mais de uma vez
#include "Grafo/Grafo.h"
#include "ItemLista/ItemLista.h"
#include "EscritaLog/EscritaLog.h"
#include <vector>
#include <algorithm> //uso do std::max_element()


//defines para o valor definido para a cor, assim é mais simples compreender qual cor é utilizada 
#define BRANCO 1
#define CINZA 2
#define PRETO 3


class BuscaProfundidade
{
private:
	Grafo gf;
	std::vector<int> finalizacoes; //i-ésimo elemento representa o tempo do vertice i
	std::vector<int> descoberta; //i-ésimo elemento representa o tempo do vertice i
	std::vector<int> cores; //i-ésimo elemento representa a cor do vertice i
	std::vector<int> ordemFinal; //lista encadeada
	int tempo; //armazena o tempo do algoritmo
	EscritaLog* log; //ponteiro para o obejto EscritaLog que monta o arquivo de Log.txt

public:
	BuscaProfundidade(Grafo grafo); //construtor que recebe como parâmetro o grafo lido, e inicializa os vectors de finalizacoes, descoberta, cores
	~BuscaProfundidade(); //destrutor da classe apenas destrói a classe
	void DFS_Visit(int u); //visita os vértices adjacentes, recebe um vértice "u" como parâmetro
	void ordencaoFinal(); //monta a ordem topológica do grafo
	std::vector<int> getOrdemFinal(); //retorna a ordem topológica do grafo
};

