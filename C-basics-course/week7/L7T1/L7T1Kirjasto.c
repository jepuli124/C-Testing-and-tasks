#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "L7T1Kirjasto.h"

char *file(){
    char aInput2[IMAX];
    scanf("%s", aInput2);
    char *aInput = setMemory(strlen(aInput2)+1);
    strcpy(aInput, aInput2);
    return (aInput);
}

char *setMemory(int iAmount){
    char *pChar;
    if ((pChar = (char*)malloc(iAmount * sizeof(char))) == NULL ){
        perror("Muistin varaus epäonnistui");
        exit(0);
        }
    return(pChar);
}

CALCULATION * setMemoryCalculation(CALCULATION *List, int iAmount){
    if ((List = (CALCULATION*)malloc((iAmount+1) * sizeof(CALCULATION))) == NULL ){
        perror("Muistin varaus epäonnistui");
        exit(0);
        }
    return(List);
}

CALCULATION * read(CALCULATION *pCalculation){
    FILE *document;
    char aRow[IMAX];
    CALCULATION *pNew, *pPointer;
    char *pInput;
    char *pSplit;
    printf("Anna luettavan tiedoston nimi: ");
    pInput = file();
    if ((document = fopen(pInput, "r")) == NULL) {
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
        }   
    else{   
        while (fgets(aRow, IMAX, document) != NULL) {
            if ((pSplit = strtok(aRow, ";")) == NULL) {
                exit(0);
                }
            pNew = setMemoryCalculation(pNew, strlen(aRow)+1);
            pNew->iYear = atoi(pSplit);
            if ((pSplit = strtok(NULL, "\n")) == NULL) {
            exit(0);
            }
            pNew->iBought = atoi(pSplit);
            pNew->pNext = NULL;
            if (pCalculation == NULL){
                pCalculation = pNew;
                } 
            else {
                pPointer = pCalculation;
                while (pPointer->pNext != NULL)
                    {
                    pPointer = pPointer->pNext;
                    }
                pPointer->pNext = pNew;
            }
        }
    }
    printf("Tiedosto '%s' luettu.\n", pInput);
    free(pInput); 
    fclose(document);
    return pCalculation;
}

void printList(CALCULATION *pList){
    CALCULATION *pPointer = pList;
    int iSum = 0;
    printf("Akvaariokalojen tuonti euroina:\n");
    pPointer = pPointer->pNext;
    while (pPointer->pNext != NULL)
    {
        printf("%d	%d\n", pPointer->iYear, pPointer->iBought);
        iSum += pPointer->iBought;
        pPointer = pPointer->pNext;
    }
    printf("%d	%d\n", pPointer->iYear, pPointer->iBought);
    iSum += pPointer->iBought;
    pPointer = pPointer->pNext;
    printf("Ajanjaksolla tuonti oli yhteensä %d euroa.\n", iSum);

    return;
}

CALCULATION * freeMemory(CALCULATION *pStart){
    CALCULATION *pPointer = pStart;
    while (pPointer != NULL)
    {   
        pStart = pPointer->pNext;
        free(pPointer);
        pPointer = pStart;
    }
     //printf("\nMuisti vapautettu.\n");
     return (NULL);
}