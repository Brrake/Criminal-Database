//
// Created by david on 26/05/2021.
//
/**
 * Libreria dedicata alla generazione casuale di un soggetto
 */

#ifndef PROGETTO_FINALE_GENERAZIONESOGGETTOCASUALE_H
#define PROGETTO_FINALE_GENERAZIONESOGGETTOCASUALE_H

#include "menuUtente.h"

#define N_NOMI 12 // Nomi disponibili per la generazione
#define MIN 0 // Valore minimo di generazione relativo alla chiave impronta
#define MAX 2 // Valore massimo di generazione relativo alla chiave impronta
#define N_PAESI 11 // Paesi disponibili per la generazione
#define L_PAESI 25 // Lunghezza della stringa relativa ai paesi

/**
 * Funzioni che genera un soggetto casuale
 */

void generaRecord(RecordSoggetto *soggetto,Schedati *schedato);

/**
 * Funzioni di Input/Output
 * @return
 */

RecordSoggetto generaSoggetto();
void stampaBarba(RecordSoggetto *soggetto);
void stampaCicatrici(RecordSoggetto *soggetto);
/**
 * Funzioni di generazione da minimo a massimo
 */

int generaCasualeInt(int min,int max);
float generaCasualeFloat(int min, int max);
double generaCasualeDouble(double min,double max);
char generaChar(int min,int max);

/**
 * Procedure di generazione relative al soggetto
 */

void generaNome(RecordSoggetto *soggetto);
void generaCognome(RecordSoggetto *soggetto);
void generaAltezza(RecordSoggetto *soggetto);
void generaPeso(RecordSoggetto *soggetto);
void generaColore(char *valore);
void generaSegniParticolari(RecordSoggetto *soggetto);
void generaLunghezza(RecordSoggetto *soggetto);
void generaChiave(RecordSoggetto *soggetto);
void generaResidenza(RecordSoggetto *soggetto);
void generaPosizione(RecordSoggetto *soggetto);
void generaStato(RecordSoggetto *soggetto);

#endif //PROGETTO_FINALE_GENERAZIONESOGGETTOCASUALE_H
