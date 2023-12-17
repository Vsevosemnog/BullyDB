#include "../include/DBClass.h"

FILE* DBClass::CreateDataBase(const char* name)
{
    FILE* file; // Database file
    void* lpBullyDBBase = NULL; // Database pointer
    long lenName = 0; // Database name length

    lpBullyDBBase = &this->database;
    this->InitialClass();

    int i = 0;
    // Copying database name into struct
    while((name[i] != 0) && (i < Core::MAX_BASE_NAME_LEN))
    {
        this->database.BaseName[i] = name[i];
        i++;
    }
    this->database.BaseName[i] = '\0';
    lenName = i;

    file = fopen(this->database.BaseName, "wb"); //Database file creation
    if (file == NULL)
    {
        printf("Unable to open file %s **\n", this->database.BaseName);
        return NULL;
    }
    fwrite(lpBullyDBBase, 1, this->database.StructSize, file);

    return file;
}

bool DBClass::InitialClass()
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

int DBClass::CreateTable(const char* name)
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
            return -1;
        }
        fwrite(database, 0,0,file);
        this->database.TableCount++;
    }

    return iRet;
}

FILE* DBClass::OpenDataBase(const char *name)
{
    FILE* file;
    void* database = NULL;
    long lenName = 0;
    int i = 0;

    database = &this->database;

    file = fopen(name, "r+b");
    if(file == NULL)
    {
        printf("Unable to open file %s **\n", this->database.BaseName);
        return NULL;
    }

    fread(database,1,this->database.StructSize, file);
    fclose(file);

    return file;
}

bool DBClass::CloseDataBase(FILE* file)
{
    void* database = NULL;
    database = &this->database;

    // Set file inner pointer to the beginning
    fseek(file, 0, SEEK_SET);
    fwrite(database, 1, this->database.StructSize, file);
    fclose(file);
    return true;
}

int DBClass::CreateField(int IDTable,const char* name, int type, int size,const char* comment)
{
    int iRet = 0;
    int k =0;
    int e = 0;

    if(IDTable > 0 && IDTable <= Core::BULLYDB_MAX_TABLE)
    {
        int i = this->database.TablesInBase[IDTable].FieldCount;

        this->database.TablesInBase[IDTable].FieldsInTable[i].FieldType = type;
        this->database.TablesInBase[IDTable].FieldsInTable[i].FieldSize = size;

        while( (e < Core::MAX_COMMENTARY_LEN) && (comment[e] != 0))
        {
            this->database.TablesInBase[IDTable].FieldsInTable[i].Commentary[e] = comment[e];
            e++;
        }
        this->database.TablesInBase[IDTable].FieldsInTable[i].Commentary[e] = '\0';

        while( (k < Core::MAX_FIELD_NAME_LEN) && (name[k] !=0))
        {
            this->database.TablesInBase[IDTable].FieldsInTable[i].FieldName[k] = name[k];
            k++;
        }
        this->database.TablesInBase[IDTable].FieldsInTable[i].FieldName[k] = '\0';

        this->database.TablesInBase[IDTable].FieldCount++;

        this->database.TablesInBase[IDTable].RecordSize += size;

        iRet = this->database.TablesInBase[IDTable].FieldsInTable[i].ID;
    }
    return iRet;
}