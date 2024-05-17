//
// Created by kamil on 23.12.2021.
//

#ifndef TRY_STONESTORAGE_H
#define TRY_STONESTORAGE_H

#include "StorageType.h"

class StoneStorage : public StorageType{
public:
    StoneStorage();
    int getBuildLevel ();
    std::string getId ();
};


#endif //TRY_STONESTORAGE_H
