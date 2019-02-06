#ifndef INSCRIPTION_H_INCLUDED
#define INSCRIPTION_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#pragma once


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

typedef struct tIdentity{

    char sID[10];
    char sNom[256];
    char sPrenom[256];
    char sAdresse[256];
    char sPostal[10];
    char sVille[256];

}tIdentity;

extern void ecrireFichier();
extern int calculNbLignes(FILE *pFile);

#endif // INSCRIPTION_H_INCLUDED
