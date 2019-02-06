#include <stdio.h>
#include <stdlib.h>
#include "vue.h"
#include "inscription.h"

/**
    i : int             :nVar
    f : float           :flVar
    d : double          :dblVar
    c : char            :cVar
    l : long int        :lnVar
    ll: long long int   :llnVar
    L : double long     :ldblVar
    h : short int       :srVar
    ui: unsigned int    :unVar
    uf: unsigned float  :unfVar
    s : *STRING*
    * : *POINTEUR*      :pVar
*/

/**
  * BUT : Programme principale: affiche un menu, l'utilisateur choisi si il veux entrer un nouveau client, si il veux afficher les client ou si il veux quitter le programme
  * ENTREE :Un entier
  * SORTIE :
  */
int main()
{

    int nChoix=0;

    do{

        fflush(stdin);
        printf("Entrez un chiffre.\n");
        printf("1: ecrireFichier\n");
        printf("2: lireFichier\n");
        printf("0: QUITTER\n");

        scanf("%d",&nChoix);
        fflush(stdin);

        if (nChoix == 1){
            ecrireFichier();
        } else if (nChoix == 2){
            lireFichier();
        }

    }while(nChoix != 0);

    system("pause");

    return 0;
}
