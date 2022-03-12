/*
Feito por Guilherme Eduardo Silva Batalhoti
O arquivo main.cpp controla as escolhas principais do programa.
*/

#include <iostream>

#include "Grafo/Grafo.h"
#include "ItemLista/ItemLista.h"
#include "LeituraGrafo/LeituraGrafo.h"
#include "Dijkstra/Dijkstra.h"
#include "CaminhosMinimos_GAO/CaminhosMinimos_GAO.h"
#include "EscritaLog/EscritaLog.h"

int main()
{
	// leitura do grafo passado noa rquivo texto
	EscritaLog* log = EscritaLog::getInstance();
	LeituraGrafo leitura;
	Grafo grafo(leitura.gf.getLista(), leitura.gf.getNumVertices());
	int opcao, raiz; //variáveis auxiliares de escolha

	do
	{
		opcao = raiz = -1; //grantia que nenhuma opção será escolhida sem a escolha do usuário
		std::cout << "Escolha uma opcao:" << std::endl;
		std::cout << "1- Algoritmo de Dikstra;" << std::endl;
		std::cout << "2- Caminhos minimos;" << std::endl;
		std::cout << "0- Sair." << std::endl << std::endl;
		std::cout << "Sua opcao: ";
		std::scanf("%d", &opcao);

		if (opcao == 1)
		{
			system("cls");
			std::cout << "Escolha um vertice (1, 2, 3, 4, ...) como origem: ";
			std::scanf("%d", &raiz);
			std::cout << std::endl;

			Dijkstra alg1(grafo.getNumVertices(), raiz, grafo);
			alg1.Algoritmo();
			for (int i = 0; i < grafo.getNumVertices(); i++)
			{
				std::cout << "Caminho: " << raiz << " ate " << i+1 << std::endl;
				log->escreveLog("Caminho: " + std::to_string(raiz) + " até " + std::to_string(i+1) + "\n");				
				alg1.ImprimeCaminhos(i);
				log->escreveLog("\n\n");	
				std::cout << std::endl << "----------------------------------------------------" << std::endl;
			}

			std::cout << std::endl << "Pressione qualquer tecla para retornar ao menu..." << std::endl;
			log->escreveLog("\n\nSAÍDA DO ALGORITMO DE DIJKSTRA!! \n\n\n");
			system("pause");
		}
		else if (opcao == 2)
		{
			system("cls");
			CaminhosMinimos_GAO alg2(grafo);
			alg2.Algoritmo();
			for (int i = 0; i < grafo.getNumVertices(); i++)
			{
				std::cout << "Caminho: " << alg2.getPrimeiroVertice() << " ate " << i+1 << std::endl;
				log->escreveLog("Caminho: " + std::to_string(alg2.getPrimeiroVertice()) + " até " + std::to_string(i+1) + "\n");			
				alg2.ImprimeCaminhos(i);
				log->escreveLog("\n\n");
				std::cout << std::endl << "----------------------------------------------------" << std::endl;
			}

			std::cout << std::endl << "Pressione qualquer tecla para retornar ao menu..." << std::endl;
			log->escreveLog("\n\nSAÍDA DO ALGORITMO DE CAMINHOS_MINIMOS_GAO!! \n\n\n");
			system("pause");
		}
		else if (opcao == 0)
		{
			log->escreveLog("\n\nSAINDO DO PROGRAMA...");
			break;
		}

		system("cls");
	} while (true);
	
	system("pause");
	return 0;
}
