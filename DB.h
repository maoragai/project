//
// Created by zap on 01/10/2020.
//

#ifndef UNTITLED2_DB_H
#define UNTITLED2_DB_H


#include <string>
#include "HD.h"
class HD;
class DB {
public:
    HD* GetHDByName(std::string HDName);

    void InsertHD(HD *hd);
};

#endif //UNTITLED2_DB_
