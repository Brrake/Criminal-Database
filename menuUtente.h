//
// Created by david on 24/05/2021.
//

#ifndef PROGETTO_FINALE_MENUUTENTE_H
#define PROGETTO_FINALE_MENUUTENTE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

/**
 * Inclusione di tutte le librerie necessarie
 */

#include "strutture.h"
#include "controlloAcquisizioni.h"
#include "generazioneSoggettoCasuale.h"
#include "acquisizioneSoggetto.h"
#include "stampaElenco.h"
#include "confrontaSoggetti.h"
#include "caricaFile.h"
#include "salvaFile.h"
#include "eliminaSoggeto.h"

/**
 * Definizione enumerazione scelta utente
 */

typedef enum{INSERISCI = 1,GENERA,STAMPA,CONFRONTA,CARICA,SALVA,ELIMINA,ESCI}SceltaMenu; // Partenza da 1 per scelta stilistica

/**
 * Definizione del menu utente
 */

void menuUtente();

/**
 * Definizione azioni del menu
 */

void sceltaAzione(RecordSoggetto *soggetto, Schedati *schedati,const int sceltaUtente);



#endif //PROGETTO_FINALE_MENUUTENTE_H
