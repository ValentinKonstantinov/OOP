#pragma once
#include "Body.h"
#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <memory>
#include <sstream>

class CCompound : public CBody {
public:
    CCompound(const std::string& type);

    void addBody(const std::shared_ptr<CBody>& body);

    double GetVolume() const override;

private:
    void AppendProperties(std::ostream& strm) const override;
    std::vector<std::shared_ptr<CBody>> m_bodies;
    double m_volume = 0;
    double m_mass = 0;
};
