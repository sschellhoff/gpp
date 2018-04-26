#pragma once

#include <map>
#include <memory>
#include <typeindex>
#include <typeinfo>
#include <algorithm>
#include "EdgeInformation.hpp"

namespace gpp {

class Edge {
private:
    std::size_t from;
    std::size_t to;
    std::map<std::type_index, std::unique_ptr<EdgeInformation>> info;
public:
    Edge(std::size_t from, std::size_t to) : from(from), to(to) {
    }
    
    std::size_t start() const {
        return from;
    }
    
    std::size_t end() const {
        return to;
    }
    
    template <typename T, typename... Args>
    void addInfo(Args&&... args) {
        info[typeid(T)] = std::make_unique<T>(std::forward<Args>(args)...);
    }
    template <typename T>
    bool hasInfo() {
        return info.find(typeid(T)) != info.end();
    }
    template <typename T>
    T &getInfo() {
        return *static_cast<T*>(info[typeid(T)].get());
    }
    template <typename T>
    void removeInfo() {
        info.erase(std::remove(info.begin(), info.end(), typeid(T)), info.end());
    }
    
    Edge flipped() const {
        auto flipped_edge = Edge{to, from};
        for(auto &entry : info) {
            flipped_edge.info[entry.first] = entry.second->clone();
        }
        return flipped_edge;
    }
};

}