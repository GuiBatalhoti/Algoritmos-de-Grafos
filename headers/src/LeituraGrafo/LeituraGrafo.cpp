// Informações no arquivo "Grafo.h"

#include "LeituraGrafo.h"

LeituraGrafo::LeituraGrafo()
{
	this->log = EscritaLog::getInstance();
	this->arquivo = std::fopen("../../Grafo.txt", "r");

	if (!this->arquivo) //caso não seja possível abrir o arquivo
	{
		this->log->escreveLog("ERRO NA ABERTURA DO ARQUIVO PARA LEITURA DO GRAFO!!\n");
		exit(1);
	}

	this->log->escreveLog("SUCESSSO NA ABERTURA DO ARQUIVO PARA LEITURA DO GRAFO!!\n");
	int nVertices, v1_atual, v1_anterior = 1, v2, peso; //número de vértices, vértice 1, vértice 2, peso da aresta
	ItemLista aux; //variável auxiliar
	std::vector<ItemLista> lista_aux; //variável auxiliar

	std::fseek(this->arquivo, 0, SEEK_SET); //garantindo que ponteiro de arquivo esteja no começo
	std::fscanf(this->arquivo, "%d", &nVertices); //leitura do número de vértices do grafo

	while (true) //leitura do resto do arquivo
	{
		std::fscanf(this->arquivo, "%d %d %d", &v1_atual, &v2, &peso); //leitura de três inteiros separados por espaço		
		
		//atribuindo os valores do objeto aux
		aux.setVertice(v2);
		aux.setPeso(peso);

		/*
		Se o vértice v1, for diferente da iteração anterior, quer dizer que mudamos de vértice, 
		logo é necessário colocarmos toda a informação deste na lista principal e limpar a lista auxiliar.
		*/
		if (v1_anterior != v1_atual)
		{
			this->lista.push_back(lista_aux);
			lista_aux.clear();			
		}

		//colocando a informação para o novo vértice
		lista_aux.push_back(aux);
		
		if (std::feof(arquivo)) // se encontrarmos o final do arquivo, paramos o loop
		{
			this->lista.push_back(lista_aux);
			break;
		}
		v1_anterior = v1_atual;
	}
	//Por fim, cria-se um grafo para recuperarmos depois
	gf = Grafo(this->lista, nVertices);
}

LeituraGrafo::~LeituraGrafo()
{
	this->log = EscritaLog::getInstance();
	this->log->escreveLog("Destrutor da classe LeituraGrafo executado.\n");
	std::fclose(this->arquivo);
	//destrutor da classe apenas tem a função de destruir o objeto
}