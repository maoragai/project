//
// Created by zap on 01/10/2020.
//

#ifndef UNTITLED2_DB_H
#define UNTITLED2_DB_H


#include <string>
#include "HD.h"

class DB {
public:
    HD *GetHDByName(std::string HDName);

    void DB::InsertHD(HD);
};

#endif //UNTITLED2_DB_H
