#include <vector> //uso da estrutura "vector" built-in ao invés de um vetor[], por suas funções internas
#include "Grafo.h"

Grafo::Grafo(std::vector<std::vector<ItemLista>> lista, int nVertices)
{
	this->log = EscritaLog::getInstance();
	this->log->escreveLog("Contrutor da classe Grafo executado.\n");
	this->lista = lista;
	this->nVertices = nVertices;
}

Grafo::Grafo()
{
	this->log = EscritaLog::getInstance();
}

Grafo::~Grafo()
{
	this->log = EscritaLog::getInstance();
	this->log->escreveLog("Destrutor da classe Grafo executao.\n");
}

std::vector<ItemLista> Grafo::getListaVerticeAdjacente(int v)
{
	this->log = EscritaLog::getInstance();
	this->log->escreveLog("Chamada do método getListaVerticeAdjacente da classe Grafo.\n");
	return this->lista[v];
}

ItemLista Grafo::getVerticePeso(int v1, int v2)
{
	this->log = EscritaLog::getInstance();
	this->log->escreveLog("Chamada do método getVerticePeso da classe Grafo.\n");
	return this->lista[v1][v2];
}

std::vector<std::vector<ItemLista>> Grafo::getLista()
{
	this->log = EscritaLog::getInstance();
	this->log->escreveLog("Chamada do método getLista da classe Grafo.\n");
	return this->lista;
}

int Grafo::getNumVertices()
{
	this->log = EscritaLog::getInstance();
	this->log->escreveLog("Chamada do método getNumVertices da classe Grafo.\n");
	return this->nVertices;
}

void Grafo::setNumVertices(int n)
{
	this->log = EscritaLog::getInstance();
	this->log->escreveLog("Chamada do método setNumVertices da classe Grafo.\n");
	this->nVertices = n;
}