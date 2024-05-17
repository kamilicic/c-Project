//
// Created by kamil on 28.12.2021.
//
#include "GameEngine.h"
#include "Building.h"

void GameEngine::buildBuilding(Svet* svet) {
    int pos1=0,pos2=0;
    std::cout << "Which building do you want to build?" << std::endl;
    std::cout
            << "[1] GoldMine, [2] GoldStorage, [3] StoneMine, [4] StoneStorage, [5] LumberMill, [6] WoodStorage, [0] Go back."
            << std::endl;
    int building;
    std::cin >> building;
    switch (building) {
        case 1:
            if (GoldMine != nullptr) {
                std::cerr << "This building has been built!" << std::endl;
            } else {
                if (50 <= TownHall->m_storedGold && 30 <= TownHall->m_storedStone && 20 <= TownHall->m_storedWood) {
                    TownHall->m_storedGold -= 50;
                    TownHall->m_storedStone -= 30;
                    TownHall->m_storedWood -= 20;
                    GoldMine = new Mines(EnumMine::GoldMine);
                    std::cout << "Where do you want to place this building?" << std::endl;
                    std::cout << "position 1:";
                    std::cin >> pos1;
                    std::cout << std::endl;
                    pos1 = CheckPosition(pos1);
                    std::cout << "position 2:";
                    std::cin >> pos2;
                    std::cout << std::endl;
                    pos2 = CheckPosition(pos2);
                    while(svet->CheckLocationForBuilding(pos1,pos2)){
                        std::cout<<"There is already a building at this location.\nPlease select a different location.";
                        std::cout << "position 1:";
                        std::cin>>pos1;
                        pos1= CheckPosition(pos1);
                        std::cout << "position 2:";
                        std::cin>>pos2;
                        pos2= CheckPosition(pos2);
                    }
                    auto* GoldMineB=new Building();
                    GoldMineB->SetMine(GoldMine);
                    svet->PlaceBuilding(GoldMineB,pos1,pos2);
                    std::cout << "You build GoldMine." << std::endl;
                } else {
                    std::cout << "You have not enough resources to build this building." << std::endl;
                }

                break;
                case 2:
                    if (GoldStorage != nullptr) {
                        std::cerr << "This building has been built!" << std::endl;
                    } else {
                        if (40 <= TownHall->m_storedGold && 50 <= TownHall->m_storedStone &&
                            40 <= TownHall->m_storedWood) {
                            TownHall->m_storedGold -= 40;
                            TownHall->m_storedStone -= 50;
                            TownHall->m_storedWood -= 40;
                            GoldStorage = new Storage(EnumStorage::GoldStorage);
                            std::cout << "Where do you want to place this building?" << std::endl;
                            std::cout << "position 1:";
                            std::cin >> pos1;
                            std::cout << std::endl;
                            pos1 = CheckPosition(pos1);
                            std::cout << "position 2:";
                            std::cin >> pos2;
                            std::cout << std::endl;
                            pos2 = CheckPosition(pos2);
                            while(svet->CheckLocationForBuilding(pos1,pos2)){
                                std::cout<<"There is already a building at this location.\nPlease select a different location.";
                                std::cout << "position 1:";
                                std::cin>>pos1;
                                pos1= CheckPosition(pos1);
                                std::cout << "position 2:";
                                std::cin>>pos2;
                                pos2= CheckPosition(pos2);
                            }
                            auto* GoldStorageB=new Building();
                            GoldStorageB->SetStorage(GoldStorage);
                            svet->PlaceBuilding(GoldStorageB,pos1,pos2);
                            std::cout << "You build GoldStorage." << std::endl;
                        } else {
                            std::cout << "You have not enough resources to build this building." << std::endl;
                        }
                    }
                break;
                case 3:
                    if (StoneMine != nullptr) {
                        std::cerr << "This building has been built!" << std::endl;
                    } else {
                        if (30 <= TownHall->m_storedGold && 50 <= TownHall->m_storedStone &&
                            40 <= TownHall->m_storedWood) {
                            TownHall->m_storedGold -= 30;
                            TownHall->m_storedStone -= 50;
                            TownHall->m_storedWood -= 40;
                            StoneMine = new Mines(EnumMine::StoneMine);
                            std::cout << "Where do you want to place this building?" << std::endl;
                            std::cout << "position 1:";
                            std::cin >> pos1;
                            std::cout << std::endl;
                            pos1 = CheckPosition(pos1);
                            std::cout << "position 2:";
                            std::cin >> pos2;
                            std::cout << std::endl;
                            pos2 = CheckPosition(pos2);
                            while(svet->CheckLocationForBuilding(pos1,pos2)){
                                std::cout<<"There is already a building at this location.\nPlease select a different location.";
                                std::cout << "position 1:";
                                std::cin>>pos1;
                                pos1= CheckPosition(pos1);
                                std::cout << "position 2:";
                                std::cin>>pos2;
                                pos2= CheckPosition(pos2);
                            }
                            auto* StoneMineB=new Building();
                            StoneMineB->SetMine(StoneMine);
                            svet->PlaceBuilding(StoneMineB,pos1,pos2);
                            std::cout << "You build StoneMine." << std::endl;
                        } else {
                            std::cout << "You have not enough resources to build this building." << std::endl;
                        }
                    }
                break;
                case 4:
                    if (StoneStorage != nullptr) {
                        std::cerr << "This building has been built!" << std::endl;
                    } else {
                        if (40 <= TownHall->m_storedGold && 20 <= TownHall->m_storedStone &&
                            40 <= TownHall->m_storedWood) {
                            TownHall->m_storedGold -= 40;
                            TownHall->m_storedStone -= 20;
                            TownHall->m_storedWood -= 40;
                            StoneStorage = new Storage(EnumStorage::StoneStorage);
                            std::cout << "Where do you want to place this building?" << std::endl;
                            std::cout << "position 1:";
                            std::cin >> pos1;
                            std::cout << std::endl;
                            pos1 = CheckPosition(pos1);
                            std::cout << "position 2:";
                            std::cin >> pos2;
                            std::cout << std::endl;
                            pos2 = CheckPosition(pos2);
                            while(svet->CheckLocationForBuilding(pos1,pos2)){
                                std::cout<<"There is already a building at this location.\nPlease select a different location.";
                                std::cout << "position 1:";
                                std::cin>>pos1;
                                pos1= CheckPosition(pos1);
                                std::cout << "position 2:";
                                std::cin>>pos2;
                                pos2= CheckPosition(pos2);
                            }
                            auto* StoneStorageB=new Building();
                            StoneStorageB->SetStorage(StoneStorage);
                            svet->PlaceBuilding(StoneStorageB,pos1,pos2);
                            std::cout << "You build StoneStorage." << std::endl;
                        } else {
                            std::cout << "You have not enough resources to build this building." << std::endl;
                        }
                    }
                break;
                case 5:
                    if (LumberMill != nullptr) {
                        std::cerr << "This building has been built!" << std::endl;
                    } else {
                        if (40 <= TownHall->m_storedGold && 40 <= TownHall->m_storedStone &&
                            30 <= TownHall->m_storedWood) {
                            TownHall->m_storedGold -= 40;
                            TownHall->m_storedStone -= 40;
                            TownHall->m_storedWood -= 30;
                            LumberMill = new Mines(EnumMine::LumberMill);
                            std::cout << "Where do you want to place this building?" << std::endl;
                            std::cout << "position 1:";
                            std::cin >> pos1;
                            std::cout << std::endl;
                            pos1 = CheckPosition(pos1);
                            std::cout << "position 2:";
                            std::cin >> pos2;
                            std::cout << std::endl;
                            pos2 = CheckPosition(pos2);
                            while(svet->CheckLocationForBuilding(pos1,pos2)){
                                std::cout<<"There is already a building at this location.\nPlease select a different location.";
                                std::cout << "position 1:";
                                std::cin>>pos1;
                                pos1= CheckPosition(pos1);
                                std::cout << "position 2:";
                                std::cin>>pos2;
                                pos2= CheckPosition(pos2);
                            }
                            auto* LumberMillB=new Building();
                            LumberMillB->SetMine(LumberMill);
                            svet->PlaceBuilding(LumberMillB,pos1,pos2);
                            std::cout << "You build LumberMill." << std::endl;
                        } else {
                            std::cout << "You have not enough resources to build this building." << std::endl;
                        }
                    }
                break;
                case 6:
                    if (WoodStorage != nullptr) {
                        std::cerr << "This building has been built!" << std::endl;
                    } else {
                        if (30 <= TownHall->m_storedGold && 30 <= TownHall->m_storedStone &&
                            30 <= TownHall->m_storedWood) {
                            TownHall->m_storedGold -= 30;
                            TownHall->m_storedStone -= 30;
                            TownHall->m_storedWood -= 30;
                            WoodStorage = new Storage(EnumStorage::WoodStorage);
                            std::cout << "Where do you want to place this building?" << std::endl;
                            std::cout << "position 1:";
                            std::cin >> pos1;
                            std::cout << std::endl;
                            pos1 = CheckPosition(pos1);
                            std::cout << "position 2:";
                            std::cin >> pos2;
                            std::cout << std::endl;
                            pos2 = CheckPosition(pos2);
                            while(svet->CheckLocationForBuilding(pos1,pos2)){
                                std::cout<<"There is already a building at this location.\nPlease select a different location.";
                                std::cout << "position 1:";
                                std::cin>>pos1;
                                pos1= CheckPosition(pos1);
                                std::cout << "position 2:";
                                std::cin>>pos2;
                                pos2= CheckPosition(pos2);
                            }
                            auto* WoodStorageB=new Building();
                            WoodStorageB->SetStorage(WoodStorage);
                            svet->PlaceBuilding(WoodStorageB,pos1,pos2);
                            std::cout << "You build WoodStorage." << std::endl;
                        } else {
                            std::cout << "You have not enough resources to build this building." << std::endl;
                        }
                    }
                break;
                case 0:
                    return;
                default:
                    std::cerr << "Unknown building!" << std::endl;
            }
    }
}
