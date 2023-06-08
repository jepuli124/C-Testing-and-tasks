#include <stdio.h>

/* char aInput[30];
char aInput2[30]; */
int iInput;


int main(void) {
    printf("Anna palautettujen tehtävien lukumäärä: ");
    scanf("%i", &iInput);
    if (iInput <= 14 ) {printf("Olet palauttanut %i tehtävää, joten arvosanasi on 0.", iInput); }
    else if(iInput <= 17){
        printf("Olet palauttanut %i tehtävää, joten arvosanasi on 1.", iInput);
    }
    else if (iInput <= 20){
        printf("Olet palauttanut %i tehtävää, joten arvosanasi on 2.", iInput);
    }
    else if(iInput <= 23){
        printf("Olet palauttanut %i tehtävää, joten arvosanasi on 3.", iInput);
    }
    else if(iInput <= 26){
        printf("Olet palauttanut %i tehtävää, joten arvosanasi on 4.", iInput);
    }
    else if(iInput <= 30){
        printf("Olet palauttanut %i tehtävää, joten arvosanasi on 5.", iInput);
    }
    else{
        printf("Kurssilla on vain 30 tehtävää.");
    }
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