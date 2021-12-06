//
// Created by Paul on 25/11/2021.
//

#ifndef ECHEC_V_0_MENU_V_1_H
#define ECHEC_V_0_MENU_V_1_H

#define DIMENSION 8

typedef struct{
    char piece;
    int equipe;
}Piece;

void menu_V_1();
int conversionChiffre(const char* coordonnees);
int conversionLettre(const char* coordonnees);

void jouer( int* pNombreCoups, Piece plateau[DIMENSION][DIMENSION]);
#endif //ECHEC_V_0_MENU_V_1_H
