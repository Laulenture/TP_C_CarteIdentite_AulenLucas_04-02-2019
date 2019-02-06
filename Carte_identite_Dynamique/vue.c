#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE 1000

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
  * BUT : Lis le fichier et affiche son contenu
  * ENTREE : le fichier
  * SORTIE : le contenu du fichier
  */
void lireFichier(){

    FILE *pFile;
    char *psTemp=NULL;
    char *psTemp2=NULL;

    ///Vérification que l'allocaion de psTemp à bien eu lieu
    if((psTemp=malloc(TAILLE*sizeof(char)))==NULL){

        perror("Erreur de creation d'alloaction\n");

    } else {
        ///Vérification que l'allocaion de psTemp2 à bien eu lieu
        if((psTemp2=malloc(TAILLE*sizeof(char)))==NULL){

        perror("Erreur de creation d'alloaction\n");

        } else {
            ///Ouverture avec validation du fichier en mode 'lecture/read'
            if ((pFile = fopen("clients.txt","r"))== NULL){
                perror("ERREUR OUVERTURE/CREATION FICHIER");
            } else {
                ///Lecture du fichier
                while(fgets(psTemp,255,pFile)!=NULL){
                    strcat(psTemp2,psTemp);
                }
            }
        }
    }

    fclose(pFile);

    ///Ecriture à l'écran du contenu du fichier
    printf("%s\n",psTemp2);

}
