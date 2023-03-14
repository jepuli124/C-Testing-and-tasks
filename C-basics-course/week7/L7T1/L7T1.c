#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "L7T1Kirjasto.h"
 

/* 2023227JalkanenKonstaL7T1 */



int main(void) {

    CALCULATION *pListOfCL = NULL;
    pListOfCL = read(pListOfCL);
    printList(pListOfCL);
    pListOfCL = freeMemory(pListOfCL);
    printf("\nKiitos ohjelman käytöstä.\n");
    return(0);
}
