//
// Created by david on 04/06/2021.
//

/**
 * Libreria dedicata al salvataggio su un file binario
 */

#ifndef PROGETTO_FINALE_SALVAFILE_H
#define PROGETTO_FINALE_SALVAFILE_H
#include "menuUtente.h"


/**
 * Procedure di salvataggio
 */
void salva(Schedati *schedati);
void salvaDati(RecordSoggetto *soggetto, char *nomeFile, int nElementi);
void salvaDatiCriptati(RecordSoggetto *soggetto, char *nomeFile, int nElementi);

/**
 * Procedure di criptaggio
 */

void criptaDecriptaInfo(RecordSoggetto *soggetto,int nElementi);
void cripta(char *valore);


#endif //PROGETTO_FINALE_SALVAFILE_H
