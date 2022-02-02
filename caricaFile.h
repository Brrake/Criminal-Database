//
// Created by david on 03/06/2021.
//

/**
 * Libreria che si occupa  del caricamento dei file
 */


#ifndef PROGETTO_FINALE_CARICAFILE_H
#define PROGETTO_FINALE_CARICAFILE_H
#include "menuUtente.h"

#define SCELTA_CARICA 10 // Dimensione risposta Riguardo a che tipo di file si vuole caricare

/**
 * Procedure per il caricamento del database
 */

void carica(Schedati *schedati);
void caricaDati(Schedati *schedato, char *nomefile);
void caricaDatiCriptati(Schedati *schedato, char *nomefile);




#endif //PROGETTO_FINALE_CARICAFILE_H
