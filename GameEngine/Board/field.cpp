//
// Created by Admin on 17/01/2022.
//

#include "field.h"

field::field() {
m_stone = rand() % (1000 + 1 - 0) + 0;
m_wood = rand() % (1000 + 1 - 0) + 0;
m_gold = rand() %(1000 + 1-0) +0;
m_researched = false;
m_type = SetType();
//CheckCount();
}

std::string field::SetType() {
    std::string type;
    if(m_wood>700){
        type = " Forest  ";
    }else
    if(m_stone>700){
        type = " Mountain";
    }else if(m_gold>700){
        type= "GoldMount";
    }else
        type = "  Field  ";
    return type;
}

void field::setStone() {
    if(m_stone+m_wood+m_gold>2000){
            m_stone=2000-(m_wood+m_gold);
    }
}
void field::setWood(){
    if(m_stone+m_wood+m_gold>2000){
            m_wood=2000-(m_stone+m_gold);
    }
}
void field::setGold() {
    if(m_stone+m_wood+m_stone>2000){
        m_gold=2000-(m_wood+m_stone);
    }
}

void field::editStone(int stoneAmount) {
    if(stoneAmount<m_stone){
        m_stone -=stoneAmount;
    }else{
        m_stone=0;
        std::cout<<"Stone has been depleted at the location of your StoneMine.\n"
                   "Please relocate your StoneMine."<<std::endl;
    }


}

void field::editWood(int woodAmount) {
    if(woodAmount<m_wood){
        m_wood -=woodAmount;
    }else{
        m_wood=0;
        std::cout<<"All the trees at the location of your LumberMill are gone.\n"
                   "Please relocate your LumberMill."<<std::endl;
    }

}

void field::editGold(int goldAmount) {
    if(goldAmount<m_gold){
        m_gold-=goldAmount;
    }else{
        m_gold=0;
        std::cout<<"Gold has been depleted at the location of your GoldMine.\n"
                   "Please relocate your GoldMine."<<std::endl;
    }

}

void field::SetResearchState() {
    m_researched = true;
}

int field::getStoneInfo() {
    return m_stone;
}

int field::getWoodInfo() {
    return m_wood;
}

int field::getGoldInfo() {
    return m_gold;
}

bool field::getResearched(){
    return m_researched;
}

void field::PrintInfo() {
    if(m_researched){
        std::cout <<m_type;
    }else
        std::cout<<" Unknown ";

}

void field::CheckCount() {
    if(m_wood>m_stone){
        if(m_wood>m_gold){
            setWood();
        }else{
            setGold();
            }
    }else if(m_stone>m_gold){
        setStone();
    }else{
        setGold();
    }
}