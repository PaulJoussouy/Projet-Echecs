//
// Created by Paul on 06/12/2021.
//

#include "Regles.h"
#include <stdio.h>
void regles(){

    int reglesDeplacement = 0;
    int reglesBut = 0;
    int reglesSpeciaux = 0;
    int reglesDeroulement = 0;

    printf("Regles des Echecs : \n");

    printf("Le jeu d echecs est un jeu de societe opposant deux joueurs de part et d autre d un \n");
    printf("tablier appele echiquier compose de soixante-quatre cases, 32 claires et 32 sombres \n");
    printf("nommees les cases blanches et les cases noires. Les joueurs jouent a tour de role en\n");
    printf("deplacant l une de leurs seize pieces (ou deux pieces en cas de roque), claires pour\n");
    printf("le camp des blancs, sombres pour le camp des noirs. Chaque joueur possede au depart\n");
    printf("un roi, une dame, deux tours, deux fous, deux cavaliers et huit pions. Le but du jeu\n");
    printf("est d infliger a son adversaire un echec et mat, une situation dans laquelle le roi\n");
    printf("d un joueur est en prise sans qu il soit possible d y remedier. \n");

    do {

        printf("\n");
        printf("Veuillez saisir : \n");
        printf("1) Deroulement du jeu\n");
        printf("2) Mouvement des pieces \n");
        printf("3) Coups speciaux \n");
        printf("0 pour quitter\n>");
        scanf(" %d", &reglesBut);

        switch (reglesBut) {

            case 1 : {

                printf("\n");
                printf("Deroulement du jeu : \n");
                printf("Au debut d une partie d echecs, ce sont toujours les blancs qui commencent.\n");
                printf("Lors d un tour de jeu, le joueur peut effectuer soit un deplacement, soit \n");
                printf("une prise soit un coup special.\n");
                printf("\n");
                printf("But du jeu : \n");
                printf("Ces differents deplacements sont proposes aux joueurs pour parvenir a \n");
                printf("realiser leur objectif qui est de prendre le roi adverse. Lorsque ce but\n");
                printf("est atteint, le joueur qui y est parvenu gagne immediatement la partie qui\n");
                printf("prend fin automatiquement.\n");

                do {

                    printf("\n");
                    printf("1) Echec\n");
                    printf("2) Echec et Mat\n");
                    printf("3) Pat\n");
                    printf("0 pour revenir aux regles\n>");

                    scanf(" %d", &reglesDeroulement);

                    switch (reglesDeroulement) {

                        case 1 : {

                            printf("\n");
                            printf("Echec :\n");
                            printf("Chaque fois que vous pouvez prendre le roi de votre adversaire a votre\n");
                            printf("prochain coup, il y a echec. Votre adversaire doit alors tenter de parer\n");
                            printf("votre echec, lors de son tour de jeu.\n");

                            break;
                        }//fin case echec

                        case 2 : {

                            printf("\n");
                            printf("Echec et mat\n");
                            printf("S il n y parvient pas, son roi est alors echec et mat. Vous remportez \n");
                            printf("donc la partie.\n");

                            break;
                        }//fin case échec et mat

                        case 3 : {

                            printf("\n");
                            printf("Pat\n");
                            printf("Une partie d echecs peut egalement se terminer sur un match nul. Si lors du\n");
                            printf("tour d un joueur, celui-ci ne peut deplacer aucune de ses pieces et que son\n");
                            printf("roi n est pas en echec. On dit alors que la partie se termine par un pat.\n");
                            printf("Il y a egalement pat lors qu'un coup est repete 3 fois.\n");

                            break;
                        }//fin case pat

                        case 0 : {

                            break;
                        }//fin case quitter

                        default : {

                            printf("\n");
                            printf("Saisie invalide, veuillez recommencer. \n");

                            break;
                        }//fin case defautl

                    }//fin switch case

                }while (reglesDeroulement != 0);


                break;
            }//fin case déroulement du jeu

            case 2 : {

                printf("\n");
                printf("Mouvement des pieces : \n");

                do {

                    printf("1) Pion \n");
                    printf("2) Tour \n");
                    printf("3) Cavalier \n");
                    printf("4) Fou \n");
                    printf("5) Reine \n");
                    printf("6) Roi \n");
                    printf("0 pour revenir aux regles \n>");
                    scanf(" %d", &reglesDeplacement);

                    switch (reglesDeplacement) {

                        case 1 : {

                            //règles du pion
                            printf("\n");
                            printf("Le pion avance uniquement devant lui d une seule case. Lors de son premier \n");
                            printf("deplacement, il peut exceptionnellement avancer d une ou de deux cases. Pour\n");
                            printf("prendre une piece ennemie, il se deplace seulement en diagonale d une seule case.\n");

                            break;
                        }//fin case du pion

                        case 2 : {

                            //règles de la tour
                            printf("\n");
                            printf("La tour se deplace horizontalement ou verticalement d autant de cases que vous\n");
                            printf("le souhaitez.\n");

                            break;
                        }//fin case de la tour

                        case 3 : {

                            //règles du cavalier
                            printf("\n");
                            printf("Le cheval se deplace en L. Il saute par-dessus les cases qui entourent sa position\n");
                            printf("initiale (meme s il y a des pieces du meme joueur).\n");

                            break;
                        }//fin case du cavalier

                        case 4 : {

                            //règles du fou
                            printf("\n");
                            printf("Le fou se deplace diagonalement d autant de cases que vous le souhaitez.\n");

                            break;
                        }//fin case du fou

                        case 5 : {

                            //règles de la reine
                            printf("\n");
                            printf("La dame se deplace diagonalement, horizontalement et verticalement d autant de\n");
                            printf("cases que vous le souhaitez.\n");

                            break;
                        }//fin case de la reine

                        case 6 : {

                            //règles du roi
                            printf("\n");
                            printf("Le roi se deplace sur n importe quelle case adjacente a sa position initiale.\n");
                            printf("Cependant, il ne peut pas aller sur une case s il se met en echec.\n");


                            break;
                        }//fin case du roi

                        case 0 : {

                            //quitter les règles

                            break;
                        }

                        default : {

                            //saisie invalide
                            printf("\n");
                            printf("Saisie non valide, veuillez recommencer. \n");

                            break;
                        }

                    }//fin du switch case (regles)

                }while (reglesDeplacement != 0);

                break;
            }//fin case mouvement des pieces

            case 3 : {

                printf("\n");
                printf("Coups speciaux : \n");

                do {

                    printf("1) Roque\n");
                    printf("2) Promotion\n");
                    printf("3) Prise en passant\n");
                    printf("0 pour revenir aux regles\n>");

                    scanf(" %d", &reglesSpeciaux);

                    switch (reglesSpeciaux) {

                        case 1 : {

                            printf("\n");
                            printf("Roque : \n");
                            printf("Le roque permet de deplacer le roi de 2 cases vers la tour et de positionner\n");
                            printf("la tour en question derriere le roi. Il ne peut plus etre effectue si le roi\n");
                            printf("ou la tour ont deja bouge. Il est momentanement empeche si le roi est echec\n");
                            printf("ou s il y a des pieces entre le roi et la tour.\n");

                            break;
                        }

                        case 2 : {

                            printf("\n");
                            printf("Promotion : \n");
                            printf("Quand un pion parvient jusqu a la range la plus proche du joueur adverse,\n");
                            printf("il se transforme en dame, en tour, en fou ou en cavalier. La piece promue\n");
                            printf("est immediatement operationnelle.\n");

                            break;
                        }

                        case 3 : {

                            printf("\n");
                            printf("Prise en passant : \n");
                            printf("Lorsqu un pion se deplace de deux cases (au cours de son premier deplacement)\n");
                            printf("le joueur adverse peut le prendre avec l un de ses pions comme s il n avait\n");
                            printf("avance que d une seule case.\n");

                            break;
                        }

                        case 0 : {

                            break;
                        }

                        default : {

                            printf("\n");
                            printf("Saisie invalide, veuillez recommencer.\n");

                            break;
                        }

                    }//fin switch case

                }while (reglesSpeciaux != 0);

                break;
            }//fin case coups spéciaux

            case 0 : {

                printf("\n");
                printf("sources : https://www.echecs.club/regles/ \n");
                printf("Bonne partie !\n");

                break;
            }//fin case quitter

            default : {

                printf("\n");
                printf("Saisie non valide, veuillez recommencer.\n");

                break;
            }
        }

    }while (reglesBut != 0);

    return;
}