//
// Created by kamil on 28.12.2021.
//

#include "TownHall.h"

TownHall::TownHall() {
    m_id = "TH";
    m_buildLevel = 1;
}

std::string TownHall::getId() {
    return m_id;
}

int TownHall::getBuildLevel() {
    return m_buildLevel;
}