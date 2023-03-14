#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define IMAX 30
#define ILINE 5
/* 2023221JalkanenKonstaL6T1*/

typedef struct linkedlist
{
    char aLine[ILINE];
    struct linkedlist *pNext;
}LINKEDLIST;

void file(char *aInput){
    printf("Anna luettavan tiedoston nimi: ");
    scanf("%s", aInput);
}

void readFile(char *pFile, LINKEDLIST **pStart){
    FILE *document;
    char aRow[IMAX];
    char *pSplit;
    LINKEDLIST *pNew, *pPointer;
    if ((document = fopen(pFile, "r")) == NULL) {
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
        }   
    else{    
        while (fgets(aRow, IMAX, document) != NULL) {
            setMemory(&pNew);
            if ((pSplit = strtok(aRow, ";")) == NULL) {
                exit(0);
                }
            strcpy(pNew->aLine, pSplit);
            pNew->pNext = NULL;
            if (*pStart == NULL){
                *pStart = pNew;
                } 
            else {
                pPointer = *pStart;
                while (pPointer->pNext != NULL)
                {
                    pPointer = pPointer->pNext;
                }
                pPointer->pNext = pNew;
                }
            if ((pSplit = strtok(NULL, "\n")) == NULL) {
                exit(0);
                };
            setMemory(&pNew);
            strcpy(pNew->aLine, pSplit);
            pNew->pNext = NULL;
            pPointer = *pStart;
            while (pPointer->pNext != NULL)
            {
                pPointer = pPointer->pNext;
            }
            pPointer->pNext = pNew;
                
            }     
        }
    printf("Tiedosto '%s' luettu linkitettyyn listaan.\n", pFile);
    return;
}

void printList(LINKEDLIST *pStart){
    printf("Tehtäviä tehtiin seuraavasti:\n");
    LINKEDLIST *pPointer = pStart;
    while (pPointer != NULL)
    {   
        printf("Tehtävän %s ", pPointer->aLine);
        pPointer = pPointer->pNext;
        printf("teki %s opiskelijaa.\n", pPointer->aLine);
        pPointer = pPointer->pNext;
    }
}

void setMemory(LINKEDLIST **pNew){
    if ((*pNew = (LINKEDLIST*)malloc(sizeof(LINKEDLIST)*ILINE)) == NULL ){
            perror("muisti epäonnistui, muista ensikerralla uudestaan:");
            exit(0);
    }
}

void freeMemory(LINKEDLIST **pStart){
    LINKEDLIST *pPointer = *pStart;
    while (pPointer != NULL)
    {   
        *pStart = pPointer->pNext;
        free(pPointer);
        pPointer = *pStart;
    }
     printf("\nMuisti vapautettu.\n");
}


int main(void) {
    char aFilename[IMAX];
    char *aInput = aFilename;
    LINKEDLIST *pStart = NULL;
    file(aInput);
    readFile(aInput, &pStart);
    printList(pStart);
    freeMemory(&pStart);
    printf("Kiitos ohjelman käytöstä.\n");

    return(0);
}
