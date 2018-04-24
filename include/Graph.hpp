#pragma once

#include <vector>
#include "Node.hpp"

namespace gpp {

class Graph {
private:
    bool is_digraph;
    std::vector<Node> nodes;
    std::vector<std::vector<std::size_t>> edges;
public:
    Graph(std::size_t size);

    bool isDigraph() const;

    Node &getNode(std::size_t idx);

    void addEdge(std::size_t from, std::size_t to);
    bool hasEdge(std::size_t from, std::size_t to) const;
};

}