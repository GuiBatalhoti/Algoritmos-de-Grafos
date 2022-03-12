#include "EscritaLog.h"

EscritaLog* EscritaLog::instance = 0;

EscritaLog::EscritaLog()
{
	this->arquivo = std::fopen("../../Log.txt", "w");

	if (!this->arquivo) //caso não seja possível abrir o arquivo
	{
		std::cout << "ERRO NA ABERTURA DO ARQUIVO DE LOG!!" << std::endl;
		std::cin.get();
		exit(1);
	}
}

EscritaLog::~EscritaLog()
{
	std::fclose(this->arquivo);
}

void EscritaLog::escreveLog(std::string mensagem)
{
	std::fprintf(this->arquivo, "%s", mensagem.c_str());
}

EscritaLog* EscritaLog::getInstance()
{
	if (instance == 0)
		instance = new EscritaLog();
	return instance;
}