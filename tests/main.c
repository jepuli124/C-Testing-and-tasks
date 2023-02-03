#include <stdio.h>

#define iBigchange 65
#define iChange 97  

char aAlphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char aAlphabet2[] = "abcdefghijklmnopqrstuvwxyz";

char cInput;
char aInput[30];

int iCounter;
int iCounter2;
int iSum = 0;

int main(void) {
    printf("Anna merkki: ");
    scanf("%c", &cInput);
    for(iCounter=iBigchange; iCounter != 91; ++iCounter){
        if (cInput == aAlphabet[iCounter-iBigchange]){
            printf("Merkki '%c' on ASCII-taulukon mukaan lukuna %i.\n", cInput, iCounter);
            break;
            }
        }
    for(iCounter=iChange; iCounter != 123; ++iCounter){
        if (cInput == aAlphabet2[iCounter-iChange]){
            printf("Merkki '%c' on ASCII-taulukon mukaan lukuna %i.\n", cInput, iCounter);
            break;
            }
        }
    printf("Anna merkkijono: ");
    scanf("%s", aInput);
    while (iCounter2 >= 0)
                {
                for(iCounter=iBigchange; iCounter != 91; ++iCounter){
                    if (cInput == aAlphabet[iCounter-iBigchange]){
                        printf("%i", iCounter);
                        iSum += iCounter;
                        }
                    }
                for(iCounter=iChange; iCounter != 123; ++iCounter){
                    if (cInput == aAlphabet2[iCounter-iChange]){
                        printf("%i", iCounter);
                        iSum += iCounter;
                        }
                    }           
                --iCounter2;
                }
    printf("Merkkijonon '%s' merkkien summa on %i.\n", aInput, iSum);
    /*
    if (iStart <= iInput) {
        if (iEnd >= iInput) {
            while (iInput >= 1)
                {
                for(i=0; i != iCopy; ++i){
                    printf("*");
                }
                printf("\n");
                --iInput;
                }
        }
        else {
        printf("Antamasi luku ei ole määritellyllä välillä.");
        } 
    }
    else {
        printf("Antamasi luku ei ole määritellyllä välillä.");
    }   
    */
    /*
    if (iInput <= 14 ) {
        printf("Olet palauttanut %i tehtävää, joten arvosanasi on 0", iInput);
    }
    else if(iInput <= 17){
        printf("Olet palauttanut %i tehtävää, joten arvosanasi on 1", iInput);
    }
    else if (iInput <= 20){
        printf("Olet palauttanut %i tehtävää, joten arvosanasi on 2", iInput);
    }
    else if(iInput <= 23){
        printf("Olet palauttanut %i tehtävää, joten arvosanasi on 3", iInput);
    }
    else if(iInput <= 26){
        printf("Olet palauttanut %i tehtävää, joten arvosanasi on 4", iInput);
    }
    else if(iInput <= 30){
        printf("Olet palauttanut %i tehtävää, joten arvosanasi on 5", iInput);
    }
    */
    /* scanf("%i", &iInput2);
    printf("Anna lemmikin ikä: ");

    printf("Anna lemmikin paino: ");
    */

    
    /*
    iOutput = iInput + 1;
    iOutput2 = iInput2 - 1;
    */
    /*
    printf("Lemmikin nimi on %s ja rotu on %s.\nSen ikä on %i vuotta ja paino %.1f kg.", iInput, fInput); 
    */
    return(0);
}