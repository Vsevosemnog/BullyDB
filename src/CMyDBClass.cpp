#include "CMyDBClass.h"

FILE* CMyDBClass::CreateDataBase(char* name)
{
    FILE* file;
    void* lpBullyDBBase = NULL;
    long lenName = 0;

    lpBullyDBBase = &this->database;
    this->InitialClass();

    int i = 0;
    while((name[i] != 0) && (i < Core::MAX_LEN_NAME_BASE))
    {
        this->database.NameBase[i] = name[i];
        i++;
    }
    this->database.NameBase[i] = '\0';
    lenName = i;

    file = fopen(this->database.NameBase, "wb");
    if (file == NULL)
    {
        printf("Unable to open file %s **\n", this->database.NameBase);
        return NULL;
    }
    fwrite(lpBullyDBBase, 1, this->database.StructSize, file);

    return file;
}