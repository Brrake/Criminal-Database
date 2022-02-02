//
// Created by david on 04/06/2021.
//
/**
 * Libreria dedicata all' eliminazione di un soggetto
 */

#ifndef PROGETTO_FINALE_ELIMINASOGGETO_H
#define PROGETTO_FINALE_ELIMINASOGGETO_H
#include "menuUtente.h"


/**
 * Funzione di Input
 */

void cancellaSoggetto(Schedati *schedati);

/**
 * Funzioni di eliminazione
 */

RecordSoggetto *eliminaCriminale(RecordSoggetto *soggetto, int id, int nElementi);
void azioneElimina(Schedati *schedati, int id);
void rimuoviSoggettoInCoda(Schedati *schedati);
void rimuoviSoggettoDaIndice(Schedati *schedati,int id);

#endif //PROGETTO_FINALE_ELIMINASOGGETO_H
