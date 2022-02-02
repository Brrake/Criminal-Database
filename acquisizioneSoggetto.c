//
// Created by david on 26/05/2021.
//

#include "acquisizioneSoggetto.h"

/**
 * Procedura che Acquisisce il mio soggetto e lo aggiunge in lista
 * @param schedato Scheda in cui aggiungere il mio soggetto
 */
void inserisciRecord(Schedati *schedato){
    RecordSoggetto soggetto;

    soggetto = acquisisciSoggetto();
    aggiungiElemento(schedato,&soggetto);

}

/**
 * Procedura di inizializzazione della mia lista schedati
 * @param schedato Inizializzo la mia lista schedati
 */
void inizializzaVettoreDinamico (Schedati *schedato){
    schedato->schedato = NULL;
    schedato->nSchedati = 0;

}

/**
 * Procedura che aggiunge un elemento tra i schedati
 * @param schedato Scheda in cui aggiungere il soggetto
 * @param soggetto Soggetto da aggiungere
 */

void aggiungiElemento(Schedati *schedato, RecordSoggetto *soggetto){
    schedato->nSchedati++; // Aumenta di 1 il numero di schedati
    printf("\nIl soggetto inserito e' il numero %d.\n",schedato->nSchedati);

    if(schedato->schedato == NULL) // Se il puntatore è == NULL allora crea uno spazio dedicato alla sua dimensione nell' heap
        schedato->schedato = (RecordSoggetto *) malloc(schedato->nSchedati * sizeof(RecordSoggetto));
    else // Altrimenti rialloca lo spazio
        schedato->schedato = (RecordSoggetto *) realloc(schedato->schedato,schedato->nSchedati * sizeof(RecordSoggetto));

    if(schedato->schedato == NULL) // Se nonostante abbia creato o riallocato uno spazio il puntatore continua ad essere == NULL
        exit(-1); // Esci con il codice -1

    schedato->schedato[schedato->nSchedati-1] = *soggetto; // Altrimenti assegna il mio puntatore con dimensione nSchedati - 1 al soggetto appena creato
    // nSChedati - 1 perchè il mio vettore parte da 0
}

/**
 * Funzione che acquisisce in input tutti i dati di un soggetto
 * @return Soggetto acquisito
 */

RecordSoggetto acquisisciSoggetto(){
    RecordSoggetto soggetto;
    _Bool flagErroreInserimento; // Variabile booleana per il controllo dell' inserimento
    char sceltaBarba; // Variabile in cui viene memorizzata la risposta [S]i/[N]o per la presenza di barba nel soggetto
    char sceltaCicatrici; // Variabile in cui viene memorizzata la risposta [S]i/[N]o per la presenza di cicatrici nel soggetto

    do {

        //Acquisizione nome
        flagErroreInserimento = false;
        printf("Nome (max %d caratteri): ", DIM_NOME_COGNOME);
        flagErroreInserimento = inserimentoNomeErrato(soggetto.nomeSoggetto); // Controllo dell' inserimento
        svuotaBuffer(); // Gestione caratteri ancora presenti nel buffer

    }while(flagErroreInserimento); // Chiedi l' inserimento finchè non vengono inseriti i parametri richiesti

    do {
        // Acquisizione cognome
        flagErroreInserimento = false;
        printf("\nCognome (max %d caratteri): ", DIM_NOME_COGNOME);
        flagErroreInserimento = inserimentoNomeErrato(soggetto.cognomeSoggetto);// Controllo dell' inserimento
        svuotaBuffer();// Gestione caratteri ancora presenti nel buffer

    }while(flagErroreInserimento);// Chiedi l' inserimento finchè non vengono inseriti i parametri richiesti

    do {

        //Acquisizione altezza
        flagErroreInserimento = false;
        printf("\nAltezza in cm: ");
        flagErroreInserimento = inserimentoAltezzaErrato(&soggetto.altezzaSoggetto); // Controllo dell' inserimento
        svuotaBuffer();// Gestione caratteri ancora presenti nel buffer

    }while(flagErroreInserimento); // Chiedi l' inserimento finchè non vengono inseriti i parametri richiesti

    do {

        //Acquisizione peso
        flagErroreInserimento = false;
        printf("\nPeso in kg: ");
        flagErroreInserimento = inserimentoPesoErrato(&soggetto.pesoSoggetto); // Controllo dell' inserimento
        svuotaBuffer();// Gestione caratteri ancora presenti nel buffer

    }while(flagErroreInserimento); // Chiedi l' inserimento finchè non vengono inseriti i parametri richiesti

    do {

        //Acquisizione colore occhi
        flagErroreInserimento = false;
        printf("\nColore Occhi:# ");
        flagErroreInserimento = inserimentoColoreErrato(soggetto.coloreOcchi); // Controllo dell' inserimento
        svuotaBuffer();// Gestione caratteri ancora presenti nel buffer

    }while(flagErroreInserimento);// Chiedi l' inserimento finchè non vengono inseriti i parametri richiesti

    do {

        //Acquisizione colore capelli
        flagErroreInserimento = false;
        printf("\nColore Capelli:# ");
        flagErroreInserimento = inserimentoColoreErrato(soggetto.coloreCapelli);// Controllo dell' inserimento
        svuotaBuffer();// Gestione caratteri ancora presenti nel buffer

    }while(flagErroreInserimento);// Chiedi l' inserimento finchè non vengono inseriti i parametri richiesti

    do {

        //Acquisizione Lunghezza capelli
        flagErroreInserimento = false;
        printf("\nLunghezza capelli: ");
        printf("\n1) CORTI - 2) MEDI - 3) LUNGHI - 4) ALTRO");
        printf("\nScelta: ");
        scanf("%d", &soggetto.lunghezzaCapelli);
        flagErroreInserimento = inserimentoLunghezzaErrato(&soggetto);// Controllo dell' inserimento
        svuotaBuffer();// Gestione caratteri ancora presenti nel buffer

    }while(flagErroreInserimento);// Chiedi l' inserimento finchè non vengono inseriti i parametri richiesti

    do {

        //Acquisizione Barba
        flagErroreInserimento = false;
        printf("\nBarba ([S]i/[N]o): ");
        scanf("%c", &sceltaBarba);
        flagErroreInserimento = inserimentoSceltaErrato(sceltaBarba);// Controllo dell' inserimento [S]i/[N]o
        svuotaBuffer();// Gestione caratteri ancora presenti nel buffer
        acquisisciSegniParticolari(&soggetto.barba,sceltaBarba); // Assegnazione di true o false in base a sceltaBarba

    }while(flagErroreInserimento);// Chiedi l' inserimento finchè non vengono inseriti i parametri richiesti

    do {

        //Acquisizione Cicatrici
        flagErroreInserimento = false;
        printf("\nCicatrici ([S]i/[N]o): ");
        scanf("%c", &sceltaCicatrici);
        flagErroreInserimento = inserimentoSceltaErrato(sceltaCicatrici);// Controllo dell' inserimento [S]i/[N]o
        svuotaBuffer();// Gestione caratteri ancora presenti nel buffer
        acquisisciSegniParticolari(&soggetto.cicatrici,sceltaCicatrici);// Assegnazione di true o false in base a sceltaCicatrici

    }while(flagErroreInserimento);// Chiedi l' inserimento finchè non vengono inseriti i parametri richiesti

    do {

        //Acquisizione Chiave impronta digitale
        flagErroreInserimento = false;
        printf("\nChiave impronta digitale: ");
        flagErroreInserimento = inserimentoChiaveErrato(soggetto.chiaveImpronta);// Controllo dell' inserimento
        svuotaBuffer();// Gestione caratteri ancora presenti nel buffer

    }while(flagErroreInserimento);// Chiedi l' inserimento finchè non vengono inseriti i parametri richiesti

    do{

        //Acquisizione Residenza
        flagErroreInserimento = false;
        printf("\nResidenza: Via , Citta' , Provincia\n");
        flagErroreInserimento = inserimentoResidenzaErrato(soggetto.residenzaSoggetto);// Controllo dell' inserimento
        svuotaBuffer();// Gestione caratteri ancora presenti nel buffer

    }while(flagErroreInserimento);// Chiedi l' inserimento finchè non vengono inseriti i parametri richiesti

    printf("\nInserire le coordinate dell\'ultima posizione GPS: ");

    do {
        //Acquisizione Ultima posizione GPS
        flagErroreInserimento = false;
        printf("\nInserire l\'ultima latitudine conosciuta: ");
        flagErroreInserimento = inserimentoLatitudineErrata(&soggetto.ultimaPosizione.ultimaLatitudine);// Controllo dell' inserimento
        svuotaBuffer();// Gestione caratteri ancora presenti nel buffer

    }while(flagErroreInserimento);// Chiedi l' inserimento finchè non vengono inseriti i parametri richiesti

    do{
        flagErroreInserimento = false;
        printf("\nInserire l\'ultima longitudine conosciuta: ");
        flagErroreInserimento = inserimentoLongitudineErrata(&soggetto.ultimaPosizione.ultimaLongitudine);// Controllo dell' inserimento
        svuotaBuffer();// Gestione caratteri ancora presenti nel buffer

    }while(flagErroreInserimento);// Chiedi l' inserimento finchè non vengono inseriti i parametri richiesti

    do{
        //Acquisizione Stato
        flagErroreInserimento = false;
        printf("\nStato: ");
        printf("\n01) Libero - 02) Ricercato - 03) In Arresto - 04) Evaso");
        printf("\nScelta: ");
        scanf("%d", &soggetto.statoSoggetto);
        flagErroreInserimento = inserimentoStatoErrato(&soggetto);// Controllo dell' inserimento
        svuotaBuffer();// Gestione caratteri ancora presenti nel buffer

    }while(flagErroreInserimento);// Chiedi l' inserimento finchè non vengono inseriti i parametri richiesti



    printf("\n"); // Andata a capo

    return soggetto;
}

/**
 * Svuota il buffer per evitare successivi errori di acquisizione di stringhe o char
 * @return False se nel buffer c'è stato almeno un carattere diverso da '\n'
 */
_Bool svuotaBuffer() {
    _Bool inputCorretto = true;


    //Scorri il buffer finché non si ha un carattere di andata a capo
    while (getchar() != '\n') {
        inputCorretto = false; //Se nel buffer c'è stato almeno un carattere diverso da '\n'
    }
    return inputCorretto;

}

