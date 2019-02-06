#include <stdio.h>
#include <stdlib.h>
#include "inscription.h"

/**
    i : int             :nNom
    f : float           :flNom
    d : double          :dblNom
    c : char            :cNom
    l : long            :lnNom
    ui: unsigned int    : unNomVar
    uf: unsigned float  : unfNomVar
    s : *STRING*
*/

/**
  * BUT : Demande � l'utilisateur les iformations du client puis les inscrit dans un fichier et num�rotte le client
  * ENTREE : les informations du client
  * SORTIE : Les informations du client dans le fichier et num�rotation du client
  */
void ecrireFichier(){

    ///Initialisation des variables
    FILE *pFile;
    //Initialisation et calcul du nombre de clients en fonction du nombre de ligne
    int nClient = (calculNbLignes(pFile)-1)/8+1;
    //tIdentity carte;
    tIdentity Carte;

    ///Lecture des donn�es du client
    printf("Entrez l'identifiant du client.\n");
    gets(Carte.sID);
    fflush(stdin);

    printf("Entrez le nom du client.\n");
    gets(Carte.sNom);
    fflush(stdin);

    printf("Entrez le prenom du client.\n");
    gets(Carte.sPrenom);
    fflush(stdin);

    printf("Entrez l'adresse du client.\n");
    gets(Carte.sAdresse);
    fflush(stdin);

    printf("Entrez le code postal du client.\n");
    gets(Carte.sPostal);
    fflush(stdin);

    printf("Entrez la ville du client.\n");
    gets(Carte.sVille);
    fflush(stdin);

    ///Ouverture avec validation du fichier en mode 'ajouter/add'
    if ((pFile=fopen("clients.txt", "a"))==NULL){
        perror("Erreur de creation de fichier\n");
    } else {

        ///Inscrit les information du client dans le fichier
        fputc('\n', pFile);
        fprintf(pFile,"Client %d", nClient);
        fputc('\n', pFile);
        fputs(Carte.sID, pFile);
        fputc('\n', pFile);
        fputs(Carte.sNom, pFile);
        fputc('\n', pFile);
        fputs(Carte.sPrenom, pFile);
        fputc('\n', pFile);
        fputs(Carte.sAdresse, pFile);
        fputc('\n', pFile);
        fputs(Carte.sPostal, pFile);
        fputc('\n', pFile);
        fputs(Carte.sVille, pFile);
        fputc('\n', pFile);
        fclose(pFile);
    }

}

/**
  * BUT : Compte ne nombre de lignes dans le fichier en incr�mentant un compteur � chaque fois qu'on '\n' est trouv�
  * ENTREE : le fichier
  * SORTIE : le nombre de ligne (-1)
  */
int calculNbLignes (FILE *pFile){

    ///Initialisation des variables
    int nLigne=0;
    char cChara;

    ///Ouverture avec validation du fichier en mode 'lecture/read'
    if ((pFile=fopen("clients.txt", "r"))==NULL){
        perror("Erreur de creation de fichier\n");
    } else {

        ///Remonter en d�but de fichier
        rewind(pFile);
        ///Lecture de tous les charact�res du fichier et intr�mentation d'un compteur � chaque fois qu'un '\n' est trouv�
        ///NOTE: du � la m�thode utiliser il retourne le nombre de lignes - 1
        while((cChara = fgetc(pFile)) !=  EOF){
            if(cChara == '\n'){
                nLigne ++;
            }
        }

    }

    return nLigne + 1;

}
