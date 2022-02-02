//
// Created by david on 30/05/2021.
//

/**
 * Libreria per la gestione delle strutture
 */

#ifndef PROGETTO_FINALE_STRUTTURE_H
#define PROGETTO_FINALE_STRUTTURE_H

/* Definizione Macro dimensioni */

#define DIM_NOME_COGNOME 64 // Dimensione massima nomi e cognomi
#define HEX_COLORI 6 // Dimensione massima esadecimale riguardante i colori
#define DIM_CHIAVE_IMPRONTA 16 // Dimensione massima chiave impronta
#define DIM_RESIDENZA 512 // Dimensione massima della residenza
#define MIN_ALTEZZA 0 // Dimensione minima dell' altezza
#define MAX_ALTEZZA 250 // Dimensione massima dell' altezza
#define MIN_PESO 0.00 // Dimensione minima del peso
#define MAX_PESO 200.00 // Dimensione massima del peso
#define MIN_LATITUDINE (-90.0000) // Dimensione minima dell' ultima latitudine conosciuta
#define MAX_LATITUDINE 90.0000 // Dimensione massima dell' ultima latitudine conosciuta
#define MIN_LONGITUDINE (-180.0000) // Dimensione minima dell' ultima longitudine conosciuta
#define MAX_LONGITUDINE 180.0000 // Dimensione massima dell' ultima longitudine conosciuta

/* Definizione Macro SI/NO */

#define CHAR_SI 'S'
#define CHAR_NO 'N'
#define CHAR_MIN_S 's'
#define CHAR_MIN_N 'n'


/**
 * Struttura dell' ultima posizione conosciuta
 */

typedef struct{
    double ultimaLatitudine;
    double ultimaLongitudine;

}PosizioneGPS;

/**
 * Enumerazione stato soggetto
 */

typedef enum{LIBERO = 1, RICERCATO, INARRESTO, EVASO} StatoSoggetto; // Partenza da 1 per scelta stilistica

/**
 * Enumerazione tipo di capelli
 */

typedef enum{CORTI = 1,MEDI,LUNGHI,ALTRO} TipoCapelli; // Partenza da 1 per scelta stilistica

/**
 * Struttura dati del soggetto
 */

typedef struct{
    char nomeSoggetto[DIM_NOME_COGNOME];
    char cognomeSoggetto[DIM_NOME_COGNOME];
    int altezzaSoggetto;
    float pesoSoggetto;
    char coloreOcchi[HEX_COLORI + 1];
    char coloreCapelli[HEX_COLORI + 1];
    TipoCapelli lunghezzaCapelli;
    _Bool barba;
    _Bool cicatrici;
    char chiaveImpronta[DIM_CHIAVE_IMPRONTA + 1];
    char residenzaSoggetto[DIM_RESIDENZA];
    PosizioneGPS ultimaPosizione;
    StatoSoggetto statoSoggetto;
} RecordSoggetto;

/**
 * Struttura del vettore dinamico
 */

typedef struct {
    RecordSoggetto *schedato;
    int nSchedati; // Numero di soggetti memorizzati
}Schedati;



#endif //PROGETTO_FINALE_STRUTTURE_H
