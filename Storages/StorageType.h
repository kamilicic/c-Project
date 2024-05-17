//
// Created by kamil on 23.12.2021.
//

#ifndef TRY_STORAGETYPE_H
#define TRY_STORAGETYPE_H
#include <iostream>

class StorageType {
public:
    int m_buildLevel;
    std::string m_id;
    int getBuildLevel ();
    std::string getId ();
    void setBuildLevel ();
};


#endif //TRY_STORAGETYPE_H
