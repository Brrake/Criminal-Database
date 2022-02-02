//
// Created by david on 24/05/2021.
//

#include "menuUtente.h"


/**
 * Procedura per l' acquisizione della scelta utente
 */

void menuUtente() {
    SceltaMenu sceltaUtente;
    Schedati schedati;
    RecordSoggetto soggetto;
    srand(time(NULL));


    inizializzaVettoreDinamico(&schedati);


    do {
        printf("\n####################\n");
        printf("#       MENU       #\n");
        printf("####################\n");
        printf("#1) Inserisci nuovo Soggetto \n"
               "#2) Genera casualmente nuovo Soggetto \n"
               "#3) Stampa Soggetti memorizzati \n"
               "#4) Confronta Soggetti \n"
               "#5) Carica Dati \n"
               "#6) Salva Dati\n"
               "#7) Elimina Soggetto\n"
               "#8) Esci\n");
        printf("Scelta:");
        scanf("%d", &sceltaUtente);
        svuotaBuffer();
        sceltaAzione(&soggetto,&schedati,sceltaUtente);

    }while (sceltaUtente != ESCI);

}

/**
 * Procedura che coordina le azioni del menu
 * @param soggetto Struttura RecordSoggetto
 * @param schedati Struttura del Vettore Dinamico
 * @param sceltaUtente Scelta dell' utente sull' azione del menu
 */

void sceltaAzione(RecordSoggetto *soggetto, Schedati *schedati,const int sceltaUtente) {



            switch (sceltaUtente) {
                case INSERISCI:
                    printf("\n----- INSERISCI -----\n");
                    printf("\n");
                    inserisciRecord(schedati);
                    break;
                case GENERA:
                    printf("\n----- GENERA -----\n");
                    generaRecord(soggetto, schedati);
                    break;
                case STAMPA:
                    printf("\n----- STAMPA -----\n");
                    stampa(schedati);
                    break;
                case CONFRONTA:
                    printf("\n----- CONFRONTA -----\n");
                    confronto(schedati, schedati);
                    break;
                case CARICA:
                    printf("\n----- CARICA -----\n");
                    carica(schedati);
                    break;
                case SALVA:
                    printf("\n----- SALVA -----\n");
                    salva(schedati);
                    break;
                case ELIMINA:
                    printf("\n----- ELIMINA -----\n");
                    cancellaSoggetto(schedati);
                    break;
                case ESCI:
                    printf("\n----- ARRIVEDERCI -----\n");
                    break;

                default:
                    printf("\nInserire una scelta valida!\n");
                    break;

            }


}



