//
// Created by david on 26/05/2021.
//


/**
 * Libreria che si occupa dei controlli
 */

#ifndef PROGETTO_FINALE_CONTROLLOACQUISIZIONI_H
#define PROGETTO_FINALE_CONTROLLOACQUISIZIONI_H

#include "acquisizioneSoggetto.h"
#include "menuUtente.h"

/**
 * Funzioni di controllo del corretto inserimento dei valori da parte dell'utente
 */

_Bool inserimentoNomeErrato(char *valore);
_Bool inserimentoAltezzaErrato(int *valore);
_Bool inserimentoPesoErrato(float *valore);
_Bool inserimentoColoreErrato(char *valore);
_Bool inserimentoLunghezzaErrato(RecordSoggetto *soggetto);
_Bool inserimentoSceltaErrato(char scelta);
_Bool inserimentoChiaveErrato(char *valore);
_Bool inserimentoResidenzaErrato(char *valore);
void acquisisciSegniParticolari(_Bool *valore, char scelta);
_Bool inserimentoLatitudineErrata(double *valore);
_Bool inserimentoLongitudineErrata(double *valore);
_Bool inserimentoStatoErrato(RecordSoggetto *soggetto);
_Bool controlloInserimentoConfronto(RecordSoggetto *soggetto1, RecordSoggetto *soggetto2,int nElementi,int id1,int id2);
_Bool esisteSoggetto(RecordSoggetto *soggetto);

/**
 * Funzioni di controllo del corretto inserimento delle risposte all'interno del menu
 */

void controlloSceltaStampa(int sceltaUno,int sceltaTutti,Schedati *schedati);
void controlloSceltaCarica(int sceltaCriptati,int sceltaDecriptati,Schedati *schedati);
void controlloSceltaSalva(int sceltaCriptati,int sceltaDecriptati,Schedati *schedati);
_Bool controlloSceltaConfronto(Schedati *schedato1,Schedati *schedato2,int sceltaConfronto);



#endif //PROGETTO_FINALE_CONTROLLOACQUISIZIONI_H
