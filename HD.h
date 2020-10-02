//
// Created by zap on 01/10/2020.
//

#ifndef UNTITLED2_HD_H
#define UNTITLED2_HD_H

#include <string>
#include "DB.h"


class HD {
public:
    FileSource FS;// indicate what is the source of the hard drive

    //Description: takes a saved HD name and create HD class.
    HD *pullFromDB(DB &db, std::string HDName);

    FILE *ListExecutebels();

    void SaveInDB(DB &db);

    void
};

#endif //UNTITLED2_HD_H
