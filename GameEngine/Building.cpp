//
// Created by Admin on 17/01/2022.
//

#include "Building.h"
Building::Building() {
    m_mineB = nullptr;
    m_storageB = nullptr;
    m_exists = false;
}

void Building::SetMine(Mines* mine) {
    m_mineB = mine;
    m_exists = true;
}

void Building::SetStorage(Storage *storage) {
    m_storageB = storage;
    m_exists = true;
}

void Building::PrintInfoB() {
    if(m_mineB!=nullptr){
        std::cout<<"[  "<<m_mineB->getId()<<" "<<m_mineB->getBuildLevel()<<"   ]";
    }else
    if(m_storageB!= nullptr){
        std::cout<<"[  "<<m_storageB->getId()<<" "<<m_storageB->getBuildLevel()<<"   ]";
    }
    else
        std::cout<<"[         ]";

}

bool Building::GetExistance() {
    return m_exists;
}

Mines *Building::GetMineB() {
    return m_mineB;
}

Storage *Building::GetStorageB() {
    return m_storageB;
}
Building::~Building() {
    delete m_storageB;
    delete m_mineB;
}

