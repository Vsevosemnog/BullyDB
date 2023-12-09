#include "CMyDBClass.h"

FILE* CMyDBClass::CreateDataBase(char* name)
{
    FILE* file;
    void* lpBullyDBBase = NULL;
    long lenName = 0;

    lpBullyDBBase = &this->database;
    this->InitialClass();

    int i = 0;
    while((name[i] != 0) && (i < Core::MAX_BASE_NAME_LEN))
    {
        this->database.BaseName[i] = name[i];
        i++;
    }
    this->database.BaseName[i] = '\0';
    lenName = i;

    file = fopen(this->database.BaseName, "wb");
    if (file == NULL)
    {
        printf("Unable to open file %s **\n", this->database.BaseName);
        return NULL;
    }
    fwrite(lpBullyDBBase, 1, this->database.StructSize, file);

    return file;
}

bool CMyDBClass::InitialClass()
{
    for(int i = 0; i < Core::MAX_BASE_NAME_LEN; i++)
        this->database.BaseName[i] = 0;
    
    this->database.TableCount = 0;
    this->database.StructSize = sizeof(Core::DB_BULLYDB_BASE);

    for(int i =0; i < Core::MAX_TABLE_NAME_LEN; i++)
    {
        this->database.TablesInBase[i].ID = i + 1;
        for(int j=0; j < Core::MAX_TABLE_NAME_LEN; j++)
            this->database.TablesInBase[i].TableName[j] = 0;
        
        this->database.TablesInBase[i].FieldCount = 0;
        this->database.TablesInBase[i].RecordSize = 0;
        this->database.TablesInBase[i].RecordCount = 0;
        
        this->database.TablesInBase[i].StructSize = sizeof(Core::DB_BULLYDB_TABLE);

        for(int j=0; j < Core::BULLYDB_MAX_FIELDS; j++)
        {
            this->database.TablesInBase[i].FieldsInTable[j].ID = j+1;
            for(int k=0; k < Core::MAX_FIELD_NAME_LEN; k++)
                this->database.TablesInBase[i].FieldsInTable[j].FieldName[k] = 0;

            for(int k=0; k< Core::MAX_COMMENTARY_LEN; k++)
                this->database.TablesInBase[i].FieldsInTable[j].Commentary[k] = 0;

            this->database.TablesInBase[i].FieldsInTable[j].FieldSize = sizeof(Core::DB_BULLYDB_TABLE);
            this->database.TablesInBase[i].FieldsInTable[j].FieldType = 0;
        }
    }

    return true;
}

int CMyDBClass::CreateTable(char* name)
{
    int iRet = 0;
    int i =0;
    FILE* file;
    void* database = NULL;

    if(this->database.TableCount < Core::BULLYDB_MAX_TABLE)
    {
        database = &this->database;
        int k = this->database.TableCount;

        while((name[i] != 0) && (i < Core::MAX_TABLE_NAME_LEN))
        {
            this->database.TablesInBase[k].TableName[i] = name[i];
            i++;
        }
        this->database.TablesInBase[k].TableName[i] = '\0';

        iRet = this->database.TablesInBase[k].ID;

        file = fopen(name, "wb");
        if(file == NULL)
        {
            printf("Unable to create file %s **\n", name);
            return NULL;
        }
        fwrite(database, 0,0,file);
        this->database.TableCount++;
    }

    return iRet;
}