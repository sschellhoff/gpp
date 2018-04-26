#pragma once

#include "EdgeInformation.hpp"

namespace gpp {

class EdgeCost : public EdgeInformation {
private:
    float cost;
public:
    EdgeCost(float cost) : cost(cost) {
    }
    virtual ~EdgeCost() {}
    
    float getCost() const {
        return cost;
    }
    
    virtual std::unique_ptr<EdgeInformation> clone() const {
        return std::make_unique<EdgeCost>(cost);
    }
};

}

