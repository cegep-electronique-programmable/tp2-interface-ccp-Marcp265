/*
* ecran.h
* Contient toutes les fonctions pour interagir avec l'ecran modele
* NHD-0420D3Z-FL-GBW
*
* Auteur : Marc Pilon
*/

#ifndef ECRAN_H
#define ECRAN_H

/***********Includes************/


/************Defines************/


/*********Declarations**********/
/*
* Fonction : ecranAllume
* Description : Envoie la commande pour allumer l'ecran
*
* Params : Aucun
* 
* Retour : Aucun
*/
void ecranAllume(void);

/*
* Fonction : ecranEteint
* Description : Envoie la commande pour eteindre l'ecran
*
* Params : Aucun
* 
* Retour : Aucun
*/
void ecranEteint(void);

/*
* Fonction : curseurPosition 
* Description : Envoie la commande pour mettre le curseur � une position
*
* Params : position
* 
* Retour : Aucun
*/
void curseurPosition(int position);

/*
* Fonction : vide�cran
* Description : Envoie la commande pour vider l'�cran
*
* Params : Aucun
* 
* Retour : Aucun
*/
void videEcran(void);

/*
* Fonction : 
* Description : Envoie la commande pour �crire un caract�re
*
* Params : caractere
* 
* Retour : Aucun
*/
void ecrireCaractere(char caractere);

/*
* Fonction : ecranAllume
* Description : Envoie la commande pour allumer le backlight
*
* Params : Aucun
* 
* Retour : Aucun
*/
void backlightAllume(int brightness);

#endif