#include "../include/CMyDBClass.h"

int main(int argc, char* argv[])
{
    CMyDBClass* testClass = new CMyDBClass();
    //FILE* testFile = (*testClass).CreateDataBase("testDB");
    FILE* testFile = (*testClass).OpenDataBase("testDB");
    return 0;
}