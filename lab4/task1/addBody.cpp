#pragma once
#include "Body.h"
#include "Header.h"

std::shared_ptr<CBody> DefineSphereParam(IO& io)
{
    std::cout << "enter density and radius" << std::endl;
    double density;
    double radius;
    while (io.in >> density >> radius && density < 0 && radius < 0)
    {
        std::cout << " Error density < 0 && radius < 0" << std::endl;
    }
    std::shared_ptr<CBody> bodyPtr = std::make_shared<CSphere>(density, radius);
    return bodyPtr;
}

std::shared_ptr<CBody> DefineParallelepipedParam(IO& io)
{
    std::cout << "enter density width height depth" << std::endl;
    double density;
    double width;
    double height;
    double depth;
    io.in >> density >> width >> height >> depth;
    std::shared_ptr<CBody> bodyPtr = std::make_shared<CParallelepiped>(density, width, height, depth);
    return bodyPtr;
}

std::shared_ptr<CBody> DefineConeParam(IO& io)
{
    std::cout << "enter density radius height" << std::endl;
    double density;
    double radius;
    double height;
    io.in >> density >> radius >> height;
    return std::make_shared<CCone>(density, radius, height);
}

std::shared_ptr<CBody> DefineCylinderParam(IO& io)
{
    std::cout << "enter density radius height" << std::endl;
    double density;
    double radius;
    double height;
    io.in >> density >> radius >> height;
    std::shared_ptr<CBody> bodyPtr = std::make_shared<CCylinder>(density, radius, height);
    return bodyPtr;
}

std::shared_ptr<CBody> DefineCompound(IO& io)
{
    std::shared_ptr<CCompound> compound = std::make_shared<CCompound>("Compound");
    std::vector<std::shared_ptr<CBody>> bodies = AddBody(io);
    for (const auto& ptr : bodies) {
        compound->addBody(ptr);
    }
    return compound;
}

std::shared_ptr<CBody> DefineBody(const std::string& nameBody, IO& io)
{
    if (nameBody == "Sphere")
    {
        return DefineSphereParam(io);
    }
    if (nameBody == "Parallelepiped")
    {
        return DefineParallelepipedParam(io);
    }
    if (nameBody == "Cone")
    {
        return DefineConeParam(io);
    }
    if (nameBody == "Cylinder")
    {
        return DefineCylinderParam(io);
    }
    if (nameBody == "Compound")
    {
        return DefineCompound(io);
    }
    return nullptr;
}

std::vector<std::shared_ptr<CBody>> AddBody(IO& io)
{
    std::vector<std::shared_ptr<CBody>> bodies;
    std::cout << "enter body name or ... to complete entry" << std::endl;
    std::string nameBody;
    while (io.in >> nameBody && nameBody != "...")
    {
        if (auto body = DefineBody(nameBody, io))
        {
            bodies.push_back(body);
        }
        else
        {
            std::cout << "Error. unable to create shape " << nameBody << std::endl;
        }
    }
    return bodies;
}

void PrintBodies(IO& io, const std::vector<std::shared_ptr<CBody>>& bodies)
{
    for (const auto& ptr : bodies) {
        io.out << ptr->ToString() << std::endl;
    }
}

void PrintBodyMaxMass(IO& io, const std::vector<std::shared_ptr<CBody>>& bodies)
{
    std::shared_ptr<CBody> maxMassBody;
    if (!bodies.empty())
    {
        maxMassBody = bodies.front();
        for (const auto& ptr : bodies)
        {
            if (ptr->GetMass() > maxMassBody->GetMass())
            {
                maxMassBody = ptr;
            }
        }
    }
    if (maxMassBody)
    {
        io.out << "max mass " << maxMassBody->ToString();
    }
    else
    {
        io.out << "No bodies found." << std::endl;
    }
}

void PrintMinimumWeightWater(IO& io, const std::vector<std::shared_ptr<CBody>>& bodies)
{
    std::shared_ptr<CBody> minMassBodyInWater;
    if (!bodies.empty())
    {
        minMassBodyInWater = bodies.front();
        for (const auto& ptr : bodies)
        {
            if (ptr->GetMass() - ptr->GetVolume() * 1000 < minMassBodyInWater->GetMass() - ptr->GetVolume() * 1000)
            {
                minMassBodyInWater = ptr;
            }
        }
    }
    if (minMassBodyInWater)
    {
        io.out << "Min mass to water " << minMassBodyInWater->ToString();
    }
    else {
        io.out << "No bodies found." << std::endl;
    }
}
