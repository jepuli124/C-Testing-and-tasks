#include <stdio.h>
#include <string.h>
#include <stdlib.h>

 
#define iMax 30 
#define ROW 3
#define COLUMN 3
/* 2023210JalkanenKonstaL4T4*/




void matrixWrite(char pInput[IMAX], int matrix[ROW][COLUMN]){
    FILE *Document;
    if ((Document = fopen(pInput, "w")) == NULL) {
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }
    printf("\nLähtömatriisi: \n%4d %4d %4d \n%4d %4d %4d \n%4d %4d %4d \n", matrix[0][0], matrix[0][1], matrix[0][2], matrix[1][0], matrix[1][1], matrix[1][2], matrix[2][0], matrix[2][1], matrix[2][2]);
    printf("\nLähtömatriisin transpoosi: \n%4d %4d %4d \n%4d %4d %4d \n%4d %4d %4d \n", matrix[0][0], matrix[1][0], matrix[2][0], matrix[0][1], matrix[1][1], matrix[2][1], matrix[0][2], matrix[1][2], matrix[2][2]);
    fprintf(Document, "Lähtömatriisi: \n%4d %4d %4d \n%4d %4d %4d \n%4d %4d %4d \n", matrix[0][0], matrix[0][1], matrix[0][2], matrix[1][0], matrix[1][1], matrix[1][2], matrix[2][0], matrix[2][1], matrix[2][2]);
    fprintf(Document, "\nLähtömatriisin transpoosi: \n%4d %4d %4d \n%4d %4d %4d \n%4d %4d %4d \n", matrix[0][0], matrix[1][0], matrix[2][0], matrix[0][1], matrix[1][1], matrix[2][1], matrix[0][2], matrix[1][2], matrix[2][2]);
    fclose(Document);
    printf("\nTiedosto '%s' kirjoitettu.", pInput);
    return;
}

void file(char *pInput){
    printf("Anna kirjoitettavan tiedoston nimi: ");
    scanf("%s", pInput);
    return;
}

int main(void) {

    char aInput[IMAX];
    char* pInput = aInput;
    file(pInput);
    int matrix[ROW][COLUMN];
    printf("Anna arvot lähtömatriisille: \n");
    for (int i = 0; i != ROW; i++){
        for (int j = 0; j != COLUMN; j++){
            printf("Rivi %i, alkio %i: ", i+1, j+1);
            scanf("%i", &matrix[i][j]);
        }
    }
    
    matrixWrite(pInput, matrix);

    printf("\nKiitos ohjelman käytöstä.\n");


    return(0);
}