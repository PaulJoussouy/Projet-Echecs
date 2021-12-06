//
// Created by Paul on 25/11/2021.
//

#ifndef ECHEC_V_0_AFFICHERPLATEAUX_H
#define ECHEC_V_0_AFFICHERPLATEAUX_H
#include "menu_V_1.h"
typedef struct{
    int ligne;
    int colonne;
}Coordonnee;


/*=====================================================================
In:
But:
Out:
*/

void jeNeSaisPasCommentNommer(const int nombreDeCoup, Piece plateau[DIMENSION][DIMENSION], Piece plateauVide[1][1], int* pNumeroLigneActuelle, int* pNumeroColonneActuelle, int* pNumeroLigneFuture, int* pNumeroColonneFuture, int* pDeplacer, int* mouvementPossible);
//..................................
/*=====================================================================
In: un entier constant correspondant aux nombre de coup joue
But: aficher le plateaux sans couleur oriente au equipes qui joue (ex: si blanc joue--> pion blanc en bas)
Out: rien
In/Out: tableaux deux dim correspondant au infos du plateaux
*/
void afficherPlateaux(Piece plateau[DIMENSION][DIMENSION], const int nombreDeCoup);
//..................................

/*=====================================================================
In: un entier constant correspondant aux nombre de coup joue
But: aficher le plateaux en couleur oriente au equipes qui joue (ex: si blanc joue--> pion blanc en bas)
Out: rien
In/Out: tableaux deux dim correspondant au infos du plateaux
PS: les fonctions couleurs ne fonctionne peut etre pas sur platforme autre que Machintosh ( a essayer)
*/
void afficherPlateauxCouleur(Piece plateau[DIMENSION][DIMENSION], const int nombreDeCoup);
//..................................

/*=====================================================================
In: deux entier correspondant a l'adresse du pion selectionner, et un correspondant au nombre de coup
But: aficher le plateaux en couleur oriente au equipes qui joue (ex: si blanc joue--> pion blanc en bas) et en fond vert dans les case ou on peux se deplacer
Out: rien
In/Out: tableaux deux dim correspondant au infos du plateaux
PS: les fonctions couleurs ne fonctionne peut etre pas sur platforme autre que Machintosh ( a essayer)
*/
void afficherCoupCouleur(Piece plateau[DIMENSION][DIMENSION], const int nombreDeCoup, int ligneActuelle, int colonneActuelle, Coordonnee tableauxMouvementPossible[]);
//..................................


#endif //ECHEC_V_0_AFFICHERPLATEAUX_H
