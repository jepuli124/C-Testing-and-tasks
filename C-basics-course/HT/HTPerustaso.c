/*************************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
* Tekijä: Konsta Jalkanen   
* Opiskelijanumero: 000489689
* Päivämäärä: 12/03/2023
* Kurssin oppimateriaalien lisäksi työhön ovat vaikuttaneet seuraavat
* lähteet ja henkilöt, ja se näkyy tehtävässä seuraavalla tavalla:
* Tuomas Lättilä ja Tomi Vilpponen ovat huomauttaneet tyyliohjeiden noudattamisesta olevasta puutteesta. 
* Aleksi natunen huomautti stdout olemassa olosta.
* Mahdollisen vilppiselvityksen varalta vakuutan, että olen tehnyt itse
* tämän tehtävän ja vain yllä mainitut henkilöt sekä lähteet ovat
* vaikuttaneet siihen yllä mainituilla tavoilla.
*/
/*************************************************************************/
/* Tehtävä Harjoitus työ, tiedoston nimi HTPerustaso.c */
/* eof */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "HTPerusKirjasto.h"



int main(void) {
    int iMenu = 0;  // alustetaan arvoja
    int iIsread = 0, iIsAnalysided = 0;  
    LINKEDLIST *pLinkedList = NULL;
    AMOUNTWORDCLASS AmountWordClass[ILENGTHARRAY] = {{0}};
    for (int i = 0; i != 10; i++){
        AmountWordClass[i].iClass = i+1;
        AmountWordClass[i].iAmount = 0;
    }
    AMOUNTWORDCLASS *pAmountWordClass = AmountWordClass; 
    ANALYSIS *pAnalysis = setMemoryAnalysis();

    do  // valikko loop
    {   
        iMenu = menu();  // Valinnan kysyminen
        
        if (iMenu == 1)
        {   
            if (iIsread == 1){ // Jos tiedosto on jo luettu, niin tyhjennetään linkitetty lista uutta lukemista varten
                pLinkedList = freeMemory(pLinkedList);
            }
            pLinkedList = readFile(pLinkedList);
            iIsread = 1; // merkataan että tiedosto on kertaaleen luettu
        }
        else if (iMenu == 2)
        {   
            if (iIsAnalysided == 1){ // Jos tiedot on jo analysoitu, niin tyhjennetään tietue uutta tietoa varten
                free(pAnalysis);
                for (int i = 0; i != 10; i++){
                    AmountWordClass[i].iAmount = 0;
                }
            }
            if (iIsread == 1){
                pAnalysis = analysisOfInformation(pLinkedList, pAnalysis);
                pAmountWordClass = wordperclass(pLinkedList, pAmountWordClass);
                iIsAnalysided = 1; // merkataan että tiedot on kertaaleen analysoitu
            }
            else{
                printf("Ei analysoitavaa, lue tiedosto ennen analyysiä.\n");
            }
            
        }
        else if (iMenu == 3)
        {
            if (iIsAnalysided == 1){
                informationRoute(pAnalysis, AmountWordClass);
            }
            else{
                printf("Ei kirjoitettavia tietoja, analysoi tiedot ennen tallennusta.\n");
            }      
        }
        else if (iMenu == 0)
        {
            printf("Lopetetaan.\n");
        }
        else{
            printf("Tuntematon valinta, yritä uudestaan.\n");
        }
        printf("\n");
    } while(iMenu != 0);
    

    
    if (iIsread == 1){ // Linkitetty listassa on tyhjennettäviä tietoja vain jos tiedostoa on luettu siihen. (ohjelma kaatuu tyhjästä tiedostosta.)
        pLinkedList = freeMemory(pLinkedList);
    }
    free(pAnalysis);
    pAnalysis = NULL;
    printf("Kiitos ohjelman käytöstä.\n");
    return(0);
}

