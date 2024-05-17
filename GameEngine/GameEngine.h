//
// Created by kamil on 25.12.2021.
//

#ifndef TRY_GAMEENGINE_H
#define TRY_GAMEENGINE_H
#include <iostream>
#include "../Mines/Mines.h"
#include "../Storages/Storage.h"
#include "Board/Svet.h"



class GameEngine {
public:
    Svet* m_svet;
    Storage *TownHall;
    Mines *GoldMine;
    Mines *StoneMine;
    Mines *LumberMill;
    Storage *StoneStorage;
    Storage *GoldStorage;
    Storage *WoodStorage;
    GameEngine();
    void play();
    void buildBuilding (Svet* m_svet);
    void generateResource ();
    void printFullInfo ();
    void printBuildingInfo ();
    void upgradeInfo ();
    void upgradeBuilding ();
    void upgradeTownHall ();
    void upgradeGoldMine ();
    void upgradeGoldStorage ();
    void upgradeStoneMine ();
    void upgradeStoneStorage();
    void upgradeLumberMill();
    void upgradeWoodStorage();
    void buildInfo();
    void ShowOptions();
    void NextDay();
    void Help();
    int CheckPosition(int pos);
};


#endif //TRY_GAMEENGINE_H
