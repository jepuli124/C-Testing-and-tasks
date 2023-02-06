#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define iChance 95

int iInput, iInput2;
char aGenerated[30];

void seed(){
    int iInput;
    printf("Tämä ohjelma luo satunnaisia merkkijonoja.\nAnna satunnaisgeneraattorin siemenluku: ");
    scanf("%i", &iInput);
    srand(iInput);
}

int amount(){
    int iInput2;
    printf("Anna arvottavien merkkien määrä: ");
    scanf("%i", &iInput2);
    iInput2--;
    return iInput2;
}

char* random(int iInput2, char *aGenerated){
    int iValue = 0;
    int iCounter = 0;
    char cChar;
    for(int i = 0; i <= iInput2; i++){
        iValue = rand() % iChance;
        cChar = iValue + 32;
        if (isdigit(cChar)){
            aGenerated[iCounter] = iValue + 32;
            iCounter++;
        }
        else if (isalpha(cChar)){
            aGenerated[iCounter] = iValue + 32;
            iCounter++;
        }
        else if (isspace(cChar))
        {
            aGenerated[iCounter] = iValue + 32;
            iCounter++;
        }
        
        
    }
    iCounter++;
    aGenerated[iCounter] = ('\0');

    return aGenerated;
}

void testc(char *aGenerated){
    if (strchr(aGenerated, 'c')){
        printf("\nMerkkijonosta löydettiin merkki 'c'.");
        return;
    }
    printf("\nMerkkijonossa ei ollut merkkiä 'c'.");
    return;
}



int main(void){
    seed();
    iInput2 = amount();
    random(iInput2, aGenerated);
    testc(aGenerated);
    printf("\nGeneroitiin merkkijono '%s', jossa on %li merkkiä.\n", aGenerated, strlen(aGenerated));
    printf("Kiitos ohjelman käytöstä.\n");
    return(0);
}