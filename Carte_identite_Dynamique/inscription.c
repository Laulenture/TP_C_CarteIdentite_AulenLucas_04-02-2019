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
  * BUT : Demande à l'utilisateur les iformations du client puis les inscrit dans un fichier et numérotte le client
  * ENTREE : les informations du client
  * SORTIE : Les informations du client dans le fichier et numérotation du client
  */
void ecrireFichier(){

    ///Initialisation des variables
    FILE *pFile;
    //Initialisation et calcul du nombre de clients en fonction du nombre de ligne
    int nClient = (calculNbLignes(pFile)-1)/8+1;
    //tIdentity carte;
    tIdentity *pCarte=NULL;

    ///Vérification que l'allocaion de pCarte à bien eu lieu
    if((pCarte=malloc(sizeof(struct tIdentity)))==NULL){

        perror("Erreur de creation d'alloaction\n");

    } else {

        ///Lecture des données du client
        printf("Entrez l'identifiant du client.\n");
        gets(pCarte->sID);
        fflush(stdin);

        printf("Entrez le nom du client.\n");
        gets(pCarte->sNom);
        fflush(stdin);

        printf("Entrez le prenom du client.\n");
        gets(pCarte->sPrenom);
        fflush(stdin);

        printf("Entrez l'adresse du client.\n");
        gets(pCarte->sAdresse);
        fflush(stdin);

        printf("Entrez le code postal du client.\n");
        gets(pCarte->sPostal);
        fflush(stdin);

        printf("Entrez la ville du client.\n");
        gets(pCarte->sVille);
        fflush(stdin);

        ///Ouverture avec validation du fichier en mode 'ajouter/add'
        if ((pFile=fopen("clients.txt", "a"))==NULL){
            perror("Erreur de creation de fichier\n");
        } else {

            ///Inscrit les information du client dans le fichier
            fputc('\n', pFile);
            fprintf(pFile,"Client %d", nClient);
            fputc('\n', pFile);
            fputs(pCarte->sID, pFile);
            fputc('\n', pFile);
            fputs(pCarte->sNom, pFile);
            fputc('\n', pFile);
            fputs(pCarte->sPrenom, pFile);
            fputc('\n', pFile);
            fputs(pCarte->sAdresse, pFile);
            fputc('\n', pFile);
            fputs(pCarte->sPostal, pFile);
            fputc('\n', pFile);
            fputs(pCarte->sVille, pFile);
            fputc('\n', pFile);
            fclose(pFile);
        }

    }

}

/**
  * BUT : Compte ne nombre de lignes dans le fichier en incrémentant un compteur à chaque fois qu'on '\n' est trouvé
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

        ///Remonter en début de fichier
        rewind(pFile);
        ///Lecture de tous les charactères du fichier et intrémentation d'un compteur à chaque fois qu'un '\n' est trouvé
        ///NOTE: du à la méthode utiliser il retourne le nombre de lignes - 1
        while((cChara = fgetc(pFile)) !=  EOF){
            if(cChara == '\n'){
                nLigne ++;
            }
        }

    }

    return nLigne + 1;

}
