cmake_minimum_required(VERSION 3.21)
project(try)

set(CMAKE_CXX_STANDARD 14)

add_executable(try main.cpp
        Mines/GoldMine.cpp
        Mines/GoldMine.h
        Mines/Mines.cpp
        Mines/Mines.h
        Mines/EnumMine.h
        Mines/MineType.cpp
        Mines/MineType.h
        Mines/StoneMine.cpp
        Mines/StoneMine.h
        Mines/LumberMill.cpp
        Mines/LumberMill.h
        Storages/Storage.cpp
        Storages/Storage.h
        Storages/EnumStorage.h
        Storages/StorageType.cpp
        Storages/StorageType.h
        Storages/GoldStorage.cpp
        Storages/GoldStorage.h
        Storages/StoneStorage.cpp
        Storages/StoneStorage.h
        Storages/WoodStorage.cpp
        Storages/WoodStorage.h
        GameEngine/GameEngine.cpp
        GameEngine/GameEngine.h
        Storages/TownHall.cpp
        Storages/TownHall.h
        GameEngine/BuildBuilding.cpp
        GameEngine/GenerateResource.cpp
        GameEngine/PrintFullInfo.cpp
        GameEngine/PrintBuildingInfo.cpp
        GameEngine/UpgradeBuilding/UpgradeTownHall.cpp
        GameEngine/UpgradeBuilding/UpgradeGoldMine.cpp
        GameEngine/UpgradeBuilding/UpgradeGoldStorage.cpp
        GameEngine/UpgradeBuilding/UpgradeStoneMine.cpp
        GameEngine/UpgradeBuilding/UpgradeStoneStorage.cpp
        GameEngine/UpgradeBuilding/UpgradeLumberMill.cpp
        GameEngine/UpgradeBuilding/UpgradeWoodStorage.cpp
        GameEngine/UpgradeBuilding/UpgradeInfo.cpp
        GameEngine/BuildInfo.cpp
        GameEngine/Board/Svet.cpp
        GameEngine/Board/Svet.h
        GameEngine/Board/field.cpp
        GameEngine/Board/field.h
        GameEngine/Building.h
        GameEngine/Building.cpp
        )



