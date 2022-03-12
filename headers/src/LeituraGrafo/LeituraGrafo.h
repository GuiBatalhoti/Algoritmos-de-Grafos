/*
Classe feita para a leitura do arquivo ".txt" que contém o grafo.

Sobre os atributos:
- arquivo: ponteiro para o aquivo a ser lido;
- lista: vector contrupido da mesma maneira que a lista de adjacência da classe Grafo;
- log: ponteiro para o obejto EscritaLog que monta o arquivo de Log.txt;
- gf: grafo lido.

Sobre os métodos:
- LeituraGrafo(): contrutor da classe que lê oa rquivo "Grafo.txt" e monta um objeto Grafo;
- ~LeituraGrafo(): destrutor da classe, nehuma outra função além de destuir o obejto;
*/

#pragma once //utilizado em todos os cabeçalhos para evitar que o compialdor abra o arquivo mais de uma vez

#include <vector>
#include <iostream>
#include <cstdio>
#include <string>
#include "EscritaLog/EscritaLog.h"
#include "Grafo/Grafo.h"
#include "ItemLista/ItemLista.h"

class LeituraGrafo
{
private:
	EscritaLog* log; //ponteiro para o obejto EscritaLog que monta o arquivo de Log.txt;
	std::FILE* arquivo; //ponteiro para o aquivo a ser lido;
	std::vector<std::vector<ItemLista>> lista; //vector contrupido da mesma maneira que a lista de adjacência da classe Grafo;

public:
	Grafo gf; //grafo lido.
	LeituraGrafo(); //contrutor da classe que lê oa rquivo "Grafo.txt" e monta um objeto Grafo;
	~LeituraGrafo(); //destrutor da classe, nehuma outra função além de destuir o obejto;
};
