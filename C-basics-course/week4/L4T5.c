#include <stdio.h>
#include <string.h>
#include <stdlib.h>

 
#define IMAX 30 

/* 2023210JalkanenKonstaL4T5*/



void printForward(char word[IMAX], int iCounter){
    if(iCounter < strlen(word)){
    char *pWord = word;
    printf("%c\n", pWord[iCounter]);
    iCounter++;
    printForward(word, iCounter);
    }
    return;
}

void printBackward(char *word, int iCounter){
    if(iCounter >= 0){
    char *pWord = word;
    printf("%c\n", pWord[iCounter]);
    iCounter--;
    printBackward(word, iCounter);
    }
    return;
}

int main(int argc, char *argv[]) {

    int iInput2;
    int iRun = 1;
    if (argc >= 3){
        printf("Annoit liikaa parametreja.");
        return(0);
    }
    else if(argc <= 1){
        printf("Et antanut tarpeeksi parametreja.");
        return(0);
    }
    
    do 
    {
        printf("Valitse haluamasi toiminto:\n1) Tulosta merkkijono\n2) Tulosta merkkijono takaperin\n0) Lopeta\nAnna valintasi: ");
        scanf("%i", &iInput2);
        if (iInput2 == 1){
            printForward(argv[1], 0);
            printf("\n");
        }
        else if (iInput2 == 2){
            printBackward(argv[1], strlen(argv[1])-1);
            printf("\n");
        }
        else if (iInput2 == 0){
            printf("Lopetetaan.");
            iRun = 0;
        }
        else{
            printf("\nTuntematon valinta, yritä uudestaan.\n");
        }
    } while (iRun == 1);

    printf("\n\nKiitos ohjelman käytöstä.\n");


    return(0);
}