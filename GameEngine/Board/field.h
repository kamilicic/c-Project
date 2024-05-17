//
// Created by Admin on 17/01/2022.
//

#ifndef MAIN_CPP_FIELD_H
#define MAIN_CPP_FIELD_H
#include <iostream>
#include <ctime>

class field {
    int m_stone;
    int m_wood;
    int m_gold;
    bool m_researched;
    std::string m_type;


public:
    field();
    std::string SetType();
    void setStone();
    void setWood();
    void setGold();
    void editStone(int stoneAmount);
    void editWood(int woodAmount);
    void editGold(int goldAmount);
    int getStoneInfo();
    int getWoodInfo();
    int getGoldInfo();
    bool getResearched();
    void PrintInfo();
    void SetResearchState();
    void CheckCount();

};


#endif //MAIN_CPP_FIELD_H
