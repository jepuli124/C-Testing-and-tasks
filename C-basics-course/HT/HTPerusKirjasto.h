/*************************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
* Tekijä: Konsta Jalkanen   
* Opiskelijanumero: 000489689
* Päivämäärä: 12/03/2023
* Kurssin oppimateriaalien lisäksi työhön ovat vaikuttaneet seuraavat
* lähteet ja henkilöt, ja se näkyy tehtävässä seuraavalla tavalla: 
* Tuomas Lättilä ja Tomi Vilpponen ovat huomauttaneet tyyliohjeiden noudattamisesta olevasta puutteesta. 
* Aleksi natunen huomautti stdout olemassa olosta.
* Mahdollisen vilppiselvityksen varalta vakuutan, että olen tehnyt itse
* tämän tehtävän ja vain yllä mainitut henkilöt sekä lähteet ovat
* vaikuttaneet siihen yllä mainituilla tavoilla.
*/
/*************************************************************************/
/* Tehtävä Harjoitus työ, tiedoston nimi HTPerusKirjasto.h */
/* eof */

#ifndef HTPERUSKIRJASTO_H
#define HTPERUSKIRJASTO_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define IMAXCHARACTER 255
#define ILENGTHARRAY 10

typedef struct linkedList
{
    char aSentence[IMAXCHARACTER];
    int iClass;
    struct linkedList *pNextPiece;
} LINKEDLIST;

typedef struct analysis
{
    char aLongestWord[IMAXCHARACTER];    
    char aShortestWord[IMAXCHARACTER];
    char aAlphabeticallyFirst[IMAXCHARACTER];
    char aAlphabeticallyLast[IMAXCHARACTER];
    float fAverageLength;
    int iDataAmount;
} ANALYSIS;

typedef struct amountWordClass
{ 
    int iAmount;
    int iClass;
} AMOUNTWORDCLASS;

char *file(char aFile[]);

LINKEDLIST *setMemoryLinkedList();

ANALYSIS *setMemoryAnalysis();

AMOUNTWORDCLASS *setMemoryStructArray(int iAmount);

LINKEDLIST *freeMemory(LINKEDLIST *pListPart);

int menu();

LINKEDLIST *readFile(LINKEDLIST *pLinkedList);

ANALYSIS *analysisOfInformation(LINKEDLIST *pLinkedList, ANALYSIS *Analysis);

AMOUNTWORDCLASS *wordperclass(LINKEDLIST *pLinkedList, AMOUNTWORDCLASS *pAmountWordClass);

void writeFile(ANALYSIS *pAnalysis, AMOUNTWORDCLASS AmountWordClass[], FILE *txt, char *pFilename);

void informationRoute(ANALYSIS *pAnalysis, AMOUNTWORDCLASS AmountWordClass[]);

#endif