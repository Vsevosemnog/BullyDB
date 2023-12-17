#include "../include/DBClass.h"

int main(int argc, char* argv[])
{
    DBClass* testClass = new DBClass();
    FILE* testFile = (*testClass).CreateDataBase("testDB");
    //FILE* testFile = (*testClass).OpenDataBase("testDB");
    return 0;
}