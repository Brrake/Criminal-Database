cmake_minimum_required(VERSION 3.19)
project(Progetto_Finale C)

set(CMAKE_C_STANDARD 99)

add_executable(Progetto_Finale main.c menuUtente.c menuUtente.h acquisizioneSoggetto.c acquisizioneSoggetto.h controlloAcquisizioni.c controlloAcquisizioni.h "generazioneSoggettoCasuale.c" "generazioneSoggettoCasuale.h" strutture.c strutture.h stampaElenco.c stampaElenco.h confrontaSoggetti.c confrontaSoggetti.h caricaFile.c caricaFile.h salvaFile.c salvaFile.h eliminaSoggeto.c eliminaSoggeto.h strutture.c)