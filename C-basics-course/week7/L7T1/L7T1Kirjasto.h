#ifndef L7T1Kirjasto.h
#define L7T1Kirjasto.h
 
#define IMAX 127 

/* 2023227JalkanenKonstaL7T1 */


typedef struct calculation
{
    int iYear;
    int iBought;
    struct calculation *pNext;
    
} CALCULATION;


char *file(); 

char *setMemory(int iAmount);

CALCULATION * setMemoryCalculation(CALCULATION *List, int iAmount);

CALCULATION * read(CALCULATION *pCalculation);

void printList(CALCULATION *pList);

CALCULATION * freeMemory(CALCULATION *pStart);

#endif