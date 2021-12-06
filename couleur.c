//
// Created by Paul on 22/11/2021.
//

#include "couleur.h"
#include <stdio.h>

void  rouge(){
    printf("\033[0;31m");
}

void  gris(){
    printf("\033[0;37m");
}

void  jaune(){
    printf("\033[0;33m");//"\033[0;33m"
}

void fondVert(){
    printf("\033[0;42m");
}

void encadreCase(){
    printf("\033[0;51m");// 3;51
}
/*
 * [0;45m      color le font
 * printf("\033[3;40m") ecrit en italique
 * printf("\033[7;40m") met le font en noir
 *  printf("\033[3;41m") met le font rouge
 *  printf("\033[3;41m") met font vert
 *  printf("\033[3;51m") entoure la piece
 */

void  bleu(){
    printf("\033[0;34m");
}

void  violet(){
    printf("\033[0;35m");
}

void  vert(){
    printf("\033[0;32m");
}

void  cyan(){
    printf("\033[0;36m");
}

void  resetCouleur(){
    printf("\033[0m");
}

/*
 * end="\033[0m"
black="\033[0;30m"
blackb="\033[1;30m"
white="\033[0;37m"
whiteb="\033[1;37m"
red="\033[0;31m"
redb="\033[1;31m"
green="\033[0;32m"
greenb="\033[1;32m"
yellow="\033[0;33m"
yellowb="\033[1;33m"
blue="\033[0;34m"
blueb="\033[1;34m"
purple="\033[0;35m"
purpleb="\033[1;35m"
lightblue="\033[0;36m"
lightblueb="\033[1;36m"

 */