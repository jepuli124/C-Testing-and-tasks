#include <stdio.h>
#include <string.h>
#include <stdlib.h>

 
#define IMAX 30

/* 2023219JalkanenKonstaL5T4*/


typedef struct calculation
{
    char list[IMAX];
} CALCULATION;

void write(CALCULATION *pListOfCL, int iAmount, char aFilename[]){
    FILE *Document;
    char aHolder[IMAX];
    printf("\n");
    for(int i = 0; i != iAmount; i++){
            printf("%s", pListOfCL[i].list);
        }
    if ((Document = fopen(aFilename, "a")) == NULL) {
        perror("\nTiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    } 
    else{  
        for(int i = 0; i != iAmount; i++){
            strcpy(aHolder, pListOfCL[i].list);
            fputs(aHolder, Document);

        }
    }
    printf("\nTiedosto '%s' kirjoitettu.\n", aFilename);
    fclose(Document);
    return;
}

void read(CALCULATION *pListOfCL, int *iCounter3, char aFilename[]){
    if (strlen(aFilename) < 2){
        printf("");
        return;
    } 
    FILE *document;
    char aRow[IMAX];
    if ((document = fopen(aFilename, "r")) == NULL) {
        perror("\nTiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
        }   
    else{    
        while (fgets(aRow, IMAX, document) != NULL) {
            resetMemoryCalculation(&pListOfCL, strlen(aRow));
            strcpy(pListOfCL[*iCounter3].list, aRow);
            *iCounter3++;
        }
    } 
    printf("Tiedosto '%s' luettu.\n", aFilename);
    fclose(document);
}

void fileR(char *aInput){
    printf("\nAnna luettavan tiedoston nimi: ");
    scanf("%s", *aInput);
}
void fileW(char *aInput){
    printf("\nAnna kirjoitettavan tiedoston nimi: ");
    scanf("%s", *aInput);
}

int menu(){
    int iInput;
    printf("Valitse haluamasi toiminto:\n1) Lue tiedosto\n2) Laske merkkijonojen summa\n3) Kirjoita tiedosto\n0) Lopeta\nAnna valintasi: ");
    scanf("%i", &iInput);
    return iInput;
}

void setMemory(char **pChar){
    if ((*pChar = (char*)malloc(IMAX * sizeof(char))) == NULL ){
        perror("Muistin varaus epäonnistui");
        exit(0);
        }
}

CALCULATION * setMemoryCalculation(CALCULATION *List){
    if ((List = (CALCULATION*)malloc(sizeof(List) * IMAX)) == NULL ){
        perror("Muistin varaus epäonnistui");
        exit(0);
        }
    return List;
}


void resetMemoryCalculation(CALCULATION **List, int iAmount){
    if ((*List = (CALCULATION*)realloc(*List, sizeof(CALCULATION) * (iAmount + 1))) == NULL ){
        perror("Muistin varaus epäonnistui");
        exit(0);
    }
}

int ascii(char aString[]){
    int iCounter2 = 0;
    int iValue = 0;
    int iSum = 0;
    while (iCounter2 <= strlen(aString))
        {
        iValue = aString[iCounter2];
        iSum += iValue;
        ++iCounter2;
        }
    return iSum;
}

CALCULATION * calculateSum(CALCULATION *pListOfCL, int iCounter3){
    char aAdd[IMAX];
    for (int iCounter = 0; iCounter < iCounter3; iCounter++){
        int iSum = 0;
        if (strlen(pListOfCL[iCounter].list) > 0) {
            iSum = ascii(pListOfCL[iCounter].list);
            pListOfCL[iCounter].list[strlen(pListOfCL[iCounter].list)-1] = '\0';
        }
        sprintf(aAdd, "%s;%i\n", pListOfCL[iCounter].list, iSum);

        strcpy(pListOfCL[iCounter].list, aAdd);
    }
    printf("\n\nSummat laskettu %i merkkijonolle.\n", iCounter3);
    return pListOfCL;
}

int main() {
    CALCULATION *pListOfCL = setMemoryCalculation(pListOfCL);
    int iInput2 = 0;
    int iCounter3 = 0;
    int iCounter2 = 0;
    do 
    {
        iInput2 = menu();
        if (iInput2 == 1){
            char aFilename[IMAX];
            fileW(*aFilename);
            read(pListOfCL, &iCounter3, aFilename);
        }
        else if (iInput2 == 2){
            if (strlen(pListOfCL->list) < 0){
                printf("\nEi analysoitavaa, lue tiedosto ennen analyysia.\n");
            }
            else{
            pListOfCL = calculateSum(pListOfCL, iCounter3);
            }
        }
        else if (iInput2 == 3){
            char aFilename[IMAX];
            fileR(*aFilename);
            if (strlen(pListOfCL->list) < 0){
                printf("\nEi kirjoitettavia tietoja, analysoi tiedot ennen tallennusta.\n");
            }
            else{
            write(pListOfCL, iCounter3);
            }
        }
        else if (iInput2 == 0){
            printf("\nMuisti vapautettu.");
            printf("\nLopetetaan.\n\nKiitos ohjelman käytöstä.\n");
            iCounter2 = 1;
        }
        else{
            printf("\nTuntematon valinta, yritä uudestaan.\n");
        }
    } while (iCounter2 == 0);
    
    free(pListOfCL);
    pListOfCL = NULL;
    return(0);
}
