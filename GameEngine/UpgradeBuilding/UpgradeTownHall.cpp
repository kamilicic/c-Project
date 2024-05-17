//
// Created by kamil on 28.12.2021.
//
#include "../GameEngine.h"


void GameEngine::upgradeTownHall() {
    if (GoldStorage != nullptr && StoneStorage != nullptr && WoodStorage != nullptr) {
        if ((GoldStorage->getStoredGold() + TownHall->getStoredGold()) - (250 * TownHall->getBuildLevel()) >= 0 &&
            (StoneStorage->getStoredStone() + TownHall->getStoredStone()) - (250 * TownHall->getBuildLevel())  >= 0 &&
            (StoneStorage->getStoredStone() + TownHall->getStoredStone()) - (250 * TownHall->getBuildLevel())  >= 0) {
            TownHall->m_storedGold =
                    (GoldStorage->getStoredGold() + TownHall->getStoredGold()) - (250 * TownHall->getBuildLevel());
            GoldStorage->m_storedGold = 0;
            TownHall->m_storedStone =
                    (StoneStorage->getStoredStone() + TownHall->getStoredStone()) - (250 * TownHall->getBuildLevel());
            StoneStorage->m_storedStone = 0;
            TownHall->m_storedWood =
                    (WoodStorage->getStoredWood() + TownHall->getStoredWood()) - (250 * TownHall->getBuildLevel());
            WoodStorage->m_storedWood = 0;
            TownHall->upgradeLevel();
            std::cout << "Building upgraded." << std::endl;
        } else {
            std::cout << "You have not enough resources." << std::endl;
        }
    } else {
        std::cout << "You first have to build all building's to start upgrading buildings." << std::endl;
    }
}