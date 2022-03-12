add_library(grafo src/Grafo/Grafo.h src/Grafo/Grafo.cpp)
target_include_directories(grafo PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")

add_library(ItemLista src/ItemLista/ItemLista.h src/ItemLista/ItemLista.cpp)
target_include_directories(ItemLista PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")

add_library(Leitura src/LeituraGrafo/LeituraGrafo.h src/LeituraGrafo/LeituraGrafo.cpp)
target_include_directories(Leitura PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")

add_library(Dijkstra src/Dijkstra/Dijkstra.h src/Dijkstra/Dijkstra.cpp)
target_include_directories(Dijkstra PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")

add_library(BuscaProfundidade src/BuscaProfundidade/BuscaProfundidade.h src/BuscaProfundidade/BuscaProfundidade.cpp)
target_include_directories(BuscaProfundidade PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")

add_library(CaminhoMinimo_GAO src/CaminhosMinimos_GAO/CaminhosMinimos_GAO.h src/CaminhosMinimos_GAO/CaminhosMinimos_GAO.cpp)
target_include_directories(CaminhoMinimo_GAO PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")

add_library(EscritaLog src/EscritaLog/EscritaLog.h src/EscritaLog/EscritaLog.cpp)
target_include_directories(EscritaLog PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")