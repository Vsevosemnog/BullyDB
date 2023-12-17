#ifndef CORE_H
#define CORE_H

// #define BULLYDB_MAX_FIELDS 64 // Max field count in table
// #define BULLYDB_MAX_TABLE 128 // Max table count in database

// #define MAX_LEN_NAME_FIELD 128 // Max field name length
// #define MAX_LEN_NAME_TABLE 128 // Max table name length
// #define MAX_LEN_NAME_BASE 256 // Max database name length

namespace Core
{
    const int BULLYDB_MAX_FIELDS = 64; // Max field count in table
    const int BULLYDB_MAX_TABLE = 128; // Max table count in database
    const int MAX_FIELD_NAME_LEN = 128; // Max field name length
    const int MAX_TABLE_NAME_LEN = 128; // Max table name length
    const int MAX_BASE_NAME_LEN = 256; // Max database name length
    const int MAX_COMMENTARY_LEN = 128; // Max commentary field length

    typedef struct tagDB_BullyDB_Field
    {
        long ID; // Unique field id 
        char FieldName[MAX_FIELD_NAME_LEN]; // Field name
        long FieldType; // Field type (int, double, etc)
        long FieldSize; // Field size for this type
        char Commentary[MAX_COMMENTARY_LEN]; // Commentary
    } DB_BULLYDB_FIELD; // Table field describe type

    typedef struct tagDB_BullyDB_Table
    {
        long ID; // Unique table id
        long StructSize; // Struct size
        char TableName[MAX_TABLE_NAME_LEN]; // Table name
        long FieldCount; // Field count
        long RecordSize; // Record size (All field sizes sum)
        long RecordCount; // Record count
        DB_BULLYDB_FIELD FieldsInTable[BULLYDB_MAX_FIELDS]; // Field array
    } DB_BULLYDB_TABLE; // Table describe type

    typedef struct tagDB_BullyDB_Base
    {
        char BaseName[MAX_BASE_NAME_LEN]; // Database name
        long StructSize; // Struct size 
        long TableCount; // Table count
        DB_BULLYDB_TABLE TablesInBase[BULLYDB_MAX_TABLE]; // Table array
    } DB_BULLYDB_BASE; // Database describe type
}
#endif