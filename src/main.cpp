#include "Graph.hpp"

#include <iostream>

int main(int argc, char* argv[]) {
    gpp::Graph g{6};
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 1);
    g.addEdge(4, 2);
    g.addEdge(4, 3);
    g.addEdge(4, 5);
    g.addEdge(5, 5);
    
    std::cout << g.toString();
    
    return 0;
}