/**
*	NOM FICHIER:    main.cpp
* 	DESCRIPTION :   Ce main permet de compter le nombre de mot
*                                  contenu dans un fichier texte
*
*	Auteur :                J. Monnier
*	Date:                     13/01/2019
*/

#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
#include <stdio.h>

/**
* NOM FONCTION: nombreMotFichier
* PARAMETRES: std::string contenuChaine
* ENTREES: std::string contenuChaine
* ENTREES-SORTIES:
* RENVOI: int nbMot+1
* DESCRIPTION: retourne le nombre de mot contenu dans un string sous forme d'un entier
*
* DATE : 13/01/2019
* AUTEUR : J.MONNIER
* CONTRAINTES D’UTILISATION: si chaine vide la fonction nous retournera 1
*/
int nombreMotFichier(std::string contenuChaine){
    int nbMot     =   0;

    char caracterePrecedent = ' ';

    for(unsigned int i=0 ; i != contenuChaine.size() ;  i++){
        if (((contenuChaine[i] != ' ')&&(caracterePrecedent == ' '))){
            nbMot ++;
        }
        caracterePrecedent = contenuChaine[i];
    }
    return nbMot+1;
}//fin fonction nombreMotFichier


/**
* NOM FONCTION: main
* PARAMETRES: int argc, char ** argv
* ENTREES: int argc, char ** argv
* RENVOI: return 0
* DESCRIPTION:  récupère le nom du fichier, l'ouvre et stocke tout le contenu dans un buffer string
*                               puis implémente la fonction nombreMotFichier() pour calculer le nombre de mot contenu
*                               dans le buffer
*
* DATE : 13/01/2019
* AUTEUR : J.MONNIER
* CONTRAINTES D’UTILISATION:
*/
int main(int argc, char ** argv){
    int nbMot   =   0;
    std::string contenuFichier;
    std::stringstream bufferFichier;
    std::ifstream fichier(argv[1], std::ios::in);

//Teste le nombre d'argument passé en paramètre lors de l'exécution du script
    if (argc >=3){
        std::cout << "Trop de parametres !!!" <<std::endl;
        return -1;
    }

    if(fichier){

        bufferFichier << fichier.rdbuf(); //on récupère ce que contient ke fichier (ressemble au cout mais on redirige dans un buffer)
        fichier.close();
        nbMot   =   nombreMotFichier(bufferFichier.str()); //compte le nombre de mot dans le string bufferFichier
        std::cout<<bufferFichier.str()<<std::endl;
        std::cout<<"nombre de mot : "<< nbMot <<std::endl;


    }else{
        std::cerr << "Impossible d'ouvrir le fichier!" <<std::endl;
    }

    return 0;
}

/*
#include <fstream>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <string>
#include <cstdlib>

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Usage: count_words <infile>\n";
        return EXIT_FAILURE;
    }

    std::ifstream infile(argv[1]);

    std::istream_iterator<std::string> in{ infile }, end;

    std::cout << "Word count: " << std::distance(in, end)<< std::endl;
}

*/
