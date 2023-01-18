#include <stdio.h>

int iInput;
float fInput;

int main(void) {
    scanf("Anna kokonaisluku: %i", &iInput);
    scanf("Anna liukuluku: %f", &fInput);
    printf("Annoit luvut %i ja %f.\n", iInput, fInput);
    return(0);
}