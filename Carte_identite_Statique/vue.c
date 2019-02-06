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
    char sTemp[TAILLE];
    char sTemp2[TAILLE];

    ///Ouverture avec validation du fichier en mode 'lecture/read'
    if ((pFile = fopen("clients.txt","r"))== NULL){
        perror("ERREUR OUVERTURE/CREATION FICHIER");
    } else {
        ///Lecture du fichier
        while(fgets(sTemp,255,pFile)!=NULL){
            strcat(sTemp2,sTemp);
        }
    }

    fclose(pFile);

    ///Ecriture à l'écran du contenu du fichier
    printf("%s\n",sTemp2);

}
