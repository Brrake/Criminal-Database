//
// Created by david on 26/05/2021.
//

#include "generazioneSoggettoCasuale.h"

/**
 * Funzione che genera e aggiunge al vettore dinamico un soggetto generato casualmente
 * @param soggetto Struttura in cui caricare i dati generati
 * @param schedato Scheda in cui aggiungere il soggetto
 */

void generaRecord(RecordSoggetto *soggetto,Schedati *schedato){
    *soggetto = generaSoggetto();
    aggiungiElemento(schedato, soggetto);

}

/**
 * Funzione che racchiude tutte le generazioni
 * @return Soggetto generato automaticamente
 */

RecordSoggetto generaSoggetto(){

    RecordSoggetto soggetto;

    generaNome(&soggetto);
    generaCognome(&soggetto);
    generaAltezza(&soggetto);
    generaPeso(&soggetto);
    generaColore(soggetto.coloreOcchi);
    generaColore(soggetto.coloreCapelli);
    generaLunghezza(&soggetto);
    generaSegniParticolari(&soggetto);
    generaChiave(&soggetto);
    generaResidenza(&soggetto);
    generaPosizione(&soggetto);
    generaStato(&soggetto);


    return soggetto;
}


/**
 * Funzione che genera un intero con due estremi distinti
 * @param min Valore minimo generabile
 * @param max Valore mamssimo generabile
 * @return Intero casuale
 */

int generaCasualeInt(int min,int max){
    return min + rand() % ((max) - min + 1);
}

/**
 * Funzione che genera casualmente un float con due estremi distinti
 * @param min Valore minimo generabile
 * @param max Valore massimo generabile
 * @return Float casuale
 */

float generaCasualeFloat(int min, int max){
    return ((float) min + rand() % (max - min + 1))/ 10;

}

/**
 * Funzione che genera casualmente un double con due estremi distinti
 * @param min Valore minimo generabile
 * @param max Valore massimo generabile
 * @return Double casuale
 */

double generaCasualeDouble(double min,double max){
    double numeroCasuale,differenza;
        differenza = (max - min);
        numeroCasuale = (rand()/(double)RAND_MAX) * differenza;
        numeroCasuale += min ;
        return numeroCasuale;

}

/**
 * Funzione che genera casualmente un char con due estremi distinti
 * @param min Char minimo generabile
 * @param max Char massimo generabile
 * @return Char casuale
 */

char generaChar(int min,int max){
    return min + rand() % (max - min);
}

/**
 * Procedura che genera casualmente un nome
 * @param soggetto Soggetto a cui assegnare il nome casuale
 */

void generaNome(RecordSoggetto *soggetto){

    char nomi [N_NOMI][DIM_NOME_COGNOME] = {"Davide","Claudio", "Giovanni","Salvatore","Stefano","Mirko",
                                        "Matteo","Alessandro","Luca","Camilla","Cristina","Andrea"};
    int i;

    i = generaCasualeInt(MIN,(N_NOMI-1));

    strcpy(soggetto->nomeSoggetto, nomi[i]); // Copia il contenuto del nome generato all' interno del relativo campo

    printf("\nNome generato : %s\n", soggetto->nomeSoggetto);


}

/**
 * Procedura che genera casualmente un cognome
 * @param soggetto Soggetto a cui assegnare il cognome casuale
 */

void generaCognome(RecordSoggetto *soggetto){

    const char cognomi [N_NOMI][DIM_NOME_COGNOME] = {"Rubiu","Riina", "Messina","Capone","Mattarella",
                                           "Draghi","Conte","Bagarella","De Luca","Murtas","Melis","Arzu"};
    int i;

    i = generaCasualeInt(MIN,(N_NOMI-1));

    strcpy(soggetto->cognomeSoggetto, cognomi[i]); // Copia il contenuto del cognome generato all' interno del relativo campo

    printf("\nCognome generato : %s\n", soggetto->cognomeSoggetto);

}

/**
 * Procedura che genera casualmente un altezza
 * @param soggetto Soggetto a cui assegnare l' altezza casuale
 */

void generaAltezza(RecordSoggetto *soggetto){


    soggetto->altezzaSoggetto = generaCasualeInt(MIN_ALTEZZA,MAX_ALTEZZA);

    printf("\nAltezza generata : %dcm\n", soggetto->altezzaSoggetto);
}

/**
 * Procedura che genera casualmente un peso
 * @param soggetto Soggetto a cui assegnare il peso casuale
 */

void generaPeso(RecordSoggetto *soggetto){


    soggetto->pesoSoggetto = generaCasualeFloat(MIN_PESO,MAX_PESO);

    printf("\nPeso generato : %.2fkg\n", soggetto->pesoSoggetto);
}

/**
 * Procedura che genera casualmente un colore
 * @param soggetto Soggetto a cui assegnare il colore casuale
 */

void generaColore(char *valore){

    int i;
    int casuale;
    char generazione[HEX_COLORI +1] = {0};

   for(i=0;i<HEX_COLORI;i++) {
        casuale = generaCasualeInt(MIN, MAX);
            if (casuale == 1) {
                generazione[i] = generaChar('A', 'F');
            } else {
                generazione[i] = generaChar('0', '9');
            }

   }

    strcpy(valore,generazione); // Copia il contenuto del colore generato all' interno del relativo campo

    printf("\nColore Occhi generato : %s\n", generazione);


}

/**
 * Procedura che genera casualmente una lunghezza
 * @param soggetto Soggetto a cui assegnare la lunghezza casuale
 */

void generaLunghezza(RecordSoggetto *soggetto){

     soggetto->lunghezzaCapelli = generaCasualeInt(CORTI,ALTRO);
    switch (soggetto->lunghezzaCapelli) {
        case CORTI:
            printf("\nTipo di capelli generato : CORTI\n");
            break;
        case MEDI:
            printf("\nTipo di capelli generato : MEDI\n");
            break;
        case LUNGHI:
            printf("\nTipo di capelli generato : LUNGHI\n");
            break;
        case ALTRO:
            printf("\nTipo di capelli generato : ALTRO\n");
    }


}

/**
 * Procedura che genera casualmente un booleano true o false
 * @param soggetto Soggetto a cui assegnare un segno casuale
 */

void generaSegniParticolari(RecordSoggetto *soggetto){
    int casuale,casuale2;

    casuale = generaCasualeInt(false, true);
    if(casuale==true)
        soggetto->barba = true;
    else
        soggetto->barba = false;
    stampaBarba(soggetto);

    casuale2 = generaCasualeInt(false,true);
    if(casuale2==true)
        soggetto->cicatrici = true;
    else
        soggetto->cicatrici = false;

    stampaCicatrici(soggetto);
}

/**
 * Procedura che genera casualmente una chiave impronta
 * @param soggetto Soggetto a cui assegnare una chiave impronta casuale
 */

void generaChiave(RecordSoggetto *soggetto){

    int i;
    int casuale;
    char chiave[DIM_CHIAVE_IMPRONTA + 1];

    printf("\nChiave generata : ");

    for(i=0;i<DIM_CHIAVE_IMPRONTA;i++) {
        casuale = generaCasualeInt(MIN, MAX);
        if(casuale==0)
            chiave[i] = generaChar('A','Z');
        if(casuale==1)
            chiave[i] = generaChar('0','9');
        if(casuale==2)
            chiave[i] = generaChar('a','z');

    }

    strcpy(soggetto->chiaveImpronta,chiave); // Copia il contenuto dell' impronta generato all' interno del relativo campo
    printf("%s\n",soggetto->chiaveImpronta);
}

/**
 * Procedura che genera casualmente una residenza
 * @param soggetto Soggetto a cui assegnare una residenza casuale
 */

void generaResidenza(RecordSoggetto *soggetto){

    int casualeVia, casualeCitta, casualeProvincia;


    char via[N_PAESI][L_PAESI] = {"Via Raffaello - ","Via Michelangelo - ","Via Dante - ","Via Roma - ",
                                  "Via Sardegna - ","Via Pascoli - ","Via Leopardi - ","Via Manzoni - ",
                                  "Via Ungaretti - ","Via Molise - ","Via Garibaldi - "};
    char citta[N_PAESI][L_PAESI] = {"NYC - ","Los Angeles - ","Lotzorai - ","Nuoro - ",
                                  "Cagliari - ","Milano - ","Viterbo - ","Catanzaro - ",
                                  "Boston - ","Budoni - ","Arzana - "};
    char provincia[N_PAESI][L_PAESI] = {"NYC","Los Angeles","Ogliastra","Nuoro",
                                    "Cagliari","Milano","Viterbo","Sassari",
                                    "Sud Sardegna","Roma","Palermo"};


    casualeVia = generaCasualeInt(MIN,(N_PAESI-1));
    casualeCitta = generaCasualeInt(MIN,(N_PAESI-1));
    casualeProvincia = generaCasualeInt(MIN,(N_PAESI-1));


    strcpy(soggetto->residenzaSoggetto, via[casualeVia]); // Copia il contenuto della via generata all' interno del relativo campo
    strcat(soggetto->residenzaSoggetto,citta[casualeCitta]); // Copia il contenuto della citta generata all' interno del relativo campo
    strcat(soggetto->residenzaSoggetto,provincia[casualeProvincia]); // Copia il contenuto della provincia generata all' interno del relativo campo


    printf("\nResidenza : %s\n", soggetto->residenzaSoggetto);



}

/**
 * Procedura che genera casualmente una posizione
 * @param soggetto Soggetto a cui assegnare una posizione casuale
 */

void generaPosizione(RecordSoggetto *soggetto){


    soggetto->ultimaPosizione.ultimaLatitudine = generaCasualeDouble(MIN_LATITUDINE,MAX_LATITUDINE);
    soggetto->ultimaPosizione.ultimaLongitudine = generaCasualeDouble(MIN_LONGITUDINE,MAX_LONGITUDINE);

    printf("\nUltima Latitudine generata : %lf\n",soggetto->ultimaPosizione.ultimaLatitudine);
    printf("\nUltima Longitudine generata : %lf\n",soggetto->ultimaPosizione.ultimaLongitudine);

}

/**
 * Procedura che genera casualmente uno stato del soggetto
 * @param soggetto Soggetto a cui assegnare uno stato casuale
 */

void generaStato(RecordSoggetto *soggetto){


    soggetto->statoSoggetto = generaCasualeInt(LIBERO,EVASO);
    switch (soggetto->statoSoggetto) {
        case LIBERO:
            printf("\nStato generato : LIBERO\n");
            break;
        case RICERCATO:
            printf("\nStato generato : RICERCATO\n");
            break;
        case INARRESTO:
            printf("\nStato generato : IN ARRESTO\n");
            break;
        case EVASO:
            printf("\nStato generato : EVASO\n");
    }



}

/**
 * Procedura che stampa TRUE o FALSE in funzione di generaSegniParticolari
 * @param soggetto Soggetto da cui prendere il valore relativo alla barba
 */

void stampaBarba(RecordSoggetto *soggetto){

    if(soggetto->barba == true)
        printf("\nBarba : TRUE\n");
    else
        printf("\nBarba : FALSE\n");
}

/**
 * Procedura che stampa TRUE o FALSE in funzione di generaSegniParticolari
 * @param soggetto Soggetto da cui prendere il valore relativo alla cicatrice
 */

void stampaCicatrici(RecordSoggetto *soggetto){

    if(soggetto->cicatrici == true)
        printf("\nCicatrici : TRUE\n");
    else
        printf("\nCicatrici : FALSE\n");
}


