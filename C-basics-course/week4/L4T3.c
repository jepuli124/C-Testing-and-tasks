#include <stdio.h>
#include <string.h>
#include <stdlib.h>

 
#define iMax 30 

/* 202328JalkanenKonstaL4T3*/


typedef struct calculation
{
    char list[IMAX];
} CALCULATION;

void write(char *aFilename, CALCULATION listOfCL[IMAX], int iAmount){
    FILE *Document;
    char aHolder[IMAX];
    if ((Document = fopen(aFilename, "a")) == NULL) {
        perror("\nTiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    } 
    else{  
        for(int i = 0; i != iAmount; i++){
            strcpy(aHolder, &listOfCL[i]);
            fputs(aHolder, Document);

        }
    }
    printf("\nTiedosto '%s' kirjoitettu.\n", aFilename);
    fclose(Document);

    return;
}

CALCULATION choise1(char *aFilename, int *iValue){
    int iInput3 = 0;
    char aChanger[IMAX];
    printf("\nAnna lukuun lisättävä kokonaisluku: ");
    scanf("%i", &iInput3);
    printf("%i+%i=%i\n", *iValue, iInput3, *iValue+iInput3);
    /*if (aChanger[0] == '@'){
        sprintf(calculation->list, "%i+%i=%i\n",  calculation->iValue, calculation->iValue2, iMiddleput);
    }
    else{
        sprintf(calculation->list, "%s%i+%i=%i\n", aChanger ,calculation->iValue, calculation->iValue2, iMiddleput);
    }*/
    sprintf(aChanger, "%i+%i=%i\n", *iValue, iInput3, *iValue+iInput3 );
    CALCULATION calculation;
    strcpy(calculation.list, aChanger);
    *iValue += iInput3; 
            
    /*while (calculation.list[iCounter] != NULL)
            {
                iCounter++;
            }
            calculation.list[iCounter] = iInput[0];
            iCounter++;
            calculation->list[iCounter] = iInput[1];
            iCounter++;
            calculation->list[iCounter] = iInput[2]; */
    return calculation;
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
        }
    } 
    printf("Tiedosto '%s' luettu ja tulostettu.\n", iFilename);
    fclose(document);
}

void file(char aInput[IMAX]){
    printf("Anna kirjoitettavan tiedoston nimi: ");
    scanf("%s", aInput);
}

int main(void) {
    char aInput[IMAX];
    int iInput2, iFirstNumber, iCounter2 = 0;
    int iCounter3 = 0;
    CALCULATION listOfCL[IMAX];
    

    printf("Anna kokonaisluku: ");
    scanf("%i", &iFirstNumber);
    file(aInput);
    
    do 
    {
        printf("\nValitse haluamasi toiminto:\n1) Lisää lukuun\n2) Kirjoita historia tiedostoon\n3) Lue historia tiedostosta\n0) Lopeta\nAnna valintasi: ");
        scanf("%i", &iInput2);
        if (iInput2 == 1){
            listOfCL[iCounter3] = choise1(aInput, &iFirstNumber);
            iCounter3++;
        }
        else if (iInput2 == 2){
            write(aInput, listOfCL, iCounter3);
        }
        else if (iInput2 == 0){
            printf("\nLopetetaan.\n\nKiitos ohjelman käytöstä.\n");
            iCounter2 = 1;
        }
        else if (iInput2 == 3){
            read(aInput);
        }
        else{
            printf("\nTuntematon valinta, yritä uudestaan.\n");
        }
    } while (iCounter2 == 0);

    return(0);
}