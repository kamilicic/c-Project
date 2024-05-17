//
// Created by Admin on 17/01/2022.
//

#ifndef MAIN_CPP_SVET_H
#define MAIN_CPP_SVET_H
#include <array>
#include "../Building.h"
#include "field.h"

class Svet {
    std::array<std::array<field * , 5 > , 5>  m_hraciePole;
    std::array<std::array<Building* , 5> , 5> m_BuildingBoard;
    std::string m_nazov;
    int m_day;
    int m_week;
    int m_month;
    int m_year;
public:

    Svet();
    void NameKingdome(std::string nazov);
    std::string GetKingdomeName();
    void ZobrazDosku();
    void Research(int pos1, int pos2);
    void ExactNumberOfresources(int pos1,int pos2);
    void PlaceBuilding(Building* building,int i,int j);
    void RelocateBuilding();
    void DisplayResources(int pos1,int pos2);
    bool CheckLocationForBuilding(int pos1,int pos2);
    void nextDay();
    int CheckPositionS(int pos);
    field* GethraciePole();
    field* GetGMlocation();
    field* GetLMlocation();
    field* GetSMlocation();

};


#endif //MAIN_CPP_SVET_H
