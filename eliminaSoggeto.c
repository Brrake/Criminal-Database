//
// Created by david on 04/06/2021.
//

#include "eliminaSoggeto.h"

/**
 * Funzione che si occupa di chiedere l'id del soggetto che si vuole eliminare
 * @param schedati Scheda da cui eliminare il soggetto
 */

void cancellaSoggetto(Schedati *schedati) {
    int id;

    printf("\nInserire l\'id del soggetto che si desidera cancellare:\n");
    printf("ID: ");
    scanf("%d",&id);

    azioneElimina(schedati,id);
}

/**
 * Funzione che si occupa di cancellare completamente, se esiste,  il soggetto indicato
 * @param schedati Scheda da cui eliminare il soggetto
 * @param id Id del soggetto da eliminare
 */

void azioneElimina(Schedati *schedati, int id){


    if(schedati->nSchedati >=1) {
        eliminaCriminale(schedati->schedato, id - 1, schedati->nSchedati);
        rimuoviSoggettoDaIndice(schedati, id);
        rimuoviSoggettoInCoda(schedati);
    }else{
        printf("\nCrea un contatto prima di eliminarlo!\n");
    }

}

/**
 * Funzione che si occupa di rimuovere il soggetto dal suo determinato indice
 * @param schedati Scheda da cui eliminare il soggetto
 * @param id Id del soggetto da eliminare
 */

void rimuoviSoggettoDaIndice(Schedati *schedati,int id){
    int i;
    for(i=id-1; i<(schedati->nSchedati-1); i++){
        schedati->schedato[i] = schedati->schedato[i+1];
    }

}

/**
 * Funzione che si occupa di rimuovere il soggetto con i dati azzerati dalla coda del vettore
 * @param schedati Scheda da cui rimuovere il soggetto
 */

void rimuoviSoggettoInCoda(Schedati *schedati){

    if(schedati->schedato != NULL) {
        schedati->nSchedati--;
        schedati->schedato = (RecordSoggetto *) realloc(schedati->schedato, schedati->nSchedati * sizeof(RecordSoggetto));
    }
}

/**
 * Funzione che si occupa di azzerare i cambi di un soggetto indicato tramite id
 * @param soggetto Soggetto da eliminare
 * @param id Id del soggetto da eliminare
 * @param nElementi Elem
 * @return
 */

RecordSoggetto *eliminaCriminale(RecordSoggetto *soggetto, int id, int nElementi){

    if(id <= nElementi) {
        if (esisteSoggetto(&soggetto[id]) == true) {
            soggetto = &soggetto[id];

            strcpy(soggetto->nomeSoggetto, "");
            strcpy(soggetto->cognomeSoggetto, "");
            soggetto->altezzaSoggetto = 0;
            soggetto->pesoSoggetto = 0;
            strcpy(soggetto->coloreOcchi, "");
            strcpy(soggetto->coloreCapelli, "");
            soggetto->lunghezzaCapelli = (TipoCapelli) NULL;
            soggetto->barba = NULL;
            soggetto->cicatrici = NULL;
            strcpy(soggetto->chiaveImpronta, "");
            strcpy(soggetto->residenzaSoggetto, "");
            soggetto->ultimaPosizione.ultimaLatitudine = 0;
            soggetto->ultimaPosizione.ultimaLongitudine = 0;
            soggetto->statoSoggetto = (StatoSoggetto) NULL;
        }
        printf("\nRimozione del soggetto %d avvenuta con successo!\n", id+1);

    }else
        printf("\nInserisci un id valido.\n");


    return soggetto;


}