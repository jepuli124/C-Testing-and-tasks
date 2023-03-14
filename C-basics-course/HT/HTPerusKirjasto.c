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
/* Tehtävä Harjoitus työ, tiedoston nimi HTPerusKirjasto.c */
/* eof */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "HTPerusKirjasto.h"

char *file(char aFile[]){  // kysytään tiedoston nimi
    printf("Anna tiedoston nimi: ");
    scanf("%s", aFile);
    return(aFile);
}

LINKEDLIST *setMemoryLinkedList(){  // Luodaan linkitetyn listan palanen
    LINKEDLIST *pStorable;
    if ((pStorable = (LINKEDLIST*)malloc(sizeof(LINKEDLIST))) == NULL){
        perror("Muistinvaraus epäonnistui, lopetetaan");
        exit(0);
    }
    pStorable->pNextPiece = NULL;
    return(pStorable);
}

ANALYSIS *setMemoryAnalysis(){  // Luodaan dynaaminen analyysi tietue
    ANALYSIS *pStorable;
    if ((pStorable = (ANALYSIS*)malloc(sizeof(ANALYSIS))) == NULL){
        perror("Muistinvaraus epäonnistui, lopetetaan");
        exit(0);
    }
    
    return(pStorable);
}

AMOUNTWORDCLASS *setMemoryStructArray(int iAmount){  // luodaan dynaaminen tietue taulukko
    AMOUNTWORDCLASS *pStorable;
    if ((pStorable = (AMOUNTWORDCLASS*)malloc(sizeof(AMOUNTWORDCLASS) * iAmount)) == NULL){
        perror("Muistinvaraus epäonnistui, lopetetaan");
        exit(0);
    }
    for (int i = 1; i != iAmount; i++){
        pStorable[i-1].iClass = i;
    }
    return(pStorable);
}

LINKEDLIST *freeMemory(LINKEDLIST *pListPart){   // vapauttaa linkkitetyn listan muistin
    LINKEDLIST *ptr = pListPart;
    while(pListPart->pNextPiece != NULL)
    {
        pListPart = ptr->pNextPiece;
        free(ptr);
        ptr = pListPart; 
    }
    free(pListPart);
    pListPart = NULL;
    return(pListPart);
}

int menu(){  // Kysyy käyttäjältä operaation Valinnat
    int iChoice = 0;
    printf("Valitse haluamasi toiminto:\n");
    printf("1) Lue tiedosto\n");
    printf("2) Analysoi tiedot\n");
    printf("3) Kirjoita tulokset\n");
    printf("0) Lopeta\n");
    printf("Anna valintasi: ");
    scanf("%i", &iChoice);
    getchar();
    return(iChoice);
}

LINKEDLIST *readFile(LINKEDLIST *pLinkedList){  // lukee tiedoston
    FILE *txt;
    char aRow[IMAXCHARACTER];
    char aSplit[IMAXCHARACTER] = "\0";
    char *pSplit = aSplit; 
    char aSplit2[IMAXCHARACTER] = "\0";
    char *pSplit2 = aSplit2; 
    char aFilename[IMAXCHARACTER];
    char *pFilename = aFilename;
    LINKEDLIST *ptr, *pNewpart;
    pFilename = file(aFilename);

    if ((txt = fopen(pFilename, "r")) == NULL){
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }
    
    fgets(aRow, IMAXCHARACTER, txt);  // jättää tiedoston ensimmäisen rivin lukematta linkitettyyn listaan
    while((fgets(aRow, IMAXCHARACTER, txt)) != NULL)
    {   
        if ((pSplit = strtok(aRow, ";")) == NULL){  // pilkkoo tietoa
            perror("Merkkijonon pilkkominen epäonnistui, lopetetaan");
            exit(0);
        }
        if ((pSplit2 = strtok(NULL, ";")) == NULL){
            perror("Merkkijonon pilkkominen epäonnistui, lopetetaan");
            exit(0);
        }
        pNewpart = setMemoryLinkedList();  // luo palasen listaan
        strcpy(pNewpart->aSentence, pSplit);
        pNewpart->iClass = atoi(pSplit2);
        pNewpart->pNextPiece = NULL;
        if (pLinkedList == NULL){
            pLinkedList = pNewpart;
        }
        else{
            ptr = pLinkedList;
            while(ptr->pNextPiece != NULL)  // etsii viimeisen palan ja lisää siihen linkittämällä uuden
            {
                ptr = ptr->pNextPiece;
            }
            ptr->pNextPiece = pNewpart;
        }

    }
    printf("Tiedosto '%s' luettu.\n", pFilename);
    fclose(txt);
    return pLinkedList;
}


ANALYSIS *analysisOfInformation(LINKEDLIST *pLinkedList, ANALYSIS *pAnalysis){  // analysoi tietoa taulukkoon
    float fSum = 0;   // float jotta jakolasku ulostulo olisi float, 
    int iCounter = 0; 
    LINKEDLIST *ptr = pLinkedList;
    while(ptr->pNextPiece != NULL){
        fSum = fSum + strlen(ptr->aSentence);
        if (iCounter != 0){
            if (strlen(ptr->aSentence) > strlen(pAnalysis->aLongestWord)){
                strcpy(pAnalysis->aLongestWord, ptr->aSentence); 
            }
            if (strlen(ptr->aSentence) < strlen(pAnalysis->aShortestWord)){
                strcpy(pAnalysis->aShortestWord, ptr->aSentence); 
            } 
            if (strcmp(ptr->aSentence, pAnalysis->aAlphabeticallyFirst) < 0){
                strcpy(pAnalysis->aAlphabeticallyFirst, ptr->aSentence);
            }
            if (strcmp(ptr->aSentence, pAnalysis->aAlphabeticallyLast) > 0){
                strcpy(pAnalysis->aAlphabeticallyLast, ptr->aSentence);
            }
        }  
        else{
            strcpy(pAnalysis->aLongestWord, ptr->aSentence);
            strcpy(pAnalysis->aShortestWord, ptr->aSentence); 
            strcpy(pAnalysis->aAlphabeticallyFirst, ptr->aSentence); 
            strcpy(pAnalysis->aAlphabeticallyLast, ptr->aSentence);
        }
        iCounter++;
        ptr = ptr->pNextPiece;
    }
    fSum = fSum + strlen(ptr->aSentence);  // Looppi jättää viimeisen tekemättä, joten tämä teettää sen viimeiselle
    if (strlen(ptr->aSentence) > strlen(pAnalysis->aLongestWord)){
        strcpy(pAnalysis->aLongestWord, ptr->aSentence); 
    }
    if (strlen(ptr->aSentence) < strlen(pAnalysis->aShortestWord)){
        strcpy(pAnalysis->aShortestWord, ptr->aSentence); 
    } 
    if (strcmp(ptr->aSentence, pAnalysis->aAlphabeticallyFirst) < 0){
        strcpy(pAnalysis->aAlphabeticallyFirst, ptr->aSentence);
    }
    if (strcmp(ptr->aSentence, pAnalysis->aAlphabeticallyLast) > 0){
        strcpy(pAnalysis->aAlphabeticallyLast, ptr->aSentence);
    }
    iCounter++;

    pAnalysis->fAverageLength = (fSum / iCounter);

    pAnalysis->iDataAmount = iCounter;
    printf("Analysoitu %i sanaa.\n", iCounter);
    return(pAnalysis);   
}

AMOUNTWORDCLASS *wordperclass(LINKEDLIST *pLinkedList, AMOUNTWORDCLASS *pAmountWordClass){  // laskee luokkien koot
    LINKEDLIST *ptr = pLinkedList;
    while(ptr->pNextPiece != NULL){
        pAmountWordClass[ptr->iClass-1].iAmount++;
        ptr = ptr->pNextPiece;
    }
    pAmountWordClass[ptr->iClass-1].iAmount++;
    printf("Sanaluokittaiset lukumäärät analysoitu.\n");
    return (pAmountWordClass);
}

void writeFile(ANALYSIS *pAnalysis, AMOUNTWORDCLASS AmountWordClass[], FILE *txt, char *pFilename){  // kirjoittaa analysoidut tiedot
    fprintf(txt, "Tilastotiedot %i sanasta:\n", pAnalysis->iDataAmount);
    fprintf(txt, "Keskimääräinen sanan pituus on %.1f merkkiä.\n", pAnalysis->fAverageLength);
    fprintf(txt, "Pisin sana '%s' on %li merkkiä pitkä.\n", pAnalysis->aLongestWord, strlen(pAnalysis->aLongestWord));
    fprintf(txt, "Lyhyin sana '%s' on %li merkkiä pitkä.\n", pAnalysis->aShortestWord, strlen(pAnalysis->aShortestWord));
    fprintf(txt, "Aakkosjärjestyksessä ensimmäinen sana on '%s'.\n", pAnalysis->aAlphabeticallyFirst);
    fprintf(txt, "Aakkosjärjestyksessä viimeinen sana on '%s'.\n", pAnalysis->aAlphabeticallyLast);
    fprintf(txt, "\n");
    fprintf(txt, "Sanaluokka;Lkm\n");
    for (int i = 0; i != 10; i++)
    {
        fprintf(txt, "Luokka %i;%i\n", AmountWordClass[i].iClass, AmountWordClass[i].iAmount);
    }
    return;   
}

void informationRoute(ANALYSIS *pAnalysis, AMOUNTWORDCLASS AmountWordClass[]){ // määrittää minne writeFile funktio kirjoittaa
    FILE *txt;
    char aFilename[IMAXCHARACTER];
    char *pFilename = aFilename;
    pFilename = file(aFilename);

    writeFile(pAnalysis, AmountWordClass, stdout, pFilename);
    if ((txt = fopen(pFilename, "w")) == NULL){
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }
    writeFile(pAnalysis, AmountWordClass, txt, pFilename);
    printf("Tiedosto '%s' kirjoitettu.\n", pFilename);
    fclose(txt);
    return;
}

