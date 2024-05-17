//
// Created by kamil on 23.12.2021.
//

#include "Mines.h"

Mines::Mines(EnumMine enumMine) {
    m_type = nullptr;
    changeMineType(enumMine);
}

void Mines::changeMineType(EnumMine enumMine) {
    m_enumMine = enumMine;
    if (m_type != nullptr) {
        delete m_type;
    }
    switch (enumMine) {
        case EnumMine::GoldMine:
            m_type = new GoldMine();
            break;
        case EnumMine::StoneMine:
            m_type = new StoneMine();
            break;
        case EnumMine::LumberMill:
            m_type = new LumberMill();
            break;
    }
    makeChanges();
}

void Mines::makeChanges() {
    setId(m_type->getId());
    setBuildLevel(m_type->getBuildLevel());
}

void Mines::setId(std::string id) {
    m_type->m_id = id;
}

void Mines::setBuildLevel(int buildLevel) {
    m_type->m_buildLevel = buildLevel;
}

void Mines::upgradeLevel() {
    m_type->m_buildLevel++;
}

std::string Mines::getId() {
    return m_type->getId();
}

int Mines::getBuildLevel() {
    return m_type->m_buildLevel;
}

void Mines::generateResource(int AORAL) {
    m_resource = 20* m_type->m_buildLevel;
    if(m_resource>AORAL){
        m_resource=AORAL;
    }

}

int Mines::getResource() {
    return m_resource;
}

void Mines::printInfo() {
    std::cout << "Building id: " << m_type->getId() << ". Building level: " << m_type->m_buildLevel << std::endl;
}