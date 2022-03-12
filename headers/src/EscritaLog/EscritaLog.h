/*
Classe feita para a escrita dos passos no arquivo de Log de processamento. Implementa o padrão de design Singleton.

Sobre os atributos:
- arquivo: ponteiro do tipo static para o aquivo a ser escrito, assim todos os abjetos da classe terão o mesmo arquivo.
- instance: ponteiro para implementação do padrão de projeto Singleton.

Sobre os métodos:
- EscritaLog(): abre o arquivo de Log de processamento, e em caso de falha, dispara uma mensagem para o usuário;
- ~EscritaLog(): destrutor da classe, nehuma outra função além de destuir o obejto;
- void escreveLog(std::string mensagem): este método recebe como parâmetro uma string que será a mensagem a ser escrita dentro do Log e a escreve no arquivo.
- EscritaLog* getInstance(): retorna a instância da classe.
*/
#pragma once
#include <iostream>
#include <cstdio>
#include <string>

class EscritaLog
{
protected:
	static EscritaLog* instance; //ponteiro para implementação do padrão de projeto Singleton.
private:
	FILE *arquivo; //ponteiro do tipo static para o aquivo a ser escrito, assim todos os abjetos da classe terão o mesmo arquivo.
	EscritaLog(); //abre o arquivo de Log de processamento, e em caso de falha, dispara uma mensagem para o usuário;
public:
	~EscritaLog(); //abre o arquivo de Log de processamento, e em caso de falha, dispara uma mensagem para o usuário;
	void escreveLog(std::string mensagem); //este método recebe como parâmetro uma string que será a mensagem a ser escrita dentro do Log e a escreve no arquivo.
	static EscritaLog* getInstance(); //retorna a instância da classe.
};