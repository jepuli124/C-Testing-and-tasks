#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "L7T2Kirjasto.h"

/* 2023222JalkanenKonstaL7T2*/


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
    int iRead = 0;
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
            if (iRead == 0){
                read(&pListOfCL);
                iRead = 1;
            }
            else{
                freeMemory(&pListOfCL);
                printf("\nMuisti vapautettu.");
                read(&pListOfCL);
            }
            
        }
        else if (iInput2 == 4){
            RemoveFromList(&pListOfCL, &iFirstNumber);
        }
        else {
            printf("\nTuntematon valinta, yritä uudestaan.\n");
        }
    } while (iCounter2 == 0);
    freeMemory(&pListOfCL);
    printf("\nLopetetaan.\n\nMuisti vapautettu.\nKiitos ohjelman käytöstä.\n");
    return(0);
}