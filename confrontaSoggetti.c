//
// Created by david on 31/05/2021.
//

#include "confrontaSoggetti.h"

/**
 * Procedura che si occupa di fornire all' utente una scelta
 * tra i due tipi di confronto (Confronto tra 2 soggetti e 1 rispetto agli altri)
 * @param schedato1
 * @param schedato2
 */

void confronto(Schedati *schedato1, Schedati *schedato2){
    int sceltaConfronto;
    _Bool flagInserimentoErrato;



    do {
        flagInserimentoErrato = false;
        printf("\nVuoi confrontare 2) elementi o 1) elemento rispetto agli altri?\n");
        printf("Scelta:");
        scanf("%d", &sceltaConfronto);

        flagInserimentoErrato = controlloSceltaConfronto(schedato1,schedato2,sceltaConfronto);

    }while(flagInserimentoErrato);





}

/**
 * Procedura che confronta due soggetti
 * @param schedato1 Primo soggetto da confrontare
 * @param schedato2 Secondo soggetto da confrontare
 */

void confrontoTra2(Schedati *schedato1, Schedati *schedato2){
    int percentuale;

    percentuale = confrontaRecord(schedato1->schedato,schedato2->schedato,schedato1->nSchedati);
    stampaConfronto(percentuale);

}

/**
 * Procedura di controllo per la stampa della percentuale
 * @param percentuale Valore intero di percentuale
 */

void stampaConfronto(int percentuale){

    if(percentuale == -1){ // Se la percentuale == -1
        printf("\nNon esistono abbastanza soggetti.");
        printf("\n");
    }
    else // Altrimenti esegui la stampa
        printf("\nI record selezionati hanno un' affinita' del %d%c\n",percentuale,'%');

}

/**
 * Funzione he si occupa di richiedere quali soggetti confrontare tramite id
 * @param soggetto1 Primo soggetto da confrontare
 * @param soggetto2 Secondo soggetto da confrontare
 * @param nElementi Numero di schedati
 * @return Percentuale di confronto
 */

int confrontaRecord(RecordSoggetto *soggetto1, RecordSoggetto *soggetto2,int nElementi) {

    int contatore = 0;
    int percentuale;

    int id1 = 0; // Id del primo soggetto, scelto dall' utente, da confrontare
    int id2 = 0; // Id del secondo soggetto, scelto dall' utente, da confrontare

    _Bool flagErroreInserimento; // Variabile booleana di controllo

    do {
        flagErroreInserimento=false;
        printf("\nQuali record vuoi confrontare?\n");
        printf("Record 1: ");
        scanf("%d", &id1);
        printf("\nRecord 2: ");
        scanf("%d", &id2);

        flagErroreInserimento = controlloInserimentoConfronto(soggetto1,soggetto2,nElementi,id1,id2); // Controllo dell' inserimento

    } while (flagErroreInserimento == true);

    percentuale = calcoloPercentuale(soggetto1,soggetto2,id1,id2,contatore,nElementi); // percentuale è uguale a un intero che rappresenta il valore percentuale

    return percentuale;

}


/**
 * Funzione che permette di calcolare la percentuale di affinità tra 2 soggetti
 * @param soggetto1 Primo soggetto da confrontare
 * @param soggetto2 Secondo soggetto da confrontare
 * @param id1 Id del primo soggetto
 * @param id2 Id del secondo soggetto
 * @param contatore Numero di valori combacianti
 * @param nElementi Numero di soggetti schedati
 * @return Intero percentuale
 */

int calcoloPercentuale(RecordSoggetto *soggetto1, RecordSoggetto *soggetto2,int id1,int id2, int contatore,int nElementi){
    int percentuale;

    if(nElementi>1) { // Se esiste più di 1 schedato esegui i calcoli
        contatore = contoCorrispondenze(soggetto1, soggetto2, id1, id2);
        percentuale = (contatore * 100) / 13;
    }else // Altrimenti restituisci -1
        percentuale = -1;

    return percentuale;

}

/**
 * Funzione la cui funzionalità è quella di contare quanti dati di soggetto 1 corrispondano a soggetto 2
 * @param soggetto1 Primo soggetto da confrontare
 * @param soggetto2 Secondo soggetto da confrontare
 * @param id1 Id del primo soggetto
 * @param id2 Id del secondo soggetto
 * @return Numero di dati combacianti
 */

int contoCorrispondenze(RecordSoggetto *soggetto1, RecordSoggetto *soggetto2,int id1,int id2){
    int nome;
    int cognome;
    int coloreOcchi;
    int coloreCapelli;
    int chiave;
    int residenza;
    int contatore = 0;


    /**
     * Confronto tra le stringhe che restituisce un valore intero pari a 0 se il valore di
     * soggetto 1 corrisponde con il valore di soggetto 2
     */


    nome = strcmp(soggetto1[id1-1].nomeSoggetto,soggetto2[id2-1].nomeSoggetto);
    cognome = strcmp(soggetto1[id1-1].cognomeSoggetto,soggetto2[id2-1].cognomeSoggetto);
    coloreOcchi = strcmp(soggetto1[id1-1].coloreOcchi,soggetto2[id2-1].coloreOcchi);
    coloreCapelli = strcmp(soggetto1[id1-1].coloreCapelli,soggetto2[id2-1].coloreCapelli);
    chiave = strcmp(soggetto1[id1-1].chiaveImpronta,soggetto2[id2-1].chiaveImpronta);
    residenza = strcmp(soggetto1[id1-1].residenzaSoggetto,soggetto2[id2-1].residenzaSoggetto);

    /**
     * Se il soggetto 1 è uguale al soggetto 2 aggiungi 1 al contatore
     */

    if(nome == 0)
        contatore++;
    if(cognome == 0)
        contatore++;
    if((soggetto1[id1-1].altezzaSoggetto) == (soggetto2[id2-1].altezzaSoggetto))
        contatore++;
    if(soggetto1[id1-1].pesoSoggetto == soggetto2[id2-1].pesoSoggetto)
        contatore++;
    if(coloreOcchi == 0)
        contatore++;
    if(coloreCapelli == 0)
        contatore++;
    if(soggetto1[id1-1].lunghezzaCapelli == soggetto2[id2-1].lunghezzaCapelli)
        contatore++;
    if(soggetto1[id1-1].barba == soggetto2[id2-1].barba)
        contatore++;
    if(soggetto1[id1-1].cicatrici == soggetto2[id2-1].cicatrici)
        contatore++;
    if(chiave == 0)
        contatore++;
    if(residenza == 0)
        contatore++;
    if((soggetto1[id1-1].ultimaPosizione.ultimaLatitudine == soggetto2[id2-1].ultimaPosizione.ultimaLatitudine) &&
        soggetto1[id1-1].ultimaPosizione.ultimaLongitudine == soggetto2[id2-1].ultimaPosizione.ultimaLongitudine)
        contatore++;
    if(soggetto1[id1-1].statoSoggetto == soggetto1[id2-1].statoSoggetto)
        contatore++;



    return contatore;
}

