#pragma once

#include <vector>
#include "Node.hpp"
#include "Edge.hpp"
#include <string>

namespace gpp {

class Graph {
private:
    bool is_digraph;
    std::vector<Node> nodes;
    std::vector<std::vector<Edge>> edges;
public:
    Graph(std::size_t size);

    bool isDigraph() const;

    Node &getNode(std::size_t idx);

    void addEdge(std::size_t from, std::size_t to);
    void addEdge(Edge &&edge);
    bool hasEdge(std::size_t from, std::size_t to) const;
    Edge &getEdge(std::size_t from, std::size_t to);
    
    std::string toString() const;
};

}