//
// Created by kamil on 23.12.2021.
//

#include "Storage.h"

Storage::Storage(EnumStorage enumStorage) {
    m_storedGold = 0;
    m_storedStone = 0;
    m_storedWood = 0;
    m_type = nullptr;
    changeStorageType(enumStorage);
    m_maxGold = 150;
    m_maxStone = 150;
    m_maxWood = 150;
}

void Storage::changeStorageType(EnumStorage enumStorage) {
    m_enumStorage = enumStorage;
    if (m_type != nullptr) {
        delete m_type;
    }
    switch (enumStorage) {
        case EnumStorage::GoldStorage:
            m_type = new GoldStorage();
            break;
        case EnumStorage::StoneStorage:
            m_type = new StoneStorage();
            break;
        case EnumStorage::WoodStorage:
            m_type = new WoodStorage();
            break;
        case EnumStorage::TownHall:
            m_type = new TownHall();
            m_storedGold = 150;
            m_storedStone = 150;
            m_storedWood = 150;
            break;
    }
    makeChanges();
}

void Storage::makeChanges() {
    setId(m_type->getId());
    setBuildLevel(m_type->getBuildLevel());
}

void Storage::setId(std::string id) {
    m_type->m_id = id;
}

void Storage::setBuildLevel(int buildLevel) {
    m_type->m_buildLevel = buildLevel;
}

void Storage::upgradeLevel() {
    m_type->m_buildLevel++;
    m_maxGold += 60 * m_type->m_buildLevel;
}

int Storage::getBuildLevel() {
    return m_type->m_buildLevel;
}

std::string Storage::getId() {
    return m_type->m_id;
}

void Storage::storeResource(std::string id, int resourceQuantity) {
    int storeResource = m_storedGold;
    if (id == "GM") {
        if (checkStorage("GM", resourceQuantity)) {
            storeResource += resourceQuantity;
            m_storedGold = storeResource;
        } else {
            m_storedGold = m_maxGold;
            std::cout << "Full storage, cannot store resource here" << std::endl;
        }
    }

    if (id == "SM") {
        if (checkStorage("SM", resourceQuantity)) {
            m_storedStone += resourceQuantity;
        } else {
            m_storedStone = m_maxStone;
            std::cout << "Full storage, cannot store resource" << std::endl;
        }
    }
    if (id == "LM") {
        if (checkStorage("LM", resourceQuantity)) {
            m_storedWood += resourceQuantity;
        } else {
            m_storedWood = m_maxWood;
            std::cout << "Full storage, cannot store resource" << std::endl;
        }
    }
}

int Storage::getStoredGold() {
    return m_storedGold;
}

int Storage::getStoredStone() {
    return m_storedStone;
}

int Storage::getStoredWood() {
    return m_storedWood;
}

bool Storage::checkStorage(std::string id, int resourceQuantity) {
    if (id == "GM") {
        return m_storedGold + resourceQuantity < m_maxGold;
    } else if (id == "SM") {
        return m_storedStone + resourceQuantity < m_maxStone;
    } else if (id == "LM") {
        return m_storedWood + resourceQuantity < m_maxWood;
    }
}

void Storage::printGoldInfo() {
    std::cout << "Building id: " << m_type->getId() << ". Building level: " << m_type->m_buildLevel << ". Gold: " << m_storedGold << ". Max gold ca be stored: " << m_maxGold << std::endl;
}
void Storage::printStoneInfo() {
    std::cout << "Building id: " << m_type->getId() << ". Building level: " << m_type->m_buildLevel << ". Stone: " << m_storedStone;
}
void Storage::printWoodInfo() {
    std::cout << "Building id: " << m_type->getId() << ". Building level: " << m_type->m_buildLevel << ". Wood: " << m_storedWood;
}

void Storage::printTownHallInfo() {
    std::cout << "Building id: " << m_type->getId() << ". Building level: " << m_type->m_buildLevel << ". Gold: " << m_storedGold << ", stone: " << m_storedStone << ", wood: " << m_storedWood << std::endl;
}