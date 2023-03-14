# Makefile HT
#/*************************************************************************/
#/* CT60A2500 C-ohjelmoinnin perusteet
#* Tekijä: Konsta Jalkanen    
#* Opiskelijanumero: 000489689
#* Päivämäärä: 12/03/2023
#* Kurssin oppimateriaalien lisäksi työhön ovat vaikuttaneet seuraavat
#* lähteet ja henkilöt, ja se näkyy tehtävässä seuraavalla tavalla:
#* Tuomas Lättilä ja Tomi Vilpponen ovat huomauttaneet tyyliohjeiden noudattamisesta olevasta puutteesta. 
#* Aleksi natunen huomautti stdout olemassa olosta.
#* Mahdollisen vilppiselvityksen varalta vakuutan, että olen tehnyt itse
#* tämän tehtävän ja vain yllä mainitut henkilöt sekä lähteet ovat
#* vaikuttaneet siihen yllä mainituilla tavoilla.
#*/
#/*************************************************************************/
#/* Tehtävä Harjoitus työ, tiedoston nimi Makefile */
#/* eof */

HT: HTPerustaso.o HTPerusKirjasto.o
	gcc HTPerustaso.o HTPerusKirjasto.o -o HT
HTPerustaso.o: HTPerustaso.c HTPerusKirjasto.h
	gcc HTPerustaso.c -c -std=c99 -pedantic -Wall
HTPerusKirjasto.o: HTPerusKirjasto.c HTPerusKirjasto.h
	gcc HTPerusKirjasto.c -c -std=c99 -pedantic -Wall
          

