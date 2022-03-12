#include "Dijkstra.h"

Dijkstra::Dijkstra(int numVertices, int raiz, Grafo grafo)
{
	this->log = EscritaLog::getInstance();
	this->log->escreveLog("Contrutor da classe Dijkstra executado.\n");
	this->grafo = grafo;
	this->numVertices = numVertices;
	this->raiz = raiz-1;
	for (int i = 0; i < numVertices; i++)
	{
		//preenche os valroes dos vetores para inicialização
		this->abertos.push_back(i);
		this->distancia.push_back(INT_MAX); //distância "infinita", no caso o maiorr valor possível para um variável do tipo inteiro
		this->verticePai.push_back(-1); //inicialmente não se considera os vértices adjacentes, innicial,mente consideraremos NULL como -1
	}
	this->distancia[this->raiz] = 0; //o vértoce raiz não tem distância até ele mesmo    
}

Dijkstra::~Dijkstra()
{
	this->log = EscritaLog::getInstance();
	this->log->escreveLog("Destrutor da classe Dijkstra executado.\n");
}

void Dijkstra::ImprimeCaminhos(int vFinal)
{
	this->log = EscritaLog::getInstance();
	this->log->escreveLog("Método ImprimeCaminhos da classe Dijkstra executado.\n");

	if (this->raiz == vFinal)
	{
		std::cout << this->raiz+1;
		this->log->escreveLog(std::to_string(this->raiz+1));
	}
	else if (this->verticePai[vFinal] == -1)
	{
		std::cout << "Nao existe trajeto" << std::endl;
		this->log->escreveLog("Não existe trajeto.");
	}
	else
	{
		this->ImprimeCaminhos(verticePai[vFinal]);
		std::cout << " - " << vFinal+1;
		this->log->escreveLog(" - " + std::to_string(vFinal+1));
	}
}

void Dijkstra::Relaxa(int vAtual, int vAdjacente, int i)
{
	this->log = EscritaLog::getInstance();
	this->log->escreveLog("Método Relaxa da classe Dijkstra executado.\n");

	ItemLista aux = this->grafo.getVerticePeso(vAtual, i);
	if (this->distancia[vAdjacente] > (this->distancia[vAtual] + aux.getPeso()))
	{
		this->distancia[vAdjacente]  = this->distancia[vAtual] + aux.getPeso();
		this->verticePai[vAdjacente] = vAtual;
	}
	this->log->escreveLog("\nAbertos: ");
	for (int i = 0; i < this->abertos.size(); i++)
		this->log->escreveLog(std::to_string(this->abertos[i]+1) + "  ");
	this->log->escreveLog("\n\nVisistados: ");
	for (int i = 0; i < this->visitados.size(); i++)
		this->log->escreveLog(std::to_string(this->visitados[i]+1) + "  ");
	this->log->escreveLog("\n\nDistância (vértice:distância): ");
	for (int i = 0; i < this->distancia.size(); i++)
		this->log->escreveLog(std::to_string(i+1) + ":" + std::to_string(this->distancia[i]) + "  ");
	this->log->escreveLog("\n\nPredecessor (vértice:predecessor): ");
	for (int i = 0; i < this->verticePai.size(); i++)
		this->log->escreveLog(std::to_string(i+1) + ":" + std::to_string(this->verticePai[i]+1) + "  ");
	this->log->escreveLog("\n\n");
}

int Dijkstra::ExtrairMinimo()
{
	this->log = EscritaLog::getInstance();
	this->log->escreveLog("Método ExtrairMinimo da classe Dijkstra executado.\n");

	int i, v, atual, anterior = INT_MAX; //incialmente o anterior tem valor infinito
	for (i = 0; i < this->distancia.size(); i++)
	{
		atual = this->distancia[i];
		if (atual < anterior)
			for (int j = 0; j < this->abertos.size(); j++)
				if (this->abertos[j] == i) //se estiver no vetor de nós em aberto
				{
					anterior = atual;
					v = i;
				}
	}
	
	return v;
}

void Dijkstra::Algoritmo()
{
	this->log = EscritaLog::getInstance();
	this->log->escreveLog("Método Algoritmo da classe Dijkstra executado.\n");
	
	while (!this->abertos.empty())
	{
		int u = this->ExtrairMinimo();
		this->visitados.push_back(u);
		auto i = this->abertos.begin();
		for (i = i; i != this->abertos.end(); i++) //encontra o iterator relativo à posição encontrada
		{
			if (*i == u)
				break;		
		}
		this->abertos.erase(i); //função erase recebe apenas iterator como parâmetro

		std::vector<ItemLista> aux = this->grafo.getListaVerticeAdjacente(u);
		
		for (int i = 0; i < aux.size(); i++)
		{
			ItemLista adj = aux[i];
			this->Relaxa(u, adj.getVertice()-1, i);
		}
	}
	
}