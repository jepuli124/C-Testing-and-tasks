#include <stdio.h>

char cInput;
char cInput2[20];
/*int iOutput;
int iOutput2;
*/
int main(void) {
    printf("Anna merkki: ");
    scanf("%c", &cInput);
    printf("Annoit merkin '%c'\n", cInput);
    printf("Anna korkeintaan 20 merkkiä pitkä merkkijono: ");
    scanf("%s", cInput2);
    printf("Annoit merkkijonon '%s'.", cInput2);
    /*
    iOutput = iInput + 1;
    iOutput2 = iInput2 - 1;
    */
   /*
    printf("%i * %i = %i\n(%i / %i) - 10 = %i\n%i %s %i = %i", iOutput, iInput2, iOutput * iInput2, iInput, iInput2, (iInput / iInput2) - 10, iInput, "%" , iOutput2, iInput % iOutput2); 
    */
    return(0);
}
