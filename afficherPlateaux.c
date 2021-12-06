//
// Created by Paul on 25/11/2021.
//

#include "afficherPlateaux.h"
#include <stdio.h>
#include "couleur.h"
#include "menu_V_1.h"

void jeNeSaisPasCommentNommer(const int nombreDeCoup, Piece plateau[DIMENSION][DIMENSION], Piece plateauVide[1][1], int* pNumeroLigneActuelle, int* pNumeroColonneActuelle, int* pNumeroLigneFuture, int* pNumeroColonneFuture, int* pDeplacer, int* mouvementPossible){
    //les blancs jouent

    // // il faut vérifier qu'il y a bien une pièce saisie
    // // et qu'elle est bien de la bonne couleur (équipe == 1)

    printf("\nTour des blancs : \n");

    do {

        do {

            //sélection de la pièce
            printf("Selection : numero de colonne, numero de ligne \n");
            scanf("%d %d", pNumeroColonneActuelle, pNumeroLigneActuelle);
            *pNumeroColonneActuelle = *pNumeroColonneActuelle - 1;
            *pNumeroLigneActuelle = *pNumeroLigneActuelle - 1;


            if (plateau[*pNumeroLigneActuelle][*pNumeroColonneActuelle].equipe != 1){
                printf("Case selectionnee non valide. \n");
            }

        } while (plateau[*pNumeroLigneActuelle][*pNumeroColonneActuelle].equipe != 1);

        //affichage coups disponibles

        //demande à l'utilisateur de confirmer pièce sélectionnée
        printf("1 pour valider la piece, 0 pour changer \n>");
        scanf(" %d", pDeplacer);

    } while (*pDeplacer != 1);

    do {

        //saisie du déplacement de le pièce sélectionnée
        printf("Deplacement : numero de colonne, numero de ligne \n");
        scanf("%d %d", pNumeroColonneFuture, pNumeroLigneFuture);
        *pNumeroColonneFuture = *pNumeroColonneFuture - 1;
        *pNumeroLigneFuture = *pNumeroLigneFuture - 1;


        //mouvement sur une pièce noire
        if(plateau[*pNumeroLigneFuture][*pNumeroColonneFuture].equipe == 2){
            plateau[*pNumeroLigneFuture][*pNumeroColonneFuture] = plateau[*pNumeroLigneActuelle][*pNumeroColonneActuelle];
            plateau[*pNumeroLigneActuelle][*pNumeroColonneActuelle] = plateauVide[0][0];
            mouvementPossible = 1;
        }
            //mouvement sur une pièce blanche
        else if(plateau[*pNumeroLigneFuture][*pNumeroColonneFuture].equipe == 1){
            printf("Mouvement impossible, veuillez recommencer : \n");
            mouvementPossible = 0;
        }
            //mouvement sur une case vide
        else if(plateau[*pNumeroLigneFuture][*pNumeroColonneFuture].equipe != 1 && plateau[*pNumeroLigneFuture][*pNumeroColonneFuture].equipe != 2){
            plateau[*pNumeroLigneFuture][*pNumeroColonneFuture] = plateau[*pNumeroLigneActuelle][*pNumeroColonneActuelle];
            plateau[*pNumeroLigneActuelle][*pNumeroColonneActuelle] = plateauVide[0][0];
            mouvementPossible = 1;
        }


    } while (mouvementPossible != 1);

}//fin du tour des blancs

void afficherPlateaux(Piece plateau[DIMENSION][DIMENSION], const int nombreDeCoup){

    //affichage du plateau après déplacement blanc en bas:
    if(nombreDeCoup % 2 == 1){

        printf("      1     2     3     4     5     6     7     8  \n");
        printf("    _____ _____ _____ _____ _____ _____ _____ _____\n");
        printf("1  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", plateau[0][0].piece, plateau[0][1].piece, plateau[0][2].piece, plateau[0][3].piece, plateau[0][4].piece, plateau[0][5].piece, plateau[0][6].piece, plateau[0][7].piece);
        printf("   |_____|_____|_____|_____|_____|_____|_____|_____|\n");
        printf("2  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", plateau[1][0].piece, plateau[1][1].piece, plateau[1][2].piece, plateau[1][3].piece, plateau[1][4].piece, plateau[1][5].piece, plateau[1][6].piece, plateau[1][7].piece);
        printf("   |_____|_____|_____|_____|_____|_____|_____|_____|\n");
        printf("3  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", plateau[2][0].piece, plateau[2][1].piece, plateau[2][2].piece, plateau[2][3].piece, plateau[2][4].piece, plateau[2][5].piece, plateau[2][6].piece, plateau[2][7].piece);
        printf("   |_____|_____|_____|_____|_____|_____|_____|_____|\n");
        printf("4  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", plateau[3][0].piece, plateau[3][1].piece, plateau[3][2].piece, plateau[3][3].piece, plateau[3][4].piece, plateau[3][5].piece, plateau[3][6].piece, plateau[3][7].piece);
        printf("   |_____|_____|_____|_____|_____|_____|_____|_____|\n");
        printf("5  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", plateau[4][0].piece, plateau[4][1].piece, plateau[4][2].piece, plateau[4][3].piece, plateau[4][4].piece, plateau[4][5].piece, plateau[4][6].piece, plateau[4][7].piece);
        printf("   |_____|_____|_____|_____|_____|_____|_____|_____|\n");
        printf("6  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", plateau[5][0].piece, plateau[5][1].piece, plateau[5][2].piece, plateau[5][3].piece, plateau[5][4].piece, plateau[5][5].piece, plateau[5][6].piece, plateau[5][7].piece);
        printf("   |_____|_____|_____|_____|_____|_____|_____|_____|\n");
        printf("7  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", plateau[6][0].piece, plateau[6][1].piece, plateau[6][2].piece, plateau[6][3].piece, plateau[6][4].piece, plateau[6][5].piece, plateau[6][6].piece, plateau[6][7].piece);
        printf("   |_____|_____|_____|_____|_____|_____|_____|_____|\n");
        printf("8  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", plateau[7][0].piece, plateau[7][1].piece, plateau[7][2].piece, plateau[7][3].piece, plateau[7][4].piece, plateau[7][5].piece, plateau[7][6].piece, plateau[7][7].piece);
        printf("   |_____|_____|_____|_____|_____|_____|_____|_____|\n");

    }
        //affichage du plateau après déplacement noir en bas:
    else{

        printf("      8     7     6     5     4     3     2     1  \n");
        printf("    _____ _____ _____ _____ _____ _____ _____ _____\n");
        printf("8  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", plateau[7][7].piece, plateau[7][6].piece, plateau[7][5].piece, plateau[7][4].piece, plateau[7][3].piece, plateau[7][2].piece, plateau[7][1].piece, plateau[7][0].piece);
        printf("   |_____|_____|_____|_____|_____|_____|_____|_____|\n");
        printf("7  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", plateau[6][7].piece, plateau[6][6].piece, plateau[6][5].piece, plateau[6][4].piece, plateau[6][3].piece, plateau[6][2].piece, plateau[6][1].piece, plateau[6][0].piece);
        printf("   |_____|_____|_____|_____|_____|_____|_____|_____|\n");
        printf("6  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", plateau[5][7].piece, plateau[5][6].piece, plateau[5][5].piece, plateau[5][4].piece, plateau[5][3].piece, plateau[5][2].piece, plateau[5][1].piece, plateau[5][0].piece);
        printf("   |_____|_____|_____|_____|_____|_____|_____|_____|\n");
        printf("5  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", plateau[4][7].piece, plateau[4][6].piece, plateau[4][5].piece, plateau[4][4].piece, plateau[4][3].piece, plateau[4][2].piece, plateau[4][1].piece, plateau[4][0].piece);
        printf("   |_____|_____|_____|_____|_____|_____|_____|_____|\n");
        printf("4  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", plateau[3][7].piece, plateau[3][6].piece, plateau[3][5].piece, plateau[3][4].piece, plateau[3][3].piece, plateau[3][2].piece, plateau[3][1].piece, plateau[3][0].piece);
        printf("   |_____|_____|_____|_____|_____|_____|_____|_____|\n");
        printf("3  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", plateau[2][7].piece, plateau[2][6].piece, plateau[2][5].piece, plateau[2][4].piece, plateau[2][3].piece, plateau[2][2].piece, plateau[2][1].piece, plateau[2][0].piece);
        printf("   |_____|_____|_____|_____|_____|_____|_____|_____|\n");
        printf("2  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", plateau[1][7].piece, plateau[1][6].piece, plateau[1][5].piece, plateau[1][4].piece, plateau[1][3].piece, plateau[1][2].piece, plateau[1][1].piece, plateau[1][0].piece);
        printf("   |_____|_____|_____|_____|_____|_____|_____|_____|\n");
        printf("1  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", plateau[0][7].piece, plateau[0][6].piece, plateau[0][5].piece, plateau[0][4].piece, plateau[0][3].piece, plateau[0][2].piece, plateau[0][1].piece, plateau[0][0].piece);
        printf("   |_____|_____|_____|_____|_____|_____|_____|_____|\n");

    }

}

void afficherPlateauxCouleur(Piece plateau[DIMENSION][DIMENSION], const int nombreDeCoup){
    int i= 0, j= 0 ;

    //affichage du plateau (noir en bas):
    if(nombreDeCoup % 2 == 1){
        printf("noir en bas\n");
        printf("    _____ _____ _____ _____ _____ _____ _____ _____ \n");
        for(i= 0; i<=7; i++){
            // affiche le numero de ligne:
            printf("%d  |", i+ 1);

            // affiche les cases:
            for( j= 7; j>= 0; j--){

                //si joueur blanc:
                if(plateau[i][j].equipe == 1){
                    // affiche de couleur jaune:
                    jaune();
                    printf("  %c  ", plateau[i][j].piece);

                    // remet la couleur de base:
                    resetCouleur();

                    // dessine la barre:
                    printf("|");
                }

                // si joueur noir:
                else if( plateau[i][j].equipe == 2){
                    // affiche de couleur violet:
                    violet();
                    printf("  %c  ", plateau[i][j].piece);

                    // remet la couleur de base:
                    resetCouleur();

                    // dessine la barre:
                    printf("|");
                }

                // si la case est vide:
                else{
                    // affiche du vide sans couleur :
                    printf("     ");

                    // dessine la barre:
                    printf("|");
                }

            }
            // va à la ligne:
            printf("\n");

            // affiche le bas:
            printf("   |_____|_____|_____|_____|_____|_____|_____|_____|\n");
        }
        printf("      H     G     F     E     D     C     B     A  \n");
    }

        //affichage du plateau  (blanc en bas):
    else{
        printf("blanc en bas\n");
        printf("    _____ _____ _____ _____ _____ _____ _____ _____\n");
        for(i= 7; i>=0; i--){
            // affiche le numero de ligne:
            printf("%d  |", i+1);

            // affiche les cases:
            for(j= 0; j<= 7; j++){

                //si joueur blanc:
                if(plateau[i][j].equipe == 1){
                    // affiche de couleur jaune:
                    jaune();
                    printf("  %c  ", plateau[i][j].piece);

                    // remet la couleur de base:
                    resetCouleur();

                    // dessine la barre:
                    printf("|");
                }

                    // si joueur noir:
                else if( plateau[i][j].equipe == 2){
                    // affiche de couleur violet:
                    violet();
                    printf("  %c  ", plateau[i][j].piece);

                    // remet la couleur de base:
                    resetCouleur();

                    // dessine la barre:
                    printf("|");
                }

                // si la case est vide:
                else{
                    // affiche du vide sans couleur :
                    printf("     ");

                    // dessine la barre:
                    printf("|");
                }

            }
            // va à la ligne:
            printf("\n");

            // affiche le bas:
            printf("   |_____|_____|_____|_____|_____|_____|_____|_____|\n");

        }
        printf("      A     B     C     D     E     F     G     H  \n");
    }

}





void afficherCoupCouleur(Piece plateau[DIMENSION][DIMENSION], const int nombreDeCoup, int ligneActuelle, int colonneActuelle, Coordonnee tableauxMouvementPossible[]){
    int i= 0, j= 0 ;
    int fondColorer = 0; // si le fond est colore prend 1 sinon prend 0

    printf("%d  ",tableauxMouvementPossible[0].ligne);
    printf("%d \n",tableauxMouvementPossible[0].colonne);
    printf("%d   ",tableauxMouvementPossible[1].ligne);
    printf("%d \n",tableauxMouvementPossible[1].colonne);
    printf("%d   ",tableauxMouvementPossible[6].ligne);
    printf("%d \n",tableauxMouvementPossible[6].colonne);
    printf("%d   ",tableauxMouvementPossible[7].ligne);
    printf("%d \n",tableauxMouvementPossible[7].colonne);


    //affichage du plateau avec la case actuelle selectionner encadre et les coup possible en fond vert (noir en bas) :
    if(nombreDeCoup % 2 == 1){
        printf("noir en bas\n");
        printf("    _____ _____ _____ _____ _____ _____ _____ _____ \n");
        for(i= 0; i<=7; i++){
            // affiche le numero de ligneActuelle:
            printf("%d  |", i+1 );

            // affiche les cases:
            for(j= 7; j>= 0; j--){

                //si joueur blanc:
                if(plateau[i][j].equipe == 1){

                    // si c'est la piece selectionner on encadre :
                    if(i == ligneActuelle && j == colonneActuelle){
                        encadreCase();
                    }

                    // si c'est un coup possible on met le fond en vert:
                    for(int k= 0; k< 30; k++){
                       if((tableauxMouvementPossible[k]).ligne == i && (tableauxMouvementPossible[k]).colonne == j){
                           // met le fond en vert:
                           fondVert();
                           fondColorer = 1 ;
                       }
                    }

                    // affiche de couleur jaune si le fond n'est pas colorer :
                    if( fondColorer != 1){
                        jaune();
                    }

                    // affiche la piece :
                    printf("  %c  ", plateau[i][j].piece);

                    // remet la couleur de base:
                    resetCouleur();

                    // dessine la barre:
                    printf("|");

                    // reinitialise fondColorer:
                    fondColorer= 0;
                }

                //si joueur noir:
                else if(plateau[i][j].equipe == 2){


                    // si c'est un coup possible on met le fond en vert:
                    for(int k= 0; k< 30; k++){
                        if((tableauxMouvementPossible[k]).ligne == i && (tableauxMouvementPossible[k]).colonne == j){
                            // met le fond en vert:
                            fondVert();
                            fondColorer = 1 ;
                        }
                    }

                    // affiche de couleur violet si le fond n'est pas colorer :
                    if( fondColorer != 1){
                        violet();
                    }

                    // si c'est la piece selectionner on encadre :
                    if(i == ligneActuelle && j == colonneActuelle){
                        encadreCase();
                    }

                    // affiche la piece :
                    printf("  %c  ", plateau[i][j].piece);

                    // remet la couleur de base:
                    resetCouleur();

                    // dessine la barre:
                    printf("|");

                    // reinitialise fondColorer:
                    fondColorer= 0;
                }

                    // si la case est vide:
                else{
                    // si c'est un coup possible on met le fond en vert:
                    for(int k= 0; k< 30; k++){
                        if((tableauxMouvementPossible[k]).ligne == i && (tableauxMouvementPossible[k]).colonne == j){
                            // met le fond en vert:
                            fondVert();
                            fondColorer = 1 ;
                        }
                    }

                    // affiche du vide :
                    printf("     ");

                    // redefinit couleur d'origine:
                    resetCouleur();

                    // dessine la barre:
                    printf("|");

                    // reinitialise fondColorer:
                    fondColorer= 0;

                }

            }
            // va à la ligneActuelle:
            printf("\n");

            // affiche le bas:
            printf("   |_____|_____|_____|_____|_____|_____|_____|_____|\n");
        }

        printf("      H     G     F     E     D     C     B     A  \n");
    }



    //affichage du plateau avec case selectionner, coup possible (blanc en bas):
    else{
        printf("blanc en bas\n");
        printf("    _____ _____ _____ _____ _____ _____ _____ _____\n");
        for(i= 7; i>=0; i--){
            // affiche le numero de ligneActuelle:
            printf("%d  |", i+1);

            // affiche les cases:
            for(j= 0; j<= 7; j++){

                //si joueur blanc:
                if(plateau[i][j].equipe == 1){

                    // si c'est la piece selectionner on encadre :
                    if(i == ligneActuelle && j == colonneActuelle){
                        encadreCase();
                        fondColorer= 1;
                    }

                    // si c'est un coup possible on met le fond en vert:
                    for(int k= 0; k< 31; k++){
                        if((tableauxMouvementPossible[k]).ligne == i && (tableauxMouvementPossible[k]).colonne == j){
                            // met le fond en vert:
                            fondVert();
                            fondColorer = 1 ;

                        }
                    }

                    // affiche de couleur jaune si le fond n'est pas colorer :
                    if( fondColorer != 1){
                        jaune();
                    }

                    // affiche la piece :
                    printf("  %c  ", plateau[i][j].piece);

                    // remet la couleur de base:
                    resetCouleur();

                    // dessine la barre:
                    printf("|");

                    // reinitialise fondColorer:
                    fondColorer= 0;
                }

                    // si joueur noir:
                else if(plateau[i][j].equipe == 2){

                    // si c'est la piece selectionner on encadre :
                    if(i == ligneActuelle && j == colonneActuelle){
                        encadreCase();
                    }

                    // si c'est un coup possible on met le fond en vert:
                    for(int k= 0; k< 30; k++){
                        if((tableauxMouvementPossible[k]).ligne == i && (tableauxMouvementPossible[k]).colonne == j){
                            // met le fond en vert:
                            fondVert();
                            fondColorer = 1 ;
                        }
                    }

                    // affiche de couleur violet si le fond n'est pas colorer :
                    if( fondColorer != 1){
                        violet();
                    }

                    // affiche la piece :
                    printf("  %c  ", plateau[i][j].piece);

                    // remet la couleur de base:
                    resetCouleur();

                    // dessine la barre:
                    printf("|");

                    // reinitialise fondColorer:
                    fondColorer= 0;
                }

                    // si la case est vide:
                else{
                    // si c'est un coup possible on met le fond en vert:
                    for(int k= 0; k< 30; k++){
                        if((tableauxMouvementPossible[k]).ligne == i && (tableauxMouvementPossible[k]).colonne == j){
                            // met le fond en vert:
                            fondVert();
                            fondColorer = 1 ;
                        }
                    }

                    // affiche du vide couleur :
                    printf("     ");

                    // remet la couleur de base:
                    resetCouleur();

                    // dessine la barre:
                    printf("|");

                    // reinitialise fondColorer:
                    fondColorer= 0;

                }

            }
            // va à la ligneActuelle:
            printf("\n");

            // affiche le bas:
            printf("   |_____|_____|_____|_____|_____|_____|_____|_____|\n");

        }
        printf("      A     B     C     D     E     F     G     H  \n");
    }

}