#include <sys/types.h>
#include <dirent.h>
#include <stdbool.h>

#define NBR_MAX_JOUEURS 100

int nbrFichiersExistants = 0;
char *fichiersExistants[30];

bool checkInTable(char* table, char* value){
    if (nbrFichiersExistants == 0) return false;
    for(int i=0; i<NBR_MAX_JOUEURS; i++){
        if(strcmp(&table[i],value) == 0 || strcmp(value,".") == 0 || strcmp(value,"..") == 0)
        return true;
    }
    return false;
}

int listerJoueurs(){
    struct dirent *lecture;
    DIR *rep;
    rep = opendir("/tmp/kahoot");
    while ((lecture = readdir(rep))) {
        if(checkInTable(fichiersExistants,lecture->d_name) == false){
            strcpy(&fichiersExistants[nbrFichiersExistants++],lecture->d_name);
            printf("%s a rejoint la partie...\n",&fichiersExistants[nbrFichiersExistants-1]);
        }
    }
    closedir(rep);
}