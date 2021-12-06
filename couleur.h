//
// Created by Paul on 22/11/2021.
//

#ifndef ECHEC_V_0_COULEUR_H
#define ECHEC_V_0_COULEUR_H
/*=====================================================================
In: rien
But: mettre la couleur de l'affichage console en:
 rouge, gris, jaune, bleu, violet, vert, cyan ou reinisialiser la couleur a celle d'origine
Out: rien
In/Out: rien
PS: * ne fonctionne peut etre pas sur platforme autre que Machintosh (il faut essayer),
    * il faut appeler la fonction de la couleur choisit juste avant le printf
    * ne pas oublier de reinitialiser la couleur apres l'utilisation du printf
*/
void  rouge();
void  gris();
void  jaune();
void  bleu();
void  violet();
void  vert();
void  cyan();

void encadreCase();
void fondVert();
void  resetCouleur();
//..................................


#endif //ECHEC_V_0_COULEUR_H
