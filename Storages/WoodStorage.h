//
// Created by kamil on 23.12.2021.
//

#ifndef TRY_WOODSTORAGE_H
#define TRY_WOODSTORAGE_H
#include "StorageType.h"

class WoodStorage : public StorageType{
public:
    WoodStorage ();
    int getBuildLevel ();
    std::string getId ();
};


#endif //TRY_WOODSTORAGE_H
