//
// Created by kamil on 25.12.2021.
//

#include "GameEngine.h"

GameEngine::GameEngine() {
    TownHall = new Storage(EnumStorage::TownHall);
    GoldMine = nullptr;
    StoneMine = nullptr;
    LumberMill = nullptr;
    GoldStorage = nullptr;
    StoneStorage = nullptr;
    WoodStorage = nullptr;
    m_svet = new Svet();
}

void GameEngine::play() {
    unsigned int method = 0;
    std::string nazov;
    int pos1, pos2,pos3,pos4;
    std::cout << "Hello, Your kingdom has been created. \nWhat do you want to call your Kingdome?" << std::endl;
    std::cin >> nazov;
    m_svet->NameKingdome(nazov);
    std::cout << "\nSweet, the name '" << m_svet->GetKingdomeName()
              << "' suits your kingdom perfectly. \n Now you can chose what to do:" << std::endl;
    printFullInfo();
    ShowOptions();

    do {

        std::cin >> method;

        switch (method) {
            case 1:
                NextDay();
                break;
            case 2:
                m_svet->ZobrazDosku();
                ShowOptions();
                break;
            case 3:
                printFullInfo();
                ShowOptions();
                break;
            case 30:
                printBuildingInfo();
                ShowOptions();
                break;
            case 4:
                buildBuilding(m_svet);
                ShowOptions();
                break;
            case 40:
                buildInfo();
                ShowOptions();
                break;
            case 5:
                upgradeBuilding();
                ShowOptions();
                break;
            case 50:
                upgradeInfo();
                ShowOptions();
                break;
            case 6:
                if (GoldStorage != nullptr){
                    if (0 <= GoldStorage->getStoredGold() - 10){
                        GoldStorage->m_storedGold = GoldStorage->m_storedGold - 10;
                        m_svet->Research(pos1, pos2);
                    } else if (0 <= (TownHall->getStoredGold() + GoldStorage->getStoredGold()) - 10) {
                        GoldStorage->m_storedGold = 0;
                        if (0 <= GoldStorage->getStoredGold() - 10) {
                            TownHall->m_storedGold = TownHall->m_storedGold - (GoldStorage->getStoredGold() - 10);
                        } else {
                            TownHall->m_storedGold = TownHall->m_storedGold + (GoldStorage->getStoredGold() - 10);
                        }
                        m_svet->Research(pos1, pos2);
                    }  else {
                        std::cerr << "You have not enough resources!" << std::endl;
                    }
                } else {
                    if (0 <= TownHall->getStoredGold() - 10) {
                        TownHall->m_storedGold = TownHall->m_storedGold - 10;
                        m_svet->RelocateBuilding();
                    } else {
                        std::cerr << "You have not enough resources!" << std::endl;
                    }
                }
                ShowOptions();
            case 7:
                if (GoldStorage != nullptr){
                    if (0 <= GoldStorage->getStoredGold() - 40){
                        GoldStorage->m_storedGold = GoldStorage->m_storedGold - 40;
                        m_svet->Research(pos1, pos2);
                    } else if (0 <= (TownHall->getStoredGold() + GoldStorage->getStoredGold()) - 40) {
                        GoldStorage->m_storedGold = 0;
                        if (0 <= GoldStorage->getStoredGold() - 40) {
                            TownHall->m_storedGold = TownHall->m_storedGold - (GoldStorage->getStoredGold() - 40);
                        } else {
                            TownHall->m_storedGold = TownHall->m_storedGold + (GoldStorage->getStoredGold() - 40);
                        }
                        m_svet->Research(pos1, pos2);
                    }  else {
                        std::cerr << "You have not enough resources!" << std::endl;
                    }
                } else {
                    if (0 <= TownHall->getStoredGold() - 40) {
                        TownHall->m_storedGold = TownHall->m_storedGold - 40;
                        m_svet->Research(pos1, pos2);
                    } else {
                        std::cerr << "You have not enough resources!" << std::endl;
                    }
                }
                ShowOptions();
                break;
            case 8:
                m_svet->ExactNumberOfresources(pos1, pos2);
                ShowOptions();
                break;
            case 9:
                Help();
                ShowOptions();
            default:
                std::cerr << "Unknown command!" << std::endl;

        }

    } while (method != 0 && TownHall->getBuildLevel() != 6);
    if (TownHall->getBuildLevel() == 6) {
        std::cout << "You complete the game. CONGRATULATION and thank you for playing this game, bye :)" << std::endl;
    }
}

    void GameEngine::ShowOptions() {
        std::cout <<
        "---------------------------------------------------\n"
        "[1]  - Next Day (Generates resources)              \n"
        "[2]  - Show Your kingdom map                       \n"
        "[3]  - Show amount of Stored resources             \n"
        "[4]  - Build building                              \n"
        "[40] - Build building Info                         \n"
        "[5]  - Upgrade building                            \n"
        "[50] - Upgrade building Info                       \n"
        "[6]  - Relocate building                           \n"
        "[7]  - Research an area                            \n"
        "[8]  - Show amount of resources at location        \n"
        "[9]  - Help                                        \n"
        "[0]  - End Game (does not save progress....yet)    \n";
    }

void GameEngine::Help() {
    std::cout<<"To win this game you need to reach Town Hall lvl 6 in the shortest amount of time possible.\n"
                "To get more resources you first need to build a mine of the type of resource u want to collect.\n"
                "When you switch day resources will be automatically collected and stored in your storages.\n"
                "Make sure to research the location of where you want to build your mines as not every location\n"
                "contains the same amount of resources. But don't worry. You can always relocate your building\n"
                "for a small fee.\n"
                "To start upgrading your buildings you first needto build all buildings."
                "No building level can be higher then the current TownHall level."
                "";
}


void GameEngine::NextDay() {
    m_svet->nextDay();
    generateResource();
    printFullInfo();
    ShowOptions();
}

int GameEngine::CheckPosition(int pos) {
    while (pos > 4 or pos < 0) {
        std::cerr << "You are attempting to enter a location out of range. Please try again."
                  << std::endl;
        std::cout << "Position 1:";
        std::cin >> pos;
    }
    return pos;
}

void GameEngine::upgradeBuilding() {
    std::cout << "Which building do you want to upgrade?" << std::endl;
    std::cout
            << "[1] TownHall \n[2] GoldMine \n[3] GoldStorage \n[4] StoneMine \n[5] StoneStorage \n[6] LumberMill \n[7] WoodStorage \n[0] Go back   "
            << std::endl;
    int building;
    std::cin >> building;
    switch (building) {
        case 1:
            upgradeTownHall();
            break;
        case 2:
            if (GoldMine != nullptr) {
                upgradeGoldMine();
            } else {
                std::cerr << "Building not built!" << std::endl;
            }
            break;
        case 3:
            if (GoldStorage != nullptr) {
                upgradeGoldStorage();
            } else {
                std::cerr << "Building not built!" << std::endl;
            }
            break;
        case 4:
            if (StoneMine != nullptr) {
                upgradeStoneMine();
            } else {
                std::cerr << "Building not built!" << std::endl;
            }
            break;
        case 5:
            if (StoneStorage != nullptr) {
                upgradeStoneStorage();
            } else {
                std::cerr << "Building not built!" << std::endl;
            }
            break;
        case 6:
            if (LumberMill != nullptr) {
                upgradeLumberMill();
            } else {
                std::cerr << "Building not built!" << std::endl;
            }
            break;
        case 7:
            if (WoodStorage != nullptr) {
                upgradeWoodStorage();
            } else {
                std::cerr << "Building not built!" << std::endl;
            }
            break;
        case 0:
            return;
        default:
            std::cerr << "Unknown building!" << std::endl;
    }


}
