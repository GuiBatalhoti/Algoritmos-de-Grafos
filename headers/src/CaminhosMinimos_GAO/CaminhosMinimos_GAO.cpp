//mais informações no arquivo "CaminhosMinimos_GAO.h"

#include "CaminhosMinimos_GAO.h"

CaminhosMinimos_GAO::CaminhosMinimos_GAO(Grafo grafo)
{
	this->log = EscritaLog::getInstance();
	this->log->escreveLog("Contrutor da classe CaminhosMinimos_GAO executado.\n");
	
	this->gf = grafo;
 	BuscaProfundidade busca(this->gf);
	this->ordemTopologica = busca.getOrdemFinal();
	for (int i = 0; i < this->gf.getNumVertices(); i++)
	{
		//preenche os valroes dos vetores para inicialização
		this->distancia.push_back(INT_MAX); //distância "infinita", no caso o maiorr valor possível para um variável do tipo inteiro
		this->verticePai.push_back(-1); //inicialmente não se considera os vértices adjacentes, innicial,mente consideraremos NULL como -1
	}
	this->raizTopologica = this->ordemTopologica[0];
	this->distancia[0] = 0;
}

CaminhosMinimos_GAO::~CaminhosMinimos_GAO()
{
	this->log = EscritaLog::getInstance();
	this->log->escreveLog("Destrutor da classe CaminhosMinimos_GAO executado.\n");
}

void CaminhosMinimos_GAO::Algoritmo()
{
	this->log = EscritaLog::getInstance();
	this->log->escreveLog("Método Algoritmo da classe CaminhosMinimos_GAO executado.\n");

	for (int i = 0; i < this->ordemTopologica.size(); i++)
	{
		std::vector<ItemLista> aux = this->gf.getListaVerticeAdjacente(this->ordemTopologica[i]);
		for (int j = 0; j < aux.size(); j++)
		{
			ItemLista adj = aux[j];
			this->Relaxa(this->ordemTopologica[i], adj.getVertice()-1, j);
		}	
	}
}

void CaminhosMinimos_GAO::Relaxa(int vAtual, int vAdjacente, int i)
{
	this->log = EscritaLog::getInstance();
	this->log->escreveLog("Método Relaxa da classe CaminhosMinimos_GAO executado.\n");

	ItemLista aux = this->gf.getVerticePeso(vAtual, i);
	if (this->distancia[vAdjacente] > (this->distancia[vAtual] + aux.getPeso()))
	{
		this->distancia[vAdjacente]  = this->distancia[vAtual] + aux.getPeso();
		this->verticePai[vAdjacente] = vAtual;
	}
	
	this->log->escreveLog("\nDistância (vértice:distância): ");
	for (int i = 0; i < this->distancia.size(); i++)
		this->log->escreveLog(std::to_string(i+1) + ":" + std::to_string(this->distancia[i]) + "  ");
	this->log->escreveLog("\n\nPredecessor (vértice:predecessor): ");
	for (int i = 0; i < this->verticePai.size(); i++)
		this->log->escreveLog(std::to_string(i+1) + ":" + std::to_string(this->verticePai[i]+1) + "  ");
	this->log->escreveLog("\n\n");
}

void CaminhosMinimos_GAO::ImprimeCaminhos(int vFinal)
{
	this->log = EscritaLog::getInstance();
	this->log->escreveLog("Método ImprimeCaminhos da classe CaminhosMinimos_GAO executado.\n");

	if (this->raizTopologica == vFinal)
	{
		std::cout << this->raizTopologica+1;
		this->log->escreveLog(std::to_string(this->raizTopologica+1));
	}
	else if (this->verticePai[vFinal] == -1)
	{
		std::cout << "Nao existe trajeto" << std::endl;
		this->log->escreveLog("Não existe trajeto.");
	}
	else
	{
		this->ImprimeCaminhos(this->verticePai[vFinal]);
		std::cout << " - " << vFinal+1;
		this->log->escreveLog(" - " + std::to_string(vFinal+1));
	}
}

int CaminhosMinimos_GAO::getPrimeiroVertice()
{
	this->log = EscritaLog::getInstance();
	this->log->escreveLog("Método detPrimeiroVertice da classe CaminhosMinimos_GAO executado.\n");
	return this->ordemTopologica[0]+1;
}