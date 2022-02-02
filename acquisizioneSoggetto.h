//
// Created by david on 26/05/2021.
//

/**
 * Libreria dedicata all' acquisizione manuale del soggetto
 */

#ifndef PROGETTO_FINALE_ACQUISIZIONESOGGETTO_H
#define PROGETTO_FINALE_ACQUISIZIONESOGGETTO_H



#include "menuUtente.h"


/* Funzioni di Input del soggetto */

RecordSoggetto acquisisciSoggetto();

/* Funzioni di manipolazione della lista soggetti */

void inizializzaVettoreDinamico (Schedati *schedato);
void aggiungiElemento(Schedati *schedato, RecordSoggetto *soggetto);
void inserisciRecord(Schedati *schedato);

/* Funzioni di supporto */

_Bool svuotaBuffer();

#endif //PROGETTO_FINALE_ACQUISIZIONESOGGETTO_H
