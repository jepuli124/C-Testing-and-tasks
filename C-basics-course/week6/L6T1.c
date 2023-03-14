#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/* 2023221JalkanenKonstaL6T1*/

typedef struct linkedlist
{
    char cCharacter;
    struct linkedlist *pNext;
}LINKEDLIST;



int main() {
    char cInput = '\0';
    LINKEDLIST *pStart = NULL, *pEnd = NULL;
    LINKEDLIST *pPointer, *pNew;
    printf("Anna listan kirjaimet.\n");
    while (cInput != 'q'){
        printf("Anna kirjain, q lopettaa: ");
        
        if ((pNew = (LINKEDLIST*)malloc(sizeof(LINKEDLIST))) == NULL ){
            perror("muisti epäonnistui, muista ensikerralla uudestaan:");
            exit(0);
        }
        scanf("%c", &cInput);
        getchar();
        pNew->cCharacter = cInput;
        pNew->pNext = NULL;
        if (pStart == NULL){
            pStart = pNew;
            pEnd = pNew;
        } 
        else {
            pEnd->pNext = pNew;
            pEnd = pNew;
        }
    }
    printf("Listassa on seuraavat kirjaimet:\n");
    pPointer = pStart;
    while (pPointer->pNext != NULL)
    {
        printf("%c ", pPointer->cCharacter);
        pPointer = pPointer->pNext;
    }
    pPointer = pStart;
    while (pPointer->pNext != NULL)
    {   
        pStart = pPointer->pNext;
        free(pPointer);
        pPointer = pStart;
    }

    printf("\n\nMuisti vapautettu.\n");
    printf("Kiitos ohjelman käytöstä.\n");

    return(0);
}
