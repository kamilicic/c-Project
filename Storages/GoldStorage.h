//
// Created by kamil on 23.12.2021.
//

#ifndef TRY_GOLDSTORAGE_H
#define TRY_GOLDSTORAGE_H

#include "StorageType.h"

class GoldStorage : public StorageType {
public:
    GoldStorage ();
    int getBuildLevel ();
    std::string getId ();
};


#endif //TRY_GOLDSTORAGE_H
