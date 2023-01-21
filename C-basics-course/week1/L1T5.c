#include <stdio.h>

char aInput[30];
char aInput2[30];
int iInput;
float fInput;

int main(void) {
    printf("Anna lemmikin nimi: ");
    scanf("%s", aInput);
    printf("Anna lemmikin rotu: ");
    scanf("%s", aInput2);
    printf("Anna lemmikin ikä: ");
    scanf("%i", &iInput);
    printf("Anna lemmikin paino: ");
    scanf("%f", &fInput);

    
    /*
    iOutput = iInput + 1;
    iOutput2 = iInput2 - 1;
    */
   
    printf("Lemmikin nimi on %s ja rotu on %s.\nSen ikä on %i vuotta ja paino %.1f kg.", aInput, aInput2, iInput, fInput); 
    
    return(0);
}