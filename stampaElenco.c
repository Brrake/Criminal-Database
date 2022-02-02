//
// Created by david on 30/05/2021.
//

#include "stampaElenco.h"


/**
 * Procedura che richiede se si desidera ordinare i criminali in ordine alfabetico
 * @param schedati Scheda da ordinare
 */

void richiestaOrdinamento(Schedati *schedati){
    _Bool flagInserimentoErrato;
    char sceltaOrdinamento;

    do {
        flagInserimentoErrato = false;
        printf("\nVuoi ordinare i criminali in ordine alfabetico?\n");
        printf("[S]i/[N]o\n");
        printf("Scelta:");
        scanf("%c", &sceltaOrdinamento);
        svuotaBuffer();
        flagInserimentoErrato = inserimentoSceltaErrato(sceltaOrdinamento);
        if(sceltaOrdinamento == CHAR_SI || sceltaOrdinamento == CHAR_MIN_S)
            ordinaAlfabeticamente(schedati->schedato,schedati->nSchedati);

    } while (flagInserimentoErrato);



}

/**
 * Procedura che permette di scegliere in che modo si vuole stampare
 * @param schedati
 */

void stampa(Schedati *schedati){
    char sceltaStampa[SCELTA_STAMPA + 1];
    char tutti[SCELTA_STAMPA + 1] = {"Tutti"};
    char uno[SCELTA_STAMPA + 1] = ("Uno");
    int sceltaTutti;
    int sceltaUno;
    _Bool flagInserimentoErrato;

    do {
        flagInserimentoErrato = false;
        printf("\nVuoi stampare tutti o solo un soggetto?\n");
        printf("[Tutti]/[Uno]\n");
        printf("Scelta:");
        scanf("%s", sceltaStampa);
        flagInserimentoErrato = inserimentoNomeErrato(sceltaStampa);
        svuotaBuffer();

        sceltaTutti = strcmp(sceltaStampa,tutti);
        sceltaUno = strcmp(sceltaStampa,uno);

        controlloSceltaStampa(sceltaUno,sceltaTutti,schedati);

    }while(flagInserimentoErrato || (sceltaTutti != 0 && sceltaUno != 0));

    if(sceltaTutti == 0 && schedati->nSchedati >= 2) { // Se viene scelto di stampare l' elenco e ci sono 2 o più schedati richiedi l'ordinamento
        richiestaOrdinamento(schedati);
    }

}

/**
 * Procedura che si occupa di ordinare alfabeticamente i soggetti in lista tramite il metodo Bubble Sort
 * @param soggetto Soggetti da ordinare
 * @param nElementi Numero di schedati
 */

void ordinaAlfabeticamente(RecordSoggetto *soggetto, int nElementi) {

    int i, j;
    char deposito[DIM_NOME_COGNOME];// Variabile di supporto

//Bubble Sort

    for (i = 0; i < nElementi - 1; i++) {
        for(j=0;j<nElementi-i-1;j++) {
            if (strcmp(soggetto[j].cognomeSoggetto, soggetto[j + 1].cognomeSoggetto) > 0) { // Se il confronto è maggiore di zero
                strcpy(deposito, soggetto[j].cognomeSoggetto); // Copia il contenuto del cognome in una variabile di supporto
                strcpy(soggetto[j].cognomeSoggetto, soggetto[j + 1].cognomeSoggetto); // Copia il contenuto del cognome da spostare in quello precedente
                strcpy(soggetto[j + 1].cognomeSoggetto, deposito); // Copia il contenuto della variabile di supporto nel soggetto successivo
            }
            if (strcmp(soggetto[j].nomeSoggetto, soggetto[j + 1].nomeSoggetto) > 0) { // Se il confronto è maggiore di zero
                strcpy(deposito, soggetto[j].nomeSoggetto); // Copia il contenuto del cognome in una variabile di supporto
                strcpy(soggetto[j].nomeSoggetto, soggetto[j + 1].nomeSoggetto);  // Copia il contenuto del cognome da spostare in quello precedente
                strcpy(soggetto[j + 1].nomeSoggetto, deposito); // Copia il contenuto della variabile di supporto nel soggetto successivo
            }
        }
    }





    for(i=0; i<nElementi; i++){
        stampaSoggetto(soggetto,i);
    }


}

/**
 * Procedura che acquisisce l' id del soggetto da stampare e stampa se l' inserimento è corretto
 * @param schedato Scheda da cui prendere il soggetto
 */

void stampaRecord(Schedati *schedato){
    int idScelto;
    _Bool flagInserimentoCorretto;


    flagInserimentoCorretto = true;
    printf("\nInserisci l' id del soggetto:");
    scanf("%d", &idScelto);
    flagInserimentoCorretto = controlloInserimentoId(schedato, idScelto); // Verifica inserimento corretto

    if(flagInserimentoCorretto == true)
       stampaSoggetto(schedato->schedato,idScelto - 1);


}

/**
 * Funzione per il controllo dell' id inserito
 * @param schedati Schedato da controllare
 * @param idScelto Id inserito dall' utente
 * @return True se esiste un soggetto a quell' id
 */

_Bool controlloInserimentoId(Schedati *schedati,const int idScelto){
    _Bool soggettoCancellato;

    if(idScelto > 0 && idScelto <= schedati->nSchedati) {

        soggettoCancellato = true;
        soggettoCancellato = soggettoCancellato && strcmp(schedati->schedato[idScelto].nomeSoggetto, "") == 0;
        soggettoCancellato = soggettoCancellato && strcmp(schedati->schedato[idScelto].cognomeSoggetto, "") == 0;
        return !soggettoCancellato;
    }
    if(idScelto < 0 || idScelto > schedati->nSchedati){
        printf("\nNon esiste nessun soggetto con l\'id inserito.\n");
    }
    return false;
}

/**
 * Procedura per stampare l' elenco di tutti i criminali
 * @param soggetto
 * @param nElementi
 */

void stampaElencoCriminali(RecordSoggetto *soggetto, int nElementi){
    int i;
    _Bool stampato = false;



    for(i=0;i<nElementi;i++) { // Scorri il vettore di nElementi e controlla se esiste almeno 1 contatto
        stampato = esisteSoggetto(&soggetto[i]);
    }

    if(stampato){ // Se esiste scorri il vettore di nElementi e stampa ogni contatto
        for(i=0;i<nElementi;i++){
            stampaSoggetto(soggetto,i);
        }

    }else{ // Altrimenti
        printf("\nNon esiste nessun contatto.");
        printf("\n");
    }

}

/**
 * Procedura che stampa un soggetto in base al suo id
 * @param soggetto Soggetto da stampare
 * @param id Id del soggetto da stampare
 */

void stampaSoggetto(RecordSoggetto *soggetto, int id){
    printf("\n%d) %s %s\n\tAltezza: %dcm\n\tPeso: %.2fkg\n\tColore Occhi: %s\n\tColore capelli: %s"
           "\t\n",id+1,
           soggetto[id].cognomeSoggetto ,soggetto[id].nomeSoggetto,soggetto[id].altezzaSoggetto,soggetto[id].pesoSoggetto,soggetto[id].coloreOcchi,
           soggetto[id].coloreCapelli);
    stampaCapelliBarbaCicatrici(soggetto,id);
    printf("\tChiave Impronta: %s\n\tResidenza: %s"
           "\n\tUltima latitudine: %lf\n\tUltima Longitudine: %lf\n",soggetto[id].chiaveImpronta,
           soggetto[id].residenzaSoggetto,soggetto[id].ultimaPosizione.ultimaLatitudine,
           soggetto[id].ultimaPosizione.ultimaLongitudine);
    stampaStato(soggetto,id);

}

/**
 * Procedura che stampa a parole i valori delle enumerazioni e booleane
 * @param soggetto Soggetto da stampare
 * @param id Id del soggetto da stampare
 */

void stampaCapelliBarbaCicatrici(RecordSoggetto *soggetto, int id){

    switch (soggetto[id].lunghezzaCapelli) {

        case CORTI:
            printf("\tLunghezza capelli : CORTI\n");
            break;
        case MEDI:
            printf("\tLunghezza capelli : MEDI\n");
            break;
        case LUNGHI:
            printf("\tLunghezza capelli : LUNGHI\n");
            break;
        case ALTRO:
            printf("\tLunghezza capelli : ALTRO\n");
            break;
    }

    if(soggetto->barba == true)
        printf("\tBarba : TRUE\n");
    else
        printf("\tBarba : FALSE\n");
    if(soggetto->cicatrici == true)
        printf("\tCicatrici : TRUE\n");
    else
        printf("\tCicatrici : FALSE\n");
}

/**
 * Procedura che stampa a parole i valori dell' enumerazione riguardante lo stato del soggetto
 * @param soggetto Soggetto da stampare
 * @param id Id del soggetto da stampare
 */

void stampaStato(RecordSoggetto *soggetto, int id){

    switch (soggetto[id].statoSoggetto) {

        case LIBERO:
            printf("\tStato : LIBERO\n");
            break;
        case RICERCATO:
            printf("\tStato : RICERCATO\n");
            break;
        case EVASO:
            printf("\tStato : EVASO\n");
            break;
        case INARRESTO:
            printf("\tStato : IN ARRESTO\n");
            break;
    }

}