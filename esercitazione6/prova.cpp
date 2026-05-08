
#include <iostream>
#include "unidirected_edge.hpp"
#include "unidirected_graph.hpp"
using namespace std;

int main() {
    // Creiamo due grafi
    unidirected_graph<int> g1;
    unidirected_graph<int> g2;

    // Aggiungiamo archi al primo grafo (G1)
    g1.add_edges(unidirected_edge(1,1));
	g1.add_edges(unidirected_edge(3, 4));
    g1.add_edges(unidirected_edge(2, 3));
    g1.add_edges(unidirected_edge(1, 2));

    // Aggiungiamo archi al secondo grafo (G2)
    g2.add_edges(unidirected_edge(4, 5)); // Questo è solo in G2
    g2.add_edges(unidirected_edge(1, 2)); // Questo è in comune con G1
	
	// Test della differenza
    unidirected_graph diff = g1 - g2;
    
	std::cout << "Dato G1:" << std::endl;
    for (const auto& edge : g1.all_edges()) {
        std::cout << "(" << edge.from() << " -- " << edge.to() << ")" << std::endl;
    }
	
	std::cout << "e dato G2:" << std::endl;
    for (const auto& edge : g2.all_edges()) {
        std::cout << "(" << edge.from() << " -- " << edge.to() << ")" << std::endl;
    }
	
	
    std::cout << "Archi nella differenza (G1 - G2):" << std::endl;
    for (const auto& edge : diff.all_edges()) {
        std::cout << "(" << edge.from() << " -- " << edge.to() << ")" << std::endl;
    }
	
	std::cout << "i vicini del nodo 3 nel grafo G1 sono:" << std::endl;
	list <int> nodi= g1.neighbours(3);
    for (const auto& nodo : nodi) {
        std::cout << nodo << std::endl;
    }
	
    // Test di edge_at
    unidirected_edge e1= g1.edge_at(0);
    std::cout << "L'arco all'indice 0 di G1 e': " << e1.from() << "-" << e1.to() << std::endl;
    
	
	//test di edge_number
	unidirected_edge<int> e2=unidirected_edge(1,2);
    int index = g1.edge_number(e2);
	std::cout << "L'arco" << e2 << "ha indice " << index << std::endl;
   
   
   return 0;
}