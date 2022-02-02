//
// Created by david on 26/05/2021.
//

#include "controlloAcquisizioni.h"


/**
 * Funzione che controlla il corretto inserimento del nome e del cognome
 * @param valore Valore inserito dall' utente
 * @return True se l' inserimento è errato
 */

_Bool inserimentoNomeErrato(char *valore){
    int i;

    scanf("%30[^\n]s", valore);

    for(i=0;i<DIM_NOME_COGNOME && valore[i] != '\0';i++) {
        if ((valore[i] < 'A' && valore[i] > ' ') ||
            (valore[i] > 'Z' && valore[i] < 'a') ||
            valore[i] > 'z'){
            printf("\nERRORE!! Utilizza caratteri validi.\n");
            return true;
        }
    }

    return false;
}

/**
 * Funzione che controlla il corretto inserimento dell' altezza
 * @param valore Valore inserito dall' utente
 * @return True se l'inserimento è errato
 */

_Bool inserimentoAltezzaErrato(int *valore){
    scanf("%d", valore);
    if(*valore < MIN_ALTEZZA || *valore > MAX_ALTEZZA) {
        printf("\nERRORE!! Inserire un numero da 0 a 250\n");
        return true;
    }
    return false;
}

/**
 * Funzione che controlla il corretto inserimento del peso
 * @param valore Valore inserito dall' utente
 * @return True se l' inserimento è errato
 */

_Bool inserimentoPesoErrato(float *valore){
    int controllo;
    controllo = scanf("%f", valore);

    if(*valore < MIN_PESO || *valore > MAX_PESO) {
        printf("\nERRORE!! Inserire un numero da 0 a 200\n");
        return true;
    }
    if(controllo != 1){
        printf("\nERRORE!! Inserisci un numero da 0 a 200\n");
        getchar();
        return true;
    }

    return false;
}
/**
 * Funzione che controlla il corretto inserimento del colore
 * @param valore Valore inserito dall' utente
 * @return True se l' inserimento è errato
 */
_Bool inserimentoColoreErrato(char *valore){
    int i;
    scanf("%s", valore);
    for(i=0;i<HEX_COLORI;i++){
        if((valore[i] > ' ' && valore[i] < '0') ||
           (valore[i] > '9' && valore[i] < 'A') ||
           valore[i] > 'F') {
            printf("\nERRORE!! Questo colore non esiste o non e' scritto in modo corretto\n");
            return true;
        }
        if(valore[i] == '\0'){
            printf("\nERRORE!! Devi inserire 6 caratteri\n");
            return true;
        }
    }
    if(valore[HEX_COLORI] > HEX_COLORI){ // Se vengono inseriti più di 6 caratteri ritorna true
        printf("\nERRORE!! Inserisci 6 caratteri.\n");
        return true;
    }


    return false;
}

/**
 * Funzione che controlla il corretto inserimento della lunghezza
 * @param soggetto SOggetto da controllare
 * @return True se l'inserimento è errato
 */

_Bool inserimentoLunghezzaErrato(RecordSoggetto *soggetto) {

    if (soggetto->lunghezzaCapelli > ALTRO || soggetto->lunghezzaCapelli < CORTI){
        printf("\nERRORE!! Valore non riconosciuto\n");
        return true;
    }
    return false;


}

/**
 * Funzione che controlla il corretto inserimento di [S]i/[N]o
 * @param scelta Scelta dell' utente
 * @return True se l'inserimento è errato
 */
_Bool inserimentoSceltaErrato(char scelta){

    if(scelta == CHAR_SI || scelta == CHAR_MIN_S || scelta == CHAR_NO || scelta == CHAR_MIN_N)
        return false;
    else {
        printf("\nERRORE!! Inserire una risposta valida.\n");
        return true;
    }
}

/**
 * Funzione che controlla il corretto inserimento dei segni particolari
 * @param valore Valore inserito dall' utente
 * @return True se viene inserita la 'S'
 */


void acquisisciSegniParticolari(_Bool *valore, char scelta){
    if(scelta == CHAR_SI || scelta == CHAR_MIN_S)
        *valore =  true;
    else if(scelta == CHAR_NO || scelta == CHAR_MIN_N)
        *valore = false;
}

/**
 * Funzione che controlla il corretto inserimento della chiave impronta
 * @param valore Valore inserito dall' utente
 * @return True se l' inserimento è errato
 */


_Bool inserimentoChiaveErrato(char *valore){
    int i;
    scanf("%s", valore);

    for(i=0;i<DIM_CHIAVE_IMPRONTA && valore[i] != '\0';i++) {
        if ((valore[i] < '0' && valore[i] >= ' ') ||
            (valore[i] > '9' && valore[i] < 'A') ||
            (valore[i] > 'Z' && valore[i] < 'a') ||
            valore[i] > 'z'){
            printf("\nERRORE!! Utilizza caratteri validi.\n");
            return true;
        }else if(valore[i] == '\0'){
            printf("\nERRORE!! Devi inserire 16 caratteri\n");
            return true;
        }
    }
    if(valore[DIM_CHIAVE_IMPRONTA] > DIM_CHIAVE_IMPRONTA){
        printf("\nERRORE!! Inserisci 16 caratteri.\n");
        return true;
    }

    return false;
}

/**
 * Funzione che controlla il corretto inserimento della residenza
 * @param valore Valore inserito dall' utente
 * @return True se l' inserimento è errato
 */

_Bool inserimentoResidenzaErrato(char *valore){
    int i, contatore = 0;

    scanf("%[^\n]s", valore);

    for(i=0;i<DIM_RESIDENZA && valore[i] != '\0';i++) {
        if ((valore[i] < ',' && valore[i] > ' ') ||
            (valore[i] > ',' && valore[i] < '0') ||
            (valore[i] > '9' && valore[i] < 'A') ||
            (valore[i] > 'Z' && valore[i] < 'a') ||
            valore[i] > 'z'){
            printf("\nERRORE!! Utilizza caratteri validi.\n");
            return true;
        }
        if(valore[i] == ',') // Se nella stringa è presente una virgola aumenta di uno il contatore
            contatore++;
    }
    if(contatore < 2){ // Se nell' inserimento non ci sono almeno due virgole
        printf("\nERRORE!! Separa i campi con una virgola.\n");
        return true;
    }

    return false;
}

/**
 * Funzione che controlla il corretto inserimento della latitudine
 * @param valore Valore inserito dall' utente
 * @return True se l'inserimento è errato
 */

_Bool inserimentoLatitudineErrata(double *valore) {
    int controllo;

    controllo = scanf("%lf", valore);

    if (*valore < MIN_LATITUDINE ||
        *valore > MAX_LATITUDINE) {
        printf("\nERRORE!! Inserisci una coordinata valida.\n");
        return true;
    }
    if(controllo != 1){
        printf("\nERRORE!! Inserisci un numero\n");
        getchar();
        return true;
    }
    return false;
}

/**
 * Funzione che controlla il corretto inserimento della longitudine
 * @param valore Valore inserito dall' utente
 * @return True se l' inserimento  è errato
 */

_Bool inserimentoLongitudineErrata(double *valore) {
    int controllo;
    controllo = scanf("%lf", valore);
    if (*valore < MIN_LONGITUDINE ||
        *valore > MAX_LONGITUDINE){
        printf("\nERRORE!! Inserisci una coordinata valida.\n");
        return true;
    }
    if(controllo != 1){
        printf("\nERRORE!! Inserisci un numero\n");
        getchar();
        return true;
    }
    return false;

}

/**
 * Funzione che controlla il corretto inserimento dello stato del soggetto
 * @param soggetto Soggetto da controllare
 * @return True se l' inserimento è errato
 */

_Bool inserimentoStatoErrato(RecordSoggetto *soggetto){

    if (soggetto->statoSoggetto > EVASO || soggetto->statoSoggetto < LIBERO){
        printf("\nERRORE!! Valore non riconosciuto\n");
        return true;
    }
    return false;


}


/**
 * Funzione di controllo dell' inserimento degli indici riguardo al confronto
 * @param soggetto1 Primo soggetto da controllare
 * @param soggetto2 Secondo soggetto da controllare
 * @param nElementi Numero di schedati presenti
 * @param id1 Primo id inserito dall' utente
 * @param id2 Secondo id inserito dal' utente
 * @return True se l' inserimento è errato
 */

_Bool controlloInserimentoConfronto(RecordSoggetto *soggetto1, RecordSoggetto *soggetto2,int nElementi,int id1,int id2){

    if(esisteSoggetto(&soggetto1[id1]) == false || esisteSoggetto(&soggetto2[id2]) == false){
        printf("\nUno o piu id specificati non esistono.\n");
        return true;
    }
    if(id1 == id2){
        printf("\nInserisci 2 id differenti.\n");
        return true;
    }
    if(id1 >nElementi || id2 > nElementi){
        printf("\nUno o piu id specificati non esistono.\n");
        return true;
    }


    return false;

}

/**
 * Funzione che si occupa di condurre l' utente verso la funzione a cui vuole accedere
 * @param sceltaUno Scelta di stampare un soggetto a scelta
 * @param sceltaTutti Scelta di stampare tutti i soggetti presenti
 * @param schedati Scheda da stampare
 */

void controlloSceltaStampa(int sceltaUno,int sceltaTutti,Schedati *schedati){

    if (sceltaTutti == 0)
        stampaElencoCriminali(schedati->schedato,schedati->nSchedati);
    if(sceltaUno == 0){
        stampaRecord(schedati);
    }
}

/**
 * Funzione che si occupa di condurre l' utente verso la funzione a cui vuole accedere
 * @param sceltaCriptati Scelta di caricare i dati in modo criptato
 * @param sceltaDecriptati Scelta di caricare i dati in modo decriptato
 * @param schedati Scheda dentro la quale importare i soggetti
 */

void controlloSceltaCarica(int sceltaCriptati,int sceltaDecriptati,Schedati *schedati){


    if (sceltaCriptati == 0)
        caricaDatiCriptati(schedati,"ListaCriminaliCriptata.dat");
    if(sceltaDecriptati == 0){
        caricaDati(schedati,"ListaCriminali.dat");
    }


}

/**
 * Funzione che si occupa di condurre l' utente verso la funzione a cui vuole accedere
 * @param sceltaCriptati Scelta di salvare i dati in modo criptato
 * @param sceltaDecriptati Scelta di salvare i dati in modo decriptato
 * @param schedati Scheda da esportare
 */

void controlloSceltaSalva(int sceltaCriptati,int sceltaDecriptati,Schedati *schedati){


    if (sceltaCriptati == 0)
        salvaDatiCriptati(schedati->schedato,"ListaCriminaliCriptata.dat",schedati->nSchedati);
    if(sceltaDecriptati == 0){
        salvaDati(schedati->schedato,"ListaCriminali.dat",schedati->nSchedati);
    }


}


/**
 * Funzione che si occupa di condurre l'utente verso la funzione a cui vuole accedere
 * @param schedato1 Primo soggetto da confrontare
 * @param schedato2 Secondo soggetto da confrontare
 * @param sceltaConfronto Scelta effettuata dall' utente per accedere alla funzione di confronto tra i 2 o di 1 rispetto agli altri
 * @return True se si inserisce una risposta non valida
 */

_Bool controlloSceltaConfronto(Schedati *schedato1,Schedati *schedato2,int sceltaConfronto){

    if(schedato1->nSchedati<2){ // se il numero di schedati è minore di 2
        printf("\nCrea o Genera almeno due soggetti prima di effettuare il confronto!\n");
        return false; // Ritorna false in modo che si possa tornare al menu e crearli
    }


    if(sceltaConfronto == 2) {
        confrontoTra2(schedato1, schedato2);
        return false; // Per tornare al menu alla conclusione della funzione
    }
    if(sceltaConfronto == 1) {
        printf("\nFunzione ancora non implementata.\n");
        return false; // Per tornare al menu alla conclusione della funzione
    }

    if(sceltaConfronto < 1 || sceltaConfronto > 2 || sceltaConfronto < '0' || sceltaConfronto >'9') {
        printf("\nInserisci una risposta valida!\n");
        return true; // Per ripetere il ciclo
    }


    return false;


}

/**
 *Funzione che determina se un soggetto esiste o no
 * @param soggetto Soggetto da verificare
 * @param nElementi Numero di schedati
 * @return
 */

_Bool esisteSoggetto(RecordSoggetto *soggetto){

        if (strcmp(soggetto->nomeSoggetto, "") == 0) {
            return false;
        }else
            return true;


}