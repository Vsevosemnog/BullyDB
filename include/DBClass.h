#ifndef C_MY_DB_CLASS_H
#define C_MY_DB_CLASS_H

#include <stdio.h>
#include "core.h"

class DBClass
{
    public:
        DBClass(){};
        virtual ~DBClass(){};

        bool InitialClass();
        FILE* CreateDataBase(const char* name);
        FILE* OpenDataBase(const char* name);
        bool CloseDataBase(FILE* file);
        int CreateTable(const char* name);
        int CreateField(int IDTable,const char* name, int type, int size,const char* comment);
        Core::DB_BULLYDB_BASE database;
};
#endif