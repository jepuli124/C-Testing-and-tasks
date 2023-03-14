#include <stdio.h>
#include <string.h>
#include <stdlib.h>

 
#define IMAX 255 

/* 2023218JalkanenKonstaL5T3*/


typedef struct calculation
{
    char list[IMAX];
} CALCULATION;

void write(char *aFilename, CALCULATION *pListOfCL, int iAmount){
    FILE *Document;
    char aHolder[IMAX];
    //char *pHolder;
    //setMemory(&pHolder);
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
    //free(pHolder);
    return;
}

CALCULATION addNumber(char *aFilename, int *iValue){
    int iInput3 = 0;
    char aChanger [IMAX];
    //char *pChanger;
    //setMemory(&pChanger);
    printf("\nAnna lukuun lisättävä kokonaisluku: ");
    scanf("%i", &iInput3);
    printf("%i+%i=%i\n", *iValue, iInput3, *iValue+iInput3);   
    sprintf(aChanger, "%i+%i=%i\n", *iValue, iInput3, *iValue+iInput3 );
    CALCULATION calculation[2];
    CALCULATION *pCalculation = calculation;
    strcpy(pCalculation->list, aChanger);
    *iValue += iInput3; 
    //free(pChanger);
            
    return *pCalculation;
    }

void read(char *iFilename){
    FILE *document;
    char aRow[IMAX];
    printf("\nTiedostossa oleva laskuhistoria:\n");
    if ((document = fopen(iFilename, "r")) == NULL) {
        perror("\nTiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
        }   
    else{    
        while (fgets(aRow, IMAX, document) != NULL) {
            printf("%s", aRow);
            if (aRow[strlen(aRow)-1] != '\n'){  // Toimii ilman tätä omalla koneellani, mut ei codeGradessa.
                printf("\n");
            }
        }
    } 
    printf("Tiedosto '%s' luettu ja tulostettu.\n", iFilename);
    fclose(document);
}

void file(char *aInput){
    printf("\nAnna kirjoitettavan tiedoston nimi: ");
    scanf("%s", aInput);
}

int menu(){
    int iInput;
    printf("\nValitse haluamasi toiminto:\n1) Anna tiedoston nimi\n2) Lisää lukuun\n3) Kirjoita historia tiedostoon\n4) Lue historia tiedostosta\n0) Lopeta\nAnna valintasi: ");
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
    if ((List = (CALCULATION*)malloc(IMAX * sizeof(CALCULATION))) == NULL ){
        perror("Muistin varaus epäonnistui");
        exit(0);
        }
    return List;
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
    char *pInput;
    setMemory(&pInput);
    int iInput2, iCounter2 = 0;
    int iCounter3 = 0;
    //CALCULATION pListOfCL[IMAX];
    CALCULATION *pListOfCL = setMemoryCalculation(pListOfCL);
    int iFirstNumber = 0; 
    iFirstNumber += atoi(argv[1]);
    

    printf("Annoit luvun %i.", iFirstNumber);

    
    
    do 
    {
        iInput2 = menu();
        if (iInput2 == 1){
            file(pInput);
        }
        else if (iInput2 == 2){
            pListOfCL[iCounter3] = addNumber(pInput, &iFirstNumber);
            iCounter3++;
        }
        else if (iInput2 == 3){
            if (iCounter3 == 0){
                printf("\nEi kirjoitettavia tietoja.\n");
            }
            else if (strlen(pInput) < 2 ){
                printf("\nEi tiedoston nimeä, anna kirjoitettavan tiedoston nimi ensin.\n");
            }
            else {
            write(pInput, pListOfCL, iCounter3);
            }
        }
        else if (iInput2 == 0){
            printf("\nMuisti vapautettu.");
            printf("\nLopetetaan.\n\nKiitos ohjelman käytöstä.\n");
            iCounter2 = 1;
        }
        else if (iInput2 == 4){
            if (strlen(pInput) < 2 ){
                printf("\nEi tiedoston nimeä, anna luettavan tiedoston nimi ensin.\n");
            }
            else{
                read(pInput);
            }
        }
        else{
            printf("\nTuntematon valinta, yritä uudestaan.\n");
        }
    } while (iCounter2 == 0);
    
    free(pInput);
    free(pListOfCL);
    return(0);
}