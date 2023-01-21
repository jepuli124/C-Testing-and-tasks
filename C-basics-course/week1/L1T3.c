#include <stdio.h>

int iInput;
int iInput2;
int iOutput;
int iOutput2;

int main(void) {
    printf("Anna ensimmäinen kokonaisluku: ");
    scanf("%i", &iInput);
    printf("Anna toinen kokonaisluku: ");
    scanf("%i", &iInput2);
    iOutput = iInput + 1;
    iOutput2 = iInput2 - 1;
    printf("%i * %i = %i\n(%i / %i) - 10 = %i\n%i %s %i = %i", iOutput, iInput2, iOutput * iInput2, iInput, iInput2, (iInput / iInput2) - 10, iInput, "%" , iOutput2, iInput % iOutput2); 
    return(0);
}