#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


/* Jotain random tekstiä, Konsta Jalkanen, Tehty aikanaan, C kurssille 2023. Joku sano et tämmönen piti olla*/

#define iMax 50



struct song
{
    int iInput;
    char aName[iMax];
    char aSong[iMax];
    char aTime[iMax];

};




int main(void){
    struct song Omusic;
    printf("Anna kappaleen nimi: ");
    fgets(Omusic.aName, iMax, stdin);
    Omusic.aName[strlen(Omusic.aName)-1] = '\0';
    printf("Anna kappaleen esittäjä: ");
    fgets(Omusic.aSong, iMax, stdin);
    Omusic.aSong[strlen(Omusic.aSong)-1] = '\0';
    printf("Anna kappaleen pituus: ");
    fgets(Omusic.aTime, iMax, stdin);
    Omusic.aTime[strlen(Omusic.aTime)-1] = '\0';
    printf("Anna kappaleen julkaisuvuosi: ");
    scanf("%i", &Omusic.iInput);
    printf("Kappaleen nimi on '%s' ja esittäjä '%s'.\n", Omusic.aName, Omusic.aSong);
    printf("Kappale on %s minuuttia pitkä ja julkaistu vuonna %i.\n", Omusic.aTime, Omusic.iInput);
    printf("Kiitos ohjelman käytöstä.\n");
    return(0);
}











































/*Ei mul muuta*/