#pragma once

#include <memory>

namespace gpp {

class EdgeInformation {
public:
    virtual ~EdgeInformation() {}
    virtual std::unique_ptr<EdgeInformation> clone() const = 0;
};

}

