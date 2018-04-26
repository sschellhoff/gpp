#include "Graph.hpp"

#include <sstream>

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
    edges[from].push_back(Edge{from, to});
    if(!is_digraph) {
        edges[to].push_back(Edge{to, from});
    }
}

bool Graph::hasEdge(std::size_t from, std::size_t to) const {
    auto &candidates = edges[from];
    return std::find_if(candidates.begin(), candidates.end(), [from, to](const Edge &edge) { return edge.start() == from && edge.end() == to; } ) != candidates.end();
}

Edge &Graph::getEdge(std::size_t from, std::size_t to) {
    auto &candidates = edges[from];
    return (*std::find_if(candidates.begin(), candidates.end(), [from, to](const Edge &edge) { return edge.start() == from && edge.end() == to; } ));
}

std::string Graph::toString() const {
    std::stringstream sstream;
    
    for(std::size_t i = 0; i < edges.size(); i++) {
        auto &edgelist = edges[i];
        sstream << i << ":\t[";
        for(std::size_t j = 0; j < edgelist.size(); j++) {
            auto &edge = edgelist[j];
            sstream << edge.end();
            if(j < edgelist.size() - 1) {
                sstream << ", ";
            }
        }
        sstream << "]\n";
    }
    
    return sstream.str();
}

}