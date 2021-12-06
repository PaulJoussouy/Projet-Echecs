//
// Created by Paul on 22/11/2021.
//

#include "Enregistrer.h"
#include <stdio.h>
#include "menu_V_1.h"


//SAUVEGARDE ET CHARGEMENT AUX ENDROITS 1,2 OU 3

//SAUVEGARDE

void savPartie1(Piece plateau[8][8], const int nombreDeCoup) {

    //SAUVEGARDE

    printf("SAUVEGARDE EN COURS...\n");
    FILE* pf=NULL;

    if ((pf = fopen("../LA_Sauvegarde1.dat", "w")) == NULL) {   //Ouverture du fichier binaire
        printf("Erreur d'ouverture du fichier.\n");             //Le fichier n'existe pas
        return;   }

    fwrite(&nombreDeCoup,sizeof(int),1,pf);                 //Ecriture du nombre de coups sauvgardés dans le fichier binaire
    if (fwrite(plateau, sizeof(Piece),64, pf) != 64) {      // Ecriture des coordonees des pieces dans le fichier Sauvegarde
        printf("Probleme d'ecriture dans le fichier.\n");   //Erreur d'écriture
    }

    fclose(pf);
    pf = NULL;

    printf("SAUVEGARDE TERMINEE\n");
    return;
}

void savPartie2(Piece plateau[8][8], const int nombreDeCoup) {

    //SAUVEGARDE

    printf("SAUVEGARDE EN COURS...\n");
    FILE* pf=NULL;

    if ((pf = fopen("../LA_Sauvegarde2.dat", "w")) == NULL) {   //Ouverture du fichier binaire
        printf("Erreur d'ouverture du fichier.\n");             //Le fichier n'existe pas
        return;   }

    fwrite(&nombreDeCoup,sizeof(int),1,pf);                 //Ecriture du nombre de coups sauvgardés dans le fichier binaire
    if (fwrite(plateau, sizeof(Piece),64, pf) != 64) {      // Ecriture des coordonees des pieces dans le fichier Sauvegarde
        printf("Probleme d'ecriture dans le fichier.\n");   //Erreur d'écriture
    }

    fclose(pf);
    pf = NULL;

    printf("SAUVEGARDE TERMINEE\n");
    return;
}

void savPartie3(Piece plateau[8][8], const int nombreDeCoup) {

    //SAUVEGARDE

    printf("SAUVEGARDE EN COURS...\n");
    FILE* pf=NULL;

    if ((pf = fopen("../LA_Sauvegarde3.dat", "w")) == NULL) {        //Ouverture du fichier binaire
        printf("Erreur d'ouverture du fichier.\n");                  //Le fichier n'existe pas
        return;   }

    fwrite(&nombreDeCoup,sizeof(int),1,pf);                 //Ecriture du nombre de coups sauvgardés dans le fichier binaire
    if (fwrite(plateau, sizeof(Piece),64, pf) != 64) {      // Ecriture des coordonees des pieces dans le fichier Sauvegarde
        printf("Probleme d'ecriture dans le fichier.\n");   //Erreur d'écriture
    }

    fclose(pf);
    pf = NULL;

    printf("SAUVEGARDE TERMINEE\n");
    return;
}

//CHARGEMENT

void chrgPartie1(Piece plateau[8][8], int* nombreDeCoup)  {

    //CHARGEMENT 1

    printf("CHARGEMENT EN COURS...\n");
    FILE *pf = fopen("../LA_Sauvegarde1.dat", "r");      //Ouverture du fichier binaire 1 de sauvegarde

    if (pf == NULL) {                                   //Teste si le fichier existe
        printf("Fichier introuvable...\n");             //Si il n'exite pas, retour au menu
        return;
    }

    fread(nombreDeCoup,sizeof(int),1, pf);              //Lecture du nombre de coups sauvgardés dans le fichier binaire
    fread(plateau, sizeof(Piece),64, pf);                //Lecture des coordonnées des pièces et des cases vides

    fclose(pf);                                         //Fermeture du fichier
    pf = NULL;                                          //Pointeur nul

    printf("CHARGEMENT TERMINE\n");
    return;
}

void chrgPartie2(Piece plateau[8][8], int* nombreDeCoup)  {

    //CHARGEMENT 2

    printf("CHARGEMENT EN COURS...\n");
    FILE *pf = fopen("../LA_Sauvegarde2.dat", "r");      //Ouverture du fichier binaire 2 de sauvegarde

    if (pf == NULL) {                                   //Teste si le fichier existe
        printf("Fichier introuvable...\n");             //Si il n'exite pas, retour au menu
        return;
    }

    fread(nombreDeCoup,sizeof(int),1, pf);              //Lecture du nombre de coups sauvgardés dans le fichier binaire
    fread(plateau, sizeof(Piece),64, pf);               //Lecture des coordonnées des pièces et des cases vides

    fclose(pf);                                         //Fermeture du fichier
    pf = NULL;                                          //Pointeur nul

    printf("CHARGEMENT TERMINE\n");
    return;
}

void chrgPartie3(Piece plateau[8][8], int* nombreDeCoup)  {

    //CHARGEMENT 3

    printf("CHARGEMENT EN COURS...\n");
    FILE *pf = fopen("../LA_Sauvegarde3.dat", "r");      //Ouverture du fichier binaire 3 de sauvegarde

    if (pf == NULL) {                                   //Teste si le fichier existe
        printf("Fichier introuvable...\n");             //Si il n'exite pas, retour au menu
        return;
    }

    fread(nombreDeCoup,sizeof(int),1, pf);              //Lecture du nombre de coups sauvgardés dans le fichier binaire
    fread(plateau, sizeof(Piece),64, pf);               //Lecture des coordonnées des pièces et des cases vides

    fclose(pf);                                          //Fermeture du fichier
    pf = NULL;                                           //Pointeur nul

    printf("CHARGEMENT TERMINE\n");
    return;
}

//SELECTION DES ENDROITS DE SAUVEGARDE ET CHARGEMENT

void selectionnerSauvegarde(Piece plateau[8][8], const int nombreDeCoup)   {
    //Fonction qui permet de sélectionner l'emplacement de la sauvegarde de la partie que l'on souhaite sauvegarder

    int i = 0;
    printf("\nSAUVEGARDE\nSur quelle sauvegarde souhaitez vous enregistrer votre partie ?\n");
    printf("1) Sauvegarde 1\n2) Sauvegarde 2\n3) Sauvegarde 3\n");
    scanf("%d", &i);
    switch(i)   {

        case 1 :
            savPartie1(plateau, nombreDeCoup);      //Sauvegarde sur l'emplacement 1
            break;
        case 2 :
            savPartie2(plateau, nombreDeCoup);      //Sauvegarde sur l'emplacement 2
            break;
        case 3 :
            savPartie3(plateau, nombreDeCoup);      //Sauvegarde sur l'emplacement 3
            break;
        default :
            printf("Valeur invalide ! Retournez au menu et selectionnez une sauvegarde valide !\n");    //Choix de sauvegarde invalide, on revient au menu
            break;  }
    return;
}

void chargerSauvegarde(Piece plateau[8][8], int* nombreDeCoup)   {
    //Fonction qui permet de charger une partie sauvegardée à l'emplacement souhaité

    int i = 0;
    printf("\nCHARGEMENT\nQuelle sauvegarde souhaitez vous charger ?\n");
    printf("1) Sauvegarde 1\n2) Sauvegarde 2\n3) Sauvegarde 3\n");
    scanf("%d", &i);

    switch(i)   {

        case 1 :
            chrgPartie1(plateau, nombreDeCoup);     //Charge la partie sauvegardée sur l'emplacement 1
            break;
        case 2 :
            chrgPartie2(plateau, nombreDeCoup);     //Charge la partie sauvegardée sur l'emplacement 2
            break;
        case 3 :
            chrgPartie3(plateau, nombreDeCoup);     //Charge la partie sauvegardée sur l'emplacement 3
            break;
        default :
            printf("Valeur invalide ! Retournez au menu et selectionnez une sauvegarde valide !\n\n");      //Choix de sauvegarde invalide, on revient au menu
            break;
    }
    return;
}
