//
// Created by Admin on 17/01/2022.
//

#include "Svet.h"

Svet::Svet() {
    m_hraciePole = {};
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            m_hraciePole.at(i).at(j) = new field();
            m_BuildingBoard.at(i).at(j)= new Building();
        }
    }
    m_day=0;
    m_week=0;
    m_month=0;
    m_year=0;
}

void Svet::NameKingdome(std::string nazov) {
    m_nazov = nazov;
}

std::string Svet::GetKingdomeName() {
    return m_nazov;
}

void Svet::ZobrazDosku() {
    std::cout<<"view guide"<<std::endl;
    std::cout<<"[   x  y   ] = coordinates                                   |  Day:"<<m_day<<std::endl;
    std::cout<<"[ Unknown  ] = Type of filed                                 | Week:"<<m_week<<std::endl;
    std::cout<<"[    GM 1  ] = Building built at location + building level   |Month:"<<m_month<<std::endl;
    if(m_year!=0){
        std::cout<<"                                                            | Year:"<<m_year<<std::endl;
    }
    std::cout<<std::endl;
    for(int i=0;i<5;i++){
        for(int g=0;g<5;g++){
            std::cout<<"[   "<< i <<" "<< g <<"   ]";
        }
        std::cout<<std::endl;
        for (int j = 0; j < 5; j++) {
            std::cout<<"[";
            m_hraciePole.at(i).at(j)->PrintInfo();
            std::cout<<"]";
        }
        std::cout<<std::endl;
        for(int h=0;h<5;h++){
            m_BuildingBoard.at(i).at(h)->PrintInfoB();
        }
        std::cout<<std::endl;
        std::cout<<std::endl;

    }
}

void Svet::Research(int pos1, int pos2) {
    std::cout << "Please select the position of the field you want to research.\nPosition 1:";
    std::cin >> pos1;
    pos1 = CheckPositionS(pos1);
    std::cout << "\nPosition 2:";
    std::cin >> pos2;
    pos2 = CheckPositionS(pos2);
    if(!m_hraciePole.at(pos1).at(pos2)->getResearched()){
        m_hraciePole.at(pos1).at(pos2)->SetResearchState();
        DisplayResources(pos1,pos2);
    }else
        std::cerr<<"The field you are trying to research is already known"<<std::endl;
}

void Svet::ExactNumberOfresources(int pos1, int pos2) {
    std::cout << "Please select the position of the field you want to display resources.\nPosition 1:";
    std::cin >> pos1;
    pos1 = CheckPositionS(pos1);
    std::cout << "\nPosition 2:";
    std::cin >> pos2;
    pos2 = CheckPositionS(pos2);
    if(m_hraciePole.at(pos1).at(pos2)->getResearched()){
        DisplayResources(pos1,pos2);
    }else
        std::cout<<"You first have to research this area"<<std::endl;

}

void Svet::PlaceBuilding(Building *building,int i,int j) {
    delete m_BuildingBoard.at(i).at(j);
    m_BuildingBoard.at(i).at(j)= building;
}

void Svet::RelocateBuilding() {
    int pos1,pos2,pos3,pos4;
    ZobrazDosku();
    std::cout<<"Which building do you want to relocate?"<<std::endl;
    std::cout<<"Position 1:";
    std::cin>>pos1;
    pos1= CheckPositionS(pos1);
    std::cout<<"position 2:";
    std::cin>>pos2;
    pos2= CheckPositionS(pos2);

    while(!CheckLocationForBuilding(pos1,pos2)){
        std::cout<<"There is no building at this location.\n";
        std::cout << "position 1:";
        std::cin>>pos1;
        pos1= CheckPositionS(pos1);
        std::cout << "position 2:";
        std::cin>>pos2;
        pos2= CheckPositionS(pos2);
    }
    std::cout<<"Where do you want to place this building?\n";
    std::cout<<"position 1:";
    std::cin>>pos3;
    pos3= CheckPositionS(pos3);
    std::cout<<"position 2:";
    std::cin>>pos4;
    pos4= CheckPositionS(pos4);
    while(CheckLocationForBuilding(pos3,pos4)){
        std::cout<<"There is already a building at this location.\nPlease select a different location.";
        std::cout << "position 1:";
        std::cin>>pos3;
        pos3= CheckPositionS(pos3);
        std::cout << "position 2:";
        std::cin>>pos4;
        pos4= CheckPositionS(pos4);
    }
    std::cout<<"Your building has been relocated\n";
    m_BuildingBoard.at(pos3).at(pos4)=m_BuildingBoard.at(pos1).at(pos2);
    delete m_BuildingBoard.at(pos1).at(pos2);
    m_BuildingBoard.at(pos1).at(pos2)=new Building();
}

void Svet::DisplayResources(int pos1,int pos2) {
    std::cout<<"Wood at this location:"<<m_hraciePole.at(pos1).at(pos2)->getWoodInfo()<<std::endl;
    std::cout<<"Stone at this location:"<<m_hraciePole.at(pos1).at(pos2)->getStoneInfo()<<std::endl;
    std::cout<<"Gold at this location:"<<m_hraciePole.at(pos1).at(pos2)->getGoldInfo()<<std::endl;
}

bool Svet::CheckLocationForBuilding(int pos1,int pos2) {
    if(m_BuildingBoard.at(pos1).at(pos2)->GetExistance()){
        return true;
    }else return false;
}

void Svet::nextDay() {
    m_day++;
    if(m_day==7){
        m_day-=7;
        m_week++;
    }
    if(m_week==4){
        m_week-=4;
        m_month++;
    }
    if(m_month==12){
        m_month-=12;
        m_year++;
    }
}

int Svet::CheckPositionS(int pos) {

        while (pos > 4 or pos < 0) {
            std::cerr << "You are attempting to enter a location out of range. Please try again."
                      << std::endl;
            std::cout << "Position 1:";
            std::cin >> pos;
        }
        return pos;

}

/*field *Svet::GethraciePole() {
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(m_BuildingBoard.at(i).at(j)->GetMineB()->getId()=="GM"){
                return m_hraciePole.at(i).at(j);
            }else if(m_BuildingBoard.at(i).at(j)->GetMineB()->getId()=="SM"){
                return m_hraciePole.at(i).at(j);
            }else if(m_BuildingBoard.at(i).at(j)->GetMineB()->getId()=="LM"){
                return m_hraciePole.at(i).at(j);
            }
        }
    }
}*/

field *Svet::GetGMlocation() {
    field* pozicia;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(m_BuildingBoard.at(i).at(j)->GetExistance()) {
                if (m_BuildingBoard.at(i).at(j)->GetMineB()->getId() == "GM") {
                    pozicia = m_hraciePole.at(i).at(j);
                }
            }
        }
    }
    return pozicia;
}

field *Svet::GetLMlocation() {
    field* pozicia;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(m_BuildingBoard.at(i).at(j)->GetExistance()) {
                if (m_BuildingBoard.at(i).at(j)->GetMineB()->getId() == "LM") {
                    pozicia = m_hraciePole.at(i).at(j);
                }
            }
        }
    }
    return pozicia;
}

field *Svet::GetSMlocation() {
    field* pozicia;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(m_BuildingBoard.at(i).at(j)->GetExistance()) {
                if (m_BuildingBoard.at(i).at(j)->GetMineB()->getId() == "SM") {
                    pozicia = m_hraciePole.at(i).at(j);
                }
            }
        }
    }
    return pozicia;
}
