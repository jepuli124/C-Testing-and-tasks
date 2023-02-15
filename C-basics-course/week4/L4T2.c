#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


/* 2023207JalkanenKonstaL4T2*/

#define iMax 53








int main(int argc, char *argv[]){
    

    if (argc >= 4){
        printf("Annoit liikaa parametreja.");
        return(0);
    }
    else if(argc <= 2){
        printf("Et antanut tarpeeksi parametreja.");
        return(0);
    }
    int iCounter = 0;
    char aRead[IMAX];
    int iAmount = 0;
    iAmount = *argv[2] - 48;
    //char aOutput[] = argv[1];
    FILE *file;
    if ((file = fopen(argv[1], "r")) == NULL){
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        return(0);
    }

        while(iCounter <= iAmount-1){
            if (fgets(aRead, IMAX, file) == NULL){
                printf("\nTiedostossa ei ole enempää rivejä luettavaksi.");
                break;
            }

            if (strlen(aRead) <= 2){
                printf("\nTiedostossa ei ole enempää rivejä luettavaksi.");
                break;
            }
            else if (strlen(aRead) >= 7){
                printf("%s", aRead);
                iCounter++;
            }
        }

    
    
    
    printf("\nTiedostosta '%s' luettu %i riviä.\n", argv[1], iCounter);
    //printf("Kiitos ohjelman käytöstä.\n");
    fclose(file);
    return(0);
}











































/*Ei mul muuta*/