#ifndef C_MY_DB_CLASS_H
#define C_MY_DB_CLASS_H

#include <stdio.h>
#include "core.h"

class CMyDBClass
{
    public:
        CMyDBClass();
        virtual ~CMyDBClass();

        bool InitialClass();
        FILE* CreateDataBase(char* name);
        FILE* OpenDataBase(char* name);
        bool CloseDataBase(FILE* file);
        int CreateTable(char* name);
        int CreateField(int IDTable, char* name, int type, int size, char* comment);
        Core::DB_BULLYDB_BASE database;
};
#endif