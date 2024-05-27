#include <vector>
#include "CCompound.h"
#define _USE_MATH_DEFINES
#include <math.h>

CCompound::CCompound(const std::string& type)
    : CBody(type) {}

void CCompound::addBody(const std::shared_ptr<CBody>& body)
{
    CCompound* compound = dynamic_cast<CCompound*>(body.get());
    if (compound && std::find_if(m_bodies.begin(), m_bodies.end(), [this](const std::shared_ptr<CBody>& b) {
        return b.get() == this;
        }) != m_bodies.end()) {
        return;
    }
    m_volume = m_volume + body->GetVolume();
    m_mass = m_mass + body->GetMass();
    m_bodies.push_back(body);
}

double CCompound::GetVolume() const
{
    return m_volume;
}

void CCompound::AppendProperties(std::ostream& strm) const {
    strm << "Compound body containing " << m_bodies.size() << " bodies";
}