#pragma once
#include "Body.h"
#include "Cone.h"
#include "Cylinder.h"
#include "Parallelepiped.h"
#include "Sphere.h"
#include "CCompound.h"
#include "addBody.h"


struct IO {
    std::istream& in;
    std::ostream& out;
};

std::shared_ptr<CBody> DefineSphereParam(IO& io);
std::shared_ptr<CBody> DefineParallelepipedParam(IO& io);
std::shared_ptr<CBody> DefineConeParam(IO& io);
std::shared_ptr<CBody> DefineCylinderParam(IO& io);
std::shared_ptr<CBody> DefineBody(const std::string& nameBody, IO& io);
std::vector<std::shared_ptr<CBody>> AddBody(IO& io);
void PrintBodies(IO& io, const std::vector<std::shared_ptr<CBody>>& bodies);
void PrintBodyMaxMass(IO& io, const std::vector<std::shared_ptr<CBody>>& bodies);
void PrintMinimumWeightWater(IO& io, const std::vector<std::shared_ptr<CBody>>& bodies);