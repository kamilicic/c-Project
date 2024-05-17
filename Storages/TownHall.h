//
// Created by kamil on 28.12.2021.
//

#ifndef TRY_TOWNHALL_H
#define TRY_TOWNHALL_H
#include "StorageType.h"

class TownHall : public StorageType{
public:
    TownHall ();
    int getBuildLevel ();
    std::string getId ();
};


#endif //TRY_TOWNHALL_H
