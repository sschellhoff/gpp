#include "Graph.hpp"

namespace gpp {

Graph::Graph(std::size_t size) : is_digraph(true), nodes(size), edges(size) {
}

bool Graph::isDigraph() const {
    return is_digraph;
}

Node &Graph::getNode(std::size_t idx) {
    return nodes[idx];
}

void Graph::addEdge(std::size_t from, std::size_t to) {
    if(!is_digraph && from > to) {
        std::swap(from, to);
    }
    edges[from].push_back(to);
}

bool Graph::hasEdge(std::size_t from, std::size_t to) const {
    if(!is_digraph && from > to) {
        std::swap(from, to);
    }
    auto &candidates = edges[from];
    return std::find(candidates.begin(), candidates.end(), to) != candidates.end();
}

}