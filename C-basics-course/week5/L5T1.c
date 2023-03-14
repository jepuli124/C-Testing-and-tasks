#include <stdio.h>
#include <string.h>
#include <stdlib.h>

 
#define IMAX 30 

/* 2023215JalkanenKonstaL5T1*/



char * setMemory(){
    char *pSentence;
    if ((pSentence = (char*)malloc(sizeof(30))) == NULL ){
        perror("Muistin varaus epäonnistui");
        exit(0);
        }
    printf("Muisti varattu 30 merkille.\n");
    return pSentence;
}

void setSentence(char *word){
    printf("Anna merkkijono: ");
    fgets(word, IMAX, stdin);
    word[strlen(word)-1] = '\0';
    return;
}

int main(int argc, char *argv[]) {
    char *pSentence;
    pSentence = setMemory();
    setSentence(pSentence);
    printf("Annoit merkkijonon '%s'.\n", pSentence);
    free(pSentence);
    printf("Muisti vapautettu.\n");
    printf("Kiitos ohjelman käytöstä.\n");

    return(0);
}