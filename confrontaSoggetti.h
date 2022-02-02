//
// Created by david on 31/05/2021.
//

/**
 * Libreria che si occupa del confronto dei soggetti
 */

#ifndef PROGETTO_FINALE_CONFRONTASOGGETTI_H
#define PROGETTO_FINALE_CONFRONTASOGGETTI_H

#include "menuUtente.h"

/**
 * Funzioni di confronto
 */

void confronto(Schedati *schedato1, Schedati *schedato2);
void confrontoTra2(Schedati *schedato1, Schedati *schedato2);


/**
 * Funzione di Input/Output
 */


void stampaConfronto(int percentuale);
int confrontaRecord(RecordSoggetto *soggetto1, RecordSoggetto *soggetto2,int nElementi);

/**
 * Funzioni di calcolo
 */

int contoCorrispondenze(RecordSoggetto *soggetto1, RecordSoggetto *soggetto2,int id1,int id2);
int calcoloPercentuale(RecordSoggetto *soggetto1, RecordSoggetto *soggetto2,int id1,int id2, int contatore,int nElementi);


#endif //PROGETTO_FINALE_CONFRONTASOGGETTI_H
