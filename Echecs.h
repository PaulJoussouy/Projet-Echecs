//
// Created by Paul on 06/12/2021.
//

#ifndef ECHEC_V_0_ECHECS_H
#define ECHEC_V_0_ECHECS_H
#include "menu_V_1.h"
#include "afficherPlateaux.h"

int verifCav(int i, int lig, int col, int direction, Piece plateau[8][8]);
int verifHoVe(int i, int lig, int col, Piece plateau[8][8]);
int verifDiag(int i, int lig, int col, int direction, Piece plateau[8][8]);
Coordonnee ouEsLeRoi(Piece plateau[8][8], int eq);
int verifieEchec(Piece plateau[8][8], int lig);

#endif //ECHEC_V_0_ECHECS_H
