//Mains informações em "ItemLista.h"

#include "ItemLista.h"

ItemLista::ItemLista(int v, int p)
{
	//Contrutor da classe que recebe o número do vértice adjacênte e seu peso
	this->log = EscritaLog::getInstance();
	this->log->escreveLog("Contrutor da classe ItemLista executado.\n");
	this->vertice = v;
	this->peso = p;
}

ItemLista::ItemLista()
{
	this->log = EscritaLog::getInstance();
}

ItemLista::~ItemLista()
{
	//Destrutor da classe não possui outra função, além da destrução
	this->log = EscritaLog::getInstance();
	this->log->escreveLog("Destrutor da classe ItemLista executado.\n");
}

int ItemLista::getVertice()
{
	this->log = EscritaLog::getInstance();
	this->log->escreveLog("Método getVertice da classe ItemLista executado.\n");
	return this->vertice;
}

void ItemLista::setVertice(int v)
{
	this->log = EscritaLog::getInstance();
	this->log->escreveLog("Método setVertice da classe ItemLista executado.\n");
	this->vertice = v;
}

int ItemLista::getPeso()
{
	this->log = EscritaLog::getInstance();
	this->log->escreveLog("Método getVertice da classe ItemLista executado.\n");
	return this->peso;
}

void ItemLista::setPeso(int p)
{
	this->log = EscritaLog::getInstance();
	this->log->escreveLog("Método setPeso da classe ItemLista executado.\n");
	this->peso = p;
}