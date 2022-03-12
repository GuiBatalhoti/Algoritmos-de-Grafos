# Algoritmos-de-Grafos

## Instruções Windows
    Para a compilação dos códigos no sistema Windows, basta instalar o CMake, com o arquivo “cmake-3.22.2-windows-x86_64.msi” na pasta “Instaladores”.
    Seguir os passos da instalação e selecionar a opção “Add CMake to the sysstem PATH for all users”, esperar a finalização e a ferramenta estará pronta para o uso. 
    Após a instalação do CMake, seguimos para a instalação do Microsoft Visual Studio. 
    Durante a instalação é de suma importância que se adiciona o suporte à linguagem C++ para a IDE, assim o compilador será instalado com a IDE.
    Após as instalações, para gerar o ambiente de compilação com o CMake, abrimos o GUI que foi instalado. 
    Clique em “Browse Sourse...” e abra o diretório “Implementação” da pasta principal do Trabalho. 
    Após isso, clique em “Browse Build...” e navegue até a pasta “build”, dentro da pasta “Implementação”. 
    Clique então em “Configure”, coloque a versão do Microsoft Visual Studio na aba de especificação de gerador de compilação, clique em “Finish” e depois em “Generate”.
    Assim, será criado um arquivo “.sln” dentro da pasta “build”, abra este arquivo com o Microsoft Visual Studio. 
    Clique então com o botão direto do mouse em “main” e selecione “Set as StarUp Project” ou “Definir como Projeto de Inicialização”. 
    Navegar até a aba “Debug”, e iniciar o projeto sem depuração.
    
## Instruções para MacOS
    Para a compilação dos códigos no sistema MacOS, basta instalar o CMake com o arquivo “cmake-3.22.2-macos-universal.dmg”, na pasta “Instaladores”. Clicar em “Agree” e a 
    instalação irá seguir. Iniciar o “Launchpad” e iniciar o “CMake”.
    Após a instalação do CMake, fazer a instalação da IDE Xcode de forma padrão pela “AppStore”. Iniciar o “Launchpad” e iniciar o “Xcode”. O compilador será instalado juntamente 
    da IDE.
    Após as instalações, para gerar o ambiente de compilação com o CMake, abrimos o GUI que foi instalado. Clique em “Browse Sourse...” e abra o diretório “Implementação” da pasta 
    principal do Trabalho. Após isso, clique em “Browse Build...” e navegue até a pasta “build”, dentro da pasta “Implementação”. Clique então em “Configure”, coloque a versão do 
    Xcode na aba de especificação de gerador de compilação, clique em “Done” e depois em “Generate”.
    Assim, será criado um arquivo “.xcodeproj” dentro da pasta “build”, abra este arquivo com o Xcode. Selecione o arquivo “main” como alvo, clique no botão “run” e o programa 
    será compilado.

