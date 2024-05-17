//
// Created by Admin on 17/01/2022.
//

#ifndef MAIN_CPP_BUILDING_H
#define MAIN_CPP_BUILDING_H
#include "../Mines/Mines.h"
#include "../Storages/Storage.h"

class Building {
Mines* m_mineB;
Storage* m_storageB;
bool m_exists;
public:
    Building();
    void SetMine(Mines* mine);
    void SetStorage(Storage* storage);
    void PrintInfoB();
    bool GetExistance();
    Mines* GetMineB();
    Storage* GetStorageB();
    ~Building();
};


#endif //MAIN_CPP_BUILDING_H
