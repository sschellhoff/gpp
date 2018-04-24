#pragma once

#include <map>
#include <memory>
#include <typeindex>
#include <typeinfo>
#include <algorithm>
#include "NodeInformation.hpp"

namespace gpp {

class Node {
private:
    std::map<std::type_index, std::unique_ptr<NodeInformation>> info;
public:
    template <typename T, typename... Args>
    void addInfo(Args&&... args) {
        info[typeid(T)] = std::make_unique<T>(std::forward<Args>(args)...);
    }
    template <typename T>
    bool hasInfo() {
        return info.find(typeid(T)) != info.end();
    }
    template <typename T>
    T getInfo() {
        return info[typeid(T)];
    }
    template <typename T>
    void removeInfo() {
        info.erase(std::remove(info.begin(), info.end(), typeid(T)), info.end());
    }
};

}