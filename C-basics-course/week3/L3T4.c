#include <stdio.h>

#define iFull 61  


char aInput[iFull];
char aInput2[iFull];

int test(char *aString, char *aString2){
    char cChar = 'k';
    int iCounter = 0;
    int iCounter2 = 0;
    while (cChar != '\0'){
        cChar = aString[iCounter];
        iCounter++;
    }

    cChar = '0';
    while(cChar !='\0'){
        cChar = aString2[iCounter2];
        iCounter2++;
    }
    if (iCounter + iCounter2 >= iFull){
        printf("Merkkijonojen yhteenlaskettu pituus on liian pitkä ohjelman muistialueelle.\n");
        return 1;
    }
    return 0;
}

char* combine(char *aString, char *aString2, char *aCombined){
    char cChar = '0'; 
    int iCounter = 0;
    int iCounter2 = 0;
    while(cChar != '\0'){
        cChar = aString[iCounter];
        aCombined[iCounter2] = aString[iCounter];
        iCounter++;
        iCounter2++;
    }
    iCounter2--;
    iCounter2--;
    iCounter = 0;
    cChar = 'k';
    while (cChar != '\n'){
        aCombined[iCounter2] = aString2[iCounter];
        iCounter++;
        cChar = aString2[iCounter];
        iCounter2++;
    }
    aCombined[iCounter2] = '\0';
    return aCombined;

}
 
int main(void) {
   printf("Anna ensimmäinen merkkijono (max 30 merkkiä): ");
   fgets(aInput, iFull, stdin);

   printf("Anna toinen merkkijono (max 30 merkkiä): ");
    fgets(aInput2, iFull, stdin);
    if (test(aInput, aInput2)){
        printf("Kiitos ohjelman käytöstä.\n");
        return(0);
    }

    char aCombined[iFull];
    combine(aInput, aInput2, aCombined);
    printf("Yhdistetty merkkijono on:\n'%s'\n", aCombined);
    printf("Kiitos ohjelman käytöstä.\n");
    return(0);
}