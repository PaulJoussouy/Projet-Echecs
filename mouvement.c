//
// Created by Paul on 22/11/2021.
//

#include "mouvement.h"
#include <stdio.h>
#include "afficherPlateaux.h"

void movePossible(Piece plateau[8][8],Coordonnee tableauMouvementPossible[30],int ligne, int colonne) {
    int i = 0;
    int avanceOuRecule = ((plateau[ligne][colonne].equipe == 1) ? 1 : -1);
    int compteurCoup = 0;
    int diag = 0;
    int horizontaleEtVerticale = 0;
    int remplissage=0;
    for (remplissage=0;remplissage<31;remplissage++){
        tableauMouvementPossible[remplissage].colonne=-1;
        tableauMouvementPossible[remplissage].ligne=-1;
    }
    switch (plateau[ligne][colonne].piece) {
        case 'p': {
            //mange en diagonale,, peut à la case de départ sauter une case et avancer;
            if (plateau[ligne + avanceOuRecule][colonne].piece == 0) {
                //avancer simplement il faut que il n'y est pas de piece dans le sens(si blanc avnce ligne croissante si noir ligne décroissante)
                // ou le point peut avancer n'avance que d'une case
                tableauMouvementPossible[i].ligne = ligne + avanceOuRecule;
                tableauMouvementPossible[i].colonne = colonne;
                i += 1;
            }
            if (colonne > 0) {
                if (plateau[ligne + avanceOuRecule][colonne - 1].equipe !=
                    plateau[ligne][colonne].equipe
                    && plateau[ligne + avanceOuRecule][colonne - 1].equipe != 0) {
                    //manger vers la gauche(vision cotés blanc) condition piece sur la diagonale gauche est adversaire
                    tableauMouvementPossible[i].ligne = ligne + avanceOuRecule;
                    tableauMouvementPossible[i].colonne = colonne - 1;
                    i += 1;
                }
            }
            if (colonne < 7) {
                if (plateau[ligne + avanceOuRecule][colonne + 1].equipe !=
                    plateau[ligne][colonne].equipe
                    && plateau[ligne + avanceOuRecule][colonne + 1].equipe != 0) {
                    //manger vers la droite(vision cotés blanc)
                    tableauMouvementPossible[i].ligne = ligne + avanceOuRecule;
                    tableauMouvementPossible[i].colonne = colonne + 1;
                    i += 1;
                }
            }
            if (plateau[ligne + 2 * avanceOuRecule][colonne].piece == 0
                && ligne == (plateau[ligne][colonne].equipe == 1 ? 1 : 6)) {
                // case à 2 ligne de différence vide et on est sur la ligne de départ(ligne 2 pour les blanc 7 pour les noirs
                tableauMouvementPossible[i].ligne = ligne + 2 * avanceOuRecule;
                tableauMouvementPossible[i].colonne = colonne;
                i += 1;
            }
            break;
        }
        case 'f': {
            compteurCoup = 0;
            int continueDeCompter1 = 0;
            int continueDeCompter2 = 0;
            int continueDeCompter3 = 0;
            int continueDeCompter4 = 0;
            for (diag = 1; diag < 8; diag++) {
                if (plateau[ligne][colonne].equipe == 1) {
                    //diagonale haute droite du fou blanc
                    if (ligne + diag > 7 || colonne + diag > 7) {
                        continueDeCompter1 = 1;
                    }
                    if (ligne + diag < 7 &&
                        colonne + diag < 7) {//c pour éviter que la fonction n'entre des valeur qui font tout crasher
                        if (plateau[ligne + diag][colonne + diag].equipe == plateau[ligne][colonne].equipe) {
                            continueDeCompter1 = 1;
                        }
                    }

                    if (continueDeCompter1 == 0) {
                        tableauMouvementPossible[compteurCoup].ligne = ligne + diag;
                        tableauMouvementPossible[compteurCoup].colonne = colonne + diag;
                        compteurCoup = compteurCoup + 1;
                    }
                    if (ligne + diag < 7 && colonne + diag < 7) {
                        if (plateau[ligne + diag][colonne + diag].equipe == 2) {
                            continueDeCompter1 = 1;
                        }
                    }

                    //diagonale gauche haute du fou blanc
                    if (ligne + diag > 7 || colonne - diag < 0) {
                        continueDeCompter2 = 1;
                    }
                    if (ligne + diag < 7 && colonne + diag > 0) {
                        if (plateau[ligne + diag][colonne - diag].equipe == plateau[ligne][colonne].equipe) {
                            continueDeCompter2 = 1;
                        }
                    }
                    if (continueDeCompter2 == 0) {
                        tableauMouvementPossible[compteurCoup].ligne = ligne + diag;
                        tableauMouvementPossible[compteurCoup].colonne = colonne - diag;
                        compteurCoup = compteurCoup + 1;
                    }
                    if (ligne + diag < 7 && colonne + diag > 0) {
                        if (plateau[ligne + diag][colonne - diag].equipe == 2) {
                            continueDeCompter2 = 1;
                        }
                    }

                    //diagonale basse droite du fou blanc
                    if (ligne - diag < 0 || colonne - diag < 0) {
                        continueDeCompter3 = 1;
                    }
                    if (ligne + diag > 0 && colonne + diag > 0) {
                        if (plateau[ligne - diag][colonne - diag].equipe == plateau[ligne][colonne].equipe) {
                            continueDeCompter3 = 1;
                        }
                    }
                    if (continueDeCompter3 == 0) {
                        tableauMouvementPossible[compteurCoup].ligne = ligne - diag;
                        tableauMouvementPossible[compteurCoup].colonne = colonne - diag;
                        compteurCoup = compteurCoup + 1;
                    }
                    if (ligne + diag > 0 && colonne + diag > 0) {
                        if (plateau[ligne - diag][colonne - diag].equipe == 2) {
                            continueDeCompter3 = 1;
                        }
                    }

                    //diagonale basse droite du fou blanc
                    if (ligne - diag < 0 || colonne - diag > 7) {
                        continueDeCompter4 = 1;
                    }
                    if (ligne + diag > 0 && colonne + diag < 7) {
                        if (plateau[ligne - diag][colonne + diag].equipe == plateau[ligne][colonne].equipe) {
                            continueDeCompter4 = 1;
                        }
                    }
                    if (continueDeCompter4 == 0) {
                        tableauMouvementPossible[compteurCoup].ligne = ligne - diag;
                        tableauMouvementPossible[compteurCoup].colonne = colonne + diag;
                        compteurCoup = compteurCoup + 1;
                    }
                    if (ligne + diag > 0 && colonne + diag < 7) {
                        if (plateau[ligne - diag][colonne + diag].equipe == 2) {
                            continueDeCompter4 = 1;
                        }
                    }
                }

                if (plateau[ligne][colonne].equipe == 2) {
                    //diagonale basse gauche du fou noir
                    if (ligne + diag > 7 || colonne + diag > 7) {
                        continueDeCompter1 = 1;
                    }
                    if (ligne + diag <= 7 &&
                        colonne + diag <= 7) {//c pour éviter que la fonction n'entre des valeur qui font tout crasher
                        if (plateau[ligne + diag][colonne + diag].equipe == plateau[ligne][colonne].equipe) {
                            continueDeCompter1 = 1;
                        }
                    }

                    if (continueDeCompter1 == 0) {
                        tableauMouvementPossible[compteurCoup].ligne = ligne + diag;
                        tableauMouvementPossible[compteurCoup].colonne = colonne + diag;
                        compteurCoup = compteurCoup + 1;
                    }
                    if (ligne + diag <= 7 && colonne + diag <= 7) {
                        if (plateau[ligne + diag][colonne + diag].equipe == 1) {
                            continueDeCompter1 = 1;
                        }
                    }

                    //diagonale droite basse du fou noir
                    if (ligne + diag > 7 || colonne - diag < 0) {
                        continueDeCompter2 = 1;
                    }
                    if (ligne + diag <= 7 && colonne + diag >= 0) {
                        if (plateau[ligne + diag][colonne - diag].equipe == plateau[ligne][colonne].equipe) {
                            continueDeCompter2 = 1;
                        }
                    }
                    if (continueDeCompter2 == 0) {
                        tableauMouvementPossible[compteurCoup].ligne = ligne + diag;
                        tableauMouvementPossible[compteurCoup].colonne = colonne - diag;
                        compteurCoup = compteurCoup + 1;
                    }
                    if (ligne + diag <= 7 && colonne + diag >= 0) {
                        if (plateau[ligne + diag][colonne - diag].equipe == 1) {
                            continueDeCompter2 = 1;
                        }
                    }

                    //diagonale haute gauche du fou noir
                    if (ligne - diag < 0 || colonne - diag < 0) {
                        continueDeCompter3 = 1;
                    }
                    if (ligne + diag >= 0 && colonne + diag >= 0) {
                        if (plateau[ligne - diag][colonne - diag].equipe == plateau[ligne][colonne].equipe) {
                            continueDeCompter3 = 1;
                        }
                    }
                    if (continueDeCompter3 == 0) {
                        tableauMouvementPossible[compteurCoup].ligne = ligne - diag;
                        tableauMouvementPossible[compteurCoup].colonne = colonne - diag;
                        compteurCoup = compteurCoup + 1;
                    }
                    if (ligne + diag >= 0 && colonne + diag >= 0) {
                        if (plateau[ligne - diag][colonne - diag].equipe == 1) {
                            continueDeCompter3 = 1;
                        }
                    }

                    //diagonale haute gauche du fou noir
                    if (ligne - diag < 0 || colonne - diag > 7) {
                        continueDeCompter4 = 1;
                    }
                    if (ligne + diag >= 0 && colonne + diag <= 7) {
                        if (plateau[ligne - diag][colonne + diag].equipe == plateau[ligne][colonne].equipe) {
                            continueDeCompter4 = 1;
                        }
                    }
                    if (continueDeCompter4 == 0) {
                        tableauMouvementPossible[compteurCoup].ligne = ligne - diag;
                        tableauMouvementPossible[compteurCoup].colonne = colonne + diag;
                        compteurCoup = compteurCoup + 1;
                    }
                    if (ligne + diag >= 0 && colonne + diag <= 7) {
                        if (plateau[ligne - diag][colonne + diag].equipe == 1) {
                            continueDeCompter4 = 1;
                        }
                    }
                }
            }
            break;
        }
        case 't': {
            compteurCoup = 0;
            int compteurDebug;
            int rencontreAdversaire = 0;
            int adversaire = (plateau[ligne][colonne].equipe == 1) ? 2 : 1;
            int direction = 1;
            //vers les ligne croissante
            while (direction <= 7) {
                if (ligne + direction > 7) {
                    break;
                }
                if (plateau[ligne + direction][colonne].equipe == plateau[ligne][colonne].equipe) {
                    break;
                }
                if (plateau[ligne + direction][colonne].equipe == adversaire) {
                    rencontreAdversaire = rencontreAdversaire + 1;
                }
                if (rencontreAdversaire == 2) {
                    break;
                }
                tableauMouvementPossible[compteurCoup].ligne = ligne + direction;
                tableauMouvementPossible[compteurCoup].colonne = colonne;
                printf("ça rentre\n");
                direction = direction + 1;
                compteurCoup = compteurCoup + 1;
            }
            //vers les ligne décroissante
            rencontreAdversaire = 0;
            direction = 1;
            while (direction <= 7) {
                if (ligne - direction < 0) {
                    break;
                }
                if (plateau[ligne - direction][colonne].equipe == plateau[ligne][colonne].equipe) {
                    break;
                }
                if (plateau[ligne - direction][colonne].equipe == adversaire) {
                    rencontreAdversaire = rencontreAdversaire + 1;
                }
                if (rencontreAdversaire == 2) {
                    break;
                }
                tableauMouvementPossible[compteurCoup].ligne = ligne - direction;
                tableauMouvementPossible[compteurCoup].colonne = colonne;

                direction = direction + 1;
                compteurCoup = compteurCoup + 1;
            }
            //vers les colonne croissante
            rencontreAdversaire = 0;
            direction = 1;
            while (direction <= 7) {
                if (colonne + direction > 7) {
                    break;
                }
                if (plateau[ligne][colonne + direction].equipe == plateau[ligne][colonne].equipe) {
                    break;
                }
                if (plateau[ligne][colonne + direction].equipe == adversaire) {
                    rencontreAdversaire = rencontreAdversaire + 1;
                }
                if (rencontreAdversaire == 2) {
                    break;
                }
                tableauMouvementPossible[compteurCoup].ligne = ligne;
                tableauMouvementPossible[compteurCoup].colonne = colonne + direction;

                direction = direction + 1;
                compteurCoup = compteurCoup + 1;
            }
            //vers les colonne decroissante
            rencontreAdversaire = 0;
            direction = 1;
            while (direction <= 7) {
                if (colonne - direction > 7) {
                    break;
                }
                if (plateau[ligne][colonne - direction].equipe == plateau[ligne][colonne].equipe) {
                    break;
                }
                if (plateau[ligne][colonne - direction].equipe == adversaire) {
                    rencontreAdversaire = rencontreAdversaire + 1;
                }
                if (rencontreAdversaire == 2) {
                    break;
                }
                tableauMouvementPossible[compteurCoup].ligne = ligne;
                tableauMouvementPossible[compteurCoup].colonne = colonne - direction;

                direction = direction + 1;
                compteurCoup = compteurCoup + 1;
            }
            break;
        }
        case 'r': {
            compteurCoup = 0;
            int continueDeCompter1 = 0;
            int continueDeCompter2 = 0;
            int continueDeCompter3 = 0;
            int continueDeCompter4 = 0;
            int compteurDebug;
            int rencontreAdversaire = 0;
            int adversaire = (plateau[ligne][colonne].equipe == 1) ? 2 : 1;
            int direction = 1;
            //vers les ligne croissante
            while (direction <= 7) {
                if (ligne + direction > 7) {
                    break;
                }
                if (plateau[ligne + direction][colonne].equipe == plateau[ligne][colonne].equipe) {
                    break;
                }
                if (plateau[ligne + direction][colonne].equipe == adversaire) {
                    rencontreAdversaire = rencontreAdversaire + 1;
                }
                if (rencontreAdversaire == 2) {
                    break;
                }
                tableauMouvementPossible[compteurCoup].ligne = ligne + direction;
                tableauMouvementPossible[compteurCoup].colonne = colonne;
                printf("ça rentre\n");
                direction = direction + 1;
                compteurCoup = compteurCoup + 1;
            }
            //vers les ligne décroissante
            rencontreAdversaire = 0;
            direction = 1;
            while (direction <= 7) {
                if (ligne - direction < 0) {
                    break;
                }
                if (plateau[ligne - direction][colonne].equipe == plateau[ligne][colonne].equipe) {
                    break;
                }
                if (plateau[ligne - direction][colonne].equipe == adversaire) {
                    rencontreAdversaire = rencontreAdversaire + 1;
                }
                if (rencontreAdversaire == 2) {
                    break;
                }
                tableauMouvementPossible[compteurCoup].ligne = ligne - direction;
                tableauMouvementPossible[compteurCoup].colonne = colonne;

                direction = direction + 1;
                compteurCoup = compteurCoup + 1;
            }
            //vers les colonne croissante
            rencontreAdversaire = 0;
            direction = 1;
            while (direction <= 7) {
                if (colonne + direction > 7) {
                    break;
                }
                if (plateau[ligne][colonne + direction].equipe == plateau[ligne][colonne].equipe) {
                    break;
                }
                if (plateau[ligne][colonne + direction].equipe == adversaire) {
                    rencontreAdversaire = rencontreAdversaire + 1;
                }
                if (rencontreAdversaire == 2) {
                    break;
                }
                tableauMouvementPossible[compteurCoup].ligne = ligne;
                tableauMouvementPossible[compteurCoup].colonne = colonne + direction;

                direction = direction + 1;
                compteurCoup = compteurCoup + 1;
            }
            //vers les colonne decroissante
            rencontreAdversaire = 0;
            direction = 1;
            while (direction <= 7) {
                if (colonne - direction > 7) {
                    break;
                }
                if (plateau[ligne][colonne - direction].equipe == plateau[ligne][colonne].equipe) {
                    break;
                }
                if (plateau[ligne][colonne - direction].equipe == adversaire) {
                    rencontreAdversaire = rencontreAdversaire + 1;
                }
                if (rencontreAdversaire == 2) {
                    break;
                }
                tableauMouvementPossible[compteurCoup].ligne = ligne;
                tableauMouvementPossible[compteurCoup].colonne = colonne - direction;

                direction = direction + 1;
                compteurCoup = compteurCoup + 1;
            }
            for (diag = 1; diag < 8; diag++) {
                if (plateau[ligne][colonne].equipe == 1) {
                    //diagonale haute droite du fou blanc
                    if (ligne + diag > 7 || colonne + diag > 7) {
                        continueDeCompter1 = 1;
                    }
                    if (ligne + diag < 7 &&
                        colonne + diag < 7) {//c pour éviter que la fonction n'entre des valeur qui font tout crasher
                        if (plateau[ligne + diag][colonne + diag].equipe == plateau[ligne][colonne].equipe) {
                            continueDeCompter1 = 1;
                        }
                    }

                    if (continueDeCompter1 == 0) {
                        tableauMouvementPossible[compteurCoup].ligne = ligne + diag;
                        tableauMouvementPossible[compteurCoup].colonne = colonne + diag;
                        compteurCoup = compteurCoup + 1;
                    }
                    if (ligne + diag < 7 && colonne + diag < 7) {
                        if (plateau[ligne + diag][colonne + diag].equipe == 2) {
                            continueDeCompter1 = 1;
                        }
                    }

                    //diagonale gauche haute du fou blanc
                    if (ligne + diag > 7 || colonne - diag < 0) {
                        continueDeCompter2 = 1;
                    }
                    if (ligne + diag < 7 && colonne + diag > 0) {
                        if (plateau[ligne + diag][colonne - diag].equipe == plateau[ligne][colonne].equipe) {
                            continueDeCompter2 = 1;
                        }
                    }
                    if (continueDeCompter2 == 0) {
                        tableauMouvementPossible[compteurCoup].ligne = ligne + diag;
                        tableauMouvementPossible[compteurCoup].colonne = colonne - diag;
                        compteurCoup = compteurCoup + 1;
                    }
                    if (ligne + diag < 7 && colonne + diag > 0) {
                        if (plateau[ligne + diag][colonne - diag].equipe == 2) {
                            continueDeCompter2 = 1;
                        }
                    }

                    //diagonale basse droite du fou blanc
                    if (ligne - diag < 0 || colonne - diag < 0) {
                        continueDeCompter3 = 1;
                    }
                    if (ligne + diag > 0 && colonne + diag > 0) {
                        if (plateau[ligne - diag][colonne - diag].equipe == plateau[ligne][colonne].equipe) {
                            continueDeCompter3 = 1;
                        }
                    }
                    if (continueDeCompter3 == 0) {
                        tableauMouvementPossible[compteurCoup].ligne = ligne - diag;
                        tableauMouvementPossible[compteurCoup].colonne = colonne - diag;
                        compteurCoup = compteurCoup + 1;
                    }
                    if (ligne + diag > 0 && colonne + diag > 0) {
                        if (plateau[ligne - diag][colonne - diag].equipe == 2) {
                            continueDeCompter3 = 1;
                        }
                    }

                    //diagonale basse droite du fou blanc
                    if (ligne - diag < 0 || colonne - diag > 7) {
                        continueDeCompter4 = 1;
                    }
                    if (ligne + diag > 0 && colonne + diag < 7) {
                        if (plateau[ligne - diag][colonne + diag].equipe == plateau[ligne][colonne].equipe) {
                            continueDeCompter4 = 1;
                        }
                    }
                    if (continueDeCompter4 == 0) {
                        tableauMouvementPossible[compteurCoup].ligne = ligne - diag;
                        tableauMouvementPossible[compteurCoup].colonne = colonne + diag;
                        compteurCoup = compteurCoup + 1;
                    }
                    if (ligne + diag > 0 && colonne + diag < 7) {
                        if (plateau[ligne - diag][colonne + diag].equipe == 2) {
                            continueDeCompter4 = 1;
                        }
                    }
                }

                if (plateau[ligne][colonne].equipe == 2) {
                    //diagonale basse gauche du fou noir
                    if (ligne + diag > 7 || colonne + diag > 7) {
                        continueDeCompter1 = 1;
                    }
                    if (ligne + diag <= 7 &&
                        colonne + diag <= 7) {//c pour éviter que la fonction n'entre des valeur qui font tout crasher
                        if (plateau[ligne + diag][colonne + diag].equipe == plateau[ligne][colonne].equipe) {
                            continueDeCompter1 = 1;
                        }
                    }

                    if (continueDeCompter1 == 0) {
                        tableauMouvementPossible[compteurCoup].ligne = ligne + diag;
                        tableauMouvementPossible[compteurCoup].colonne = colonne + diag;
                        compteurCoup = compteurCoup + 1;
                    }
                    if (ligne + diag <= 7 && colonne + diag <= 7) {
                        if (plateau[ligne + diag][colonne + diag].equipe == 1) {
                            continueDeCompter1 = 1;
                        }
                    }

                    //diagonale droite basse du fou noir
                    if (ligne + diag > 7 || colonne - diag < 0) {
                        continueDeCompter2 = 1;
                    }
                    if (ligne + diag <= 7 && colonne + diag >= 0) {
                        if (plateau[ligne + diag][colonne - diag].equipe == plateau[ligne][colonne].equipe) {
                            continueDeCompter2 = 1;
                        }
                    }
                    if (continueDeCompter2 == 0) {
                        tableauMouvementPossible[compteurCoup].ligne = ligne + diag;
                        tableauMouvementPossible[compteurCoup].colonne = colonne - diag;
                        compteurCoup = compteurCoup + 1;
                    }
                    if (ligne + diag <= 7 && colonne + diag >= 0) {
                        if (plateau[ligne + diag][colonne - diag].equipe == 1) {
                            continueDeCompter2 = 1;
                        }
                    }

                    //diagonale haute gauche du fou noir
                    if (ligne - diag < 0 || colonne - diag < 0) {
                        continueDeCompter3 = 1;
                    }
                    if (ligne + diag >= 0 && colonne + diag >= 0) {
                        if (plateau[ligne - diag][colonne - diag].equipe == plateau[ligne][colonne].equipe) {
                            continueDeCompter3 = 1;
                        }
                    }
                    if (continueDeCompter3 == 0) {
                        tableauMouvementPossible[compteurCoup].ligne = ligne - diag;
                        tableauMouvementPossible[compteurCoup].colonne = colonne - diag;
                        compteurCoup = compteurCoup + 1;
                    }
                    if (ligne + diag >= 0 && colonne + diag >= 0) {
                        if (plateau[ligne - diag][colonne - diag].equipe == 1) {
                            continueDeCompter3 = 1;
                        }
                    }

                    //diagonale haute gauche du fou noir
                    if (ligne - diag < 0 || colonne - diag > 7) {
                        continueDeCompter4 = 1;
                    }
                    if (ligne + diag >= 0 && colonne + diag <= 7) {
                        if (plateau[ligne - diag][colonne + diag].equipe == plateau[ligne][colonne].equipe) {
                            continueDeCompter4 = 1;
                        }
                    }
                    if (continueDeCompter4 == 0) {
                        tableauMouvementPossible[compteurCoup].ligne = ligne - diag;
                        tableauMouvementPossible[compteurCoup].colonne = colonne + diag;
                        compteurCoup = compteurCoup + 1;
                    }
                    if (ligne + diag >= 0 && colonne + diag <= 7) {
                        if (plateau[ligne - diag][colonne + diag].equipe == 1) {
                            continueDeCompter4 = 1;
                        }
                    }
                }
            }
            break;
        }
        case 'c': {
            compteurCoup=0;
            int compteurDebug=0;
            if (ligne+2<=7){
                if (colonne+1<=7){
                    if (plateau[ligne][colonne].equipe!=plateau[ligne+2][colonne+1].equipe){
                        tableauMouvementPossible[compteurCoup].ligne=ligne+2;
                        tableauMouvementPossible[compteurCoup].colonne=colonne+1;
                        compteurCoup=compteurCoup+1;
                    }
                }
                if (colonne-1>=0){
                    if (plateau[ligne][colonne].equipe!=plateau[ligne+2][colonne-1].equipe){
                        tableauMouvementPossible[compteurCoup].ligne=ligne+2;
                        tableauMouvementPossible[compteurCoup].colonne=colonne-1;
                        compteurCoup=compteurCoup+1;
                    }
                }
            }
            if (ligne-2>=0){
                if (colonne+1<=7){
                    if (plateau[ligne][colonne].equipe!=plateau[ligne-2][colonne+1].equipe){
                        tableauMouvementPossible[compteurCoup].ligne=ligne-2;
                        tableauMouvementPossible[compteurCoup].colonne=colonne+1;
                        compteurCoup=compteurCoup+1;
                    }
                }
                if (colonne-1>=0){
                    if (plateau[ligne][colonne].equipe!=plateau[ligne-2][colonne-1].equipe){
                        tableauMouvementPossible[compteurCoup].ligne=ligne-2;
                        tableauMouvementPossible[compteurCoup].colonne=colonne-1;
                        compteurCoup=compteurCoup+1;
                    }
                }
            }
            if (colonne+2<=7){
                if (ligne+1<=7){
                    if (plateau[ligne][colonne].equipe!=plateau[ligne+1][colonne+2].equipe){
                        tableauMouvementPossible[compteurCoup].ligne=ligne+1;
                        tableauMouvementPossible[compteurCoup].colonne=colonne+2;
                        compteurCoup=compteurCoup+1;
                    }
                }
                if (ligne-1>=0){
                    if (plateau[ligne][colonne].equipe!=plateau[ligne-1][colonne+2].equipe){
                        tableauMouvementPossible[compteurCoup].ligne=ligne-1;
                        tableauMouvementPossible[compteurCoup].colonne=colonne+2;
                        compteurCoup=compteurCoup+1;
                    }
                }
            }
            if (colonne-2>=0){
                if (ligne+1<=7){
                    if (plateau[ligne][colonne].equipe!=plateau[ligne+1][colonne-2].equipe){
                        tableauMouvementPossible[compteurCoup].ligne=ligne+1;
                        tableauMouvementPossible[compteurCoup].colonne=colonne-2;
                        compteurCoup=compteurCoup+1;
                    }
                }
                if (ligne-1>=0){
                    if (plateau[ligne][colonne].equipe!=plateau[ligne-1][colonne-2].equipe){
                        tableauMouvementPossible[compteurCoup].ligne=ligne-1;
                        tableauMouvementPossible[compteurCoup].colonne=colonne-2;
                        compteurCoup=compteurCoup+1;
                    }
                }
            }
            break;
        }
        case 'R': {
            compteurCoup = 0;
            int k = 0;
            if (ligne+1<=7){
                if(colonne+1<=7){
                    if(plateau[ligne][colonne].equipe!=plateau[ligne+1][colonne+1].equipe){
                        tableauMouvementPossible[compteurCoup].ligne=ligne+1;
                        tableauMouvementPossible[compteurCoup].colonne=colonne+1;
                        compteurCoup=compteurCoup+1;
                    }
                }
                if(plateau[ligne][colonne].equipe!=plateau[ligne+1][colonne].equipe){
                    tableauMouvementPossible[compteurCoup].ligne=ligne+1;
                    tableauMouvementPossible[compteurCoup].colonne=colonne;
                    compteurCoup=compteurCoup+1;
                }
                if(colonne+1>=0){
                    if(plateau[ligne][colonne].equipe!=plateau[ligne+1][colonne-1].equipe){
                        tableauMouvementPossible[compteurCoup].ligne=ligne+1;
                        tableauMouvementPossible[compteurCoup].colonne=colonne-1;
                        compteurCoup=compteurCoup+1;
                    }
                }
            }
            if (colonne+1<=7){
                if(plateau[ligne][colonne].equipe!=plateau[ligne][colonne+1].equipe){
                    tableauMouvementPossible[compteurCoup].ligne=ligne;
                    tableauMouvementPossible[compteurCoup].colonne=colonne+1;
                    compteurCoup=compteurCoup+1;
                }
            }
            if (colonne-1>=0){
                if(plateau[ligne][colonne].equipe!=plateau[ligne][colonne-1].equipe){
                    tableauMouvementPossible[compteurCoup].ligne=ligne;
                    tableauMouvementPossible[compteurCoup].colonne=colonne-1;
                    compteurCoup=compteurCoup+1;
                }
            }
            if (ligne-1>=0){
                if(colonne+1<=7){
                    if(plateau[ligne][colonne].equipe!=plateau[ligne-1][colonne+1].equipe){
                        tableauMouvementPossible[compteurCoup].ligne=ligne-1;
                        tableauMouvementPossible[compteurCoup].colonne=colonne+1;
                        compteurCoup=compteurCoup+1;
                    }
                }
                if(plateau[ligne][colonne].equipe!=plateau[ligne-1][colonne].equipe){
                    tableauMouvementPossible[compteurCoup].ligne=ligne-1;
                    tableauMouvementPossible[compteurCoup].colonne=colonne;
                    compteurCoup=compteurCoup+1;
                }
                if(colonne+1>=0){
                    if(plateau[ligne][colonne].equipe!=plateau[ligne-1][colonne-1].equipe){
                        tableauMouvementPossible[compteurCoup].ligne=ligne-1;
                        tableauMouvementPossible[compteurCoup].colonne=colonne-1;
                        compteurCoup=compteurCoup+1;
                    }
                }
            }
            break;
        }
    }
}