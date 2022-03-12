add_executable(main main.cpp)

target_link_libraries(main PRIVATE grafo)
target_link_libraries(main PRIVATE ItemLista)
target_link_libraries(main PRIVATE Leitura)
target_link_libraries(main PRIVATE Dijkstra)
target_link_libraries(main PRIVATE BuscaProfundidade)
target_link_libraries(main PRIVATE CaminhoMinimo_GAO)
target_link_libraries(main PRIVATE EscritaLog)