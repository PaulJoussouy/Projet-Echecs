//
// Created by Paul on 22/11/2021.
//

#ifndef ECHEC_V_0_ENREGISTRER_H
#define ECHEC_V_0_ENREGISTRER_H

#include "menu_V_1.h"

void savPartie1(Piece plateau[8][8], const int nombreDeCoup);
void savPartie2(Piece plateau[8][8], const int nombreDeCoup);
void savPartie3(Piece plateau[8][8], const int nombreDeCoup);

void chrgPartie1(Piece plateau[8][8], int* nombreDeCoup);
void chrgPartie2(Piece plateau[8][8], int* nombreDeCoup);
void chrgPartie3(Piece plateau[8][8], int* nombreDeCoup);

void selectionnerSauvegarde(Piece plateau[8][8], const int nombreDeCoup);
void chargerSauvegarde(Piece plateau[8][8], int* nombreDeCoup);


#endif //ECHEC_V_0_ENREGISTRER_H
