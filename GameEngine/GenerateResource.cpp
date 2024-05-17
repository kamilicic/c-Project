//
// Created by kamil on 28.12.2021.
//

#include "GameEngine.h"
void GameEngine::generateResource() {
            if (GoldMine != nullptr) {
                int storedGold = TownHall->getStoredGold();
                GoldMine->generateResource(m_svet->GetGMlocation()->getGoldInfo());
                m_svet->GetGMlocation()->editGold(GoldMine->getResource());
                TownHall->storeResource(GoldMine->getId(), GoldMine->getResource());
                if (storedGold + GoldMine->getResource() >= TownHall->m_maxGold && GoldStorage != nullptr) {
                    GoldStorage->storeResource(GoldMine->getId(), GoldMine->getResource() - (TownHall->m_maxGold - storedGold));
                }
            } else {
                std::cerr << "Gold Mine is missing!" << std::endl;
            }
            if (StoneMine != nullptr) {
                int storedStone = TownHall->getStoredStone();
                StoneMine->generateResource(m_svet->GetSMlocation()->getStoneInfo());
                m_svet->GetSMlocation()->editStone(StoneMine->getResource());
                TownHall->storeResource(StoneMine->getId(), StoneMine->getResource());
                if (storedStone + StoneMine->getResource() >= TownHall->m_maxStone && StoneStorage != nullptr) {
                    StoneStorage->storeResource(StoneMine->getId(), StoneMine->getResource() - (TownHall->m_maxStone - storedStone));
                }
            } else {
                std::cerr << "Stone Mine is missing!" << std::endl;
            }
            if (LumberMill != nullptr) {
                int storedWood = TownHall->getStoredWood();
                LumberMill->generateResource(m_svet->GetLMlocation()->getWoodInfo());
                m_svet->GetLMlocation()->editWood(LumberMill->getResource());
                TownHall->storeResource(LumberMill->getId(), LumberMill->getResource());
                if (storedWood + LumberMill->getResource() >= TownHall->m_maxWood && WoodStorage != nullptr) {
                    WoodStorage->storeResource(LumberMill->getId(), LumberMill->getResource() - (TownHall->m_maxWood - storedWood));
                }
            } else {
                std::cerr << "Lumber Mill is missing!" << std::endl;
            }

    }
