//
// Created by kamil on 23.12.2021.
//

#ifndef TRY_MINES_H
#define TRY_MINES_H
#include <iostream>
#include "EnumMine.h"
#include "MineType.h"
#include "GoldMine.h"
#include "StoneMine.h"
#include "LumberMill.h"


class Mines {
    void makeChanges();
public:
    int m_resource = 20;
    EnumMine m_enumMine;
    MineType *m_type;
    Mines(EnumMine enumMine);
    void changeMineType (EnumMine enumMine);
    void setId (std::string id);
    void setBuildLevel (int buildLevel);
    void upgradeLevel ();
    std::string getId ();
    int getBuildLevel ();
    void generateResource (int AORAL); //AmountOfResourcesAtLocation
    int getResource ();
    void printInfo ();

};


#endif //TRY_MINES_H
