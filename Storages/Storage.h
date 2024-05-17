//
// Created by kamil on 23.12.2021.
//

#ifndef TRY_STORAGE_H
#define TRY_STORAGE_H
#include <iostream>
#include "../Mines/Mines.h"
#include "EnumStorage.h"
#include "StorageType.h"
#include "StoneStorage.h"
#include "GoldStorage.h"
#include "WoodStorage.h"
#include "TownHall.h"

class Storage {
    void makeChanges ();
public:
    int m_storedGold;
    int m_storedStone;
    int m_storedWood;
    int m_maxGold;
    int m_maxStone;
    int m_maxWood;
    EnumStorage m_enumStorage;
    StorageType *m_type;
    Storage (EnumStorage enumStorage);
    void changeStorageType (EnumStorage enumStorage);
    void setBuildLevel (int buildLevel);
    void setId (std::string id);
    void upgradeLevel ();
    int getBuildLevel ();
    std::string getId ();
    void storeResource (std::string id, int resourceQuantity);
    int getStoredGold ();
    int getStoredStone ();
    int getStoredWood ();
    void printGoldInfo ();
    void printStoneInfo ();
    void printWoodInfo ();
    void printTownHallInfo ();
    bool checkStorage (std::string id, int resourceQuantity);
};


#endif //TRY_STORAGE_H
