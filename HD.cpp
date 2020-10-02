//
// Created by zap on 01/10/2020.
//
#include "HD.h"
#include "DB.h"
#include <iostream>

using namespace std;
enum FileSource {
    DataBase,
    Physical
};


FileSource FS;// indicate what is the source of the hard drive

//Description: takes a saved HD name and create HD class.
HD *HD::pullFromDB(DB &db, std::string HDName) {
    return db.GetHDByName(HDName);
}

FILE *HD::ListExecutebels() {
    //Description: listing all the files which represents executables in the current HD.
    //we might change the output type to be of vector< file* >

}

void HD::SaveInDB(DB &db) {
    //Description: saves the HD properties in the given DB.
    db.InsertHD(this);
}