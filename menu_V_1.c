

//
// Created by Paul on 22/11/2021.
//
//
// Created by mbmar on 16/11/2021.
//
#include "menu_V_1.h"
#include <stdio.h>
#include "Enregistrer.h"
#include "afficherPlateaux.h"
#include "mouvement.h"


//void Clear()
//{
//    cout << "\x1B[2J\x1B[H";
//}




void menu_V_1(){
    Coordonnee tableauMouvementsPossibles[30];
    int  i= 0;
// initialisation tableauMouvementPossible:
    for (i = 0; i < 30; i++){
        tableauMouvementsPossibles[i].colonne=-1;
        tableauMouvementsPossibles[i].ligne=-1;
    }



    Piece plateau[DIMENSION][DIMENSION] = {{0}};
    Piece plateauVide[1][1] = {{0}};

    int menu = 0;
    int nombreCoups = 0;


    // // // // // // // // // // BLANCS // // // // // // // // // //
    Piece pionBlanc1 = {'p', 1};
    Piece pionBlanc2 = {'p', 1};
    Piece pionBlanc3 = {'p', 1};
    Piece pionBlanc4 = {'p', 1};
    Piece pionBlanc5 = {'p', 1};
    Piece pionBlanc6 = {'p', 1};
    Piece pionBlanc7 = {'p', 1};
    Piece pionBlanc8 = {'p', 1};
    Piece fouBlanc1 = {'f', 1};
    Piece fouBlanc2 = {'f', 1};
    Piece tourBlanc1 = {'t', 1};
    Piece tourBlanc2 = {'t', 1};
    Piece cavalierBlanc1 = {'c', 1};
    Piece cavalierBlanc2 = {'c', 1};
    Piece reineBlanc = {'r', 1};
    Piece roiBlanc = {'R', 1};


    // // // // // // // // // // NOIRS // // // // // // // // // //
    Piece pionNoir1 = {'p', 2};
    Piece pionNoir2 = {'p', 2};
    Piece pionNoir3 = {'p', 2};
    Piece pionNoir4 = {'p', 2};
    Piece pionNoir5 = {'p', 2};
    Piece pionNoir6 = {'p', 2};
    Piece pionNoir7 = {'p', 2};
    Piece pionNoir8 = {'p', 2};
    Piece fouNoir1 = {'f', 2};
    Piece fouNoir2 = {'f', 2};
    Piece tourNoir1 = {'t', 2};
    Piece tourNoir2 = {'t', 2};
    Piece cavalierNoir1 = {'c', 2};
    Piece cavalierNoir2 = {'c', 2};
    Piece reineNoir = {'r', 2};
    Piece roiNoir = {'R', 2};


    // // // // // // // // // // POSITION INITIALE // // // // // // // // // //
    plateau[0][0] = tourBlanc1;
    plateau[0][1] = cavalierBlanc1;
    plateau[0][2] = fouBlanc1;
    plateau[0][3] = reineBlanc;
    plateau[0][4] = roiBlanc;
    plateau[0][5] = fouBlanc2;
    plateau[0][6] = cavalierBlanc2;
    plateau[0][7] = tourBlanc2;
    plateau[1][0] = pionBlanc1;
    plateau[1][1] = pionBlanc2;
    plateau[1][2] = pionBlanc3;
    plateau[1][3] = pionBlanc4;
    plateau[1][4] = pionBlanc5;
    plateau[1][5] = pionBlanc6;
    plateau[1][6] = pionBlanc7;
    plateau[1][7] = pionBlanc8;

    plateau[7][0] = tourNoir1;
    plateau[7][1] = cavalierNoir1;
    plateau[7][2] = fouNoir1;
    plateau[7][3] = reineNoir;
    plateau[7][4] = roiNoir;
    plateau[7][5] = fouNoir2;
    plateau[7][6] = cavalierNoir2;
    plateau[7][7] = tourNoir2;
    plateau[6][0] = pionNoir1;
    plateau[6][1] = pionNoir2;
    plateau[6][2] = pionNoir3;
    plateau[6][3] = pionNoir4;
    plateau[6][4] = pionNoir5;
    plateau[6][5] = pionNoir6;
    plateau[6][6] = pionNoir7;
    plateau[6][7] = pionNoir8;




    do {

        printf("\nMenu : \n");
        printf("1) Nouvelle partie \n");
        printf("2) Reprendre la partie en cours \n");
        printf("3) Sauvegarder la partie en cours \n");
        printf("4) Reprendre une partie sauvegardee \n");
        printf("5) Regles du jeu \n");
        printf("0) Quitter \n>");

        scanf(" %d", &menu);

        switch (menu) {

            case 1 : {

                // NOUVELLE PARTIE:

                // vide entierement le plateaux actuelle:
                for( int i= 0; i< DIMENSION; i++){
                    for(int j= 0; j< DIMENSION; j++){
                        plateau[i][j] = plateauVide[0][0];
                    }
                }


                //remet les joueurs dans leur position initiale:


                // // // // // // // // // // POSITION INITIALE // // // // // // // // // //
                plateau[0][0] = tourBlanc1;
                plateau[0][1] = cavalierBlanc1;
                plateau[0][2] = fouBlanc1;
                plateau[0][3] = reineBlanc;
                plateau[0][4] = roiBlanc;
                plateau[0][5] = fouBlanc2;
                plateau[0][6] = cavalierBlanc2;
                plateau[0][7] = tourBlanc2;
                plateau[1][0] = pionBlanc1;
                plateau[1][1] = pionBlanc2;
                plateau[1][2] = pionBlanc3;
                plateau[1][3] = pionBlanc4;
                plateau[1][4] = pionBlanc5;
                plateau[1][5] = pionBlanc6;
                plateau[1][6] = pionBlanc7;
                plateau[1][7] = pionBlanc8;

                plateau[7][0] = tourNoir1;
                plateau[7][1] = cavalierNoir1;
                plateau[7][2] = fouNoir1;
                plateau[7][3] = reineNoir;
                plateau[7][4] = roiNoir;
                plateau[7][5] = fouNoir2;
                plateau[7][6] = cavalierNoir2;
                plateau[7][7] = tourNoir2;
                plateau[6][0] = pionNoir1;
                plateau[6][1] = pionNoir2;
                plateau[6][2] = pionNoir3;
                plateau[6][3] = pionNoir4;
                plateau[6][4] = pionNoir5;
                plateau[6][5] = pionNoir6;
                plateau[6][6] = pionNoir7;
                plateau[6][7] = pionNoir8;

                // mise a jour du nombre de coup:
                nombreCoups= 0;

                printf("Nouvelle partie \n");

                // joue :
                jouer(&nombreCoups, plateau);

                break;
            }// fin case 1 : jouer

            case 2 : {

                printf("Reprendre la partie en cours \n");
                jouer(&nombreCoups, plateau);

                break;
            }//fin case 2 : reprendre partie en cours

            case 3 : {

                selectionnerSauvegarde(plateau, nombreCoups);

                break;
            }//fin case 3 : sauvegarder partie en cours

            case 4 : {

                printf("Reprendre une partie sauvegardee \n");
                chargerSauvegarde(plateau, &nombreCoups);
                break;
            }

            case 5 : {

                printf("Regles des Echecs : \n");

                break;
            }//fin case 5 : règles

            case 0 : {

                //quitter
                printf("Au revoir ! \n");

                break;
            }//fin case 0 : quitter

            default : {

                printf("Saisie non valide, veuillez recommencer : \n");

                break;
            }//fin default

        }//sortie du switch case (menu)

    } while (menu != 0);


    return;
}




int conversionLettre(const char* coordonnees){

    if(coordonnees[0] == 'a' || coordonnees[0] == 'A')
        return 0;
    else if(coordonnees[0] == 'b' || coordonnees[0] == 'B')
        return 1;
    else if(coordonnees[0] == 'c' || coordonnees[0] == 'C')
        return 2;
    else if(coordonnees[0] == 'd' || coordonnees[0] == 'D')
        return 3;
    else if(coordonnees[0] == 'e' || coordonnees[0] == 'E')
        return 4;
    else if(coordonnees[0] == 'f' || coordonnees[0] == 'F')
        return 5;
    else if(coordonnees[0] == 'g' || coordonnees[0] == 'G')
        return 6;
    else if(coordonnees[0] == 'h' || coordonnees[0] == 'H')
        return 7;
}


int conversionChiffre(const char* coordonnees) {

    if (coordonnees[1] == '1')
        return 0;
    else if (coordonnees[1] == '2')
        return 1;
    else if (coordonnees[1] == '3')
        return 2;
    else if (coordonnees[1] == '4')
        return 3;
    else if (coordonnees[1] == '5')
        return 4;
    else if (coordonnees[1] == '6')
        return 5;
    else if (coordonnees[1] == '7')
        return 6;
    else if (coordonnees[1] == '8')
        return 7;
}


void jouer( int* pNombreCoups, Piece plateau[DIMENSION][DIMENSION]) {

    // variable :
    int poursuivre = 0;
    int deplacer = 0;
    int mouvementPossible = 0;

    int numeroColonneActuelle = 0;
    int numeroLigneActuelle = 0;
    int numeroColonneFuture = 0;
    int numeroLigneFuture = 0;

    char coordonnees[3] = {0};

    // creation du plateaux vide:
    Piece plateauVide[1][1] = {{0}};

    // creation du tableaux des coups possibles:
    Coordonnee tableauMouvementsPossibles[30];
    int affichecoordonne = 0, i = 0;
    //initialise tout :
    for (i = 0; i < 30; i++) {
        tableauMouvementsPossibles[i].colonne = -1;
        tableauMouvementsPossibles[i].ligne = -1;
    }


    do {

        printf("Tapez 1 pour poursuivre et 0 pour revenir au menu \n>");
        scanf(" %d", &poursuivre);

        switch (poursuivre) {
            //fonction jouer
            case 1 : {
                //poursuivre la partie en cours
                switch (*pNombreCoups % 2) {
                    case 0 : {
                        //les blancs jouent
                        // // il faut vérifier qu'il y a bien une pièce saisie
                        // // et qu'elle est bien de la bonne couleur (équipe == 1)

                        printf("\nTour des blancs : \n");

                        // affiche le plateaux:
                        afficherPlateauxCouleur( plateau, *pNombreCoups);
                        do {
                            do {
                                //sélection de la pièce
                                printf("Selection : lettre + chiffre (E2) \n>");
                                scanf(" %s", coordonnees);
                                numeroColonneActuelle = conversionLettre(coordonnees);
                                numeroLigneActuelle = conversionChiffre(coordonnees);


                                if (plateau[ numeroLigneActuelle][ numeroColonneActuelle].equipe != 1){
                                    printf("Case selectionnee non valide. \n");
                                }


                            } while (plateau[ numeroLigneActuelle][ numeroColonneActuelle].equipe != 1);

                            // calcul les coups possible :
                            movePossible(plateau, tableauMouvementsPossibles, numeroLigneActuelle, numeroColonneActuelle);
                            //affichage coups disponibles:
                            afficherCoupCouleur(plateau, *pNombreCoups, numeroLigneActuelle,  numeroColonneActuelle, tableauMouvementsPossibles);

                            //demande à l'utilisateur de confirmer pièce sélectionnée
                            printf("1 pour valider la piece, 0 pour changer \n>");
                            scanf(" %d", &deplacer);


                        } while (deplacer != 1);


                        do {

                            //saisie du déplacement de le pièce sélectionnée
                            printf("Deplacement : numero de colonne, numero de ligne \n");
                            scanf(" %s", coordonnees);
                            numeroColonneFuture = conversionLettre(coordonnees);
                            numeroLigneFuture = conversionChiffre(coordonnees);

                            // mouvement possible? :
                            for(int k= 0; k< 30; k++){
                                if((tableauMouvementsPossibles[k]).ligne == numeroLigneFuture && (tableauMouvementsPossibles[k]).colonne == numeroColonneFuture){
                                    // met a jour l'etat du mouvementpossible :
                                    mouvementPossible= 1;
                                }
                            }

                            // effectue le mouvement si il est possible:
                            if(mouvementPossible == 1){
                                plateau[numeroLigneFuture][numeroColonneFuture] = plateau[numeroLigneActuelle][numeroColonneActuelle];
                                plateau[numeroLigneActuelle][numeroColonneActuelle] = plateauVide[0][0];
                                        }


                        } while (mouvementPossible != 1);

                        // mise a jour de mouvement possible :
                        mouvementPossible= 0;

                        break;
                    }//fin du tour des blancs

                    case 1 : {
                        //les noirs jouent

                        printf("\nTour des noirs : \n");

                        // affiche le plateaux:
                        afficherPlateauxCouleur( plateau, *pNombreCoups);

                        do {

                            do {

                                //sélection de la pièce
                                printf("Selection : numero de colonne, numero de ligne \n");
                                scanf(" %s", coordonnees);
                                numeroColonneActuelle = conversionLettre(coordonnees);
                                numeroLigneActuelle = conversionChiffre(coordonnees);


                                if (plateau[numeroLigneActuelle][numeroColonneActuelle].equipe != 2){
                                    printf("Case selectionnee non valide. \n");
                                }
                            } while (plateau[numeroLigneActuelle][numeroColonneActuelle].equipe != 2);

                            // calcul les coups possible :
                            movePossible(plateau, tableauMouvementsPossibles, numeroLigneActuelle, numeroColonneActuelle);

                            //affichage coups disponibles:
                            afficherCoupCouleur(plateau, *pNombreCoups, numeroLigneActuelle,  numeroColonneActuelle, tableauMouvementsPossibles);

                            //demande à l'utilisateur de confirmer pièce sélectionnée
                            printf("1 pour valider la piece, 0 pour changer \n>");
                            scanf(" %d", &deplacer);



                        } while (deplacer != 1);

                        do {

                            //saisie du déplacement de le pièce sélectionnée
                            printf("Deplacement : numero de colonne, numero de ligne \n");
                            scanf(" %s", coordonnees);
                            numeroColonneFuture = conversionLettre(coordonnees);
                            numeroLigneFuture = conversionChiffre(coordonnees);

                            // mouvement possible? :
                            for(int k= 0; k< 30; k++){
                                if((tableauMouvementsPossibles[k]).ligne == numeroLigneFuture && (tableauMouvementsPossibles[k]).colonne == numeroColonneFuture){
                                    // met a jour l'etat du mouvementpossible :
                                    mouvementPossible= 1;
                                }
                            }

                            // effectue le mouvement si il est possible:
                            if(mouvementPossible == 1){
                                plateau[numeroLigneFuture][numeroColonneFuture] = plateau[numeroLigneActuelle][numeroColonneActuelle];
                                plateau[numeroLigneActuelle][numeroColonneActuelle] = plateauVide[0][0];
                            }


                        } while (mouvementPossible != 1);

                        // mise a jour de mouvement possible :
                        mouvementPossible= 0;

                        break;
                    }

                    default : {
                        break;
                    }

                }

                //affichage du plateau après déplacement :
                afficherPlateauxCouleur(plateau, *pNombreCoups);

                // mise a jour du nombre de coup:
                (*pNombreCoups)++;


                break;


            }//fin switch case (poursuivre)

            case 0 : {

                //arreter la partie en cours et retour au menu

                break;
            }

            default :
                printf("La saisie n'est pas valide. \n");

                break;
        }

    }while (poursuivre != 0);


}