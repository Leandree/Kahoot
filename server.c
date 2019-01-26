#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include "utils.c"

int main (int argc, char **argv){

    int nbrJoueurs;
    printf("Nombre de joueurs : ");
    scanf("%d",&nbrJoueurs);
    while(nbrFichiersExistants < nbrJoueurs)
    {
        listerJoueurs();
    }

    
    
    return 0;
}