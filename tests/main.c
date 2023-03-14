/*************************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
* Tekijä: Konsta Jalkanen   
* Opiskelijanumero: 000489689
* Päivämäärä: 01/03/2023
* Kurssin oppimateriaalien lisäksi työhön ovat vaikuttaneet seuraavat
* lähteet ja henkilöt, ja se näkyy tehtävässä seuraavalla tavalla: Minä, tein kokonaan.
* Mahdollisen vilppiselvityksen varalta vakuutan, että olen tehnyt itse
* tämän tehtävän ja vain yllä mainitut henkilöt sekä lähteet ovat
* vaikuttaneet siihen yllä mainituilla tavoilla.
*/
/*************************************************************************/
/* Tehtävä Harjoitus työ, tiedoston nimi HTKirjasto.c */
/* eof */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define IMAXCHARACTER 255

typedef struct linkedList
{
    char *pSentence;
    struct linkedList *pNextPiece;
} LINKEDLIST;

typedef struct analysis
{
    char *pLongestWord;    
    char *pShortestWord;
    char *pAlphabeticallyFirst;
    char *pAlphabeticallyLast;
    float fAverageLength;
    int iDataAmount;
} ANALYSIS;

typedef struct amountWordClass
{ 
    int iAmount;
    int iClass;
} AMOUNTWORDCLASS;

char *setMemoryChar(int iAmount);

char *resetMemoryChar(char *pStorable, int iAmounts);

LINKEDLIST *setMemoryLinkedList();

ANALYSIS *setMemoryAnalysis();

AMOUNTWORDCLASS *setMemoryStructArray(int iAmount);

LINKEDLIST *freeMemory(LINKEDLIST *pListPart);

int menu();

char file();

LINKEDLIST *readFile(LINKEDLIST *pLinkedList);

ANALYSIS *analysis(LINKEDLIST *pLinkedList, ANALYSIS *Analysis, AMOUNTWORDCLASS **pAmountWordClass);

FILE *informationRoute();

void writeFile(ANALYSIS *pAnalysis, AMOUNTWORDCLASS pAmountWordClass, FILE *txt);


int main(void) {
    int iExit = 0;
    int iMenu = 0;   
    LINKEDLIST *pLinkedList = setMemoryLinkedList(); 
    AMOUNTWORDCLASS *pAmountWordClass = setMemoryStructArray(10);
    ANALYSIS *pAnalysis = setMemortAnalysis();

    do
    {   
        
        iMenu = menu();
        if(iMenu == 1)
        {
            pLinkedList = readFile(pLinkedList);
        }
        else if (iMenu == 2)
        {
            pAnalysis = analysis(pLinkedList, pAnalysis, &pAmountWordClass);
        }
        else if (iMenu == 3)
        {
            writeFile(pAnalysis, pAmountWordClass, informationRoute());
        }
        else if (iMenu == 0)
        {
            iExit == 1;
            printf("Lopetetaan.\n");
            printf("\n");
        }
        else{
            printf("Tuntematon valinta, yritä uudestaan.\n");
        }
        
        
    } while(iExit == 1);
    
}

char *setMemoryChar(int iAmount){
    char *pStorable;
    if ((pStorable = (char*)malloc(iAmount * sizeof(char))) == NULL){
        perror("Muistinvaraus epäonnistui, lopetetaan");
        exit(0);
    }
    return(pStorable);
}

char *resetMemoryChar(char *pStorable, int iAmount){
    if ((pStorable = (char*)realloc(iAmount * sizeof(char))) == NULL){
        perror("Muistinvaraus epäonnistui, lopetetaan");
        exit(0);
    }
    return(pStorable);
}

LINKEDLIST *setMemoryLinkedList(){
    LINKEDLIST *pStorable;
    if ((pStorable = (LINKEDLIST*)malloc(sizeof(LINKEDLIST))) == NULL){
        perror("Muistinvaraus epäonnistui, lopetetaan");
        exit(0);
    }
    pStorable->pNextPiece = NULL;
    return(pStorable);
}

ANALYSIS *setMemoryAnalysis(){
    ANALYSIS *pStorable;
    if ((pStorable = (ANALYSIS*)malloc(sizeof(ANALYSIS))) == NULL){
        perror("Muistinvaraus epäonnistui, lopetetaan");
        exit(0);
    }
    
    return(pStorable);
}

AMOUNTWORDCLASS *setMemoryStructArray(int iAmount){
    AMOUNTWORDCLASS *pStorable;
    if ((pStorable = (AMOUNTWORDCLASS*)malloc(sizeof(AMOUNTWORDCLASS) * iAmount)) == NULL){
        perror("Muistinvaraus epäonnistui, lopetetaan");
        exit(0);
    }
    for (int i = 1; i != iAmount; i++;){
        pStorable[i-1].iClass = i;
    }
    return(pStorable);
}

LINKEDLIST *freeMemory(LINKEDLIST *pListPart){
    LINKEDLIST *pListPoint;
    do
    {
        pListPoint = pListPart->pNextPiece;
        free(pListPart);
        pListPart = pListPoint;
    }
    while(pListPart->pNextPiece != NULL);
    free(pListPart);
    pListPart = NULL;

    return(pListPart);
}

int menu(){
    char cChoise;
    int iChoise;
    printf("Valitse haluamasi toiminto:\n");
    printf("1) Lue tiedosto\n");
    printf("2) Analysoi tiedot\n");
    printf("3) Kirjoita tulokset\n");
    printf("4) Viikonpäiväanalyysi\n");
    printf("5) Kielitasoanalyysi\n");
    printf("0) Lopeta\n");
    printf("Anna valintasi: ");
    scanf("%c", cChoise);
    getchar();
    iChoise = atoi(cChoise);
    return(iChoise);
}

char file(){
    char aFile[IMAXCHARACTER];
    scanf("%s", aFile);
    return(aFile);
}

LINKEDLIST *readFile(LINKEDLIST *pLinkedList){
    FILE *txt;
    char aRow[IMAXCHARACTER];
    char aSplit[IMAXCHARACTER];
    LINKEDLIST *pListPoint
    printf("Anna tiedoston nimi: \n");
    char aFilename[] = file();
    if ((txt = fopen(aFilename, "r")) == NULL){
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }
    while((fgets(aRow, IMAXCHARACTER, txt)) == NULL)
    {
        LINKEDLIST *pNewpart = setMemoryLinkedList();
        pNewpart->pNextPiece == NULL;
        if ((aSplit = strtok(aRow, "\n")) == NULL){
            perror("Merkkijonon pilkkominen epäonnistui, lopetetaan");
            exit(0);
        }
        strcpy(pNewpart->pSentence, aSplit);
        if (pLinkedList == NULL){
            pLinkedList = pNewpart;
        }
        else{
            pListPoint = pLinkedList;
            while(pListPoint->pNextPiece != NULL)
            {
                pListPoint = pListPoint->pNextPiece
            }
            pListPoint->pNextPiece = pNewpart;
        }
        freeMemory(pNewpart);
    }
    
    printf("Tiedosto '%s' luettu.", aFilename);
    fclose(txt);
    
    return pLinkedList;
}


ANALYSIS *analysis(LINKEDLIST *pLinkedList, ANALYSIS *pAnalysis, AMOUNTWORDCLASS **pAmountWordClass){
    int iSum = 0, iCounter = 0;
    char aSplit[IMAXCHARACTER];
    char aSplit2[IMAXCHARACTER];
    char aSplit3[IMAXCHARACTER];
    char aSplit4[IMAXCHARACTER];
    while(pLinkedList->pSentence != NULL){
        if ((aSplit = strtok(pLinkedList->pSentence, ";")) == NULL){
            perror("Merkkijonon pilkkominen epäonnistui, lopetetaan");
            exit(0);
        }
        if ((aSplit2 = strtok(NULL, ";")) == NULL){
            perror("Merkkijonon pilkkominen epäonnistui, lopetetaan");
            exit(0);
        }
        if ((aSplit3 = strtok(NULL, ";")) == NULL){
            perror("Merkkijonon pilkkominen epäonnistui, lopetetaan");
            exit(0);
        }
        if ((aSplit4 = strtok(NULL, "\n")) == NULL){
            perror("Merkkijonon pilkkominen epäonnistui, lopetetaan");
            exit(0);
        }


        *pAmountWordClass[atoi(aSplit2)-1].iAmount++;
        iSum = iSum + strlen(aSplit);
        if (iCounter != 0){
            if (strlen(aSplit) > strlen(pAnalysis->pLongestWord)){
                strcpy(pAnalysis->pLongestWord, aSplit); 
            }
            if (strlen(aSplit) < strlen(pAnalysis->pShortestWord)){
                strcpy(pAnalysis->pShortestWord, aSplit); 
            } 
            if (strcmp(aSplit, pAnalysis->pAlphabeticallyFirst) < 0){
                strcpy(pAnalysis->pAlphabeticallyFirst, aSplit);
            }
            if (strcmp(aSplit, pAnalysis->pAlphabeticallyFirst) > 0){
                strcpy(pAnalysis->pAlphabeticallyLast, aSplit);
            }
        }  
        else{
            strcpy(pAnalysis->pLongestWord, aSplit);
            strcpy(pAnalysis->pShortestWord, aSplit); 
            strcpy(pAnalysis->pAlphabeticallyFirst, aSplit); 
            strcpy(pAnalysis->pAlphabeticallyLast, aSplit);
        }
        iCounter++;
        pLinkedList = pLinkedList->pNextPiece;
    }
    pAnalysis->fAverageLength = iSum / iCounter;
    pAnalysis->iDataAmount = iCounter;
    printf("Analysoitu %i sanaa.\n", iCounter);
    printf("Sanaluokittaiset lukumäärät analysoitu.\n");
    return(pAnalysis);   
}

FILE *informationRoute(){
    return FILE *txt;
}

void writeFile(ANALYSIS *pAnalysis, AMOUNTWORDCLASS pAmountWordClass, FILE *txt){
    printf("Anna tiedoston nimi: \n");
    char aFilename[] = file();
    printf("Tilastotiedot %i sanasta:\n", pAnalysis->iDataAmount);
    printf("Keskimääräinen sanan pituus on %1.f merkkiä.\n", pAnalysis->fAverageLength);
    printf("Pisin sana '%s' on %i merkkiä pitkä.\n", pAnalysis->pLongestWord, strlen(pAnalysis->pLongestWord));
    printf("Lyhyin sana '%s' on %i merkkiä pitkä.\n", pAnalysis->pShortestWord, strlen(pAnalysis->pShortestWord));
    printf("Aakkosjärjestyksessä ensimmäinen sana on '%s'.\n", pAnalysis->pAlphabeticallyFirst);
    printf("Aakkosjärjestyksessä viimeinen sana on '%s'.\n", pAnalysis->pAlphabeticallyLast);
    printf("\n");
    printf("Sanaluokka;Lkm\n");
    for (int i = 0; i != 10; i++;)
    {
        printf("Luokka %i;%i\n", pAmountWordClass.iClass, pAmountWordClass.iAmount);
    }
    
    if ((txt = fopen(aFilename, "w")) == NULL){
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }
    fprintf(txt, "Tilastotiedot %i sanasta:\n", pAnalysis->iDataAmount);
    fprintf(txt, "Keskimääräinen sanan pituus on %1.f merkkiä.\n", pAnalysis->fAverageLength);
    fprintf(txt, "Pisin sana '%s' on %i merkkiä pitkä.\n", pAnalysis->pLongestWord, strlen(pAnalysis->pLongestWord));
    fprintf(txt, "Lyhyin sana '%s' on %i merkkiä pitkä.\n", pAnalysis->pShortestWord, strlen(pAnalysis->pShortestWord));
    fprintf(txt, "Aakkosjärjestyksessä ensimmäinen sana on '%s'.\n", pAnalysis->pAlphabeticallyFirst);
    fprintf(txt, "Aakkosjärjestyksessä viimeinen sana on '%s'.\n", pAnalysis->pAlphabeticallyLast);
    fprintf(txt, "\n");
    fprintf(txt, "Sanaluokka;Lkm\n");
    for (int i = 0; i != 10; i++;)
    {
        fprintf(txt, "Luokka %i;%i\n", pAmountWordClass.iClass, pAmountWordClass.iAmount);
    }
    printf("Tiedosto '%s' kirjoitettu.\n", aFilename);
    fclose(txt);
    return;   
}