//
// Created by david on 03/06/2021.
//

#include "caricaFile.h"

/**
 * Procedura che permette di scegliere che tipo di file caricare tra Criptato e Decriptato
 * @param schedati Scheda sulla quale salvare i dati
 */

void carica(Schedati *schedati){


    char sceltaCarica[SCELTA_CARICA + 1]; // Stringa in cui viene memorizzata la scelta dell' utente tra Criptato e Decriptato
    char decriptati[SCELTA_CARICA + 1] = {"Decriptato"}; // Stringa che contiene la scelta Decriptato
    char criptati[SCELTA_CARICA + 1] = ("Criptato"); // Stringa che contiene la scelta Criptato
    _Bool flagInserimentoErrato; // Variabile booleana di controllo
    int sceltaDecriptati; // Variabile intera in cui viene salvato il valore di ritorno del confronto tra sceltaCarica e decriptati
    int sceltaCriptati;// Variabile intera in cui viene salvato il valore di ritorno del confronto tra sceltaCarica e criptati

    do {
        flagInserimentoErrato = false;
        printf("\nChe tipo di database vuoi caricare?\n");
        printf("[Criptato]/[Decriptato]\n");
        printf("Scelta:");
        scanf("%s", sceltaCarica);
        flagInserimentoErrato = inserimentoNomeErrato(sceltaCarica); // Controllo inserimento
        svuotaBuffer(); // Gestione del buffer

        sceltaDecriptati = strcmp(sceltaCarica,decriptati); // Confronto tra le 2 stringhe
        sceltaCriptati = strcmp(sceltaCarica,criptati); // Confronto tra le 2 stringhe

        controlloSceltaCarica(sceltaCriptati,sceltaDecriptati,schedati); // Controllo di apertura procedure



    }while(flagInserimentoErrato || (sceltaCriptati != 0 && sceltaDecriptati != 0)); // Se l'inserimento è errato o la scelta dell'utente non corrisponde alle scelte
                                                                                    // disponibili, ripeti il ciclo finchè non viene scritta la parola corretta



}

/**
 * Procedura di caricamento dei dati da un file binario
 * @param schedato Scheda in cui caricare i soggetti
 * @param nomefile Nome del file da cui caricare i soggetti
 */

void caricaDati(Schedati *schedato, char *nomefile){
    FILE *fp = NULL; // Inizializzazione file

    int i;
    int nElementi = 0;

    fp = fopen (nomefile,"rb"); // Apertura del file in lettura binaria (rb)

    if(fp == NULL) { // Se il mio file è vuoto
        printf("\nERRORE!! Il file non esiste\n");
        exit(-1);

    }
    schedato->nSchedati = nElementi;
    fread(&schedato->nSchedati, sizeof(int), 1, fp); // Leggi una informazione di dimensione int e salvala in nSchedati


    schedato->schedato = (RecordSoggetto *) malloc(schedato->nSchedati * sizeof(RecordSoggetto));

    if(schedato->schedato == NULL)
        exit(-1);

    for(i=0;i<schedato->nSchedati;i++) {
        fread(&schedato->schedato[i], sizeof(RecordSoggetto), 1, fp);// Leggi 1 informazione, di dimensione RecordSoggetto, dal mio file finchè non finisce il ciclo e salvalo nel mio vettore dinamico
    }
    fclose(fp);

    printf("\nCaricamento di %d soggetti completato con successo!\n",schedato->nSchedati);
}


/**
 * Procedura di caricamento dei dati criptati da un file binario
 * @param schedato Scheda in cui caricare i soggetti
 * @param nomefile Nome del file da cui caricare i soggetti
 */

void caricaDatiCriptati(Schedati *schedato, char *nomefile){
    FILE *fp = NULL; // Inizializzazione file

    int i;

    fp = fopen (nomefile,"rb"); // Apertura del file in lettura binaria (rb)

    if(fp == NULL) { // Se il mio file è vuoto
        printf("\nERRORE!! Il file non esiste\n");
        exit(-1);

    }

    fread(&schedato->nSchedati, sizeof(int), 1, fp); // Leggi una informazione di dimensione int e salvala in nSchedati

    schedato->schedato = (RecordSoggetto *) malloc(schedato->nSchedati * sizeof(RecordSoggetto));

    if(schedato->schedato == NULL)
        exit(-1);

    for(i=0;i<schedato->nSchedati;i++) {
        fread(&schedato->schedato[i], sizeof(RecordSoggetto), 1, fp); // Leggi 1 informazione, di dimensione RecordSoggetto, dal mio file finchè non finisce il ciclo e salvalo nel mio vettore dinamico
    }

    criptaDecriptaInfo(schedato->schedato,schedato->nSchedati); // Decripta le info. prima di importarle nel programma
    fclose(fp); // Chiusura del file

    printf("\nCaricamento di %d soggetti completato con successo!\n",schedato->nSchedati);
}


