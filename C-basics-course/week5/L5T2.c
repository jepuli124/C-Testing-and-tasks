#include <stdio.h>
#include <string.h>
#include <stdlib.h>

 
#define IMAX 30 

/* 2023215JalkanenKonstaL5T1*/



char * setName(){
    char aScan[IMAX];
    char *pScan = aScan;
    printf("Anna luettavan tiedoston nimi: ");
    fgets(aScan, IMAX, stdin);
    pScan[strlen(pScan)-1] = '\0'; 
    return pScan;
}

void readFile(char *pFile){
    FILE *document;
    char aRow[IMAX];
    char aSmallest[IMAX];
    char *pSmallest = aSmallest;
    char *pSplit;
    char *pSplit2;
    int iTest;
    int iSmallest = 101;

    if ((document = fopen(pFile, "r")) == NULL) {
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
        }   
    else{    
        while (fgets(aRow, IMAX, document) != NULL) {
            if ((pSplit = strtok(aRow, ";")) == NULL) {
                exit(0);
                }
            if ((pSplit2 = strtok(NULL, "\n")) == NULL) {
                exit(0);
                }
            iTest = atoi(pSplit2);
            if(iTest <= iSmallest){
                strcpy(aSmallest, pSplit);
                iSmallest = iTest;
            }
            
        }
    } 
    printf("Tiedosto '%s' luettu.\n", pFile);
    printf("Pienin pistemäärä oli joukkueella '%s' %i pisteellä.\n", pSmallest, iSmallest);
    return;
}

int main(int argc, char *argv[]) {
    char aFile[IMAX];
    char *pFile = aFile;
    pFile = setName();
    readFile(pFile);
    printf("Kiitos ohjelman käytöstä.\n");

    return(0);
}