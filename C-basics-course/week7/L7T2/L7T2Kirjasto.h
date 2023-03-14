#ifndef L7T1Kirjasto.h
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

 
#define IMAX 127 

/* 2023222JalkanenKonstaL7T2*/


typedef struct calculation
{
    char list[IMAX];
    struct calculation *pNext;
    
} CALCULATION;

void setMemory(char **pChar, int iAmount);

void setMemoryCalculation(CALCULATION **List, int iAmount);

void file(char **aInput);

int menu();

void write(CALCULATION **pListOfCL);

void addNumber(int *iValue, CALCULATION **pCalculation);

void read(CALCULATION **pCalculation);

void freeMemory(CALCULATION **pStart);

void RemoveFromList(CALCULATION **pList, int *pValue);

#endif
