// mais informações no arquivo "BuscaProfundidade.h"

#include "BuscaProfundidade.h"

BuscaProfundidade::BuscaProfundidade(Grafo grafo)
{
	this->log = EscritaLog::getInstance();
	this->log->escreveLog("Contrutor da classe BuscaProfundidade executado.\n");

	this->gf = grafo;
	this->tempo = 0;
	for (int i = 0; i < this->gf.getNumVertices(); i++)
	{
		this->cores.push_back(BRANCO);
		this->descoberta.push_back(-1);
		this->finalizacoes.push_back(-1); 
	}
	for (int i = 0; i < this->gf.getNumVertices(); i++)
	{
		if (this->cores[i] == BRANCO)
			this->DFS_Visit(i);
	}
	
	this->ordencaoFinal();
}

BuscaProfundidade::~BuscaProfundidade()
{
	this->log = EscritaLog::getInstance();
	this->log->escreveLog("Destrutor da classe BuscaProfundidade executado.\n");
}

void BuscaProfundidade::DFS_Visit(int u)
{
	this->log = EscritaLog::getInstance();
	this->log->escreveLog("Método DFS_Visit da classe BuscaProfundidade executado.\n");

	this->cores[u] = CINZA;
	this->tempo++;
	this->descoberta[u] = this->tempo;

	std::vector<ItemLista> lista_aux = this->gf.getListaVerticeAdjacente(u);
	for (int i = 0; i < lista_aux.size(); i++)
	{
		ItemLista aux = lista_aux[i];
		if (this->cores[aux.getVertice()-1] == BRANCO)
			this->DFS_Visit(aux.getVertice()-1);	
	}
	
	this->cores[u] = PRETO;
	this->tempo++;
	this->finalizacoes[u] = tempo;
}


std::vector<int> BuscaProfundidade::getOrdemFinal()
{
	this->log = EscritaLog::getInstance();
	this->log->escreveLog("Método getOrdemFinal da classe BuscaProfundidade executado.\n");
	return this->ordemFinal;
}

void BuscaProfundidade::ordencaoFinal()
{
	this->log = EscritaLog::getInstance();
	this->log->escreveLog("Método ordenacaoFinal da classe BuscaProfundidade executado.\n");

	//variável auxiliar
	std::vector<int> aux = this->finalizacoes;
	auto max = aux.begin(); //inicialização do iterator
	while (!aux.empty())
	{
		max = std::max_element(aux.begin(), aux.end());
		for (int i = 0; i < this->finalizacoes.size(); i++)
		{
			if (this->finalizacoes[i] == *max)
			{
				this->ordemFinal.push_back(i);
				break;
			}
		}
		aux.erase(max);
	}			
}