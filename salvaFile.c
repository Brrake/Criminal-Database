//
// Created by david on 04/06/2021.
//

#include "salvaFile.h"

/**
 * Procedura che richiede in che modo si desidera salvare i dati
 * @param schedati
 */

void salva(Schedati *schedati){

    char sceltaSalva[SCELTA_CARICA + 1];
    char decriptati[SCELTA_CARICA + 1] = {"Decriptato"};
    char criptati[SCELTA_CARICA + 1] = ("Criptato");
    _Bool flagInserimentoErrato;
    int sceltaDecriptati;
    int sceltaCriptati;

    do {
        flagInserimentoErrato = false;
        printf("\nIn che modo vuoi salvare il tuo file?\n");
        printf("[Criptato]/[Decriptato]\n");
        printf("Scelta:");
        scanf("%s", sceltaSalva);
        flagInserimentoErrato = inserimentoNomeErrato(sceltaSalva);
        svuotaBuffer();

        sceltaDecriptati = strcmp(sceltaSalva,decriptati);
        sceltaCriptati = strcmp(sceltaSalva,criptati);

        controlloSceltaSalva(sceltaCriptati,sceltaDecriptati,schedati);

    }while(flagInserimentoErrato || (sceltaCriptati != 0 && sceltaDecriptati != 0));

}

/**
 * Procedura che permette di salvare i dati all' interno di un file binario esterno
 * @param soggetto Soggetto da salvare
 * @param nomeFile Nome del file su cui salvare i dati
 * @param nElementi Numero di schedati
 */

void salvaDati(RecordSoggetto *soggetto, char *nomeFile, int nElementi){
    FILE *fp = NULL;
    int i = 0;


    fp = fopen(nomeFile,"wb");

    if(fp == NULL) {
        printf("\nERRORE!! Il file non esiste\n");
        exit(-1);
    }

    fwrite(&nElementi, sizeof(int), 1, fp);

    do {
        fwrite(&soggetto[i], sizeof(RecordSoggetto), nElementi, fp);
        i++;
    }while(i == nElementi);

    fclose(fp);

    printf("\nSalvataggio del file eseguito con successo!\n");

}

/**
 * Procedura che permette di salvare i dati in maniera criptata all' interno di un file binario esterno
 * @param soggetto Soggetto da salvare
 * @param nomeFile Nome del file su cui salvare i dati
 * @param nElementi Numero di schedati
 */

void salvaDatiCriptati(RecordSoggetto *soggetto, char *nomeFile, int nElementi){

    FILE *fp = NULL;
    int i = 0;

    fp = fopen(nomeFile,"wb");


    if(fp == NULL) {
        printf("\nERRORE!! Il file non esiste\n");
        exit(-1);
    }

    fwrite(&nElementi, sizeof(int), 1, fp);

    criptaDecriptaInfo(soggetto,nElementi);


        do {
            fwrite(&soggetto[i], sizeof(RecordSoggetto), nElementi, fp);
            i++;
        }while(i == nElementi);


    fclose(fp);

    printf("\nSalvataggio del file criptato eseguito con successo!\n");

}

/**
 * Procedura che cripta o decripta il nome e il cognome
 * @param soggetto Soggetto da criptare o decriptare
 * @param nElementi Numero di schedati
 */

void criptaDecriptaInfo(RecordSoggetto *soggetto,int nElementi){

    int i,j;

    for(i=0;i<nElementi;i++) {
        for (j = 0; j < DIM_NOME_COGNOME; j++) {
            cripta(&soggetto[i].nomeSoggetto[j]);
            cripta(&soggetto[i].cognomeSoggetto[j]);
        }
    }
}

/**
 * Procedura contenente uno switch la cui funzione è quella di criptare o decriptare un valore passato in ingresso
 * @param valore Valore da criptare o decriptare
 */

void cripta(char *valore){
    switch (*valore) {
        case 'A':
            *valore = 'Z';
            break;
        case 'B':
            *valore = 'Y';
            break;
        case'C':
            *valore = 'X';
            break;
        case'D':
            *valore = 'W';
            break;
        case'E':
            *valore = 'V';
            break;
        case'F':
            *valore = 'U';
            break;
        case'G':
            *valore = 'T';
            break;
        case'H':
            *valore = 'S';
            break;
        case'I':
            *valore = 'R';
            break;
        case'J':
            *valore = 'Q';
            break;
        case'K':
            *valore = 'P';
            break;
        case'L':
            *valore = 'O';
            break;
        case'M':
            *valore = 'N';
            break;
        case'N':
            *valore = 'M';
            break;
        case'O':
            *valore = 'L';
            break;
        case'P':
            *valore = 'K';
            break;
        case'Q':
            *valore = 'J';
            break;
        case'R':
            *valore = 'I';
            break;
        case'S':
            *valore = 'H';
            break;
        case'T':
            *valore = 'G';
            break;
        case'U':
            *valore = 'F';
            break;
        case'V':
            *valore = 'E';
            break;
        case'W':
            *valore = 'D';
            break;
        case'X':
            *valore = 'C';
            break;
        case'Y':
            *valore = 'B';
            break;
        case'Z':
            *valore = 'A';
            break;

        case 'a':
            *valore = 'z';
            break;
        case 'b':
            *valore = 'y';
            break;
        case'c':
            *valore = 'x';
            break;
        case'd':
            *valore = 'w';
            break;
        case'e':
            *valore = 'v';
            break;
        case'f':
            *valore = 'u';
            break;
        case'g':
            *valore = 't';
            break;
        case'h':
            *valore = 's';
            break;
        case'i':
            *valore = 'r';
            break;
        case'j':
            *valore = 'q';
            break;
        case'k':
            *valore = 'p';
            break;
        case'l':
            *valore = 'o';
            break;
        case'm':
            *valore = 'n';
            break;
        case'n':
            *valore = 'm';
            break;
        case'o':
            *valore = 'l';
            break;
        case'p':
            *valore = 'k';
            break;
        case'q':
            *valore = 'j';
            break;
        case'r':
            *valore = 'i';
            break;
        case's':
            *valore = 'h';
            break;
        case't':
            *valore = 'g';
            break;
        case'u':
            *valore = 'f';
            break;
        case'v':
            *valore = 'e';
            break;
        case'w':
            *valore = 'd';
            break;
        case'x':
            *valore = 'c';
            break;
        case'y':
            *valore = 'b';
            break;
        case'z':
            *valore = 'a';
            break;

    }
}