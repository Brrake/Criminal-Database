//
// Created by david on 30/05/2021.
//

/**
 * Libreria dedicata alla stampa e all' ordinamento dei criminali
 */

#ifndef PROGETTO_FINALE_STAMPAELENCO_H
#define PROGETTO_FINALE_STAMPAELENCO_H

#include "menuUtente.h"
#define SCELTA_STAMPA 5

void stampa(Schedati *schedati);
void richiestaOrdinamento(Schedati *schedati);
void stampaRecord(Schedati *schedato);

void stampaElencoCriminali(RecordSoggetto *soggetto, int nElementi);
void stampaSoggetto(RecordSoggetto *soggetto,int id);

_Bool controlloInserimentoId(Schedati *schedati,const int idScelto);
void ordinaAlfabeticamente(RecordSoggetto *soggetto, int nElementi);
void stampaCapelliBarbaCicatrici(RecordSoggetto *soggetto, int id);
void stampaStato(RecordSoggetto *soggetto, int id);

#endif //PROGETTO_FINALE_STAMPAELENCO_H
