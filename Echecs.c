//
// Created by Paul on 06/12/2021.
//

#include "Echecs.h"
#include "menu_V_1.h"
#include "afficherPlateaux.h"


int verifCav(int i, int lig, int col, int direction, Piece plateau[8][8]){
    int x;
    int y;
    switch (direction) {
        //liste des différente position du cavalier
        case 1:
            // |__
            x = lig + 1;
            y = col - 3;
        case 2:
            // L
            x = lig + 3;
            y = col - 1;
        case 3:
            // _|(montant)
            x = lig + 3;
            y = col + 1;
        case 4:
            // |¨¨(montant)
            x = lig + 1;
            y = col + 3;
        case 5:
            // |__(descendant)
            x = lig -1;
            y = col + 3;
        case 6:
            // ¨|
            x = lig - 3;
            y = col + 1;
        case 7:
            // |¨
            x = lig - 3;
            y = col - 1;
        case 8:
            // |¨¨
            x = lig - 1;
            y = col - 3;
    }
    if (x<8 && y<8){
        if (plateau[x][y].piece != ' ' && plateau[x][y].equipe != plateau[lig][col].equipe) {
            // s'assure que la 1ére piece en partant du roi dans le L est une piece ennemie
            if (plateau[x][y].piece == 'c') {
                //verifie si cette piece est dangereuse la cavalier
                return 1;
            }
        }
    }
    return 0;
}

int verifHoVe(int i, int lig, int col, Piece plateau[8][8]){
    if (lig+i<8){
        if (plateau[lig+i][col].piece=='t' || plateau[lig+i][col].piece=='r' || plateau[lig+1][col].piece=='R'&& plateau[lig+1][col].equipe!=plateau[lig][col].equipe){
            return 1;
        }
    }
    if (col+i<8){
        if (plateau[lig][col+i].piece=='t' || plateau[lig][col+i].piece=='r' || plateau[lig][col+1].piece=='R'&& plateau[lig+1][col].equipe!=plateau[lig][col].equipe){
            return 1;
        }
    }
    if (lig-i>0){
        if (plateau[lig-i][col].piece=='t' || plateau[lig-i][col].piece=='r' || plateau[lig-i][col].piece=='R'&& plateau[lig+1][col].equipe!=plateau[lig][col].equipe){
            return 1;
        }
    }
    if (col-i>0){
        if (plateau[lig][lig-i>0].piece=='t' || plateau[lig][lig-i>0].piece=='r' || plateau[lig][col-1].piece=='R'){
            return 1;
        }
    }
}

int verifDiag(int i, int lig, int col, int direction, Piece plateau[8][8]){
    int x;
    int y;
    switch (direction) {
        case 1:
            //diagonale haute droite
            x = lig + i;
            y = col + i;
        case 2:
            //diagonale haute gauche
            x = lig + i;
            y = col - i;
        case 3:
            //diagonale basse droite
            x = lig - i;
            y = col + i;

        case 4:
            //diagonale basse gauche
            x = lig - i;
            y = col - i;
    }
    if (x<8 && y<8){
        //ne pas sortir des limite du plateau
        if (plateau[x][y].piece != ' ' && plateau[x][y].equipe != plateau[lig][col].equipe) {
            // s'assure que la 1ére piece en partant du roi dans la diagonale est une piece ennemie
            if (plateau[x][y].piece == 'r' || plateau[x][y].piece == 'f' ||
                plateau[lig + 1][col + 1].piece == 'R' || plateau[lig + 1][col + 1].piece == 'p'||
                plateau[lig + 1][col - 1].piece == 'R' || plateau[lig + 1][col - 1].piece == 'p') {
                //verifie si cette piece est dangereuse roi(seulement si il est à une case de dif en diag),
                // fou,renne,pion(seulement si il est à une case de dif en diag)
                return 1;
            }
        }
    }
    return 0;
}

Coordonnee ouEsLeRoi(Piece plateau[8][8], int eq){
    char c;
    int i;
    int j;
    Coordonnee la;
    for (i=0;i<8;i++){
        for (j=0;j<8;j++){
            if (plateau[i][j].piece=='R' && plateau[i][j].equipe==eq){
                la.ligne=i;
                la.colonne=j;
                return la;
            }
        }
    }
}

int verifieEchec(Piece plateau[8][8], int eq) {
    //lig et col est la position du roi DANS LE TABLEAU pas dans le jeu
    //cette fonction verifie si le roi est attaquer en verifiant les zone du tableau ou le roi peut être attaquer
    // cad les diagonales, la ligne,
    //la colonne, la ligne et les position en L autour du roi
    int i = 0;
    int e = 0;
    Coordonnee la;
    int lig;
    int col;
    la=ouEsLeRoi(plateau,eq);
    lig=la.ligne;
    col=la.colonne;
    int c=0;
    int j = 1;
    for (i = 0; i < 8; j++) {
        for (j=1;j<5;i++){
            e=e+verifDiag(i, lig, col, j, plateau);
        }
        e=e+verifHoVe(i,lig,col,plateau);
        for (c=1;c<9;c++){
            e=e+ verifCav(i,lig,col,c,plateau);
        }
    }
    return e;
}

