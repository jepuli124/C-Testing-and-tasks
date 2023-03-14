#include <stdio.h>
#include <string.h>
#include <stdlib.h>

 
#define IMAX 127 

/* 2023222JalkanenKonstaL6T3*/


typedef struct calculation
{
    char list[IMAX];
    struct calculation *pNext;
    
} CALCULATION;

void write(CALCULATION **pListOfCL){
    FILE *Document;
    char aHolder[IMAX];
    printf("\n");
    CALCULATION *pPointer = *pListOfCL;
    char *pInput;
    setMemory(&pInput);
    printf("Anna kirjoitettavan tiedoston nimi: ");
    file(&pInput);
    while (pPointer != NULL)
    {   
        printf("%s", pPointer->list);
        pPointer = pPointer->pNext;
    }
    if ((Document = fopen(pInput, "w")) == NULL) {
        perror("\nTiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    } 
    else{  
        pPointer = *pListOfCL;
        while (pPointer != NULL){   
        strcpy(aHolder, pPointer->list);
        fputs(aHolder, Document);
        pPointer = pPointer->pNext;
        }
    }
    printf("\nTiedosto '%s' kirjoitettu.\n", pInput);
    fclose(Document);
    free(pInput);
    return;
}

void addNumber(int *iValue, CALCULATION **pCalculation){
    int iInput3 = 0;
    char aChanger [IMAX];
    CALCULATION *pNew, *pPointer;
    printf("\nAnna lukuun lisättävä kokonaisluku: ");
    scanf("%i", &iInput3);
    printf("%i+%i=%i\n", *iValue, iInput3, *iValue+iInput3);   
    sprintf(aChanger, "%i+%i=%i\n", *iValue, iInput3, *iValue+iInput3 );
    
    setMemoryCalculation(&pNew, strlen(aChanger)+1);
    strcpy(pNew->list, aChanger);
    pNew->pNext = NULL;
    if (*pCalculation == NULL){
        *pCalculation = pNew;
        } 
    else {
        pPointer = *pCalculation;
        while (pPointer->pNext != NULL)
            {
            pPointer = pPointer->pNext;
            }
        pPointer->pNext = pNew;
        }
    
    *iValue += iInput3; 
    }

void read(CALCULATION **pCalculation){
    FILE *document;
    char aRow[IMAX];
    CALCULATION *pNew, *pPointer;
    char *pInput;
    printf("\nAnna luettavan tiedoston nimi: ");
    file(&pInput);
    if ((document = fopen(pInput, "r")) == NULL) {
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
        }   
    else{   
        printf("Tiedostossa oleva laskuhistoria:\n"); 
        while (fgets(aRow, IMAX, document) != NULL) {
            if (aRow == "\n"){
                break;
            }
            printf("%s", aRow);
            setMemoryCalculation(&pNew, strlen(aRow)+1);
            strcpy(pNew->list, aRow);
            pNew->pNext = NULL;
            if (*pCalculation == NULL){
                *pCalculation = pNew;
                } 
            else {
                pPointer = *pCalculation;
                while (pPointer->pNext != NULL)
                    {
                    pPointer = pPointer->pNext;
                    }
                pPointer->pNext = pNew;
            }
        }
    }
    printf("Tiedosto '%s' luettu ja tulostettu.\n", pInput);
    free(pInput); 
    fclose(document);
}

void file(char **aInput){
    char aInput2[IMAX];
    scanf("%s", aInput2);
    setMemory(aInput, strlen(aInput2)+1);
    strcpy(*aInput, aInput2);
}

int menu(){
    int iInput;
    printf("\nValitse haluamasi toiminto:\n1) Lisää lukuun\n2) Kirjoita historia tiedostoon\n3) Lue historia tiedostosta\n0) Lopeta\nAnna valintasi: ");
    scanf("%i", &iInput);
    getchar();
    return iInput;
}

void setMemory(char **pChar, int iAmount){
    if ((*pChar = (char*)malloc(iAmount * sizeof(char))) == NULL ){
        perror("Muistin varaus epäonnistui");
        exit(0);
        }
}

void setMemoryCalculation(CALCULATION **List, int iAmount){
    if ((*List = (CALCULATION*)malloc((iAmount+1) * sizeof(CALCULATION))) == NULL ){
        perror("Muistin varaus epäonnistui");
        exit(0);
        }
}

void freeMemory(CALCULATION **pStart){
    CALCULATION *pPointer = *pStart;
    while (pPointer != NULL)
    {   
        *pStart = pPointer->pNext;
        free(pPointer);
        pPointer = *pStart;
    }
     printf("\nMuisti vapautettu.\n");
}


int main(int argc, char *argv[]) {
    if (argc > 2){
        printf("Annoit liikaa parametreja.");
        return(0);
    }
    else if(argc < 2){
        printf("Et antanut tarpeeksi parametreja.");
        return(0);
    }
    
    int iInput2, iCounter2 = 0;
    CALCULATION *pListOfCL = NULL;
    int iFirstNumber = 0; 
    iFirstNumber += atoi(argv[1]);
    

    printf("Annoit luvun %i.", iFirstNumber);

    
    
    do 
    {
        iInput2 = menu();
        if (iInput2 == 1){
            addNumber(&iFirstNumber, &pListOfCL);
        }
        else if (iInput2 == 2){
            if (pListOfCL->list == NULL){
                printf("\nEi kirjoitettavia tietoja.\n");
            }
            else {
            write(&pListOfCL);
            }
        }
        else if (iInput2 == 0){
            
            
            iCounter2 = 1;
        }
        else if (iInput2 == 3){
            read(&pListOfCL);
        }
        else {
            printf("\nTuntematon valinta, yritä uudestaan.\n");
        }
    } while (iCounter2 == 0);
    freeMemory(&pListOfCL);
    printf("Lopetetaan.\n\nKiitos ohjelman käytöstä.\n");
    return(0);
}